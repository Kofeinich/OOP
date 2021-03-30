#ifndef BACKUP_FILE_H
#define BACKUP_FILE_H
#include "string"
#include "vector"

class File{
public:
    File(std::string name, double size) : fileName(name),fileSize(size){}

    void setFileName(std::string newName){ fileName = newName;}

    void setFileSize(double newSize){ fileSize = newSize;}

    std::string getFileName(){ return fileName;}

    double  getFileSize(){ return fileSize;}

private:
    std::string fileName;
    double fileSize;
};
#endif //BACKUP_FILE_H
