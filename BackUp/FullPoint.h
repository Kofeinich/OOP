#ifndef BACKUP_FULLPOINT_H
#define BACKUP_FULLPOINT_H
#include "RestorePoint.h"

class FullPoint : public RestorePoint{


public:
    FullPoint(Storage& storage, long long curTime) : RestorePoint(storage, curTime) {}
    std::vector<File*> getFiles()override {
        return *storage.getFiles();
    }
private:
};
#endif //BACKUP_FULLPOINT_H
