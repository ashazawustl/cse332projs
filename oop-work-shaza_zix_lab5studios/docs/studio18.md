# Studio 18
1. Shaza Ali, Zix Chen
2. Factory methods have a base class that is the main 
interface, basically what everything is derived from
including virtual methods (acts as a blueprint).
It wouldn't be difficult whatsoever to adjust the 
SimpleFileSystem to include new file types, only the 
createFile() method would change by adding another if else statement 
then the file type we want to check/create.
3. Separating the function of a file system into two parts: 
creation and file accessing as two different parts.
So if we have different file types to support then we'd only modify 
one of those factory classes. The concrete file factory class would 
be what we modify if a new file type is introduced that should be created 
by existing factories. Yes, the same concrete file system can be used to 
create files for two different file types and two of the same types of files.
4. Testing!
/Users/shazaali/CLionProjects/oop-work-shaza_zix_lab5studios/cmake-build-debug/src/studio18 ./studio18
   text file 1:
   This is the content of text file 1
   text file 2:
   This is the content of text file 2
   image file 1:

   X     
     X   

File 4 was deleted successfully.

Process finished with exit code 0

expected outcome
5. SimpleFileSystem focuses on AbstractFile interface only.
