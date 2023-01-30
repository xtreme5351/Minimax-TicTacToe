//
// Created by Pranav C on 23/01/2023.
//

#ifndef TICTACTOEC___LOGIC_H
#define TICTACTOEC___LOGIC_H
#include <list>
#include <vector>
#include "Minimax.h"
using namespace std;

class Logic {
public:
    static bool isValidMove(tuple<int, int> &move, vector<vector<int>> &board);
    static vector<vector<int>> placeMove(tuple<int, int> &move, vector<vector<int>> &board, int player);
    static tuple<bool, int> hasWon(vector<vector<int>> board);
};


#endif //TICTACTOEC___LOGIC_H
