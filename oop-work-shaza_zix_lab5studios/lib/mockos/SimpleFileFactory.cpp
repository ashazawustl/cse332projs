#include "mockos/SimpleFileFactory.h"

SimpleFileFactory::SimpleFileFactory()
{
}

AbstractFile* SimpleFileFactory::createFile(string file_name)
{
    string extension = file_name.substr(file_name.find_last_of(".") + 1);
    AbstractFile * new_file;
    if (extension == "txt")
    {
        new_file = new TextFile(file_name);
    }
    else if (extension == "img")
    {
        new_file = new ImageFile(file_name);
    }
    else
    {
        new_file = nullptr;
    }
    return new_file;
}

SimpleFileFactory::~SimpleFileFactory()
{
}