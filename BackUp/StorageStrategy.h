#ifndef BACKUP_STORAGESTRATEGY_H
#define BACKUP_STORAGESTRATEGY_H

#include <vector>
#include "File.h"

class Storage{
public:
    virtual std::vector<File*>* getFiles() = 0;
    virtual void setFiles(std::vector<File*>* files) = 0;
};

class SeparatedStorage : public Storage{
public:
    SeparatedStorage(){}
    std::vector<File*>* getFiles() override{
        return files;
    }
    void setFiles(std::vector<File*>* files) override{
        this->files = files;
    };

private:
    std::vector<File*>* files;
};

class ArchiveStorage : public Storage{
public:
    ArchiveStorage()=default;
    std::vector<File*>* getFiles() override{
        return archive.getFiles();
    }
    void setFiles(std::vector<File*>* files) override{
        this->archive.setFiles(files);
    };
private:
    class Archive{
    public:
        std::vector<File*>* getFiles(){
            return files;
        }
        void setFiles(std::vector<File*>* files){
            this->files = files;
        };

    private:
        std::vector<File*>* files;
    };
    Archive archive;
};
#endif //BACKUP_STORAGESTRATEGY_H
