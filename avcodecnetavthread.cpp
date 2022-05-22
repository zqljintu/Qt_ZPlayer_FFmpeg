#include "avcodecnetavthread.h"
#include <QDebug>

avcodecNetAVthread::avcodecNetAVthread(QObject *parent) : QObject(parent)
{

}


void avcodecNetAVthread::setFilePath(char *path)
{
    this->file_path = path;
}

int avcodecNetAVthread::initAvdecodec()
{
    qDebug() <<"video 开始";

    avformat_network_init();
    av_register_all(); //初始化FFMPEG  调用了这个才能正常适用编码器和解码器

    //Allocate an AVFormatContext.
    pFormatCtx = avformat_alloc_context();


    if (avformat_open_input(&pFormatCtx, file_path, NULL, NULL) != 0) {
        qDebug() << "can't open the file.";
        return -1;
    }

    if (avformat_find_stream_info(pFormatCtx, NULL) < 0) {
        qDebug() <<"Could't find stream infomation.";
        return -1;
    }

    videoStream = -1;
    audioStream = -1;
    ///循环查找视频中包含的流信息，直到找到视频类型的流
    ///便将其记录下来 保存到videoStream 和 audioStream变量中
    ///这里我们现在只处理视频流  音频流先不管他
    for (i = 0; i < pFormatCtx->nb_streams; i++) {
        if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStream = i;
        }else if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO) {
            audioStream = i;
        } else {

        }
    }

    ///如果videoStream为-1 说明没有找到视频流
    if (videoStream == -1) {
        printf("Didn't find a video stream.");
        return -1;
    }

    if (audioStream != -1) {
        qDebug()<<QString("音频 audiostream");
        initAudoCodec();
    }


    ///查找解码器
    pCodecCtx = pFormatCtx->streams[videoStream]->codec;
    pCodec = avcodec_find_decoder(pCodecCtx->codec_id);


    if (pCodec == NULL) {
        qDebug() <<"Codec not found.";
        return -1;
    }

    ///打开解码器
    if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0) {
        qDebug() <<"Could not open codec.";
        return -1;
    }

    pFrame = av_frame_alloc();
    pFrameRGB = av_frame_alloc();

    int dstW = pCodecCtx->width;
    int dstH = pCodecCtx->height;

    img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height,
            pCodecCtx->pix_fmt, dstW, dstH,
            AV_PIX_FMT_RGB32, SWS_BICUBIC, NULL, NULL, NULL);

    numBytes = avpicture_get_size(AV_PIX_FMT_RGB32, pCodecCtx->width,pCodecCtx->height);

    out_buffer = (uint8_t *) av_malloc(numBytes * sizeof(uint8_t));
    avpicture_fill((AVPicture *) pFrameRGB, out_buffer, AV_PIX_FMT_RGB32,
            pCodecCtx->width, pCodecCtx->height);

    int y_size = pCodecCtx->width * pCodecCtx->height;

    packet = (AVPacket *) malloc(sizeof(AVPacket)); //分配一个packet
    av_new_packet(packet, y_size); //分配packet的数据

    av_dump_format(pFormatCtx, 0, file_path, 0); //输出视频信息

    int index = 0;
     int out_buffer_size;
    while (1)
    {
        if (av_read_frame(pFormatCtx, packet) < 0)
        {
            break; //这里认为视频读取完了
        }

        if (packet->stream_index == videoStream) {
            int ret, got_picture;
            ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture,packet);
            if (ret < 0) {
                qDebug() << "decode video error.";
                return -1;
            }
            if (got_picture) {
                 sws_scale(img_convert_ctx,
                      (uint8_t const * const *) pFrame->data,
                      pFrame->linesize, 0, pCodecCtx->height, pFrameRGB->data,
                      pFrameRGB->linesize);
                  emit singalVideoData(pFrameRGB, pCodecCtx->width,pCodecCtx->height);

                  if (pFrame->pkt_dts != AV_NOPTS_VALUE) {
                      videoTimeStamp = pFrame->pkt_dts;
                  } else if (pFrame->pts != AV_NOPTS_VALUE) {
                      videoTimeStamp = pFrame->pts;
                  } else {
                      videoTimeStamp = 0;
                  }
                  videoTimeStamp =  (int)((videoTimeStamp * av_q2d(pFormatCtx->streams[videoStream]->time_base)) * 1000);

            }

        } else if (packet->stream_index == audioStream) {
            int got_frame = 0, ret;
            ret = avcodec_decode_audio4(aCodecCtx, aAvFrame, &got_frame, packet);
            if (ret < 0){
                qDebug() << "decode audio error.";
                return -1;
            }
            if (got_frame > 0){
                swr_convert(
                        aAudioCovertCtx,
                        &a_out_buffer,
                        MAX_AUDIO_FRAME_SIZE * 2,
                        (const uint8_t **) aAvFrame->data,
                         aAvFrame->nb_samples);
                out_buffer_size = av_samples_get_buffer_size(NULL, out_channer_nb, aAvFrame->nb_samples,
                                                                 AV_SAMPLE_FMT_S16, 1);

                sleepTime = (aCodecCtx->sample_rate*16*2/8)/out_buffer_size;
                audioPts = packet->pts;
                if(audioOutput->bytesFree() < out_buffer_size) {
                    av_usleep(sleepTime * 1000);
                    audioDevice->write((const char*)a_out_buffer, out_buffer_size);
                } else {
                    audioDevice->write((const char*)a_out_buffer, out_buffer_size);
                }

                if (aAvFrame->pkt_dts != AV_NOPTS_VALUE) {
                    audioTimeStamp = aAvFrame->pkt_dts;
                } else if (aAvFrame->pts != AV_NOPTS_VALUE) {
                    audioTimeStamp = aAvFrame->pts;
                } else {
                    audioTimeStamp = 0;
                }
                audioTimeStamp = (int)((audioTimeStamp * av_q2d(pFormatCtx->streams[audioStream]->time_base)) * 1000);

            }

        }
        av_free_packet(packet);
    }

    return 0;
}


void avcodecNetAVthread::initAudoCodec()
{
    aCodecCtx = pFormatCtx->streams[audioStream]->codec;
    if (!aCodecCtx)
    {
        qDebug()<<QString("音频 CodecCtx失败");
        return;
    }
    AVCodec *aCodec = avcodec_find_decoder(aCodecCtx->codec_id);
    if (!aCodec)
    {
        qDebug()<<QString("音频 Codec失败");
        return;
    }

    if (avcodec_open2(aCodecCtx,aCodec, NULL) < 0){
        qDebug()<<QString("avcodec_open error (Audio)");
        return;
    }
    a_out_buffer = (uint8_t *) malloc(2 * MAX_AUDIO_FRAME_SIZE);
    aAudioCovertCtx = swr_alloc();
    av_opt_set_int(aAudioCovertCtx, "in_channel_layout",  aCodecCtx->channel_layout, 0);
    av_opt_set_int(aAudioCovertCtx, "out_channel_layout", aCodecCtx->channel_layout,  0);
    av_opt_set_int(aAudioCovertCtx, "in_sample_rate",     aCodecCtx->sample_rate, 0);
    av_opt_set_int(aAudioCovertCtx, "out_sample_rate",    aCodecCtx->sample_rate, 0);
    av_opt_set_sample_fmt(aAudioCovertCtx, "in_sample_fmt",  aCodecCtx->sample_fmt, 0);
    av_opt_set_sample_fmt(aAudioCovertCtx, "out_sample_fmt", AV_SAMPLE_FMT_S16,  0);
    swr_init(aAudioCovertCtx);
    out_channer_nb = av_get_channel_layout_nb_channels(AV_CH_LAYOUT_STEREO);
    aAvFrame = av_frame_alloc();
    initAudioConfig(aCodecCtx);
    qDebug()<<QString("Audio init success!!");
}

void avcodecNetAVthread::initAudioConfig(AVCodecContext *audioCodecCtx)
{
    qDebug()<< "init AudioConfig";
    audioFormat.setSampleRate(audioCodecCtx->sample_rate);
    audioFormat.setChannelCount(audioCodecCtx->channels);
    audioFormat.setSampleSize(8 * av_get_bytes_per_sample(AV_SAMPLE_FMT_S16));
    audioFormat.setSampleType(QAudioFormat::SignedInt);
    audioFormat.setCodec("audio/pcm");
    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice()); //选择默认输出设备
    if (!info.isFormatSupported(audioFormat))
    {
        qDebug()<<"输出设备不支持该格式，不能播放音频";
        return;
    }
    audioOutput = new QAudioOutput(info,audioFormat);
    audioDevice = audioOutput->start();
}

int avcodecNetAVthread::closeAvdecodec()
{
    av_free(out_buffer);
    av_free(a_out_buffer);
    av_free(pFrameRGB);
    av_free(pFrame);
    av_free(aAvFrame);
    av_free(pCodec);
    avcodec_close(pCodecCtx);
    avcodec_close(aCodecCtx);
    avformat_close_input(&pFormatCtx);
}

