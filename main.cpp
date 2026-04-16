#include "src/Graph/Graph.hpp"
#include <iostream>


int main(void){
    Graph* g = new Graph();

    g->Insert(0);
    g->Insert(1);
    g->Insert(2);

    g->AddEdge(0, 2);
    g->AddEdge(2, 1);

    g->PrintVertices();
    g->PrintEdges();

    return 0;
}