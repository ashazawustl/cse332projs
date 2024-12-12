#include "mockos/SimpleFileFactory.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    AbstractFileSystem* file_system= new SimpleFileSystem;
    AbstractFileFactory* factory = new SimpleFileFactory;

//  creating text files 1
    AbstractFile* text_file1 = factory->createFile("text_file1.txt");
    file_system->addFile("text_file1.txt",text_file1);
    string str = "This is the content of text file 1";
    vector<char> writeContent(str.begin(), str.end());
    text_file1->write(writeContent);

// creating text file 2
    AbstractFile* text_file2 = factory->createFile("text_file2.txt");
    file_system->addFile("text_file2.txt",text_file2);
    str = "This is the content of text file 2";
    vector<char> writeContent2(str.begin(), str.end());
    text_file2->append(writeContent2);

//  creating image file 1
    AbstractFile* image_file1 = factory->createFile("image_file1.img");
    file_system->addFile("image_file1.img", image_file1);
    image_file1->write({' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ', ' ', '3'});

//  creating image file 2
    AbstractFile* image_file2 = factory->createFile("image_file2.img");
    file_system->addFile("image_file2.img", image_file2);
    image_file2->write({' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', ' ', '4'});

    AbstractFile *file1 = file_system->openFile("text_file1.txt");
    cout << "text file 1: " << endl;
    file1->read();
    AbstractFile *file2 = file_system->openFile("text_file2.txt");
    cout << "text file 2: " << endl;
    file2->read();
    AbstractFile *file3 = file_system->openFile("image_file1.img");
    cout << "image file 1: " << endl;
    file3->read();

    AbstractFile *file4 = file_system->openFile("image_file2.img");
    string file4_name = file4->getName();
    file_system->closeFile(file4);
    file_system->deleteFile(file4_name);


    AbstractFile *deleted_file4 = file_system->openFile(file4_name);
    if (deleted_file4 == nullptr) {
        cout << "File 4 was deleted successfully." << endl;
    }

    return main_success;
}
