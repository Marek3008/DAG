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

void write_completeDAG_to_file(Graph* g, const std::string file_name){
    std::ofstream file(file_name);

    g->MakeCompleteDAG();

    for(auto vertex : g->GetVertices()){
        for(auto neigbor : vertex->GetNeighbors()){
            file << vertex->GetValue() << " " << neigbor->GetValue() << std::endl;
        }
    }
}

int main(void){
    Graph* g = new Graph();
    
    std::vector<std::pair<int, int>> edges = process_file("input.txt");

    create_graph(g, edges);

    std::cout << (g->IsDAG() ? "Zadaný graf je DAG" : "Zadaný graf NIE je DAG") << std::endl;
    std::cout << "Počet vrcholov je " << g->GetVerticesCount() << " a počet hrán je " << g->GetEdgesCount() << std::endl;
    std::cout << "Očakávaný počet hrán (v prípade, že je to DAG) je " << g->GetExpectedEdgesCount() << std::endl;

    if(g->IsDAG()){        
        write_completeDAG_to_file(g, "output.txt");

        std::cout << std::endl << "DAG:" << std::endl;
        std::cout << "Počet vrcholov je" << g->GetVerticesCount() << " a počet hrán je " << g->GetEdgesCount() << std::endl;
    }
    
    return 0;
}