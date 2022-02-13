#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <list>
#include <vector>
#include <limits>

namespace DTST
{
    template <class _Typ>
    struct tree
    {
        _Typ _value;
        tree* left;
        tree* right;
    };

    class Graphic
    {   
        public:

            /**
             * @brief 
             * 
             */
            void printGraphic();


            /**
             * @brief Construct a new Graphic object
             * 
            */
            Graphic(const uint32_t& vertexNums);

            /**
             * @brief Destroy the Graphic object
             * 
             */
            ~Graphic();

        private:
            uint32_t m_numOfVertexs;
            tree<int> m_integerTree;
            tree<float> m_floatTree;
            tree<std::string> m_stringTree;
            std::vector<bool> m_visited;
    };

};
#endif