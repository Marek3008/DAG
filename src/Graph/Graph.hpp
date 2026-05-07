#pragma once

#include "../Vertex/Vertex.hpp"
#include <vector>


class Graph{
    private:
        std::vector<Vertex*> vertices;
        std::vector<Vertex*> order;

        bool HasCycle(Vertex* vertex);
        void TopologicalSortHelper(Vertex* v, std::vector<Vertex*>& order);

    public:
        void Insert(int v);
        bool AddEdge(int v1, int v2);
        void ResetStates();
        bool IsDAG();
        void TopologicalSort();
        void MakeCompleteDAG();
        
        Vertex* GetVertex(int v) const;
        std::vector<Vertex*> GetVertices() const;
        int GetVerticesCount() const;
        int GetEdgesCount() const;
        int GetExpectedEdgesCount() const;
        
        void PrintVertices() const;
        void PrintEdges() const;
        void PrintTopologicalOrder();
};