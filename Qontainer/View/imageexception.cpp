#include "imageexception.h"

ImageException::ImageException(const QString & exception) : exception(exception) {}

QString ImageException::getException() const {
    return exception;
}
