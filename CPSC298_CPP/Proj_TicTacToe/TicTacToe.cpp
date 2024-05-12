#include <iostream> 
#include <string>
using namespace std;
#include "TicTacToe.h"


TicTacToe::TicTacToe(){
    pp_cGrid = new char* [3];
    for(int row = 0; row < 3; row++){
        pp_cGrid[row] = new char[3];
        for(int column = 0; column < 3; column++){
            pp_cGrid[row][column] = '~';
        }
    }
}

TicTacToe::~TicTacToe(){
    for(int i = 0; i < 3; i++){
        delete[] pp_cGrid[i];
    }
    delete[] pp_cGrid;
}

void TicTacToe::display(){
    for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            cout << pp_cGrid[row][column];
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void TicTacToe::playerTurn(){
    int row;
    int column;

    while(true){
        cout << "Please enter grid row number: " << endl;
        cin >> row;
        while(row < 0 || row > 2){
            cout << "The grid row number should be 0, 1, or 2." << endl;
            cout << "Please enter grid row number:" << endl;
            cin >> row;

        }
        cout << "Please enter grid column number: " << endl;
        cin >> column;
        while(column < 0 || column > 2){
            cout << "The grid column number should be 0, 1, or 2." << endl;
            cout << "Please enter grid column number:" << endl;
            cin >> column;
        }

        if(pp_cGrid[row][column] != '~'){
            cout << "The grid square [" << row << "][" << column << "] is already taken." << endl;
        }

        if(pp_cGrid[row][column] == '~'){
            pp_cGrid[row][column] = 'X';
            display();
            return;
        }
    }
}

void TicTacToe::computerTurn(){
    for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            if(pp_cGrid[row][column] == '~'){
                pp_cGrid[row][column] = 'O';
                display();
                return;
            }
        }
    }
}

bool TicTacToe::playerWin(){
    for(int row = 0; row < 3; row++){
        if(pp_cGrid[row][0] == 'X' && pp_cGrid[row][1] == 'X' && pp_cGrid[row][2] == 'X'){
            return true;
        }
    }
    for(int column = 0; column < 3; column++){
        if(pp_cGrid[0][column] == 'X' && pp_cGrid[1][column] == 'X' && pp_cGrid[2][column] == 'X'){
            return true;
        }
    }
    if(pp_cGrid[0][0] == 'X' && pp_cGrid[1][1] == 'X' && pp_cGrid[2][2] == 'X'){
        return true;
    }
    if(pp_cGrid[2][0] == 'X' && pp_cGrid[1][1] == 'X' && pp_cGrid[0][2] == 'X'){
        return true;
    }
    
    return false;
}

bool TicTacToe::computerWin(){
    for(int row = 0; row < 3; row++){
        if(pp_cGrid[row][0] == 'O' && pp_cGrid[row][1] == 'O' && pp_cGrid[row][2] == 'O'){
            return true;
        }
    }
    for(int column = 0; column < 3; column++){
        if(pp_cGrid[0][column] == 'O' && pp_cGrid[1][column] == 'O' && pp_cGrid[2][column] == 'O'){
            return true;
        }
    }
    if(pp_cGrid[0][0] == 'O' && pp_cGrid[1][1] == 'O' && pp_cGrid[2][2] == 'O'){
        return true;
    }
    if(pp_cGrid[2][0] == 'O' && pp_cGrid[1][1] == 'O' && pp_cGrid[0][2] == 'O'){
        return true;
    }
    
    return false;
}

bool TicTacToe::draw(){
    for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            if(pp_cGrid[row][column] == '~'){
                return false;
            }
        }
    }
    return true;
}

void TicTacToe::play(){
    cout << "Tic Tac Toe" << endl;
    cout << "The top row is row number 0, the middle row is row number 1, and the botttom row is row number 2." << endl;
    cout << "The left column is column number 0, the middle column is column number 1, and the right column is column number 2." << endl;
    display();

    while(true){
        playerTurn();

        if(playerWin()){
            cout << "WINNER: X!" << endl;
            cout << "Game over." << endl;
            return;
        }

        computerTurn();

        if(computerWin()){
            cout << "WINNER: O!" << endl;
            cout << "Game over." << endl;
            return;
        }

        if(draw()){
            cout << "Draw!" << endl;
            cout << "Game over." << endl;
            return;
        }
    }
}