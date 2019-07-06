#ifndef FILEEXCEPTION_H
#define FILEEXCEPTION_H

#include <string>

class FileException {
private:
    std::string exception;

public:
    FileException(const std::string &);

    std::string getException() const;
};

#endif // FILEEXCEPTION_H
