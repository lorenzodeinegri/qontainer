#ifndef IMAGEEXCEPTION_H
#define IMAGEEXCEPTION_H

#include <QString>

class ImageException {
private:
    QString exception;

public:
    ImageException(const QString &);

    QString getException() const;
};

#endif // IMAGEEXCEPTION_H
