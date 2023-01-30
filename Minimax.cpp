//
// Created by Pranav C on 27/01/2023.
//

#include "Minimax.h"
#include <iostream>
#include <vector>
#include "Logic.h"
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
    int result = this->minimax(0, false, player);
    vector<vector<int>> temp;
    return temp;
}

int Minimax::minimax(int depth, bool isMax, int player) {
    int state = weightWinCons();
    return state;
}

bool Minimax::movesLeft() {
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
