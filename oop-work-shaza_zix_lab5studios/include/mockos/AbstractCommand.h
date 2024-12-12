#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractFile.h"
#include <string>
#include <vector>


//deconstructor, displaying information regarding the commands in the command prompt and executing the commands that are selected by the user need to be publicly accessible in order to maintain dynamically allocated objects in main
class AbstractCommand {
public:
    virtual int execute(std::string) = 0;
    virtual void displayInfo() = 0;
    virtual ~AbstractCommand() = default;
};

enum {
    success = 0,
    file_not_found = 1,
    file_access_denied = 2,
    invalid_filename = 3
};

enum{
    max_file_name_length = 19
};

#endif // ABSTRACTCOMMAND_H
