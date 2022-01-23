#ifndef __SOLVING_C_H__
#define __SOLVING_C_H__

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

namespace C_Solving_Unit
{
    /**
     * @brief struct for solving the 1st test
     *  
     *      Bai 1: Viết chương trình có sử dụng hàm kiểm tra n (nhập từ bàn phím) có phải số nguyên tố không ?
     *      Bai 2: 
     *          a. Viết chương trình nhập mảng một chiều A với n phần tử (n>=10). Xuất mảng A ra màn hình (2điểm)
     *          b. Xuất ra màn hình các nguyên tố trong A trên 
     */
    namespace Deso1
    {
        /**
         * @brief checking whether integer number is prime or not
         * 
         * @param _number 
         */
        bool isPrime(const int& _number);

        /**
         * @brief Handling the prime string-formatted number
         * 
         * @param _number number with format string for checking prime number
         */
        bool Prime(char * _number);

        /**
         * @brief 

         * 
         * @param arr 
         * @param _size 
         */
        void solvingPrimeNumberArray(char** arr, int _size);
    };

    /**
     * @brief struct for solving the 1st test
     * 
     *      Bài 1.  Số hoàn hảo là số nguyên dương bằng tổng các ước thực sự của nó. Ví dụ: 6=1+2+3. 
     *              Viết chương trình có sử dụng hàm kiểm tra n (nhập từ bàn phím) có phải số hoàn hảo không ?
     * 
     *      Bài 2.  Viết chương trình có sử dụng hàm 
     *              a. Viết chương trình nhập mảng một chiều A với nphần tử (n>=10). Xuất mảng A ra màn hình (2điểm) 
     *              b. Xuất ra màn hình các hoàn hảo trong A trên (4 điểm)
     */
    namespace Deso2
    {
        /**
         * @brief checking perfect number
         * 
         * @param _number number for checking whether _number is perfect or not!
         */
        bool isPerfect(const int& _number);

        /**
         * @brief hanlding with string number
         * 
         * @param _number 
         */
        bool perfectCharNumber(char* _number);

        /**
         * @brief Array of number for printing the perfect number
         * 
         * @param arr pointer to array
         * @param _size size of array
         */
        void solvingPerfectNumber(char* arr[], const int& _size);
    };



};

#endif