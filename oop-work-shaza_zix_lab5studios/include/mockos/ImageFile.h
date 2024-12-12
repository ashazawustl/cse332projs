#ifndef IMAGEFILE_H
#define IMAGEFILE_H
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include "AbstractFile.h"

using namespace std;

class ImageFile : public AbstractFile
{

    string file_name;
    vector<char> file_contents;
    char image_size;
    int convertToIndex(unsigned int x, unsigned int y, const unsigned int size);

public:
    ImageFile(string file_name);

    virtual unsigned int getSize();
    virtual string getName();
    virtual vector<char> read();
    virtual int write(vector<char>);
    virtual int append(vector<char>);
    virtual void accept(AbstractFileVisitor* visitor);
    AbstractFile* clone(std::string newName);
    virtual ~ImageFile();
};

enum {
    ascii_of_zero = 48,
    beginning_index = 0
};

#endif //IMAGEFILE_H