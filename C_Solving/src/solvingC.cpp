#include "solvingC.h"

namespace C_Solving_Unit
{
    bool Deso1::isPrime(const int& _number)
    {
        if (_number < 2)
        {
            // printf("%d is not prime number!\n", _number);
            return false;
        }

        int num = 2;
        do
        {
            if (_number % num == 0)
            {
                // printf("%d is not prime number!\n", _number);
                return false;
            }
            num++;
        } while (num < _number / 2);

        // printf("%d is prime number!\n", _number);
        return true;
    }

    /**
     * @brief Problems for upgrading from above
     * 
     *    
     */
    bool Deso1::Prime(char* _number)
    {
        // printf("Checking: %s", _number);
        int _size = strlen(_number);
        char* temp = (char*)malloc(_size * sizeof(char));
        int _idexOfTemp = 0;

        for (int i = 0; i < _size; i++)
        {
            if (_number[i] == '\n')
            {
                break;
            }
            // double number input -> wrong
            if (_number[i] == ',')
            {
                free(temp);
                temp = NULL;
                return false;
            }

            // string input
            if (_number[i] < '0' || _number[i] > '9')
            {
                return false;
            }

            temp[_idexOfTemp] = _number[i];
            _idexOfTemp++;
        }

        /**
         * @brief   second way - shorter
         * 
         *          using atoi from stdlib.h
         */
        int number = atoi(temp);

        free(temp);
        temp = NULL;

        if (isPrime(number))
        {
            printf("%d - ", number);
            return true;
        }
        return false;
    }

    void Deso1::enterArr(char* arr[], int _size)
    {
        // allocate
        for (int i = 0; i < _size; i++)
            arr[i] = (char*)malloc(_size * sizeof(char));
        
        int _strlen;

        for (int i = 0; i < _size; i++)
        {
            // Enter the letter from keyboard
            int malloc_size = _size * sizeof(char);
            char* buffer = (char*)malloc(malloc_size);
            
            // checking for the user enters the numbers
            do
            {
                printf("Enter %d-th number: ",i);          
                fgets(buffer, malloc_size, stdin);

                
                _strlen = strlen(buffer) - 1;
            } while (_strlen == 0);
            
            
            // Point the arr[i] to the buffer
            strcpy(arr[i],buffer);
            
            // Free memory
            free(buffer);
            buffer = NULL;
        }

        // Checking for prime number
        for (int i = 0; i < _size; i++)
        {
            Prime(arr[i]);
        }
        printf("\n");
    }

};