//
// Created by Shaza Ali on 27/10/2024.
//

//This file acts like a Main.cpp but is named as such for clarity of function purposes

#include "TicTacToe.h"
#include <sstream>
#include<iostream>
#include <string>

//usage message
void Usage(){
    std::cout << "Correct usage is program_name TicTacToe" << std::endl;
    std::cout << "or specify auto_player at end of usage to play against computer" << std::endl;
}

//main functionality/execution
int main(int argc, char* argv[]) {

    if (argc == 2 && std::string(argv[1]) == "TicTacToe") {
        char choice;
        std::cout << "Would you like to play against the auto player? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            std::cout << "Initiated Auto Play" << std::endl;
            BoardSetUp autoGame(true);
            return autoGame.play();
        } else if (choice == 'n' || choice == 'N') {
            BoardSetUp noGame(false);
            return noGame.play();
        } else {
            std::cout << "Invalid choice. Exiting." << std::endl;
            return 1;  // Return a non-zero value to indicate an error
        }
    }else if (argc == 3 && argv[1]==std::string("TicTacToe") && argv[2]==std::string("auto_player")){
        std::cout << "Initiated Auto Play" << std::endl;
        BoardSetUp autoGame(true);
        return autoGame.play();
    }else {
        Usage();
        return 1;  // Return a non-zero value to indicate an error
    }
}