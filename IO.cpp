//
// Created by Pranav C on 23/01/2023.
//

#include "IO.h"
#include <iostream>
#include <vector>
using namespace std;

tuple<int, int> IO::getUserValue() {
    cout << "Enter next row and col" << endl;
    string input;
    cin >> input;
    tuple<int, int> final (stoi(input.substr(0, 1)), stoi(input.substr(1, 1)));
    return final;
}

void IO::printBoard(vector<vector<int>> board) {
    for (int y = 0; y < 3; y++){
        for (int x = 0; x < 3; x++) {
            cout << "|" << board[y][x];
        }
        cout << endl;
    }
}
