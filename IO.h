//
// Created by Pranav C on 23/01/2023.
//

#ifndef TICTACTOEC___IO_H
#define TICTACTOEC___IO_H
#include <list>
using namespace std;

class IO {
public:
    static tuple<int, int> getUserValue();
    static void printBoard(vector<vector<int>> board);
};


#endif //TICTACTOEC___IO_H
