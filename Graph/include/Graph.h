#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <list>
#include <vector>
#include <limits>

class Graphic
{        
    public:

        /**
         * @brief adding edge into vertex
         * 
         * @param vertex 
         * @param value 
         */
        void addingEdge(uint32_t vertex, uint32_t weight);

        /**
         * @brief 
         * 
         */
        void Dijkstra();

        /**
         * @brief 
         * 
         * @return int 
         */
        int32_t minDistance();

        /**
         * @brief Get the Shortest To From Source object
         * 
         * @param _des 
         * @return int32_t 
         */
        int32_t getShortestToFromSource(const int32_t& _des);

        /**
         * @brief 
         * 
         */
        void printGraphic();


        /**
         * @brief Construct a new Graphic object
         * 
        */
        Graphic(const std::vector<std::vector<int32_t>>& graphic, const int32_t& vertexNums, const int32_t& source);

        /**
         * @brief Destroy the Graphic object
         * 
         */
        ~Graphic();

    private:
        std::vector<std::vector<int32_t>> m_graph;
        std::vector<int32_t> m_distance; // <! Distance from source to i;
        std::vector<bool> m_shortestPathSet; // <! Flag for checking whether we passed the vertex-th or not
        int32_t m_defaultVertex; // <! Head of graphic
        int32_t m_numOfVertex; // <! Number of vertexs

};

#endif