#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include "IO.h"
#include "Logic.h"
#include "Minimax.h"

int main() {
    vector<vector<int>> board
    {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };
    Minimax ai (board);
    tuple<int, int> player_move (0, 0);
    bool player = true;
    while (true) {
        tuple<bool, int> temp_2 = Logic::hasWon(board);
        IO::printBoard(board);
        if (!get<0>(temp_2)) {
            cout << "=== Player " << player << " ===" << endl;
            if (player) {
                player_move = IO::getUserValue();
                if (Logic::isValidMove(player_move, board)) {
                    board = Logic::placeMove(player_move, board, player);
                    ai.updateBoard(player_move, player);
                    player = false;
                } else {
                    cout << "Invalid move, try again" << endl;
                }
            } else {
                cout << "AI" << endl;
                board = ai.runMinimax(2);
                player = true;
            }
        } else {
            cout << "=== PLAYER " << get<1>(temp_2) << " HAS WON ===" << endl;
            break;
        }
    }
    return 0;
}