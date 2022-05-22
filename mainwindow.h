#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QAudioFormat>
#include <QAudioOutput>
#include "avcodeclocalvideothread.h"
#include "avcodeclocalaudiothread.h"
#include "avcodecnetavthread.h"
extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    bool canResize = false;
    AVCodecLocalVideoThread *pAVCodecLocalVideThread = nullptr;
    avcodeclocalaudiothread *aAvCodecLocalAudioThread = nullptr;
    avcodecNetAVthread *mavCodecNetThread = nullptr;
    QThread *pLocalThread, *aLocalThread;
    QAudioFormat audioFormat;
    QAudioOutput *audioOutput;
    QIODevice *audioDevice;
    QByteArray audioByteBuf;//音频缓冲
    int befortAudioSize = 0;
    void initLocalAVCodec();
    void initNetAVCodec();
    void initVideoWidget();
    void release();
    int ScaleImg(AVFrame *src_picture, int nSrcH, int nSrcW, AVFrame *dst_picture,int nDstH ,int nDstW);

    bool m_pressed;
    QPoint m_point;//可移动的点
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);//设置窗体可移动

private:
    Ui::MainWindow *ui;
signals:
    void startAcodecLocalVideo();

private slots:
    void onReieveVideoData(AVFrame *pFrameRGB, int width, int height, int percent);
    void onReieveNetVideoData(AVFrame *pFrameRGB, int width, int height);
    void onReieveAudioData(uint8_t *aAuifoDataS16, int length);
    void initAudioFormat(AVCodecContext *mAudioCodecCtx);
};
#endif // MAINWINDOW_H
