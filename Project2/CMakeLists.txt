cmake_minimum_required(VERSION 3.0)


project(PRINT) # change project name

set(CMAKE_CXX_STANDARD 17)

include_directories(includes/ utils/)

set(SOURCE

src/project2.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})

