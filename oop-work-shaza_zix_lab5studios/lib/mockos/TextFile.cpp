#include "mockos/TextFile.h"
#include "mockos/AbstractFile.h"
#include "mockos/AbstractFileVisitor.h"
#include <algorithm>

using namespace std;

TextFile::TextFile(string name):file_name(name)
{

}

unsigned int TextFile::getSize()
{
    return file_contents.size();
}

string TextFile::getName()
{
    return file_name;
}

int TextFile::write(vector<char> new_contents)
{
    file_contents.clear();
    if (new_contents.empty())
    {
        return invalid_content;
    }

    try {
        file_contents = new_contents;
    }
    catch(...)
    {
        return write_failure;
    }
    return write_success;
}

int TextFile::append(vector<char> new_contents)
{
    if (new_contents.empty())
    {
        return invalid_content;
    }
    file_contents.insert(file_contents.end(), new_contents.begin(), new_contents.end());
    return append_success;
}

vector<char> TextFile::read(){
    return file_contents;
}

void TextFile::accept(AbstractFileVisitor* visitor)
{
    if (visitor != nullptr) {
        visitor -> visit_TextFile(this);
    } else {
        throw empty_visitor_pointer;
    }
}

//clone method for the prototype pattern
AbstractFile* TextFile::clone(std::string newName) {
    TextFile* copy = new TextFile(newName);
    copy->write(this->file_contents); //copy content
    return copy;
}

TextFile::~TextFile()
{
}