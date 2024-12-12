#ifndef ABSTRACTFILE_H
#define ABSTRACTFILE_H
#include <vector>
#include <string>

class AbstractFileVisitor;

using namespace std;

class AbstractFile
{
 public:
    //these commands are shared across all header files for the mockos and AbstractFile maintains the general inheritance of these functions
    virtual vector<char> read() = 0;
    virtual int write(vector<char>) = 0;
    virtual int append(vector<char>) = 0;
    virtual unsigned int getSize() = 0;
    virtual string getName() = 0;
    virtual void accept(AbstractFileVisitor* visitor) = 0;
    virtual AbstractFile* clone(std::string newName) = 0;
    virtual ~AbstractFile() = 0;
};

enum
{
 empty_content = 1,
 write_success = 0,
 write_failure = 2,
 invalid_size_char = 3,
 invalid_pixel = 4,
 write_content_size_mismatch = 5,
 unsupported_operation = 6,
 empty_visitor_pointer = 7,
 main_success = 0
};


#endif //ABSTRACTFILE_H