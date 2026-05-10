#pragma once

#include <vector>

/**
 * @class Vertex
 * @brief Represents an individual node in the graph.
 */
class Vertex {
    public:
        /**
         * @enum State
         * @brief Traversal states used for cycle detection and sorting.
         */
        enum State { UNVISITED, VISITING, VISITED };
    
    private:
        int value;            ///< The unique integer identifier for this vertex.
        State state;          ///< The current traversal status of the vertex.
        std::vector<Vertex*> neighbors; ///< Adjacency list storing pointers to connected vertices.

    public:
        /**
         * @brief Constructor to initialize a vertex with a value.
         * @param value The integer value for the vertex.
         */
        Vertex(int value) : value(value), state(UNVISITED) {}

        /**
         * @brief Adds a directed edge from this vertex to another.
         * @param vertex Pointer to the destination vertex.
         */
        void AddEdge(Vertex* vertex);

        /**
         * @brief Updates the traversal state of the vertex.
         * @param s The new state (UNVISITED, VISITING, or VISITED).
         */
        void SetState(State s);

        /**
         * @brief Retrieves the integer value of the vertex.
         * @return The vertex value.
         */
        int GetValue() const;

        /**
         * @brief Retrieves the current traversal state of the vertex.
         * @return The current State (UNVISITED, VISITING, or VISITED).
         */
        State GetState() const;

        /**
         * @brief Gets the list of neighboring vertices.
         * @return A vector containing pointers to all adjacent vertices.
         */
        std::vector<Vertex*> GetNeighbors() const;
        
        /**
         * @brief Prints the values of all neighbors to standard output.
         */
        void PrintNeighbors() const;
};