cmake_minimum_required(VERSION 3.14)
project(C_Tutorials C)

set(CMAKE_C_STANDARD 99)

add_executable(C_Tutorials DieRoll.c ShuffleDeck.c)
add_executable(ShuffleDeck ShuffleDeck.c)
add_executable(DieRoll DieRoll.c)