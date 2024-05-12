#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe{
    private:
        char** pp_cGrid;

    public:
        TicTacToe();
        ~TicTacToe();

        void display();
        void playerTurn();
        void computerTurn();
        bool playerWin();
        bool computerWin();
        bool draw();
        void play();
};
#endif
