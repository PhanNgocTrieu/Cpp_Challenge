#ifndef _REFERENCE_H_
#define _REFERENCE_H_

#include "_common_dic.h"

namespace application {

    class _reference {

        public:
            typedef struct {
                uint32_t _id;
            } _words;

        public:
            _reference();
            ~_reference();
        private:
            boost::unordered_map<std::string, std::string> _referenceWords;
    };
    
}

#endif