#include "Graph.hpp"
#include <iostream>
#include <algorithm>


Graph::~Graph(){
    for(auto vertex : this->vertices){
        delete vertex;
    }
}

void Graph::Insert(int v){
    if(GetVertex(v) != nullptr) return; 

    Vertex* vertex = new Vertex(v);
    this->vertices.push_back(vertex);
}

bool Graph::AddEdge(int v1, int v2){
    Vertex* vertex1 = GetVertex(v1);
    Vertex* vertex2 = GetVertex(v2);

    if(vertex1 == nullptr || vertex2 == nullptr) return false;

    for(auto neighbor : vertex1->GetNeighbors()){
        if(neighbor == vertex2) return false;
    }

    vertex1->AddEdge(vertex2);

    return true;
}

void Graph::ResetStates(){
    for(auto vertex : this->vertices){
        vertex->SetState(Vertex::UNVISITED);
    }
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

int Graph::GetEdgesCount() const {
    int count = 0;
    
    for(auto vertex : this->vertices){
        count += vertex->GetNeighbors().size();
    }

    return count;
}

bool Graph::HasCycle(Vertex* vertex){
    vertex->SetState(Vertex::VISITING);
    std::vector<Vertex*> neighbors = vertex->GetNeighbors();

    for(auto neighbor : neighbors) {
        if(neighbor->GetState() == Vertex::VISITING) return true;
        if(neighbor->GetState() == Vertex::UNVISITED && HasCycle(neighbor)) return true;
    }

    vertex->SetState(Vertex::VISITED);
    return false;
}

bool Graph::IsDAG(){
    this->ResetStates();

    for(auto vertex : this->vertices) {
        if(vertex->GetState() == Vertex::UNVISITED && this->HasCycle(vertex)) return false;
    }
    
    return true;
}

void Graph::TopologicalSortHelper(Vertex* vertex, std::vector<Vertex*>& order) {
    vertex->SetState(Vertex::VISITING);
    
    for(Vertex* neighbor : vertex->GetNeighbors()){
        if(neighbor->GetState() == Vertex::UNVISITED) TopologicalSortHelper(neighbor, order);
    }
    
    vertex->SetState(Vertex::VISITED);
    order.push_back(vertex);
}

void Graph::TopologicalSort() {
    this->order.clear();
    this->ResetStates();

    for(Vertex* vertex : this->vertices){
        if(vertex->GetState() == Vertex::UNVISITED) TopologicalSortHelper(vertex, this->order);
    }

    std::reverse(this->order.begin(), this->order.end());
}

void Graph::MakeCompleteDAG(){
    this->TopologicalSort(); 
    int n = this->order.size();

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            Vertex* u = this->order[i];
            Vertex* v = this->order[j];

            bool exists = false;
            for(auto neighbor : u->GetNeighbors()){
                if(neighbor == v) {
                    exists = true;
                    break;
                }
            }

            if(!exists) u->AddEdge(v);
        }
    }
}

int Graph::GetExpectedEdgesCount() const {
    int n = this->GetVerticesCount();
    int ec = (n * (n - 1)) / 2;
    
    return ec;
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
        vertex->PrintNeighbors();
    }
}

void Graph::PrintTopologicalOrder(){
    std::cout << "Topological order: " << std::endl;

    for(auto vertex : this->order){
        std::cout << vertex->GetValue() << " ";
    }

    std::cout << std::endl;
}