#include "Graph.hpp"
#include <iostream>

void Graph::Insert(int v){
    if(GetVertex(v) != nullptr) return; 

    Vertex* vertex = new Vertex(v);
    this->vertices.push_back(vertex);
}

bool Graph::AddEdge(int v1, int v2){
    Vertex* vertex1 = GetVertex(v1);
    Vertex* vertex2 = GetVertex(v2);

    if(vertex1 == nullptr || vertex2 == nullptr) return false;

    vertex1->AddEdge(vertex2);

    return true;
}

Vertex* Graph::GetVertex(int v) const {
    for(auto vertex : this->vertices){
        if(vertex->GetValue() == v) return vertex;
    }

    return nullptr;
}

std::vector<Vertex*> Graph::GetVertices() const {
    return this->vertices;
}

int Graph::GetVerticesCount() const {
    return this->vertices.size();
}

void Graph::PrintVertices() const {
    std::cout << "Vertices:" << std::endl;

    for(auto vertex : this->vertices){
        std::cout << vertex->GetValue() << std::endl;
    }

    std::cout << "Count: " << this->GetVerticesCount() << std::endl << std::endl;
}

void Graph::PrintEdges() const {
    std::cout << "Oriented edges: (from -> to)" << std::endl;

    for(auto vertex : this->vertices){
        vertex->PrintEdges();
    }
}