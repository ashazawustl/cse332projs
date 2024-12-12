#include "mockos/MacroCommand.h"

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* fs) : AbstractCommand(), fileSystem(fs) {}

int MacroCommand::execute(string args) {
    vector<string> parsedArgs = parsingStrategy->parse(args);
    if (parsedArgs.empty())
    {
        return invalid_args;
    }
    for (int i = 0; i < parsedArgs.size(); i++)
    {
        string arg = parsedArgs[i];
        int result = commands[i]->execute(arg);
        if (result !=0)
        {
            return result;
        }
    }
    return success;
}

void MacroCommand::addCommand(AbstractCommand* command)
{
    this->commands.push_back(command);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* ps)
{
    this->parsingStrategy = ps;
}

void MacroCommand::displayInfo() {
    cout << "macrocommand execute multiple commands." << endl;
}

MacroCommand::~MacroCommand()
{
    fileSystem = nullptr;
    for (AbstractCommand * command : commands)
    {
        command = nullptr;
    }
    parsingStrategy = nullptr;
}