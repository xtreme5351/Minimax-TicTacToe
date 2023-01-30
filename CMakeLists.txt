cmake_minimum_required(VERSION 3.24)
project(TicTacToeC__)

set(CMAKE_CXX_STANDARD 20)

add_executable(TicTacToeC__ main.cpp IO.cpp IO.h Logic.cpp Logic.h Minimax.cpp Minimax.h)
