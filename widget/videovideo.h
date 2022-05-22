#ifndef VIDEOVIDEO_H
#define VIDEOVIDEO_H

#include <QWidget>
#include <QObject>
#include <QEvent>
#include <QMouseEvent>
#include <QOpenGLWidget>

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

class VideoVideo : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit VideoVideo(QWidget *parent = nullptr);
    ~VideoVideo();
    QPainter *painter = nullptr;
    void paintEvent(QPaintEvent *event);//窗口的重新绘制
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
    void updateImageData(AVFrame *rgbData, int width, int height, int percent);
    void release();

private:

    double h_percent = 0.95f;
    double w_percent = 0.8f;
    double start_percent = 0.1f;
    double x_current = 0;
    double x_current2 = 0;

    AVFrame *rgbData = nullptr;
    bool showProgressBar = false;
    int currentPercent = 0;
    int mWidth = 400;
    int mHeight = 300;
    void paintProgressBar(QPainter *painter);//绘制进度条
    void paintCloseBar(QPainter *painter);
    void paintMoveBar(QPainter *painter);

signals:
    void closeSignal();

};

#endif // VIDEOVIDEO_H
