# Qt_ZPlayer_FFmpeg
a player coded by Qt with FFmpeg

这是一个用Qt编写的播放器，使用了开源框架FFmpeg，FFmpeg用来解析音视频，OPenGL用来渲染画面，能够实现本地播放视频文件（.mp4）,支持网络流协议（rtmp、rtsp）。
    
    1、本地播放采用的是开启两个线程来解析视频和音频，在音视频同步方面是采用了视频向音频同步的策略，让视频追逐音频。
    2、网络流播放采用单独线程来同时解析视频和音频，在标准视频流下，音视频是完全同步的
    2022-05-12-16：00
   
    1、FFmpeg是一个功能强大的音视频处理工具库。 
    2、FFmpeg相关库可到官网下载。 
    3、Qt版本5.14.1 Qt Creater4.11.1。
    2022-05-22-12：00

界面无边框：
![](https://github.com/zqljintu/Qt_ZPlayer_FFmpeg/blob/master/sources/001.png)

![](https://github.com/zqljintu/Qt_ZPlayer_FFmpeg/blob/master/sources/002.png)
