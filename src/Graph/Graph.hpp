#pragma once

#include "../Vertex/Vertex.hpp"
#include <vector>


/**
 * @class Graph
 * @brief Represents a directed graph and provides algorithms for DAG analysis and topological sorting.
 */
class Graph{
    private:
        std::vector<Vertex*> vertices;
        std::vector<Vertex*> order;

        
        /**
         * @brief Helper function that performs a Depth First Search to detect cycles.
         * @param vertex The current vertex being explored.
         * @return true if a cycle is detected from this path.
         */
        bool HasCycle(Vertex* vertex);
        
        /**
         * @brief Recursive helper for the topological sort algorithm.
         * @param v The current vertex being visited.
         * @param order Reference to the vector where the sort order is being constructed.
         */
        void TopologicalSortHelper(Vertex* vertex, std::vector<Vertex*>& order);

    public:
        ~Graph();

        
        /**
         * @brief Adds a directed edge between two existing vertices.
         * @param v1 The value of the source vertex.
         * @param v2 The value of the destination vertex.
         * @return true if the edge was added, false if a vertex was missing or the edge already exists.
         */
        bool AddEdge(int v1, int v2);
        
        /**
         * @brief Inserts a new vertex into the graph.
         * @note If a vertex with the value @p v already exists, the operation is ignored.
         * @param v The integer value to be stored in the new vertex.
         */
        void Insert(int v);

        /**
         * @brief Determines if the graph is a Directed Acyclic Graph (DAG).
         * @details Internally runs a DFS to check for back-edges (cycles).
         * @return true if the graph has no cycles, false otherwise.
         */
        bool IsDAG();

        /**
         * @brief Transforms the graph into a Complete DAG (Tournament).
         * @details Sorts the graph topologically and then adds directed edges between 
         * every pair of vertices (u, v) where u appears before v in the sort order.
         */
        void MakeCompleteDAG();

        /**
         * @brief Resets the visit state of all vertices to UNVISITED.
         * @details Typically called before starting a traversal like DFS or Topological Sort.
         */
        void ResetStates();
        
        /**
         * @brief Performs a Topological Sort on the graph.
         * @details Populates the internal 'order' vector such that for every directed edge (u, v), 
         * vertex u comes before v. Requires the graph to be a DAG.
         */
        void TopologicalSort();

        /**
         * @brief Calculates the maximum possible edges for a simple directed graph with no cycles.
         * @return The value of n(n-1)/2, where n is the number of vertices.
         */
        int GetExpectedEdgesCount() const;
        
        
        Vertex* GetVertex(int v) const;
        std::vector<Vertex*> GetVertices() const;
        int GetVerticesCount() const;
        int GetEdgesCount() const;

        void PrintVertices() const;
        void PrintEdges() const;
        void PrintTopologicalOrder();
};