#include "mockos/PasswordProxy.h"
#include "mockos/BasicDisplayVisitor.h"
#include <iostream>
#include <vector>

#include "mockos/ImageFile.h"

using namespace std;

int main() {
    AbstractFile * file1 = new ImageFile("file1");
    PasswordProxy * file1_proxy = new PasswordProxy(file1, "123");

    int write_status = file1_proxy -> write({' ', 'X', ' ', 'X', ' ', ' ', 'X', ' ', ' ', '3'});
    if (write_status == write_password_rejected)
    {
        cout << "wrong password entered when attempting to write" << endl;
    }
    else if (write_status == main_success)
    {
        cout << "write successful" << endl;
    }
    else
    {
        cout << "write status: " << write_status << endl;
    }


    vector<char> file_content = file1_proxy -> read();
    if (file_content.size() > 0)
    {
        cout << "file is successfully read" << endl;
    }

    BasicDisplayVisitor visitor;
    cout << "file1 contents using BasicDisplayVisitor:" << endl;
    file1_proxy -> accept(&visitor);

    return main_success;
}