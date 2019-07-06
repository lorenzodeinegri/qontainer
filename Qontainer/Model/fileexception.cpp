#include "fileexception.h"

FileException::FileException(const std::string & exception) : exception(exception) {}

std::string FileException::getException() const {
    return exception;
}
