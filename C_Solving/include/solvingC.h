#ifndef __SOLVING_C_H__
#define __SOLVING_C_H__

#include <iostream>
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


    /**
     * @brief  
     *          Bài 1:  Số tổ hợp C(k,n) có công thức truy hồi C(k,n) = C(k-1, n-1) + C(k,n-1) với C(0,n) = C(n,n) = 1
     *          
     *          Bài 2:  a. Viết chương trình nhập mảng một chiều A với n phần tử (n>=10). Xuất mảng A ra màn hình (2điểm)
     *                  b. Xóa các số hoàn hảo trong A trên, xuất lại mảng A sau khi xóa các số hoàn hảo.
     * 
     */
    namespace Deso3
    {
        int C(int k, int n);
        bool perfectCharNumber(char* _number);
        void solvingRemovingPerfectNumber(char* arr[], const int& _size);
    };



    namespace necessary
    {
        void print2DArray(char* arr[], const int& _size)
        {
            for (int i = 0; i < _size; i++)
            {
                std::cout << arr[i] << " ";
            }
        }

        void enter2DArray(char** arr, const int& _size)
        {
            // Allocating memory
            for (int i = 0; i < _size; i++)
                arr[i] = (char*)malloc(_size * sizeof(char));

            char * rc = NULL;
            int _strlen = 0;
            int malloc_size = _size * sizeof(char);

            for (int i = 0; i < _size; i++)
            {
                char* buffer = (char*)malloc(malloc_size); 
                do
                {
                    printf("Enter %d-th number: ",i);
                    rc = fgets(buffer, malloc_size, stdin);
                    _strlen = strlen(buffer) - 1;
                }while(rc == nullptr || _strlen == 0);

                strcpy(arr[i], buffer);

                free(buffer);
                buffer = NULL;
            }
        }
    };
};

#endif