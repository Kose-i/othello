cmake_minimum_required(VERSION 3.5.1)
project(othello LANGUAGES CXX)

include_directories(include)

add_executable(main
    src/main.cpp
    src/Game.cpp
    src/Board.cpp
    src/Hand.cpp
    src/Computer.cpp
    src/Point.cpp
    src/Player.cpp

    src/Hyoukakansuu.cpp
    src/Costmap1.cpp

)
