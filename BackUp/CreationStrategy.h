#ifndef BACKUP_CREATIONSTRATEGY_H
#define BACKUP_CREATIONSTRATEGY_H
#include "File.h"
#include "IncPoint.h"
#include "FullPoint.h"
#include "BackUp.h"

class CreationStrategy{
public:

    virtual void create(BackUp* back, Storage& storage) = 0;

};

class FullCreation : public CreationStrategy{
public:
    void create(BackUp* back, Storage& storage) override{
        std::vector <File*>* curData;
        curData = back->getFiles();

        auto files = new std::vector<File*>;
        for(auto file : *curData){
            auto f =new File(file->getFileName(), file->getFileSize());
            files->push_back(f);
        }
        storage.setFiles(files);
        auto Point = new FullPoint(storage, back->getTime());
        back->addPoint(Point);
    }
};

class IncCreation : public CreationStrategy{
public:
    void create(BackUp* back, Storage& storage) override{
        std::vector <File*>* curData;
        RestorePoint* restorePoint = back->getPoints().back();
        curData = back->getFiles();
        std::vector <File*> beforeData = restorePoint->getFiles();

        auto files = new std::vector<File*>;
        for (auto * file : *curData) {
            File* result;
            for (auto * search : beforeData) {
                if (search->getFileName() == file->getFileName()){
                    result = search;
                    break;
                }
            }
            File* diff;
            if (result != nullptr) {
                auto d =new File(result->getFileName(), file->getFileSize() - result->getFileSize());
                diff = d;
            }else{
                auto f =new File(file->getFileName(), file->getFileSize());
                diff = f;
            }
            files->push_back(diff);
        }
        storage.setFiles(files);
        auto point = new IncPoint(storage, back->getTime(), restorePoint);
        back->addPoint(point);
    }
};

#endif //BACKUP_CREATIONSTRATEGY_H
