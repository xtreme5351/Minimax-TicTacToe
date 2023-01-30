//
// Created by Pranav C on 27/01/2023.
//

#ifndef TICTACTOEC___MINIMAX_H
#define TICTACTOEC___MINIMAX_H
#include <utility>
#include <vector>
using namespace std;

class Minimax {
    private:
        int minimax(int depth, bool isMax, int player);
        bool movesLeft();

    public:
        vector<vector<int>> board;
        explicit Minimax(vector<vector<int>> board) {
            this->board = std::move(board);
        }
        [[nodiscard]] int weightWinCons() const;
        vector<vector<int>> runMinimax(int player);
        void updateBoard(tuple<int, int> &move, int player);
};


#endif //TICTACTOEC___MINIMAX_H
