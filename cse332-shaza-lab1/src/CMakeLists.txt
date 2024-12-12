# author: d.horn

# Modify lab_x to the lab number if you'd like, add any source files you create here as needed

add_executable(lab_x Main.cpp
        lab1header.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/AbstractCommand.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/AbstractFile.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/AbstractFileFactory.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/AbstractFileSystem.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/AbstractFileVisitor.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/AbstractParsingStrategy.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/BasicDisplayVisitor.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/CatCommand.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/CommandPrompt.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/Constants.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/CopyCommand.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/CreateAndEditParsingStrategy.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/DisplayCommand.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/ImageFile.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/LSCommand.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/MacroCommand.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/MetadataDisplayVisitor.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/PasswordProxy.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/RemoveCommand.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/RenameParsingStrategy.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/SimpleFileFactory.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/SimpleFileSystem.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/TextFile.h
        ../../oop-work-shaza_zix_lab5studios/include/mockos/TouchCommand.h
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/AbstractFile.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/BasicDisplayVisitor.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/CatCommand.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/CommandPrompt.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/CopyCommand.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/CreateAndEditParsingStrategy.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/DisplayCommand.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/ImageFile.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/LSCommand.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/MacroCommand.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/MetadataDisplayVisitor.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/PasswordProxy.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/RemoveCommand.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/RenameParsingStrategy.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/SimpleFileFactory.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/SimpleFileSystem.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/TextFile.cpp
        ../../oop-work-shaza_zix_lab5studios/lib/mockos/TouchCommand.cpp
        ../../oop-work-shaza_zix_lab5studios/src/Studio16.cpp
        ../../oop-work-shaza_zix_lab5studios/src/Studio17.cpp
        ../../oop-work-shaza_zix_lab5studios/src/Studio18.cpp
        ../../oop-work-shaza_zix_lab5studios/src/Studio19.cpp
        ../../oop-work-shaza_zix_lab5studios/src/Studio20.cpp
        ../../oop-work-shaza_zix_lab5studios/src/Studio21.cpp)
