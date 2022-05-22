#ifndef AVCODECLOCALAUDIOTHREAD_H
#define AVCODECLOCALAUDIOTHREAD_H

#include <QObject>
#include <QThread>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QIODevice>

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

class avcodeclocalaudiothread : public QObject
{
    Q_OBJECT
public:
    explicit avcodeclocalaudiothread(QObject *parent = nullptr);
    int audioPts = 0;
    int64_t audioTimeStamp = 0;
    int cutAudio = 0;
    void setFilePath(char *path);
private:
    bool play = true;
    void goplay(bool play);
    //音频流相关
    char *file_path = "";
    AVFrame *aAvFrame;
    AVPacket *packet;
    AVFormatContext *pFormatCtx;
    AVCodecContext *aCodecCtx;
    SwrContext *aAudioCovertCtx;
    uint8_t *a_out_buffer;
    int out_channer_nb;
    int audioStream;
    void initAudoCodec();
    //音频播放
    QAudioFormat audioFormat;
    QAudioOutput *audioOutput;
    QIODevice *audioDevice;

    void initAudioConfig(AVCodecContext *audioCodecCtx);

signals:
    void initAudioFinish();

public slots:
    int initAvdecodec();
    int closeAvdecodec();
};

#endif // AVCODECLOCALAUDIOTHREAD_H
