#ifndef AVCODECLOCALVIDEOTHREAD_H
#define AVCODECLOCALVIDEOTHREAD_H

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

class AVCodecLocalVideoThread : public QObject
{
    Q_OBJECT
public:
    explicit AVCodecLocalVideoThread(QObject *parent = nullptr);
    int64_t videoTimeStamp = 0;
    unsigned int sleepTime = 0;
    void setFilePath(char *path);

private:

    bool play = true;
    void goplay(bool play);
    char *file_path = "";
    int fileTimes = 0;
    int videoStream, i, numBytes;
    int ret, got_picture;
    //视频流相关
    AVFormatContext *pFormatCtx;
    AVCodecContext *pCodecCtx;
    AVCodec *pCodec;
    AVFrame *pFrame, *pFrameRGB;
    AVPacket *packet;
    uint8_t *out_buffer;
    SwsContext *img_convert_ctx;


signals:
    void singalVideoData(AVFrame *pFrameRGB, int width, int height, int percent);

public slots:
    int initAvdecodec();
    int closeAvdecodec();

};

#endif // AVCODECLOCALVIDEOTHREAD_H
