#pragma once

#include <vector>


class Vertex{
    public:
        enum State {UNVISITED, VISITING, VISITED};
    
    private:
        int value;
        State state;
        std::vector<Vertex*> edges;

    public:
        Vertex(int value) : value(value), state(UNVISITED) {}

        void AddEdge(Vertex* vertex);
        void SetState(State s);

        int GetValue() const;
        State GetState() const;
        std::vector<Vertex*> GetEdges() const;
        
        void PrintEdges() const;
};