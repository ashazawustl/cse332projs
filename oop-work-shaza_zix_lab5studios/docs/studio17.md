# Studio 17

1. Zix Chen, Shaza Ali
2. following the principle of abstraction I made the helper function private.

name, write content are empty;

output:
   File name:
   File contents: Write content status: 1 //this is the error code for empty_content
   File size: 0
   Updated file contents:
   Process finished with exit code 0

conclusion: expected behavior


name = "testFile"
write content = {'X', '', 'X', '', 'X', '', 'X', '', 'X', '3'}

output:
   File name: testFile
   File contents:
   Write content status: 0
   File size: 9
   Updated file contents:
   X   X
     X   
   X   X
   
   Process finished with exit code 0

conclusion: expected behavior


name = "testFile"
write content = {'X', '', 'X', '', 'X', '', 'X', '', 'X', '1'} // wrong char for size

output:
   File name: testFile
   File contents:
   Write content status: 5 //error code for write_content_size_mismatch
   File size: 0
   Updated file contents:
   
   Process finished with exit code 0

conclusion: expected behavior


name = "testFile"
write content = {'X', '', 'X', '', 'X', '', 'X', '', 'X', 'A'} // invalid char for size

output:
File name: testFile
File contents:
Write content status: 3 //error code for invalid_size_char
File size: 0
Updated file contents:

Process finished with exit code 0

conclusion: expected behavior


name = "testFile"
write content = {'X', '', 'X', '', 'O', '', 'X', '', 'X', '3'} // invalid char for size

output:
File name: testFile
File contents:
Write content status: 4 //error code for invalid_pixel
File size: 0
Updated file contents:

Process finished with exit code 0

conclusion: expected behavior


tried:
vector<char> largeAppendContent = {'X'};
result = myfile.append(largeAppendContent);

output:
   File name: testFile
   File contents:
   Write content status: 0
   File size: 9
   Updated file contents:
   X   X
   X   
   X   X
   Append content status: 6 //error code for unsupported_operation
   
   Process finished with exit code 0

conclusion: expected behavior


AbstractFile * myfile = new ImageFile("testFile"); // testing for dynamic binding

output:
   File name: testFile
   File contents:
   Write content status: 0
   File size: 9
   Updated file contents:
   X   X
     X   
   X   X
   Append content status: 6
   
   Process finished with exit code 0

conclusion: expected behavior


3. the benefits of an interface is that we can make client code reliant on the interface implementation rather than the 
concrete classes that are involved, allowing the ability to change the concrete class implementations however we like,
(and if we want to change the program we can just change the concrete classes rather than modifying the base class 
as well as the client side program), enabling long term flexibility

4. this is the test code:
   SimpleFileSystem file_system; // make the file system
   TextFile * text_file1 = new TextFile("text_file1.txt"); //make a text file

   string str = "This is the content of text file 1";
   vector<char> writeContent(str.begin(), str.end());
   text_file1 -> write(writeContent);

   string text_file1_name = text_file1 -> getName();

   file_system.addFile(text_file1_name, text_file1);

   file_system.createFile("text_file2.txt"); //create another text file within file system
   AbstractFile * text_file2 = file_system.openFile("text_file2.txt"); //testing the openFile method

   str = "This is the content of text file 2";
   vector<char> writeContent2(str.begin(), str.end());
   text_file2->append(writeContent2); 
   file_system.closeFile(text_file2); //testing the closeFile method

   ImageFile * image_file1 = new ImageFile("image_file1.img"); // making an image file
   image_file1 -> write({' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ' , ' ' , '3' });

   string image_file1_name = image_file1 -> getName();
   file_system.addFile(image_file1_name, image_file1); //testing addFile

   file_system.createFile("image_file2.img"); // making another image file within file system
   AbstractFile * image_file2 = file_system.openFile("image_file2.img");
   image_file2->write({' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ' , ' ' ,' ', 'X', ' ', 'X', ' ', ' ', ' ', '4' });
   file_system.closeFile(image_file2);

   AbstractFile * file1 = file_system.openFile("text_file1.txt");
   cout << "text file 1: " << endl;
   file1 -> read();
   AbstractFile * file2 = file_system.openFile("text_file2.txt");
   cout << "text file 2: " << endl;
   file2 -> read();
   AbstractFile * file3 = file_system.openFile("image_file1.img");
   cout << "image file 1: " << endl;
   file3 -> read();

   AbstractFile * file4 = file_system.openFile("image_file2.img");
   string file4_name = file4 -> getName();
   file_system.closeFile(file4);
   file_system.deleteFile(file4_name); // testing the deleteFile method
 
   AbstractFile * deleted_file4 = file_system.openFile(file4_name); // if file was successfully deleted this should return a nullptr
   if (deleted_file4 == nullptr) {
   {
   cout << "File 4 was deleted successfully." << endl;
   }

   return main_success;

output:
   text file 1:
   This is the content of text file 1
   text file 2:
   This is the content of text file 2
   image file 1:

   X     
     X   
   File 4 was deleted successfully.
   
   Process finished with exit code 0

conclusion: expected behavior


in the createFile() method where we check for file extension in the input parameter for the file name, where we just 
add a new if statement that checks if the extension is matching the newly implemented file type extension and inside the
loop we just add whatever dynamic declaration method for that file class.

