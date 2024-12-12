#ifndef COPYCOMMAND_H
#define COPYCOMMAND_H

#include "AbstractCommand.h"
#include <iostream>
#include <sstream>

class CopyCommand : public AbstractCommand {
private:
    AbstractFileSystem* fileSystem;

public:
    CopyCommand(AbstractFileSystem* fs);
    virtual int execute(std::string args);
    virtual void displayInfo();
    virtual ~CopyCommand();
};

enum{
     copy_failed = 12,
     invalid_copycommand_arg = 13,
     add_file_failed = 14
};

#endif // COPYCOMMAND_H
