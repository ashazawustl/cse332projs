#ifndef SIMPLEFILESYSTEM_H
#define SIMPLEFILESYSTEM_H
#include <map>
#include <set>
#include "AbstractFile.h"
#include "AbstractFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

class SimpleFileSystem : public AbstractFileSystem
{
    map<string, AbstractFile*> files;
    set<AbstractFile*> opened_files;

public:
    virtual int addFile(string file_name, AbstractFile * file);
//  virtual int createFile(string file_name);
    virtual int deleteFile(string file_name);
    virtual AbstractFile * openFile(string file_name);
    virtual int closeFile(AbstractFile * file);

    virtual ~SimpleFileSystem();


    virtual set<string> getFileNames();
};

enum
{
    invalid_file_ptr = 5,
    invalid_file_extension = 6,
};
#endif //SIMPLEFILESYSTEM_H