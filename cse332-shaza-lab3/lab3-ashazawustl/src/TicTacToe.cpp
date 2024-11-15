/**
 * Main.cpp
 * CSE 332S
 * Lab Num: 3
 * Author:Shaza Ali
*/

#include<iostream>
#include "TicTacToe.h"
#include<string>
#include<sstream>
#include<ctime>
#include<cstdlib>

using namespace std;

//initializing board and draw
BoardSetUp::BoardSetUp(bool gameStart){
    movesMade = 0;
    xCoord = 0;
    yCoord = 0;
    trackPlayer = "X";

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (i == 0 && j > 0) {
                board[i][j] = to_string(j - 1);
            } else if (j == 0 && i > 0) {
                board[i][j] = to_string(5 - i);
            } else {
                board[i][j] = " ";
            }
        }
    }
}

//overloading the operator to print the board
std::ostream& operator<<(std::ostream& output, const BoardSetUp& boarddimensions) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            output << boarddimensions.board[i][j] << " ";
        }
        output << std::endl;
    }
    return output;
}

void BoardSetUp::printBoard() const {
        std::cout << *this;
}

void BoardSetUp::updatePlayerMoves() {
    std::stringstream ss;
    ss << xCoord << "," << yCoord << "; ";

    if (trackPlayer == "X") {
        horizMove += ss.str();
        std::cout << "Player " << trackPlayer << ": " << horizMove << std::endl;
    } else {
        vertMove += ss.str();
        std::cout << "Player " << trackPlayer << ": " << vertMove << std::endl;
    }
}

//different win checks: horizontal, vertical, diagonal
bool BoardSetUp::done(){
    //a column win check
    for (int col = 2; col < 5; ++col) {
        if (board[1][col] == " ") {
            continue;
        } else if (board[1][col] == board[2][col]
                   && board[2][col] == board[3][col]) {
            return true;

        }
    }
    //a row win check
    for (int row = 1; row < 4; ++row) {
        if (board[row][2] == " ") {
            continue;
        } else if (board[row][2] == board[row][3]
                   && board[row][3] == board[row][4]) {
            return true;
        }
    }
    //a diagonal win check
    if (board[2][3] == " ") {
        return false;

    } else if (board[1][2] == board[2][3] && board[2][3] == board[3][4]) {
        return true;

    } else if (board[3][2] == board[2][3] && board[2][3] == board[1][4]) {
        return true;
    }

    return false;
}


//check for a draw/tie
bool BoardSetUp::draw(){
    ++movesMade;
    return (movesMade == 9 || this->done());
}


//asking user for their move which will be xCoord and yCoord
int BoardSetUp::turnPrompt(unsigned int& x, unsigned int& y) {
    std::string input;

    while (true) {
        // prompts and read in user input
        std::cout << "Enter coordinates of next move or quit to quit" << std::endl;
        std::getline(std::cin, input);
        input.erase(remove_if(input.begin(), input.end(), isspace), input.end());

        // checks to see whether the user typed quit
        if (input == "quit") {
            return quit;
        }

        //parsing input
        std::stringstream ss(input);
        char comma;
        unsigned int tempX, tempY;

        // Read and validate format
        if (ss >> tempX >> comma >> tempY && comma == ',' && ss.eof()) {
            // Check if coordinates are within range
            if (1 <= tempX && tempX <= 3 && 1 <= tempY && tempY <= 3) {
                x = tempX;
                y = tempY;
                return 0;
            } else {
                std::cout << "Coordinates not valid" << std::endl;
            }
        } else {
            std::cout << "Invalid command" << std::endl;
        }
    }
}

int BoardSetUp::turn() {

    // if the player wants auto play, only this portion of the code runs
    if (autoPlay && trackPlayer == "O") {
        auto_player();
        trackPlayer = "X";
        return 0;
    }

    std::cout << std::endl;
    std::cout << "Player " << trackPlayer << "'s turn" << std::endl;

    //If it's player "O", call the random_move function
    if (trackPlayer == "O") {
        random_move();
    } else {
    //
        unsigned int tempX, tempY;

        while (true) {
            if (turnPrompt(xCoord, yCoord) == quit) {
                return quit;
            }

            // Determine tempX based on xCoord
            tempX = xCoord;
            tempY = yCoord + 1;

            // Set board position if it's empty
            if (board[tempX][tempY] == " ") {
                board[tempX][tempY] = trackPlayer;
                break;
            } else {
                std::cout << "Coordinates have already been played" << std::endl;
            }
        }
    }

    // Output the board
    printBoard();

    // Update moves and display them
    updatePlayerMoves();

    // Alternate the player's turn
    trackPlayer = (trackPlayer == "X") ? "O" : "X";

    return 0;
}

int BoardSetUp::play() {
    // Print initial board
    std::cout << *this;  // Print the board using the overloaded operator

    // Main game loop
    while (true) {
        // Process the player's turn
        if (turn() == quit) {
            std::cout << movesMade << " turn(s) have been made." << std::endl;
            std::cout << "Player " << trackPlayer << " has decided to quit" << std::endl;
            return quit;
        }

        // Check for a win after the last move
        if (done()) {
            std::cout << "Player " << ((trackPlayer == "X") ? "O" : "X") << " has won!" << std::endl;
            return 0;
        }

        // Check for a draw after each move
        if (draw()) {
            std::cout << movesMade << " turns have been made but no winner." << std::endl;
            return tie;
        }

        // Print the updated board after the move
        std::cout << *this;
    }
}


//check for both a possible block or a hopeless loss
bool BoardSetUp::checkWinOpportunity(const std::string& playerMove) {
    for (int i = 1; i < 4; ++i) {
        for (int j = 2; j < 5; ++j) {
            if (board[i][j] == " ") {
                board[i][j] = playerMove;
                if (this->done()) {
                    board[i][j] = " "; // Reset the board
                    return true; // Winning move found
                }
                board[i][j] = " "; // Reset the board
            }
        }
    }
    return false; // No winning move found
}

// creates an automatic player
void BoardSetUp::auto_player() {
    //checking whether player or computer will win
    if (possWin()) {
        std::cout << "Auto is winning" << std::endl;
    } else if (preventWin()) {
        std::cout << "Auto has blocked" << std::endl;
    } else {
        random_move();
        std::cout << "Auto has randomly moved" << std::endl;
    }

    //print out the board
   printBoard();
}


//in case there's no options left for a computer win
void BoardSetUp::random_move() {
    // Seed the random number generator with the current time
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }

    while (true) {
        // Generate random row and column indices for the move
        int randRow = 1 + (rand() % 3);
        int randCol = 2 + (rand() % 3);

        // Check if current position is empty
        if (board[randRow][randCol] == " ") {
            board[randRow][randCol] = "O";
            std::cout << "Player O placed at: " << randRow << "," << randCol - 1 << std::endl;
            break;
        }
    }
}

//let computer win
bool BoardSetUp::possWin(){
    return checkWinOpportunity("O");
}

//let computer block player's win
bool BoardSetUp::preventWin() {
    return checkWinOpportunity("X");
}
