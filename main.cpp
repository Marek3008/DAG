#include "src/Graph/Graph.hpp"
#include <iostream>
#include <fstream>


std::vector<std::pair<int, int>> process_file(const std::string file_name){
    std::ifstream file(file_name);
    
    std::vector<std::pair<int, int>> edges;
    int i, j;

    while(file >> i >> j){
        edges.push_back({i, j});
    }

    return edges;
}

void create_graph(Graph* g, const std::vector<std::pair<int, int>>& edges){
    for(const auto& edge : edges){
        int start = edge.first;
        int end = edge.second;
        
        if(g->GetVertex(start) == nullptr) g->Insert(start);
        if(g->GetVertex(end) == nullptr) g->Insert(end);

        g->AddEdge(start, end);
    }
}

int main(void){
    Graph* g = new Graph();
    
    std::vector<std::pair<int, int>> edges = process_file("input.txt");

    create_graph(g, edges);

    g->PrintVertices();
    g->PrintEdges();

    return 0;
}