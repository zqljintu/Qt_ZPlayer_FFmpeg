#ifndef VIDEODECODE_H
#define VIDEODECODE_H

#include <QObject>

class videoDecode : public QObject
{
    Q_OBJECT
public:
    explicit videoDecode(QObject *parent = nullptr);

signals:

};

#endif // VIDEODECODE_H
