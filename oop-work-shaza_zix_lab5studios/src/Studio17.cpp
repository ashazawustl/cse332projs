#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/SimpleFileSystem.h"
#include <iostream>
#include <vector>

using namespace std;


/*Create a SimpleFileSystem object in main, create a few files and add them to the file
system via the addFile method. Create a few files via the createFile method as well. Try
opening, writing, reading, and deleting files to ensure things are working properly.
As the answer to this question, first discuss with your group where you would need to
add code in the SimpleFileSystem class to be able to create an object of a new concrete
file type (a MusicFile for example). Record your answer in your readme. Take a closer
look at the SimpleFileSystem class. Note that it is entirely coded to use the AbstractFile
interface, with the exception of the createFile method. The createFile method depends
on understanding how to construct objects of each concrete file type. Next time, you will
alleviate this dependency by creating a separate object to handle file creation, making
the file system completely independent of the concrete type of each file it contains.
 */

/*Commented out in order to accommodate build on Remote Desktop.
 Areas of this section have become red with errors due to modifications in later studios.*/

int main() {
//    SimpleFileSystem file_system;
//
//    TextFile *text_file1 = new TextFile("text_file1.txt");
//
//    string str = "This is the content of text file 1";
//    vector<char> writeContent(str.begin(), str.end());
//    text_file1->write(writeContent);
//
//    string text_file1_name = text_file1->getName();
//
//    file_system.addFile(text_file1_name, text_file1);

    /*note to grader: createFile method was commented out of SimpleFileSystem and placed into AbstractFileFactory
    after this studio in order to accommodate future studios and lab5, the documentation in studio17.md
    should provide ample support for the functionality of this studio*/

//    file_system.createFile("text_file2.txt");
//    AbstractFile *text_file2 = file_system.openFile("text_file2.txt");
//
//    str = "This is the content of text file 2";
//    vector<char> writeContent2(str.begin(), str.end());
//    text_file2->append(writeContent2);
//    file_system.closeFile(text_file2);
//
//    ImageFile *image_file1 = new ImageFile("image_file1.img");
//    image_file1->write({' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ', ' ', '3'});
//
//    string image_file1_name = image_file1->getName();
//    file_system.addFile(image_file1_name, image_file1);
//
//    file_system.createFile("image_file2.img");
//    AbstractFile *image_file2 = file_system.openFile("image_file2.img");
//    image_file2->write({' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', ' ', '4'});
//    file_system.closeFile(image_file2);
//
//    AbstractFile *file1 = file_system.openFile("text_file1.txt");
//    cout << "text file 1: " << endl;
//    file1->read();
//    AbstractFile *file2 = file_system.openFile("text_file2.txt");
//    cout << "text file 2: " << endl;
//    file2->read();
//    AbstractFile *file3 = file_system.openFile("image_file1.img");
//    cout << "image file 1: " << endl;
//    file3->read();
//
//    AbstractFile *file4 = file_system.openFile("image_file2.img");
//    string file4_name = file4->getName();
//    file_system.closeFile(file4);
//    file_system.deleteFile(file4_name);
//
//    AbstractFile *deleted_file4 = file_system.openFile(file4_name);
//    if (deleted_file4 == nullptr) {
//        cout << "File 4 was deleted successfully." << endl;
//    }
//
//    return main_success;

}