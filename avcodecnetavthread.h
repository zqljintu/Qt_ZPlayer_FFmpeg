#ifndef AVCODECNETAVTHREAD_H
#define AVCODECNETAVTHREAD_H

#include <QObject>
#include <QThread>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QIODevice>
#include <iostream>

extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libswresample/swresample.h>>
    #include <libavdevice/avdevice.h>
    #include <libavformat/version.h>
    #include <libavutil/time.h>
    #include <libavutil/mathematics.h>
}

extern "C"
{
    #ifdef __cplusplus
    #define __STDC_CONSTANT_MACROS
    #ifdef _STDINT_H
    #undef _STDINT_H
    #endif
    #include<stdint.h>
    #endif
}
#define MAX_AUDIO_FRAME_SIZE 44100

class avcodecNetAVthread : public QObject
{
    Q_OBJECT
public:
    explicit avcodecNetAVthread(QObject *parent = nullptr);
    int64_t videoTimeStamp = 0;
    unsigned int sleepTime = 0;
    void setFilePath(char *path);
    char *file_path = "";

    int audioPts = 0;
    int64_t audioTimeStamp = 0;
    int cutAudio = 0;

private:

    int videoStream, i, numBytes;
    //视频流相关
    AVFormatContext *pFormatCtx;
    AVCodecContext *pCodecCtx;
    AVCodec *pCodec;
    AVFrame *pFrame, *pFrameRGB;
    AVPacket *packet;
    uint8_t *out_buffer;
    SwsContext *img_convert_ctx;

    //音频流相关
    int audioStream;
    AVFrame *aAvFrame;
    AVCodecContext *aCodecCtx;
    SwrContext *aAudioCovertCtx;
    uint8_t *a_out_buffer;
    int out_channer_nb;
    void initAudoCodec();

    //音频播放
    QAudioFormat audioFormat;
    QAudioOutput *audioOutput;
    QIODevice *audioDevice;
    void initAudioConfig(AVCodecContext *audioCodecCtx);

signals:
    void singalVideoData(AVFrame *pFrameRGB, int width, int height);

public slots:
    int initAvdecodec();
    int closeAvdecodec();
};













#endif // AVCODECNETAVTHREAD_H
