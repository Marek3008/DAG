COMPILER = g++
CFLAGS = -Wall -std=c++17

SRC = main.cpp src/Graph/Graph.cpp src/Vertex/Vertex.cpp

main: $(SRC)
	$(COMPILER) $(CFLAGS) $(SRC) -o main