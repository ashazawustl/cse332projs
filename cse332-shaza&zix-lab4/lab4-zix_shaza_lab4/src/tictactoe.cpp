//
// Created by Zix on 2024/10/23.
//

/*
 *tictactoe.cpp
 *created by Zix Chen c.zixin@wustl.edu
 *is the source file for the tictactoe.h
 *provides the behavior of the tictactoe class, a simple tictactoe game
 */

#include "GameBase.h"
#include "enums.h"
#include "tictactoe.h"
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

TicTacToeGame::TicTacToeGame() : GameBase(5, 5) {
    // Initialize 3x3 board with empty strings
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = " ";  // Initialize each cell to empty string
        }
    }
    //TicTacToeGame::print(); // display board
}

//destructor for TicTaToe
TicTacToeGame::~TicTacToeGame() {

}

//prints the board to the overloaded ostream
void TicTacToeGame::print() {
    cout << *this;
}

//overloaded ostream operator for the game printing
ostream& operator<<(ostream& osRef, const TicTacToeGame& gameRef) {
    int boardWidth = gameRef.getWidth();

    //print the board coordinates in correct order
    for(int i = boardWidth - 1; i >= 0; i--)
    {
        osRef << i << " "; //print the y coordinate indicators at left side
        for(int j = 0; j < boardWidth; j++)
        {
            osRef << gameRef.getBoard()[j][i];
            osRef << " ";
        }
        osRef << endl;
    }
    osRef << " ";
    //print the x coordinate indicators at the bottom
    for (int k = 0; k < boardWidth; k++)
    {
        osRef << " " << k;
    }

    osRef << endl;
    return osRef; //for repeatedly calling the << operator
}

bool TicTacToeGame::done() {
    int boardWidth = this->width;

    //check if there are 3 pieces of the same type in a row
    for (int i = 1; i < boardWidth-1; i++) {
        //rows in the inner 3x3 grid
        string piece = " ";
        bool threeInARow = true;
        for (int j = 1; j < boardWidth-1; j++)
        {
            if (piece == " ")
            {
                piece = board[i][j];
            }
            if (board[i][j] != piece || board[i][j] == " ")
            {
                //there is an empty space or the other player's piece
                threeInARow = false;
                break;
            }
        }
        if (threeInARow)
        {
            //all 3 slots checked were one player's piece
            return true;
        }

        //columns in the inner 3x3 grid
        piece = " ";
        threeInARow = true;
        for (int j = 1; j < boardWidth-1; j++)
        {
            if (piece == " ")
            {
                piece = board[j][i];
            }
            if (board[j][i] != piece || board[j][i] == " ")
            {
                threeInARow = false;
                break;
            }
        }
        if (threeInARow)
        {
            return true;
        }
    }

    //check diagonal 1
    string piece = " ";
    bool threeInARow = true;
    for (int i = 1; i < boardWidth-1; i++)
    {
        if (piece == " ")
        {
            piece = board[i][i];
        }
        if (board[i][i] != piece || board[i][i] == " ")
        {
            threeInARow = false;
            break;
        }
    }
    if (threeInARow)
    {
        return true;
    }

    //check diagonal 2
    piece = " ";
    threeInARow = true;
    int i = boardWidth-1;
    int j = 1;
    while (i > 0 && j < boardWidth)
    {
        if (piece == " ")
        {
            piece = board[i][j];
        }
        if (board[i][j] != piece || board[i][j] == " ")
        {
            threeInARow = false;
            break;
        }
        --i;
        ++j;
    }
    if (threeInARow)
    {
        return true;
    }
    //no 3 pieces in a row found
    return false;
}

bool movesRemaining(const vector<vector<string>>& board) {
    int boardWidth = board.size();

    unsigned int emptySpaces = 0;

    for (int i = 0; i < boardWidth-1; i++)
    {
        for (int j = 0; j < boardWidth-1; j++)
        {
            if (board[i][j] == " ")
            {
                //count the total number of empty spaces on the board
                ++emptySpaces;
            }
        }
    }
    //check if there are 3 pieces of the same type in a row
    for (int i = 1; i < boardWidth-1; i++) {
        //rows in the inner 3x3 grid
        string piece = " ";
        bool winningPotential = true;
        int lineSpaceCount = 0;
        for (int j = 1; j < boardWidth-1; j++)
        {
            if (piece == " ")
            {
                piece = board[i][j];
            }
            if (board[i][j] != piece || board[i][j] != " ")
            {
                winningPotential = false;
                break;
            }
            if (board[i][j] == " ")
            {
                //for checking how many empty slots are on the line of 3 slots
                ++lineSpaceCount;
            }
        }
        if (winningPotential && emptySpaces > lineSpaceCount*2)
        {
            //if the line could be a winning line and there is enough space for both players to play until the line is a winning line
            return true;
        }

        //columns in the inner 3x3 grid
        piece = " ";
        winningPotential = true;
        lineSpaceCount = 0;
        for (int j = 1; j < boardWidth-1; j++)
        {
            if (piece == " ")
            {
                piece = board[j][i];
            }
            if (board[j][i] != piece || board[j][i] != " ")
            {
                winningPotential = false;
                break;
            }
            if (board[j][i] == " ")
            {
                //for checking how many empty slots are on the line of 3 slots
                ++lineSpaceCount;
            }
        }
        if (winningPotential && emptySpaces > lineSpaceCount*2){
            //if the line could be a winning line and there is enough space for both players to play until the line is a winning line
            return true;
        }
    }

    //check diagonal 1
    string piece = " ";
    bool winningPotential = true;
    int lineSpaceCount = 0;
    for (int i = 1; i < boardWidth-1; i++)
    {
        if (piece == " ")
        {
            piece = board[i][i];
        }
        if (board[i][i] != piece || board[i][i] != " ")
        {
            winningPotential = false;
            break;
        }
        if (board[i][i] == " ")
        {
            ++lineSpaceCount;
        }
    }
    if (winningPotential && emptySpaces > lineSpaceCount*2)
    {
        //if the line could be a winning line and there is enough space for both players to play until the line is a winning line
        return true;
    }

    //check diagonal 2
    piece = " ";
    winningPotential = true;
    lineSpaceCount = 0;
    int i = boardWidth-1;
    int j = 1;
    while (i > 0 && j < boardWidth)
    {
        if (piece == " ")
        {
            piece = board[i][j];
        }
        if (board[i][j] != piece || board[i][j] != " ")
        {
            winningPotential = false;
            break;
        }
        if (board[i][j] == " ")
        {
            ++lineSpaceCount;
        }
        --i;
        ++j;
    }
    if (winningPotential && emptySpaces > lineSpaceCount*2)
    {
        //if the line could be a winning line and there is enough space for both players to play until the line is a winning line
        return true;
    }
    //no line with winning potential
    return false;
}

bool TicTacToeGame::draw() {
    return !(this->done() || movesRemaining(this->board));
}

int TicTacToeGame::turn() {
    cout << (playerXTurn ? "Player X's turn!" : "Player O's turn!") << endl;

    unsigned int x, y;
    while (true) {
        int status = prompt(x, y);
        if (status == read_move_success && x < width-1 && y < height-1 && x > 0 && y > 0 && board[x][y] == " ") {
            string currentPiece = playerXTurn ? X_pawn : O_pawn;
            board[x][y] = currentPiece;
            updateVariables(currentPiece);
            (playerXTurn ? XValidMoves : OValidMoves).push_back(make_tuple(currentPiece, x, y));
            playerXTurn = !playerXTurn;
            break;
        } else if (status == quit_game) {
            return quit_game;
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
    cout << *this << endl; //prints the board for the user
    cout << "Player X: "; //show player X valid moves so far
    for (const auto& move : XValidMoves) {
        cout << get<1>(move) << ", " << get<2>(move) << "; ";
    }
    cout << endl;
    cout << "Player O: "; //show player X valid moves so far
    for (const auto& move : OValidMoves) {
        cout << get<1>(move) << ", " << get<2>(move) << "; ";
    }
    cout << endl;
    return playerXTurn ? o_valid_move : x_valid_move;
}