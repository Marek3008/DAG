#pragma once

#include <vector>


class Vertex{
    private:
        int value;
        std::vector<Vertex*> edges;

    public:
        Vertex(int value) : value(value) {}

        void AddEdge(Vertex* vertex);
        int GetValue() const;
        std::vector<Vertex*> GetEdges() const;
        void PrintEdges() const;
};