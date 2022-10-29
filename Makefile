CXX = g++
CXXFLAGS = -g -Wall -Werror -std=c++17

all: play

play: play.o board.o chess.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf *.o *.so play
