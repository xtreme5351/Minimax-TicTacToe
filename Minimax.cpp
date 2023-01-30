//
// Created by Pranav C on 27/01/2023.
//

#include "Minimax.h"
#include <vector>
#include "Logic.h"
#include "IO.h"
using namespace std;

int Minimax::weightWinCons() const {
    tuple<bool, int> result = Logic::hasWon(this->board);
    if (get<0>(result)){
        if (get<1>(result) == 2){
            return 10;
        } else {
            return -10;
        }
    }
    return 0;
}

vector<vector<int>> Minimax::runMinimax(int player) {
    int best = -100;
    tuple<int, int> aiMove (0, 0);
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (this->board[y][x] == 0) {
                this->board[y][x] = player;
                int current_eval = this->minimax(0, false, player);
                if (current_eval > best) {
                    best = current_eval;
                    aiMove = {y, x};
                }
                this->board[y][x] = 0;
            }
        }
    }
    board[get<0>(aiMove)][get<1>(aiMove)] = 2;
    return this->board;
}

int Minimax::minimax(int depth, bool isMax, int player) {
    int state = weightWinCons();
//    IO::printBoard(this->board);
    if (state == 10 || state == -10) {
        return state;
    } else if (!this->movesLeft()) {
        return 0;
    }

    if (isMax){
        int best = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (this->board[i][j]== 0) {
                    this->board[i][j] = player;
                    best = max(best, minimax(depth+1, !isMax, player));
                    this->board[i][j] = 0;
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (this->board[i][j]== 0) {
                    this->board[i][j] = 1;
                    best = min(best, minimax(depth+1, !isMax, player));
                    this->board[i][j] = 0;
                }
            }
        }
        return best;
    }
}

[[maybe_unused]] bool Minimax::movesLeft() {
    for (int y = 0; y < 3; y++){
        for (int x = 0; x < 3; x++){
            if (this->board[y][x] == 0){
                return true;
            }
        }
    }
    return false;
}

void Minimax::updateBoard(tuple<int, int> &move, int player) {
    this->board[get<0>(move)][get<1>(move)] = player;
}
