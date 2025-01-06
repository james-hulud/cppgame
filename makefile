SRC_DIR = src
SRC_FILES = main.cpp $(SRC_DIR)/*.cpp
OUTPUT = play
INCLUDE_DIRS = -I/opt/homebrew/include
LIB_DIRS = -L/opt/homebrew/lib
LIBS = -lSDL2
CXXFLAGS = -std=c++11 -Wall -Wextra

main:
	 g++ $(CXXFLAGS) $(SRC_FILES) -o $(OUTPUT) $(INCLUDE_DIRS) $(LIB_DIRS) $(LIBS)
