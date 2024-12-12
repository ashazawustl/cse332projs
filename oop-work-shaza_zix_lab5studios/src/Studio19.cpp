#include "mockos/SimpleFileFactory.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/BasicDisplayVisitor.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    /*In main, try creating and then reading a file. Store the files contents into a local
variable declared in main. Then make an edit to the file’s contents and rewrite the
file with the modified contents. As the answer to this question, describe the tests
you ran.*/

    AbstractFile * file1 = new TextFile("textfile1");
    string str = "this is some content for text file 1";
    vector<char> writeContent(str.begin(), str.end());
    file1->write(writeContent);


    AbstractFile * file2 = new ImageFile("ImageFile1");
    file2->write({' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ', ' ', '3'});
    vector<char> localContents1 = file1 -> read();

    // Define the string to add
    std::string extraContent = " and this is some extra content";
    // Append the string to the vector
    localContents1.insert(localContents1.end(), extraContent.begin(), extraContent.end());
    file1->write(localContents1);

    vector<char> localContents2 = file2 -> read();
    int localContentsSize = localContents2.size();
    localContents2.pop_back();
    for (int i = 0; i < 4*4-localContentsSize+1; i++)
    {
        localContents2.push_back('X');
    }
    localContents2.push_back('4');
    file2->write(localContents2);

    BasicDisplayVisitor visitor;
    cout << "file1 contents using BasicDisplayVisitor:" << endl;
    file1->accept(&visitor);

    cout << "file2 contents using BasicDisplayVisitor:" << endl;
    file2->accept(&visitor);

    delete file1;
    delete file2;

    return main_success;
}