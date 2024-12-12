# Lab 5

Zix Chen, Shaza Ali

Zix Chen: steps 1, 2, 7, 8, 9, 10 and CLion Lab5.cpp test cases
Shaza Ali: steps 3, 4, 5, 6 & Remote Desktop Check + code cleanup and commenting

for the additional MacroCommand of our choosing:
touch + cat (create a file and edit it immediately) was implemented

to invoke from command prompt, "cne" is chosen as the key word

tests for the additional MacroCommand:

inputting a valid procedure:

    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ cne test.txt
    Enter input (type ':wq' to save and quit, ':q' to quit without saving):
    hello world
    :wq

conclusion: expected result


bad input 1:

    $ cne test2
    Invalid file name
    Error executing command: cne
    Error code: 15

conclusion: expected result


bad input 2:

    $ cne
    Invalid file name
    Error executing command: cne
    Error code: 15

conclusion: expected result


bad input 3:

    $ cne test.txt test2.txt
    Invalid number of args for create and edit command
    Error executing command: cne
    Error code: 15

conclusion: expected result





testing all commands:


testing touch & ls:

    $ touch test.txt
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ touch test2.txt
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ touch test3.txt
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ touch test4.txt
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ ls
    test.txt           test2.txt
    test3.txt          test4.txt
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ ls -m
    test.txt           text      0
    test2.txt          text      0
    test3.txt          text      0
    test4.txt          text      0

conclusion: expected result



testing remove:

    $ rm test.txt
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ ls
    test2.txt          test3.txt
    test4.txt  

conclusion: expected result


testing cat:
    
    $ cat test2.txt
    Enter input (type ':wq' to save and quit, ':q' to quit without saving):
    hello world
    :wq
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ ls -m
    test2.txt          text      12
    test3.txt          text      0
    test4.txt          text      0

conclusion: expected result


testing display:

    $ ds test2.txt
    hello world

conclusion: expected result


testing copy:

    $ cp test2.txt test2vers2
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ ls -m
    test2.txt          text      12
    test2vers2.txt     text      12
    test3.txt          text      0
    test4.txt          text      0

conclusion: expected result


testing rename:

    $ rn test2vers2.txt test5
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ ls -m
    test2.txt          text      12
    test3.txt          text      0
    test4.txt          text      0
    test5.txt          text      12

conclusion: expected result


testing create and edit: see above
conclusion: expected result


testing invalid args for commands:

    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ touch test.txt -x
    Invalid parameter. Proceeding as if no parameter was passed
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ ls -x
    Invalid parameter. Proceeding as if no parameter was passed
    test.txt           
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ cat test.txt -x
    Invalid parameter. Proceeding as if no parameter was passed
    Enter input (type ':wq' to save and quit, ':q' to quit without saving):
    :q
    User quit without saving.
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ cp test.txt test2 -x
    Invalid parameter. Proceeding as if no parameter was passed
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ rm test.txt -x
    Invalid parameter. Proceeding as if no parameter was passed
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ ls
    test2.txt
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ cne test.txt -x
    Invalid parameter. Proceeding as if no parameter was passed
    Enter input (type ':wq' to save and quit, ':q' to quit without saving):
    :q
    User quit without saving.
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ rn test.txt test3 -x
    Invalid parameter. Proceeding as if no parameter was passed
    Enter a command, q to quit, help for a list of commands, or
    help followed by a command name for more information about that command.
    $ ls
    test2.txt
    test3.txt

conclusion: expected result