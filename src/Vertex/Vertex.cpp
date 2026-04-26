#include "Vertex.hpp"
#include <iostream>

void Vertex::AddEdge(Vertex* vertex){
    this->edges.push_back(vertex);
}

void Vertex::SetState(Vertex::State s){
    this->state = s;
}

int Vertex::GetValue() const {
    return this->value;
}

Vertex::State Vertex::GetState() const {
    return this->state;
}

std::vector<Vertex*> Vertex::GetEdges() const {
    return this->edges;
}

void Vertex::PrintEdges() const {
    std::cout << "  Vertex " << this->value << ":" << std::endl;

    for(auto edge : this->edges){
        std::cout << "    " << edge->GetValue() << std::endl;
    }
}