#ifndef BACKUP_RESTOREPOINT_H
#define BACKUP_RESTOREPOINT_H
#include "File.h"
#include "StorageStrategy.h"

class RestorePoint{
public:
    RestorePoint(Storage& storage, long long curTime): storage(storage), creationTime(curTime) {}
    virtual std::vector<File*> getFiles() = 0;
    long long getCreationTime(){
        return creationTime;
    }
protected:
    long long creationTime = 0;
    Storage& storage;
};
#endif //BACKUP_RESTOREPOINT_H
