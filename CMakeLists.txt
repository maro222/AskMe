cmake_minimum_required(VERSION 3.23)
project(AskMe)

set(CMAKE_CXX_STANDARD 14)

add_executable(AskMe main.cpp global.h Menu.cpp Login.cpp list_users.cpp prints_questions_to_me.cpp prints_questions_from_me.cpp Answer_questions.cpp delete_questions.cpp Ask_questions.cpp feed.cpp)
