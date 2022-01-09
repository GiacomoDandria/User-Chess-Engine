cmake_minimum_required (VERSION 3.2 FATAL_ERROR)

project ("scacchiera")

include_directories (h)

add_executable(scacchiera
		src/scacchiera-main.cpp
		src/computer.cpp
		src/alfiere.cpp
		src/cavallo.cpp
		src/middlePieces.cpp
		src/pedone.cpp
		src/re.cpp
		src/regina.cpp
		src/scacchiera.cpp
		src/scacco.cpp
		src/torre.cpp
		src/traduttore.cpp
)