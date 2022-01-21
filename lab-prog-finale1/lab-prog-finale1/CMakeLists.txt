cmake_minimum_required (VERSION 3.2 FATAL_ERROR)

project ("scacchiera")

set(CMAKE_CXX_FLAGS_RELEASE "-O2")

include_directories (h)

add_executable(scacchiera
    src/scacchiera-main.cpp
    src/computer.cpp
    src/alfiere.cpp
    src/cavallo.cpp
    src/middlePieces.cpp
    src/re.cpp
    src/regina.cpp
    src/scacchiera.cpp
    src/scacco.cpp
    src/torre.cpp
    src/traduttore.cpp
    src/randomMoves.cpp
    src/document.cpp
    src/scaccomatto.cpp
 )
 
add_executable(replay
    src/replay.cpp
    src/alfiere.cpp
    src/cavallo.cpp
    src/re.cpp
    src/regina.cpp
    src/scacchiera.cpp
    src/torre.cpp
    src/traduttore.cpp
    src/document.cpp
 )
