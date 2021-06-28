cmake_minimum_required(VERSION 3.15)
project(ultimateTerminalChess)

set(CMAKE_CXX_STANDARD 17)

add_executable(ultimateTerminalChess main.cpp
        Field.cpp Field.h
        Board.cpp Board.h
        King.cpp King.h
        Queen.cpp Queen.h
        Knight.cpp Knight.h
        Rook.cpp Rook.h
        Pawn.cpp Pawn.h
        Bishop.cpp Bishop.h
        Empty.cpp Empty.h
        )