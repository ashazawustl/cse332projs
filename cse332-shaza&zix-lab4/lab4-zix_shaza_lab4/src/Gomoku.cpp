//
// Created by Shaza Ali on 01/11/2024.
//
#include "Gomoku.h"
#include "GameBase.h"
#include "enums.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

GomokuGame::GomokuGame(int boardDim) : GameBase(boardDim, boardDim) {
    this->boardDim = boardDim-1;
    for (int i = 1; i < boardDim; i++) {
        for (int j = 1; j < boardDim; j++) {
            board[i][j] = " ";  // Initialize each cell to empty string
        }
    }
}

GomokuGame::~GomokuGame(){
}

//need to complete
bool GomokuGame::done() {
    const auto& gameBoard =  getBoard();
    unsigned int xcoord = getWidth();
    unsigned int ycoord = getHeight();

    for (unsigned int a = 1; a < ycoord; ++a) {
        for (unsigned int b = 1; b < xcoord; ++b) {
            if (gameBoard[a][b] != " ") { // Check for non-empty cells
                string stone = gameBoard[a][b]; // Store the current player's stone
                unsigned int key = 1; // Initialize count of connected stones

                // Check horizontal
                for (key = 1; key < numWin && (b + key) < xcoord && gameBoard[a][b + key] == stone; ++key);
                if (key == numWin) return true;

                // Reset key for vertical check
                key = 1;

                // Check vertical
                for (key = 1; key < numWin && (a + key) < ycoord && gameBoard[a + key][b] == stone; ++key);
                if (key == numWin) return true;

                // Reset key for left diagonal check
                key = 1;

                // Check left diagonal
                for (key = 1; key < numWin && (a + key) < ycoord && (b + key) < xcoord && gameBoard[a + key][b + key] == stone; ++key);
                if (key == numWin) return true;

                // Reset key for right diagonal check
                key = 1;

                // Check right diagonal
                for (key = 1; key < numWin && (a >= key) && (b + key) < xcoord && gameBoard[a - key][b + key] == stone; ++key);
                if (key == numWin) return true;
            }
        }
    }
    return false; // No winner found

}

bool movesRemaining(const vector<vector<string>>& board, int dim, bool playerXTurn, unsigned int numWin) {
    //set up the pieces for checking things
    string white_game_piece = "W";
    string black_game_piece = "B";

    string current_game_piece = white_game_piece;
    string other_game_piece = black_game_piece;
    if (playerXTurn)
    {
        current_game_piece = black_game_piece;
        other_game_piece = white_game_piece;
    }

    int boardDim = board.size();

    //get total number of empty spaces on the board at this moment
    int emptySpaceCount = 0;
    for (unsigned int a = 1; a < boardDim; ++a)
    {
        for (unsigned int b = 1; b < boardDim; ++b)
        {
            if (board[a][b] == " ")
            {
                emptySpaceCount++;
            }
        }
    }

    //checking if there are any segments of 5 with winning potential on the board
    for (unsigned int a = 1; a < boardDim; ++a) {
        for (unsigned int b = 1; b < boardDim; ++b) {
            if (board[a][b] == current_game_piece || board[a][b] == " ") {
                // Check horizontal
                int count = 1;  // Start from 1 to include the initial cell
                int lineEmptySpace = 0;

                //check any segment of 5
                for (int key = 1; key < numWin && (b + key) < boardDim; ++key) {
                    if (board[a][b + key] == " ") {
                        ++lineEmptySpace;
                        ++count;
                    }
                    else if (board[a][b + key] == current_game_piece){
                        ++count;
                    }
                    else {
                        break;  // invalid segment, exit the loop
                    }
                }
                //if there are 5 valid slots that can potentially win and if there are enough total empty spaces for
                //both players to place their pieces until the 5 slots are filled with one player's pieces
                if (count == numWin && emptySpaceCount && emptySpaceCount >= lineEmptySpace* - 1) return true;

                // Check vertical
                count = 1;  // Start from 1 to include the initial cell
                lineEmptySpace = 0;
                for (int key = 1; key < numWin && (a + key) < boardDim; ++key) {
                    if (board[a + key][b] == " ")
                    {
                        ++lineEmptySpace;
                        ++count;
                    }
                    else if (board[a + key][b] == current_game_piece) {
                        ++count;
                    } else {
                        break;  // Invalid cell, exit the loop
                    }
                }
                if (count == numWin && emptySpaceCount && emptySpaceCount >= lineEmptySpace*2 - 1) return true;

                // Check left diagonal
                count = 1;  // Start from 1 to include the initial cell
                lineEmptySpace = 0;
                for (int key = 1; key < numWin && (a + key) < boardDim && (b + key) < boardDim; ++key) {
                    if (board[a + key][b + key] == " ")
                    {
                        ++lineEmptySpace;
                        ++count;
                    }
                    else if (board[a + key][b + key] == current_game_piece) {
                        ++count;
                    } else {
                        break;  // Invalid cell, exit the loop
                    }
                }
                if (count == numWin && emptySpaceCount && emptySpaceCount >= lineEmptySpace*2 - 1) return true;

                // Check right diagonal
                count = 1;  // Start from 1 to include the initial cell
                lineEmptySpace = 0;
                for (int key = 1; key < numWin && (a >= key) && (b + key) < boardDim; ++key) {
                    if (board[a - key][b + key] == " ")
                    {
                        ++lineEmptySpace;
                        ++count;
                    }
                    else if (board[a - key][b + key] == current_game_piece) {
                        ++count;
                    } else {
                        break;  // Invalid cell, exit the loop
                    }
                }
                if (count == numWin && emptySpaceCount && emptySpaceCount >= lineEmptySpace*2 - 1) return true;
            }
        }
    }
    // no more winning moves remain since no segment of 5 have winning potential
    return false;
}

bool GomokuGame::draw() {
    return !(this->done() || movesRemaining(this->board, this->boardDim, this->playerXTurn, this->numWin));
}


int GomokuGame::turn() {
    cout << (playerXTurn ? "Player B's turn!" : "Player W's turn!") << endl;
    int boardDim = this->boardDim;

    string B_pawn = displayPieces[0];
    string W_pawn = displayPieces[1];

    unsigned int x, y;
    while (true) {
        int status = this->prompt(x, y);
        if (status == read_move_success && x < boardDim + 1 && y < boardDim + 1 && x > 0 && y > 0 && board[x][y] == " ") {
            cout << x << ", " << y << endl;
            string currentPiece = playerXTurn ? B_pawn : W_pawn;
            cout << board[x][y] << endl;
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
    cout << *this << endl;
    return playerXTurn ? o_valid_move : x_valid_move;
}

void GomokuGame::print()
{
    cout << *this;
}

ostream& operator<<(ostream& osRef, const GomokuGame& gameRef) {
    int boardDim = gameRef.boardDim;

    for(int i = boardDim; i >= 1; i--)
    {
        if (i <= 9)
        {
            osRef << "0";
        }
        osRef << i << " "; //print the y coordinate indicators at left side
        for(int j = 1; j < boardDim + 1; j++)
        {
            osRef << gameRef.board[j][i];
            osRef << "  ";
        }
        osRef << endl;
    }
    osRef << "X ";
    //print the x coordinate indicators at the bottom
    for (int k = 1; k < boardDim + 1; k++)
    {
        if (k <= 9)
        {
            osRef << " " << "0" << k;
        }
        else
        {
            osRef << " " << k;
        }
    }
    cout << endl;
    return osRef;
}