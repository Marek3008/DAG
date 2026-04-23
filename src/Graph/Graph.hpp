#pragma once

#include "../Vertex/Vertex.hpp"
#include <vector>


class Graph{
    private:
        std::vector<Vertex*> vertices;

    public:
        void Insert(int v);
        bool AddEdge(int v1, int v2);

        Vertex* GetVertex(int v) const;
        std::vector<Vertex*> GetVertices() const;
        int GetVerticesCount() const;
        
        void PrintVertices() const;
        void PrintEdges() const;
};