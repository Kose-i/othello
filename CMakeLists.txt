cmake_minimum_required(VERSION 3.5.1)
project(othello LANGUAGES CXX)

SET(CMAKE_CXX_STANDARD 14)

include_directories(include)

#add_executable(init_study
#    src/init_study.cpp
#    src/Game.cpp
#    src/Board.cpp
#    src/Hand.cpp
#    src/Computer.cpp
#    src/Point.cpp
#    src/CalcCost.cpp
#)

add_executable(main
    src/main.cpp
    src/Game.cpp
    src/Board.cpp
    src/Hand.cpp
    src/Computer.cpp
    src/Point.cpp
    src/Player.cpp
    src/CalcCost.cpp
)
