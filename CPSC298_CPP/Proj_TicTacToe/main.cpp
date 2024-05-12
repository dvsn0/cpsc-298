#include "TicTacToe.h"

int main(){
    TicTacToe* p_game = new TicTacToe();
    p_game->play();
    delete p_game;
    return 0;
}