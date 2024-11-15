# CSE 332 Lab Base
Repository for submitting lab work

Note: We will read this file as raw text rather than markdown.

Name: Zix Chen, Shaza Ali
Lab #: 4

Document your lab work here according to the lab specification

errors encountered during build and solutions:

1. error: member initializer 'width' does not name a non-static data member or base class TicTacToeGame(int w, int h, int g): width(w), height(h), gap(g), board(h, std::vector(w, ' ')) {}
2. error: member initializer 'height' does not name a non-static data member or base class TicTacToeGame(int w, int h, int g): width(w), height(h), gap(g), board(h, std::vector(w, ' ')) {}
3. error: member initializer 'gap' does not name a non-static data member or base class TicTacToeGame(int w, int h, int g): width(w), height(h), gap(g), board(h, std::vector(w, ' ')) {}
4. error: member initializer 'board' does not name a non-static data member or base class TicTacToeGame(int w, int h, int g): width(w), height(h), gap(g), board(h, std::vector(w, ' ')) {}
5. error: a type specifier is required for all declarations TicTacToeGame::tictactoe() //constructor
6. error: expected unqualified-id TicTacToeGame::~TicTacToeGame() noexcept {}() //destructor
7. error: invalid operands to binary expression ('string' (aka 'basic_string') and 'char') if (board[x][y] == ' ') //check if empty square
8. Member reference base type 'std::string[3][3]' (aka 'basic_string[3][3]') is not a structure or union
// Five in a row check for Gomoku wasn't working, game was continuously playing without end, variable numWin in header file needed to be set to 5
// Gomoku board printing twice: the print function was in both GameBase and Gomoku, needed to get rid of Gomoku one
// printing issues with TicTacToe: the board coordinates weren't printing so we checked and there were two ostream functions that were identical and then the implementation from lab 3 was taken and replaced the current implementation for this project, now prints from 0 to 2 (3x3 board)


testing for arguments in command line:

error codes:

invalid_argv = 6,
too_many_argv = 7,
not_enough_argv = 8

zix@ZixdeMacBook-Pro src % ./lab_4
not enough arguments
Usage: ./lab_4 <game_name> (TicTacToe or Gomoku)

//this would return invalid_argv
//expected result

zix@ZixdeMacBook-Pro src % ./lab_4 a a
too many arguments
Usage: ./lab_4 <game_name> (TicTacToe or Gomoku)

//this would return too_many_argv
//expected result

zix@ZixdeMacBook-Pro src % ./lab_4 a  
failed to create game
Usage: ./lab_4 <game_name> (TicTacToe or Gomoku)

//this would return not_enough_argv
//expected result

zix@ZixdeMacBook-Pro src % ./lab_4      Gomoku
19                                                          
18                                                          
17                                                          
16                                                          
15                                                          
14                                                          
13                                                          
12                                                          
11                                                          
10                                                          
09                                                          
08                                                          
07                                                          
06                                                          
05                                                          
04                                                          
03                                                          
02                                                          
01                                                          
X  01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19
Player B's turn!
place your next piece ("x,y") or type quit to exit:

//testing for empty space tolerance, expected result


testing for game inputs:

tictactoe:

zix@ZixdeMacBook-Pro src % ./lab_4 TicTacToe          
4           
3           
2           
1           
0           
0 1 2 3 4
Player X's turn!
place your next piece ("x,y") or type quit to exit: 0,0
Invalid move. Try again.
place your next piece ("x,y") or type quit to exit: 4,4
Invalid move. Try again.

//expected result (tried to place piece outside of boundary)

place your next piece ("x,y") or type quit to exit: 1,       1
4           
3           
2           
1   X       
0           
0 1 2 3 4

Player X: 1, 1;
Player O:
Player O's turn!


//expected result (testing for empty space tolerance)


Player X's turn!
place your next piece ("x,y") or type quit to exit: 3,1
4           
3           
2   O O     
1   X X X   
0           
0 1 2 3 4

Player X: 1, 1; 2, 1; 3, 1;
Player O: 1, 2; 2, 2;
Player X's victory!

//expected result (testing for winning scenario)

Player X's turn!
place your next piece ("x,y") or type quit to exit: 1,3
4           
3   X       
2   O O X   
1   X X O   
0           
0 1 2 3 4

Player X: 1, 1; 2, 1; 3, 2; 1, 3;
Player O: 3, 1; 1, 2; 2, 2;
draw: 7 turns played, no winning moves remain.

//expected result (testing for draw scenario)


gomoku:

zix@ZixdeMacBook-Pro src % ./lab_4 Gomoku   
19                                                          
18                                                          
17                                                          
16                                                          
15                                                          
14                                                          
13                                                          
12                                                          
11                                                          
10                                                          
09                                                          
08                                                          
07                                                          
06                                                          
05                                                          
04                                                          
03                                                          
02                                                          
01                                                          
X  01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19
Player B's turn!
place your next piece ("x,y") or type quit to exit: 0,0
Invalid move. Try again.
place your next piece ("x,y") or type quit to exit: 20,20
Invalid move. Try again.

//expected result (tried to place piece outside of boundary)

place your next piece ("x,y") or type quit to exit: 1,      1
1, 1

19                                                          
18                                                          
17                                                          
16                                                          
15                                                          
14                                                          
13                                                          
12                                                          
11                                                          
10                                                          
09                                                          
08                                                          
07                                                          
06                                                          
05                                                          
04                                                          
03                                                          
02                                                          
01 B                                                        
X  01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19

Player W's turn!

//expected result (testing for empty space tolerance)

place your next piece ("x,y") or type quit to exit: 5,1
5, 1

19                                                          
18                                                          
17                                                          
16                                                          
15                                                          
14                                                          
13                                                          
12                                                          
11                                                          
10                                                          
09                                                          
08                                                          
07                                                          
06                                                          
05                                                          
04                                                          
03                                                          
02 W  W  W  W                                               
01 B  B  B  B  B                                            
X  01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19

Player X's victory!

//expected result (testing for winning scenario)

Player B's turn!
place your next piece ("x,y") or type quit to exit: 13, 18

19 W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  
18 B  W  B  W  B  W  B  W  B  W  B  W  B                    
17 B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  
16 W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  
15 W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  
14 B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  
13 B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  
12 W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  
11 W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  
10 B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  
09 B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  
08 W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  
07 W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  
06 B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  
05 B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  
04 W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  
03 W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  
02 B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  
01 B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  W  B  
X  01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19

draw: 355 turns played, no winning moves remain.

//expected result (testing for draw scenario)