# Studio 16

1. Zix Chen, Shaza Ali

2. a. an interface is typically made by declaring all functions as pure virtual functions with the = 0 syntax.
3. a. interface inheritance, TextFile doesn't inherit any data from AbstractFile, only its interface
   b. file_contents should be private and file_name should be public
4. 
name, write content and append content all empty;

output:
   File name:
   File contents:
   Write content status: 1 //this means failed, probably due to the content being empty
   File size: 0
   Updated file contents:
   Append content status: 1 //this means failed, probably due to the content being empty
   File size: 0
   Updated file contents:
   
   Process finished with exit code 0

conclusion: expected behavior

name = "testFile"
write content = "this is the write content "
append content = "this is the append content"

output:
   File name: testFile
   File contents:
   Write content status: 0
   File size: 26
   Updated file contents: this is the write content
   Append content status: 0
   File size: 52
   Updated file contents: this is the write content this is the append content
   
   Process finished with exit code 0

conclusion: expected behavior

name = ""
write content = largeContent(100000, 'A')
append content = largeAppendContent(50000, 'B')

output:
   File name:
   File contents:
   Write large content status: 0
   File size after large write: 100000
   Updated file contents: AAAAAAAAAAAAAAAAAAAAAAA...
   Append large content status: 0
   File size after large append: 150000
   Updated file contents: AAAAAAAAAAAAAAAAAAAAAAA...
   ....BBBB

   Process finished with exit code 0

conclusion: expected behavior

5.
AbstractFile * myfile = new TextFile("");
name, write content and append content all empty;

output:
   File name: 
   File contents:
   Write content status: 1 //this means failed, probably due to the content being empty
   File size: 0
   Updated file contents:
   Append content status: 1 //this means failed, probably due to the content being empty
   File size: 0
   Updated file contents:
   
   Process finished with exit code 0

conclusion: expected behavior


AbstractFile * myfile = new TextFile("testFile");
name = "testFile"
write content = "this is the write content "
append content = "this is the append content"

output:
   File name: testFile
   File contents:
   Write content status: 0
   File size: 26
   Updated file contents: this is the write content
   Append content status: 0
   File size: 52
   Updated file contents: this is the write content this is the append content
   
   Process finished with exit code 0

conclusion: expected behavior


AbstractFile * myfile = new TextFile("testFile");
name = ""
write content = largeContent(100000, 'A')
append content = largeAppendContent(50000, 'B')

output:
   File name: testFile
   File contents:
   Write content status: 0
   File size: 100000
   Updated file contents: AAAAAAAAAAAAAAAAAAAAAAAAAAA...
   
   Append content status: 0
   File size: 150000
   Updated file contents: AAAAAAAAAAAAAAAAAAAAAAAAAAA...
   ....BBBB
   
   Process finished with exit code 0

conclusion: expected behavior
