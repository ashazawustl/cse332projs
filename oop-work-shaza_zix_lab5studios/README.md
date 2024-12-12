# Mock OS Studios/Lab
Throughout these studios and the lab, you'll be creating a static library that
implements a mock operating system.
A user of this mock operating system will be able to
create and interact with files using commands.

At each stage, you'll try out your static library by writing and running executables,
and you'll test it by running unit tests.

## Directory structure
The directory structure aims to follow best practices,
so it will look similar to many C++ projects in the real world.

The idea is to separate the public interface from its implementation.

- [docs/](docs)
  - This directory contains the markdown files in which you'll answer
    the studio questions and write your lab README.

- [include/](include)
  - This directory contains the public header files for the static library.
  - They are placed within the inner directory `mockos/`,
    so when including them from source files, prefix the filename with `mockos/`.
    For example, if you wanted to use TextFile, you would type
    `#include "mockos/TextFile.h"`.
  - The prefix is not necessary when
    you're including a header file from another header file that's inside `include/mockos/`.
- [lib/](lib)
  - This directory contains the source files for the implementation of the static library.
  - Like `include/`, the files are placed within an inner `mockos/` directory.
- [src/](src)
  - This directory contains the source files for the executable code.
  - There's a source file for each studio and the lab.
- [tests/](tests)
  - This directory contains the unit tests.
  - Since the tests are already written for you, you will not need to modify the files in this directory.

## Workflow
The workflow for each studio is similar.

### Answering the studio's questions
While you go through the studio, write your answers to the studio's questions in the associated Markdown file.
As an example, for Studio 16, write your answers in `docs/studio16.md`.

### Implementing part of the static library
First, you'll implement the part of the static library
specified by the studio instructions.

When implementing a class, fill in its header file in `include/mockos/`,
and fill in its source file in `lib/mockos/`.

When you're writing the header file, you can include other header files in `include/mockos/` without the `mockos/` prefix.
For example, when writing the header file for `TextFile` in `include/mockos/TextFile.h`, you'd include AbstractFile like this:
```c++
#include "AbstractFile"
```

However, when you're writing the source file, you must add the `mockos/` prefix.
For example, when writing the source file for `TextFile` in `lib/mockos/TextFile.cpp`, you'd include its own header file like this:
```c++
#include "mockos/TextFile.h"
```

### Trying out the newly implemented methods
To try out the newly implemented methods,
you'll then write a main method in the studio's source file in `src/`.

We have created executable targets for each studio.
Just write the main method in the studio's source file,
and you can run the corresponding target.

For example, when you're working on studio 16,
you'd write a main method in `src/Studio16.cpp`.
Then, you can run the `studio16` target.

In CLion, you can choose the target by
opening the Run Configurations dropdown menu.

In VS, you can choose the target by
switching to CMake Targets View.

### Running the unit tests
Finally, you'll run the unit tests to check that everything works as we expect.

To run a studio's unit tests, run the Google Test target corresponding to that studio.
For example, for studio 16, run the `teststudio16` target.

## Lab tips
### Adding new files
We've configured CMake to find the header and source files with globs.
As a consequence, when you add new files, you'll need to reload the CMake project
for them to be added to the static library.

In CLion, right-click the top-level CMakeLists.txt
and choose "Reload CMake Project".

In VS, choose File > Open > CMake and select the top-level CMakeLists.txt.
