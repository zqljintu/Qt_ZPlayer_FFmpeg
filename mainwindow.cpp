#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget/videovideo.h"
#include <QtDebug>
#include <iostream>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::FramelessWindowHint|windowFlags());//实现无边框
    setAttribute(Qt::WA_TranslucentBackground);//设置背景透明
    ui->setupUi(this);
    initLocalAVCodec();
    //initNetAVCodec();
}


void MainWindow::initLocalAVCodec()
{
    this->canResize = true;
    pAVCodecLocalVideThread = new AVCodecLocalVideoThread();
    aAvCodecLocalAudioThread = new avcodeclocalaudiothread();
    pLocalThread = new QThread();
    aLocalThread = new QThread();
    //设置文件路径
    pAVCodecLocalVideThread->setFilePath("E:/in2.mp4");
    aAvCodecLocalAudioThread->setFilePath("E:/in2.mp4");
    aAvCodecLocalAudioThread->moveToThread(aLocalThread);
    pAVCodecLocalVideThread->moveToThread(pLocalThread);
    connect(pAVCodecLocalVideThread,&AVCodecLocalVideoThread::singalVideoData,this,&MainWindow::onReieveVideoData);
    connect(aAvCodecLocalAudioThread,&avcodeclocalaudiothread::initAudioFinish,pAVCodecLocalVideThread,&AVCodecLocalVideoThread::initAvdecodec);
    connect(this, &MainWindow::startAcodecLocalVideo, aAvCodecLocalAudioThread, &avcodeclocalaudiothread::initAvdecodec);
    aLocalThread->start();
    pLocalThread->start();
    emit startAcodecLocalVideo();
}

void MainWindow::initNetAVCodec()
{
    this->canResize = true;
    mavCodecNetThread = new avcodecNetAVthread();
    pLocalThread = new QThread();
    //设置文件路径
    mavCodecNetThread->setFilePath("rtmp://mobliestream.c3tv.com:554/live/goodtv.sdp");
    mavCodecNetThread->moveToThread(pLocalThread);
    connect(mavCodecNetThread,&avcodecNetAVthread::singalVideoData,this,&MainWindow::onReieveNetVideoData);
    connect(this,&MainWindow::startAcodecLocalVideo,mavCodecNetThread,&avcodecNetAVthread::initAvdecodec);
    pLocalThread->start();
    emit startAcodecLocalVideo();
}

void MainWindow::initVideoWidget()
{

}



//接收转码过来的数据并转化成Qt能渲染的格式
void MainWindow::onReieveVideoData(AVFrame *pFrameRGB, int width, int height, int percent)
{
//      QImage img((uchar*)pFrameRGB->data[0], width, height,QImage::Format_RGB32);
//      //2 将Qimage格式的图片转成Qpixmap格式
//      QPixmap pix = QPixmap::fromImage(img);
//      //3 设置pixmap缩放的尺寸
//      pix.scaled(ui->label->size(), Qt::KeepAspectRatio);
//      /*4  它的作用是设置label的属性scaledContents，
//      这个属性的作用是允许（禁止）label缩放它的内容充满整个可用的空间。
//      特别说明的一点是当使能该属性并且label显示pixmap时，它能够缩放pixmap充满整个可用的空间。*/
//      ui->label->setScaledContents(true);
//      //5 用label显示一张图片
//      ui->label->setPixmap(pix);
    if (this->canResize) {
        if (width != 0){
            if (width > height) {
                int w_width = this->width();
                int w_heigth = w_width * height / width;
                this->resize(w_width, w_heigth);
            } else {
                int w_height = this->height();
                int w_width = w_height * width / height;
                this->resize(w_width, w_height);
            }
        }
        this->canResize = false;
    }

    ui->openGLWidget->updateImageData(pFrameRGB, width, height, percent);

    if(pAVCodecLocalVideThread->videoTimeStamp > aAvCodecLocalAudioThread->audioTimeStamp){
        pAVCodecLocalVideThread->sleepTime =  static_cast<unsigned int>( pAVCodecLocalVideThread->videoTimeStamp - aAvCodecLocalAudioThread->audioTimeStamp);
    } else {
        pAVCodecLocalVideThread->sleepTime = 0;
    }
}

void MainWindow::onReieveNetVideoData(AVFrame *pFrameRGB, int width, int height)
{
    ui->openGLWidget->updateImageData(pFrameRGB, width, height, 0);
}

void MainWindow::initAudioFormat(AVCodecContext *audioCodecCtx)
{

}

void MainWindow::onReieveAudioData(uint8_t *aAuifoDataS16, int length)
{

}

void MainWindow::close(){
    pLocalThread->deleteLater();
    av_free(tempFrame);
    av_free(out_buffer);
}

MainWindow::~MainWindow()
{
    delete ui;
}



int MainWindow::ScaleImg(AVFrame *src_picture, int nSrcH, int nSrcW, AVFrame *dst_picture,int nDstH ,int nDstW)
{
    return 1;
}

