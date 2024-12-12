#ifndef PASSWORDPROXY_H
#define PASSWORDPROXY_H

#include "AbstractFile.h"
#include <string>
#include <vector>
using namespace std;

class PasswordProxy: public AbstractFile{
protected:
    string passwordPrompt();
    bool passHelper(string userInputPassword);
private:
    AbstractFile * file;
    string password;
public:
    PasswordProxy(AbstractFile * filePointer, string password);
    ~PasswordProxy();

    virtual vector<char> read();
    virtual int write(vector<char>);
    virtual int append(vector<char>);
    virtual unsigned int getSize();
    virtual string getName();
    virtual void accept(AbstractFileVisitor* visitor);
    AbstractFile* clone(std::string newName);
};


enum{
    passwordmatch = 0,
    passwordmismatch = 1,
    write_password_rejected = 2,
    append_password_rejected = 3
};
#endif //PASSWORDPROXY_H