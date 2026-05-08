#pragma once

#include <vector>


/**
 * @class Vertex
 * @brief Represents an individual node in the graph.
 */
class Vertex{
    public:
        /**
         * @enum State
         * @brief Traversal states used for cycle detection and sorting.
         */
        enum State {UNVISITED, VISITING, VISITED};
    
    private:
        int value;
        State state;
        std::vector<Vertex*> neighbors;

    public:
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

        int GetValue() const;
        State GetState() const;
        std::vector<Vertex*> GetNeighbors() const;
        
        void PrintNeighbors() const;
};