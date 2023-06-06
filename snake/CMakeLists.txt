cmake_minimum_required(VERSION 3.13)
project(snake)

set(PROJECT_ID snake)

set(SOURCE_FILES
        src/snake.cpp
        )

set(SOURCES_FILES_TESTS
        test/test_snake.cpp
        )

include(../SetCommonConfig.cmake)
