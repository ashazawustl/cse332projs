# CSE 332 Lab Base
Repository for submitting lab work

Note: We will read this file as raw text rather than markdown.

Name: Shaza Ali
Lab #: 2

Document your lab work here according to the lab specification
1. piece_colorString needs to be of type std::string, not void, in order to take in variable piece
2. for getString, cant just declare type as string, must be std::string
3. initially, my declaration of the getStringforColor function was int, it should've been of type piece_color
4. Wasn't really sure what to do with the struct in step 10 in the source file so I just returned the ino about the piece 
5. Had to modify my function to get and return the color of the piece by getting rid of toLowerCase(str) and including the function before it, piece_colorString
6. Added function getColorfromString to fix the problem above
7. fixed the if statements in getColorfromString (redundant since they're in getStringforColor)  by replacing with  return getStringforColor(colorStr);
8. Call to boardDimensions was ambiguous because I forgot to adjust the variable type to be a reference to unsigned int in the header file
9. The above was causing issues with rechability of the rest od the function so it was commented out for now
10. piececolor is causing me problems when trying to create a new piece to add to the gamepieces vector
11. to fix above issue, used 'color' variable instead and cast it to a const char pointer instead
12. I'm getting a warning that color is not initialized when used in the game-board.cpp file but it is? It's initialized as: piece_color color = getColorfromString(colorStr);
13. the casting towards the end is what's causing the issue (for some reason)
14. Okay I just got rid of the push back call entirely
15. fixed issue with building, was adding cpp files with #include, which isn't allowed 
16. in the line: gamepieces[i].piececolor = "no color";  there's an error called Assigning to 'piece_color' from incompatible type 'const char[9]'
17. Fixed the above by matching enum type from the header file (so replacing "no_color" with no_color)
18. Everything built successfully

Extra Credit:
1. First off, everything built successfully. The way the adjacent pieces section works is as follows:
2. The function for it is declared and defined in the game-board.cpp and game-board.h files, taking in the game_piece vector, the width, and the height (both as unsigned ints as previously done)
3. In the game-board.cpp, we check whether there's problems with the game board size acoording to the given width and height. If the size of the vector is not equal to the area of the board, the wrongsize error number is displayed.
4. In the case that the size if fine, we initialize some x and y dimensions for a board that goes in every compass direction.
5. Then we loop through every row and column, checking that the index we're given in our input file is fine with the board we have available.
6. For every row and column we print out information about the piece at the specified coordinates, going on to adjacent piece until we've got all of the pieces and their info at each given coordinate.
7. All this is called in Main.cpp
