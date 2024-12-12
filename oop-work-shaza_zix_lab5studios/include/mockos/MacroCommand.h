#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include <iostream>
#include <sstream>

using namespace std;

class MacroCommand : public AbstractCommand {
private:
    AbstractFileSystem* fileSystem;
    vector<AbstractCommand*> commands;
    AbstractParsingStrategy * parsingStrategy;

public:
    MacroCommand(AbstractFileSystem* fs);
    virtual int execute(std::string args);
    virtual void addCommand(AbstractCommand* command);
    virtual void setParseStrategy(AbstractParsingStrategy* ps);
    virtual void displayInfo();
    virtual ~MacroCommand();
};

enum{
    invalid_args = 15
};

#endif // MACROCOMMAND_H
