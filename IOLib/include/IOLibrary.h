#ifndef __IOLIB_H__
#define __IOLIB_H__

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

namespace IOlib
{
    /**
     * @brief 
     * 
     * @return int 
     */
    int integerInput();
    
    /**
     * @brief 
     * 
     * @return double 
     */
    double doubleInput();

    /**
     * @brief function for checking whether @b _src is integer number or not
     * 
     * @param _src the source for checking the number
     * @return 0 if true, 1 otherwise
     */
    int isInteger(const char* _src);

    /**
     * @brief function for checking whether @b _src is double number or not
     * 
     * @param _src 
     * @return 0 is true, 1 otherwise 
     */
    int isDouble(const char* _src);
};  

#endif // __IOLIB_H__