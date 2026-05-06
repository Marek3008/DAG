#pragma once

#include "../Vertex/Vertex.hpp"
#include <vector>


class Graph{
    private:
        std::vector<Vertex*> vertices;
        bool HasCycle(Vertex* v);

    public:
        void Insert(int v);
        bool AddEdge(int v1, int v2);
        void ResetStates();
        
        Vertex* GetVertex(int v) const;
        std::vector<Vertex*> GetVertices() const;
        int GetVerticesCount() const;
        int GetEdgesCount() const;
        int GetExpectedEdgesCount() const;
        bool IsDAG();
        
        void PrintVertices() const;
        void PrintEdges() const;
};