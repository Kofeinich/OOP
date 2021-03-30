#ifndef BACKUP_BACKUP_H
#define BACKUP_BACKUP_H
#include <iostream>
#include "File.h"
#include "RestorePoint.h"
#include "FullPoint.h"
#include "IncPoint.h"

class BackUp {
public:
    BackUp() {
    }

    void addFile(File* newFile){
        backUpData.emplace_back(newFile);
    }

    std::vector <File*>* getFiles(){
        return &backUpData;
    }

    std::vector <RestorePoint*>& getPoints(){
        return backUpPoints;
    }
    void addPoint(RestorePoint* restorePoint){
        backUpPoints.push_back(restorePoint);
    }

    void setTime(long long time){
        currentTime = time;
    }

    long long getTime(){
        return currentTime;
    }

    void show(){
        int inter = 1;
        for (auto i : backUpPoints){
            std::cout << "Point = " << inter <<" "<<"Time Creation is = "<< i->getCreationTime() << std::endl;
            std::vector <File*> curVector = i->getFiles();
            for(auto  j : curVector){
                std::cout << j->getFileName() <<" "<<j->getFileSize() << std::endl;
            }
            std::cout << std::endl;
            inter++;
        }
    }

private:
    std::vector <File*> backUpData;
    long long currentTime;
    std::vector <RestorePoint*> backUpPoints;
};

#endif //BACKUP_BACKUP_H
