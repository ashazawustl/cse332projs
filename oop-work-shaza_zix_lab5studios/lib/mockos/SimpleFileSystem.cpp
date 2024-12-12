#include "mockos/SimpleFileSystem.h"

using namespace std;

int SimpleFileSystem::addFile(string file_name, AbstractFile * file)
{
 if (this->files.count(file_name))
 {
  return file_exists;
 }
 if (file == nullptr)
 {
  return invalid_file_ptr;
 }
 files.insert(make_pair(file_name, file));
 return add_file_success;
}
/*
Previous studio implementation prior to the use of file factory for file creation, needs to be commented and present to demonstrate process
 */
//int SimpleFileSystem::createFile(string file_name)
//{
// if (this->files.count(file_name))
// {
//  return file_exists;
// }
// string extension = file_name.substr(file_name.find_last_of(".") + 1);
// AbstractFile * new_file;
// if (extension == "txt")
// {
//  new_file = new TextFile(file_name);
// }
// else if (extension == "img")
// {
//  new_file = new ImageFile(file_name);
// }
// else
// {
//  return invalid_file_extension;
// }
// files.insert(make_pair(file_name, new_file));
// return add_file_success;
//}

int SimpleFileSystem::deleteFile(string file_name)
{
 if (this->files.count(file_name))
 {
  AbstractFile * file = files[file_name];
  if (opened_files.count(file) == 0) // file is currently not open
  {
   files.erase(file_name);
   return delete_file_success;
  }
  return file_already_open; // opened_files.count(file) > 0 is true
 }
 return file_does_not_exist;
}

AbstractFile * SimpleFileSystem::openFile(string file_name)
{
 if (this->files.count(file_name))
 {
  AbstractFile * file = files[file_name];
  if (opened_files.count(file) == 0) // file is currently not open
  {
   opened_files.insert(file);
   return file;
  }
  //if (opened_files.find(file) !=  opened_files.end() ){ return nullptr; }
 }
 return nullptr; // file doesn't exist in files or file is already open
}


int SimpleFileSystem::closeFile(AbstractFile * file)
{
 if (opened_files.count(file) > 0) // file is currently open
 {
  opened_files.erase(file);
  return close_file_success;
 }
 return file_already_open;
}

set<string> SimpleFileSystem::getFileNames()
{
    set<string> file_names;
    for (auto it = files.begin(); it != files.end(); ++it) {
        file_names.insert(it->first); //use the key (file_name) from the map
    }
    return file_names;
}

SimpleFileSystem::~SimpleFileSystem()
{
    for (auto it = files.begin(); it != files.end(); ++it) {
        delete it->second; //use the value (file pointer) from the map
        it->second = nullptr;
    }
}
