//
// Created by Pranav C on 23/01/2023.
//

#include "Logic.h"
#include <list>
#include <vector>
using namespace std;

bool Logic::isValidMove(tuple<int, int> &move, vector<vector<int>> &board) {
    int x = get<0>(move);
    int y = get<1>(move);
    if (x >= 0 && x <= 2) {
        if (y >= 0 && y <= 2){
            if (board[x][y] == 0){
                return true;
            }
        }
    }
    return false;
}

vector<vector<int>> Logic::placeMove(tuple<int, int> &move, vector<vector<int>> &board, int player) {
    if (player == 0){
        player = 2;
    }
    board[get<0>(move)][get<1>(move)] = player;
    return board;
}

tuple<bool, int> Logic::hasWon(vector<vector<int>> board) {
    tuple<bool, int> final;
    int counter = 0;

    for (int i = 0; i < 3; i++){
        if (adjacent_find(board[i].begin(), board[i].end(), not_equal_to<>()) == board[i].end() && board[i][2] != 0)
        {
            get<0>(final) = true;
            get<1>(final) = board[i][2];
        }

        if (board[0][i] != 0) {
            if (board[0][i] == board[1][i]) {
                if (board[1][i] == board[2][i]) {
                    get<0>(final) = true;
                    get<1>(final) = board[2][i];
                }
            }
        }

        counter += static_cast<int>(count(board[i].begin(), board[i].end(), 0));
    }

    if (board[0][0] == board[1][1] && board[0][0] != 0){
        if (board[1][1] == board[2][2]){
            get<0>(final) = true;
            get<1>(final) = board[2][2];
        }
    }

    if (board[0][2] == board[1][1] && board[0][2] != 0){
        if (board[1][1] == board[2][0]){
            get<0>(final) = true;
            get<1>(final) = board[2][0];
        }
    }

    if (counter == 0){
        get<0>(final) = true;
        get<1>(final) = -1;
    }
    return final;
}
