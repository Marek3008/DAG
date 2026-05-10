/**
 * @file main.cpp
 * @brief Entry point for the Graph Analysis project.
 * @details This program demonstrates DAG detection, topological sorting, 
 * and the conversion of a directed graph into a complete DAG.
 */

#include "src/Graph/Graph.hpp"
#include <iostream>
#include <fstream>


/**
 * @brief Processes an input file to extract vertex pairs representing edges.
 * @param file_name The name of the input text file.
 * @return A vector of integer pairs, where each pair represents a directed edge (from, to).
 */
std::vector<std::pair<int, int>> process_file(const std::string file_name){
    std::ifstream file(file_name);
    
    std::vector<std::pair<int, int>> edges;
    int i, j;

    while(file >> i >> j){
        edges.push_back({i, j});
    }

    return edges;
}

/**
 * @brief Populates a Graph object with vertices and edges from a list.
 * @param g Pointer to the Graph instance.
 * @param edges A vector of pairs representing the edges to be inserted.
 */
void create_graph(Graph* g, const std::vector<std::pair<int, int>>& edges){
    for(const auto& edge : edges){
        int start = edge.first;
        int end = edge.second;
        
        if(g->GetVertex(start) == nullptr) g->Insert(start);
        if(g->GetVertex(end) == nullptr) g->Insert(end);

        g->AddEdge(start, end);
    }
}

/**
 * @brief Converts the graph into a complete DAG and writes the resulting edges to a file.
 * @param g Pointer to the Graph instance.
 * @param file_name The name of the output file.
 */
void write_completeDAG_to_file(Graph* g, std::string file_name){
    std::ofstream file(file_name);

    g->MakeCompleteDAG();

    for(auto vertex : g->GetVertices()){
        for(auto neigbor : vertex->GetNeighbors()){
            file << vertex->GetValue() << " " << neigbor->GetValue() << std::endl;
        }
    }
}


/**
 * @brief The main execution loop of the program.
 * @details Handles file I/O, graph construction, cycle validation, 
 * and outputs results to the console and external files.
 * @return 0 on successful execution.
 */
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
        std::cout << "Počet vrcholov je " << g->GetVerticesCount() << " a počet hrán je " << g->GetEdgesCount() << std::endl;
    }

    delete g;
    
    return 0;
}