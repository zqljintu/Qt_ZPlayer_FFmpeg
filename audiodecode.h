#ifndef AUDIODECODE_H
#define AUDIODECODE_H

#include <QObject>

class audioDecode : public QObject
{
    Q_OBJECT
public:
    explicit audioDecode(QObject *parent = nullptr);

signals:

};

#endif // AUDIODECODE_H
