#ifndef ABSTRACTFILESYSTEM_H
#define ABSTRACTFILESYSTEM_H
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"


using namespace std;

class AbstractFileSystem
{
 public:

//these functions deal with the basic handling of the files in the file system by deriving from AbstractFile
 virtual ~AbstractFileSystem() = 0;
 virtual int addFile(string file_name, AbstractFile * file) = 0;
//maintaining this line as commented due to its former use in a previous studio before the implementation of the AbstractFileFactory
// virtual int createFile(string file_name) = 0;
 virtual int deleteFile(string file_name) = 0;
 virtual AbstractFile * openFile(string file_name) = 0;
 virtual int closeFile(AbstractFile * file) = 0;

 virtual set<string> getFileNames() = 0;
};

inline AbstractFileSystem::~AbstractFileSystem() {}

enum
{
 open_file_failure = 1,
 open_file_success = 0,
 add_file_failure = 2,
 add_file_success = 0,
 file_already_open = 3,
 close_file_success = 0,
 delete_file_success = 0,
 file_exists = 3,
 file_does_not_exist = 4
};

#endif //ABSTRACTFILESYSTEM_H