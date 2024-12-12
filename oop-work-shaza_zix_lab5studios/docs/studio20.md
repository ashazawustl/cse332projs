# Studio 20

1. Zix Chen, Shaza Ali
2. The password proxy needs to have the same lifetime as the file itself because if it has a shorter lifetime, the file 
would no longer be password protected (the PasswordProxy destructor doesn't delete the file but destroys the password 
proxy). So for security reasons we need to either keep both the proxy and the file or delete them both at the same time.
4. 
test: entered correct password for write(), incorrect password for read() and correct password for accept()
output:

    Enter password: 123
    write successful
    Enter password: 1
    Incorrect Password.
    file1 contents using BasicDisplayVisitor:
    Enter password: 123
     X   
    X     
    X
    
    Process finished with exit code 0

conclusion: expected output


test: entered correct password for all operations
output:

    Enter password: 123
    write successful
    Enter password: 123
    file is successfully read
    file1 contents using BasicDisplayVisitor:
    Enter password: 123
      X   
    X     
    X
    
    Process finished with exit code 0

conclusion: expected output


test: entered incorrect password for all operations
output:

    Enter password: 1
    wrong password entered when attempting to write
    Enter password: 1
    Incorrect Password.
    file1 contents using BasicDisplayVisitor:
    Enter password: 1
    Incorrect Password.
    Process finished with exit code 0

conclusion: expected output

5. no error occurred
