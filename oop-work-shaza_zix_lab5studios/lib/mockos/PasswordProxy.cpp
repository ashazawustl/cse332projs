#include "mockos/PasswordProxy.h"
#include <iostream>

using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* filePointer, string password): file(filePointer), password(password) {};

PasswordProxy::~PasswordProxy(){
    delete file;
};

string PasswordProxy::passwordPrompt(){
    string userInputPassword;
    cout << "Enter password: ";
    cin >> userInputPassword;
    return userInputPassword;
};

bool PasswordProxy::passHelper(string userInputPassword){
    return userInputPassword == password;
};

vector<char> PasswordProxy::read(){
    string entered_password = passwordPrompt();
    bool password_correct = passHelper(entered_password);
    if (password_correct)
    {
        return file->read();
    }
    cout << "Incorrect Password." << endl;
    return vector<char>();
};

int PasswordProxy::write(vector<char> new_contents){
    string entered_password = passwordPrompt();
    bool password_correct = passHelper(entered_password);
    if (password_correct)
    {
        return file->write(new_contents);
    }
    return write_password_rejected;
};

int PasswordProxy::append(vector<char> new_contents){
    string entered_password = passwordPrompt();
    bool password_correct = passHelper(entered_password);
    if (password_correct)
    {
        return file->append(new_contents);
    }
    return append_password_rejected;
};

unsigned int PasswordProxy::getSize(){
    return file->getSize();
};

string PasswordProxy::getName(){
    return file-> getName();
};

void PasswordProxy::accept(AbstractFileVisitor* visitor) {
    string userInput = passwordPrompt();
    if(passHelper(userInput)){
        return file -> accept(visitor);
    }
    cout<< "Incorrect Password." ;
};

AbstractFile* PasswordProxy::clone(std::string newName) {
    AbstractFile* clonedFile = file->clone(newName); //clone underlying file
    return new PasswordProxy(clonedFile, password); //wrap it in new proxy
}

