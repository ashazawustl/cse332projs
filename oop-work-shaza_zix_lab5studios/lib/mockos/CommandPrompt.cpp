#include "mockos/CommandPrompt.h"
#include <sstream>

using namespace std;

CommandPrompt::CommandPrompt()
        : fileSystem(nullptr), fileFactory(nullptr) {}

void CommandPrompt::setFileSystem(AbstractFileSystem* fs) {
    fileSystem = fs;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* ff) {
    fileFactory = ff;
}

int CommandPrompt::addCommand(const string& name, AbstractCommand* command) {
    //command name is unique
    if (commands.find(name) != commands.end()) {
        return command_exists;
    }
    commands[name] = command;
    return command_prompt_success;
}

//method to list all available commands
void CommandPrompt::listCommands() const {
    cout << "Available commands:" << endl;
    for (const auto& pair : commands) {
        cout << "- " << pair.first << endl;
    }
}

//method to prompt the user for input
string CommandPrompt::prompt() const {
    //prompt message
    cout << "Enter a command, q to quit, help for a list of commands, or\n"
              << "help followed by a command name for more information about that command.\n";
    cout << "$ "; //prompt marker
    string input;
    getline(cin, input);
    return input;
}

int CommandPrompt::run() {

    while (true) {
        string userInput = prompt();

        //exit loop if user enters 'q'
        if (userInput == "q") {
            return quit;
        }
        //display available commands if 'help' is entered
        if (userInput == "help") {
            listCommands();
            continue;
        }

        istringstream iss(userInput);
        string commandName, parameters;
        iss >> commandName; //extract command name
        getline(iss, parameters); //extract the rest as parameters
        parameters.erase(0, parameters.find_first_not_of(" ")); //remove spaces

        //parse "help <command>"
        if (commandName == "help" && !parameters.empty()) {
            auto it = commands.find(parameters);
            if (it != commands.end()) {
                it->second->displayInfo(); //command-specific help
            } else {
                std::cout << "Command not found: " << parameters << std::endl;
            }
            continue;
        }

        //execute command if exists
        auto it = commands.find(commandName);
        if (it != commands.end()) {
            int result = it->second->execute(parameters); //execute with parameters
            if (result != 0) {
                cout << "Error executing command: " << commandName << endl;
                cout << "Error code: " << result << endl;
            }
        } else {
            cout << "Command not found: " << commandName << endl;
        }
    }
}

CommandPrompt::~CommandPrompt() {
    for (auto& pair : commands) {
        delete pair.second; //delete each command
        pair.second = nullptr;
    }

    fileSystem = nullptr;
    fileFactory = nullptr;
}
