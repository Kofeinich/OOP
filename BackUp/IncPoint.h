#ifndef BACKUP_INCPOINT_H
#define BACKUP_INCPOINT_H
#include "RestorePoint.h"
#include "cmath"

class IncPoint : public RestorePoint{

public:
    IncPoint(Storage& storage, long long curTime, RestorePoint* PrPoint) : RestorePoint(storage, curTime), PrevPoint(PrPoint) {}

    std::vector<File*> getFiles()override{
        std::vector<File*> files;
        for (auto * file : *storage.getFiles()) {
            File* result;
            for (auto * search : PrevPoint->getFiles()) {
                if (search->getFileName() == file->getFileName()){
                    result = search;
                    break;
                }
            }
            File* diff;
            if (result != nullptr) {
                File d(result->getFileName(), file->getFileSize() + result->getFileSize());
                diff = &d;
            }else{
                File d(file->getFileName(), file->getFileSize());
                diff = &d;
            }
            files.push_back(diff);
        }
        return files;
    }
private:
    RestorePoint* PrevPoint;
};

#endif //BACKUP_INCPOINT_H
