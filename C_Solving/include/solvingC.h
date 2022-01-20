#ifndef __SOLVING_C_H__
#define __SOLVING_C_H__

#include <stdio.h>
#include <malloc.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <iostream>

namespace C_Solving_Unit
{
    /**
     * @brief struct for solving the 1st test
     * 
     */
    struct Deso1
    {
        /**
         * @brief
         *      Bai 1: Viết chương trình có sử dụng hàm kiểm tra n (nhập từ bàn phím) có phải số nguyên tố không ?
         * 
         * @author pntrieu
         * 
         */
        bool isPrime(const int& _number);
        bool Prime(char * _number);

        /**
         * @brief 
         *      Bai 2: 
         *          a. Viết chương trình nhập mảng một chiều A với n phần tử (n>=10). Xuất mảng A ra màn hình (2điểm)
         *          b. Xuất ra màn hình các nguyên tố trong A trên
         * 
         * @param arr 
         * @param _size 
         */
        void enterArray(int arr[], int _size);
        void printPrimeNumber(int arr[], int _size);


        /**
         * @brief Upgrading for problems
         * 
         */
        void enterArr(char** arr, int _size);
    };

};

#endif