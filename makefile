SRC_DIR = src
SRC_FILES = main.cpp $(SRC_DIR)/*.cpp
OUTPUT = bin/play
INCLUDE_DIRS = -I/opt/homebrew/include -Iinclude
LIB_DIRS = -L/opt/homebrew/lib
LIBS = -lSDL2 -lSDL2_image
CXXFLAGS = -std=c++11 -Wall -Wextra

main:
	 g++ $(CXXFLAGS) $(SRC_FILES) -o $(OUTPUT) $(INCLUDE_DIRS) $(LIB_DIRS) $(LIBS)
