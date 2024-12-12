# Studio 21
1. Zix Chen, Shaza Ali
2. Because it ensures that the destructors of derived classes are called properly when an 
object is deleted through a pointer to the base class
3. Using dependency injection makes sure that the Command Prompt can
be reused in different contexts and that it can adapt to new requirements. 
Functionality can then be tested in isolated tests thereby allowing others to 
maintain the CommandPrompt with ease. 
4. 
Test 1: running quit command:

   Enter a command, q to quit, help for a list of commands, or
   help followed by a command name for more information about that command.
   $ q
   Process finished with exit code 0

conclusion: expected output!

Test 2: running help and touch without a file name

   Enter a command, q to quit, help for a list of commands, or
   help followed by a command name for more information about that command.
   $ help
   Available commands:
   - touch
   Enter a command, q to quit, help for a list of commands, or
   help followed by a command name for more information about that command.
   $

conclusion: expected output!

Test 3: running help and touch without a file name

   Enter a command, q to quit, help for a list of commands, or
   help followed by a command name for more information about that command.
   $ help touch
   touch creates a file. It can be invoked with the command: touch <filename>
   Enter a command, q to quit, help for a list of commands, or
   help followed by a command name for more information about that command.
   $

conclusion: expected output!

Test 4: running help and touch without a file name

   Enter a command, q to quit, help for a list of commands, or
   help followed by a command name for more information about that command.
   $ touch newfile1.txt
   Enter a command, q to quit, help for a list of commands, or
   help followed by a command name for more information about that command.
   $ q
   File 'newfile1.txt' successfully created and found in the file system.
   
   Process finished with exit code 0

conclusion: expected output!

5. all unit tests pass