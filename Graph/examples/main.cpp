#include <iostream>
#include "Graph.h"
#include <vector>

int main()
{
    std::vector<std::vector<int>> graphicTable = {
        {0, 5, 5, 0, 0, 0, 0},
        {0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 5, 4},
        {0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 0, 0}};

    // Graphic graph(graphicTable,7,0);

    // graph.Dijkstra();
    // graph.printGraphic();
    // std::cout << "Shortest distance from A to H = " << graph.getShortestToFromSource(6) << std::endl;

    return 0;
}