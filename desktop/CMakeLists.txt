cmake_minimum_required(VERSION 3.16)

project(SKTPassMan)

add_executable(Man src/main.cpp 
    src/Account.cpp
    src/Accounts.cpp
    src/Application.cpp
)
