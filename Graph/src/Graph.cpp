#include "Graph.h"
#include <iostream>

Graphic::Graphic(const std::vector<std::vector<int32_t>>& graphic, const int32_t& vertexNums, const int32_t& source) : 
                                                                                                        m_graph(graphic),
                                                                                                        m_distance(std::vector<int32_t>(vertexNums, INT32_MAX)),
                                                                                                        m_shortestPathSet(std::vector<bool>(vertexNums,false)),
                                                                                                        m_defaultVertex(source), 
                                                                                                        m_numOfVertex(vertexNums)
{
    m_distance[m_defaultVertex] = 0;
}

Graphic::~Graphic()
{
}

void Graphic::Dijkstra()
{
    // Find shortest path for all vertices
    for (int32_t count = 0; count < m_numOfVertex - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int32_t u = minDistance();
 
        // Mark the picked vertex as processed
        m_shortestPathSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int32_t v = 0; v < m_numOfVertex; v++)
 
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!m_shortestPathSet[v] && m_graph[u][v] && m_distance[u] != INT32_MAX
                && m_distance[u] + m_graph[u][v] < m_distance[v])
                m_distance[v] = m_distance[u] + m_graph[u][v];
    }
}

void Graphic::printGraphic()
{
    std::cout <<"Vertex \t Distance from Source" << std::endl;
    for (int32_t i = 0; i < m_numOfVertex; i++)
        std::cout  << i << " \t\t"<< m_distance[i] << std::endl;
}


int32_t Graphic::getShortestToFromSource(const int32_t& _des)
{
    return m_distance[_des];
}

int32_t Graphic::minDistance()
{
    // Initialize min value
    int32_t min = INT32_MAX;
    int32_t min_index = INT32_MAX;
 
    for (int32_t v = 0; v < m_defaultVertex; v++)
        if (m_shortestPathSet[v] == false && m_distance[v] <= min)
            min = m_distance[v], min_index = v;
 
    return min_index;
}

