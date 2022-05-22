QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    avcodeclocalaudiothread.cpp \
    avcodeclocalvideothread.cpp \
    avcodecnetavthread.cpp \
    main.cpp \
    mainwindow.cpp \
    widget/videovideo.cpp

HEADERS += \
    avcodeclocalaudiothread.h \
    avcodeclocalvideothread.h \
    avcodecnetavthread.h \
    ffmpeg/include/libavcodec/avcodec.h \
    ffmpeg/include/libavcodec/avdct.h \
    ffmpeg/include/libavcodec/avfft.h \
    ffmpeg/include/libavcodec/d3d11va.h \
    ffmpeg/include/libavcodec/dirac.h \
    ffmpeg/include/libavcodec/dv_profile.h \
    ffmpeg/include/libavcodec/dxva2.h \
    ffmpeg/include/libavcodec/jni.h \
    ffmpeg/include/libavcodec/mediacodec.h \
    ffmpeg/include/libavcodec/qsv.h \
    ffmpeg/include/libavcodec/vaapi.h \
    ffmpeg/include/libavcodec/vda.h \
    ffmpeg/include/libavcodec/vdpau.h \
    ffmpeg/include/libavcodec/version.h \
    ffmpeg/include/libavcodec/videotoolbox.h \
    ffmpeg/include/libavcodec/vorbis_parser.h \
    ffmpeg/include/libavcodec/xvmc.h \
    ffmpeg/include/libavdevice/avdevice.h \
    ffmpeg/include/libavdevice/version.h \
    ffmpeg/include/libavfilter/avfilter.h \
    ffmpeg/include/libavfilter/avfiltergraph.h \
    ffmpeg/include/libavfilter/buffersink.h \
    ffmpeg/include/libavfilter/buffersrc.h \
    ffmpeg/include/libavfilter/version.h \
    ffmpeg/include/libavformat/avformat.h \
    ffmpeg/include/libavformat/avio.h \
    ffmpeg/include/libavformat/version.h \
    ffmpeg/include/libavutil/adler32.h \
    ffmpeg/include/libavutil/aes.h \
    ffmpeg/include/libavutil/aes_ctr.h \
    ffmpeg/include/libavutil/attributes.h \
    ffmpeg/include/libavutil/audio_fifo.h \
    ffmpeg/include/libavutil/avassert.h \
    ffmpeg/include/libavutil/avconfig.h \
    ffmpeg/include/libavutil/avstring.h \
    ffmpeg/include/libavutil/avutil.h \
    ffmpeg/include/libavutil/base64.h \
    ffmpeg/include/libavutil/blowfish.h \
    ffmpeg/include/libavutil/bprint.h \
    ffmpeg/include/libavutil/bswap.h \
    ffmpeg/include/libavutil/buffer.h \
    ffmpeg/include/libavutil/camellia.h \
    ffmpeg/include/libavutil/cast5.h \
    ffmpeg/include/libavutil/channel_layout.h \
    ffmpeg/include/libavutil/common.h \
    ffmpeg/include/libavutil/cpu.h \
    ffmpeg/include/libavutil/crc.h \
    ffmpeg/include/libavutil/des.h \
    ffmpeg/include/libavutil/dict.h \
    ffmpeg/include/libavutil/display.h \
    ffmpeg/include/libavutil/downmix_info.h \
    ffmpeg/include/libavutil/error.h \
    ffmpeg/include/libavutil/eval.h \
    ffmpeg/include/libavutil/ffversion.h \
    ffmpeg/include/libavutil/fifo.h \
    ffmpeg/include/libavutil/file.h \
    ffmpeg/include/libavutil/frame.h \
    ffmpeg/include/libavutil/hash.h \
    ffmpeg/include/libavutil/hmac.h \
    ffmpeg/include/libavutil/hwcontext.h \
    ffmpeg/include/libavutil/hwcontext_cuda.h \
    ffmpeg/include/libavutil/hwcontext_d3d11va.h \
    ffmpeg/include/libavutil/hwcontext_drm.h \
    ffmpeg/include/libavutil/hwcontext_dxva2.h \
    ffmpeg/include/libavutil/hwcontext_qsv.h \
    ffmpeg/include/libavutil/hwcontext_vaapi.h \
    ffmpeg/include/libavutil/hwcontext_vdpau.h \
    ffmpeg/include/libavutil/hwcontext_videotoolbox.h \
    ffmpeg/include/libavutil/imgutils.h \
    ffmpeg/include/libavutil/intfloat.h \
    ffmpeg/include/libavutil/intreadwrite.h \
    ffmpeg/include/libavutil/lfg.h \
    ffmpeg/include/libavutil/log.h \
    ffmpeg/include/libavutil/lzo.h \
    ffmpeg/include/libavutil/macros.h \
    ffmpeg/include/libavutil/mastering_display_metadata.h \
    ffmpeg/include/libavutil/mathematics.h \
    ffmpeg/include/libavutil/md5.h \
    ffmpeg/include/libavutil/mem.h \
    ffmpeg/include/libavutil/motion_vector.h \
    ffmpeg/include/libavutil/murmur3.h \
    ffmpeg/include/libavutil/opt.h \
    ffmpeg/include/libavutil/parseutils.h \
    ffmpeg/include/libavutil/pixdesc.h \
    ffmpeg/include/libavutil/pixelutils.h \
    ffmpeg/include/libavutil/pixfmt.h \
    ffmpeg/include/libavutil/random_seed.h \
    ffmpeg/include/libavutil/rational.h \
    ffmpeg/include/libavutil/rc4.h \
    ffmpeg/include/libavutil/replaygain.h \
    ffmpeg/include/libavutil/ripemd.h \
    ffmpeg/include/libavutil/samplefmt.h \
    ffmpeg/include/libavutil/sha.h \
    ffmpeg/include/libavutil/sha512.h \
    ffmpeg/include/libavutil/spherical.h \
    ffmpeg/include/libavutil/stereo3d.h \
    ffmpeg/include/libavutil/tea.h \
    ffmpeg/include/libavutil/threadmessage.h \
    ffmpeg/include/libavutil/time.h \
    ffmpeg/include/libavutil/timecode.h \
    ffmpeg/include/libavutil/timestamp.h \
    ffmpeg/include/libavutil/tree.h \
    ffmpeg/include/libavutil/twofish.h \
    ffmpeg/include/libavutil/version.h \
    ffmpeg/include/libavutil/xtea.h \
    ffmpeg/include/libpostproc/postprocess.h \
    ffmpeg/include/libpostproc/version.h \
    ffmpeg/include/libswresample/swresample.h \
    ffmpeg/include/libswresample/version.h \
    ffmpeg/include/libswscale/swscale.h \
    ffmpeg/include/libswscale/version.h \
    mainwindow.h \
    widget/videovideo.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/ffmpeg/include

LIBS += $$PWD/ffmpeg/lib/avcodec.lib\
        $$PWD/ffmpeg/lib/avdevice.lib\
        $$PWD/ffmpeg/lib/avfilter.lib\
        $$PWD/ffmpeg/lib/avformat.lib\
        $$PWD/ffmpeg/lib/avutil.lib\
        $$PWD/ffmpeg/lib/postproc.lib\
        $$PWD/ffmpeg/lib/swresample.lib\
        $$PWD/ffmpeg/lib/swscale.lib
LIBS += -lDbgHelp

DISTFILES += \
    ffmpeg/lib/avcodec-57.def \
    ffmpeg/lib/avcodec.lib \
    ffmpeg/lib/avdevice-57.def \
    ffmpeg/lib/avdevice.lib \
    ffmpeg/lib/avfilter-6.def \
    ffmpeg/lib/avfilter.lib \
    ffmpeg/lib/avformat-57.def \
    ffmpeg/lib/avformat.lib \
    ffmpeg/lib/avutil-55.def \
    ffmpeg/lib/avutil.lib \
    ffmpeg/lib/libavcodec.dll.a \
    ffmpeg/lib/libavdevice.dll.a \
    ffmpeg/lib/libavfilter.dll.a \
    ffmpeg/lib/libavformat.dll.a \
    ffmpeg/lib/libavutil.dll.a \
    ffmpeg/lib/libpostproc.dll.a \
    ffmpeg/lib/libswresample.dll.a \
    ffmpeg/lib/libswscale.dll.a \
    ffmpeg/lib/postproc-54.def \
    ffmpeg/lib/postproc.lib \
    ffmpeg/lib/swresample-2.def \
    ffmpeg/lib/swresample.lib \
    ffmpeg/lib/swscale-4.def \
    ffmpeg/lib/swscale.lib

RESOURCES += \
    src.qrc

#release版本可调试
QMAKE_CXXFLAGS_RELEASE += $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
#release版也将生成“.pdb”后缀的调试信息文件
QMAKE_LFLAGS_RELEASE = /INCREMENTAL:NO /DEBUG
#调用库


