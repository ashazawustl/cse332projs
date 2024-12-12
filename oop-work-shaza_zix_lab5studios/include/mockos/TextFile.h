#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <vector>
#include <string>
#include <iostream>

#include "AbstractFile.h"

using namespace std;

class TextFile : public AbstractFile
{
private:
    vector<char> file_contents;

public:
    string file_name;

    TextFile(string name);

    virtual unsigned int getSize();
    virtual string getName();
    virtual int write(vector<char> new_contents);
    virtual int append(vector<char> new_lines);
    virtual vector<char> read();
    virtual void accept(AbstractFileVisitor* visitor);
    AbstractFile* clone(std::string newName);
    virtual ~TextFile();
};

enum
{
    invalid_content = 1,
    append_success = 0,
};

#endif //TEXTFILE_H