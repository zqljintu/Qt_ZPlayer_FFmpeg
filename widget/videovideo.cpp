#include "videovideo.h"
#include <QDebug>
#include <QPainter>
#include <QtDebug>

VideoVideo::VideoVideo(QWidget *parent)
  : QOpenGLWidget(parent)
{
    installEventFilter(this);
    painter = new QPainter();
    QSurfaceFormat surfaceFormat;
    surfaceFormat.setSamples(4);//多重采样
    setFormat(surfaceFormat);
    update();
}

void VideoVideo::paintEvent(QPaintEvent *event)
{
    painter->begin(this);
    if (this->rgbData) {
        QImage img((uchar*)this->rgbData->data[0], this->mWidth, this->mHeight, QImage::Format_RGB32);
        painter->drawImage(QRect(0, 0, this->width(), this->height()), img);//绘制FFMpeg解码后的视频
    } else {
        painter->fillRect(this->rect(),Qt::black);
    }
    if (this->showProgressBar) {
        paintProgressBar(painter);
    }

    painter->end();

}

void VideoVideo::paintProgressBar(QPainter *painter)
{
    x_current = this->width() * w_percent * currentPercent / 100;
    x_current2 = this->width() * start_percent + x_current;
    QColor baseColor(0,20,20);
    QColor inColor(255,0,0);
    QColor outColor(255,255,255);
    painter->setRenderHint(QPainter::SmoothPixmapTransform);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::transparent);
    painter->setBrush(baseColor);
    QRectF rect = QRectF(this->width() * start_percent, this->height() * h_percent, this->width() * w_percent, 8);
    painter->drawRoundedRect(rect, 4, 4);


    painter->setBrush(inColor);
    QRectF rect1 = QRectF(this->width() * start_percent, this->height() * h_percent, x_current, 8);
    painter->drawRoundedRect(rect1, 4, 4);
    painter->setBrush(outColor);
    painter->drawEllipse(x_current2 - 6, this->height() * h_percent - 6 , 20, 20);
    painter->setBrush(inColor);
    painter->drawEllipse(x_current2, this->height() * h_percent, 8, 8);
}

void VideoVideo::mousePressEvent(QMouseEvent *event)
{
     if ((event->pos().x() > start_percent * this->width()) && (event->pos().x() < (1-start_percent) * this->width())
             && (event->pos().y() > h_percent * this->height()) && (event->pos().y() < h_percent * this->height() + 8))
     {
         int pressX = event->pos().x();
         this->currentPercent = (pressX - this->width() * start_percent) * 100 / (this->width() * w_percent);
         update();
     }
}

void VideoVideo::mouseMoveEvent(QMouseEvent *event)
{
    if(event->type() == QEvent::MouseMove){
        if ((event->pos().x() > start_percent * this->width()) && (event->pos().x() < (1-start_percent) * this->width())
                && (event->pos().y() > h_percent * this->height()) && (event->pos().y() < h_percent * this->height() + 8))
        {
            int pressX = event->pos().x();
            this->currentPercent = (pressX - this->width() * start_percent) * 100 / (this->width() * w_percent);
            update();
        }
    }

}

void VideoVideo::mouseReleaseEvent(QMouseEvent *event)
{
    if ((event->pos().x() > start_percent * this->width()) && (event->pos().x() < (1-start_percent) * this->width())
            && (event->pos().y() > h_percent * this->height()) && (event->pos().y() < h_percent * this->height() + 8))
    {

    }
}

bool VideoVideo::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::Enter) {
        this->showProgressBar = true;
        setCursor(Qt::PointingHandCursor);
        update();
    } else if (event->type() == QEvent::Leave) {
        this->showProgressBar = false;
        setCursor(Qt::CustomCursor);
        update();
    }
    return false;
}

void VideoVideo::updateImageData(AVFrame *rgbData, int width, int height, int percent)
{
    this->rgbData = rgbData;
    this->mWidth = width;
    this->mHeight = height;
    this->currentPercent = percent;
    update();
}

VideoVideo:: ~VideoVideo()
{

}
