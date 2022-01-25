#include "solvingC.h"

namespace C_Solving_Unit
{

    /**
     * *************************
     * @brief DESo1            *
     * 
     * *************************
     */

    namespace Deso1
    {
        bool isPrime(const int& _number)
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
        bool Prime(char* _number)
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
                    free(temp);
                    temp = NULL;
                    return false;
                }

                temp[_idexOfTemp] = _number[i];
                _idexOfTemp++;
            }

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

        void solvingPrimeNumberArray(char* arr[], int _size)
        {
            // Checking for prime number
            for (int i = 0; i < _size; i++)
            {
                Prime(arr[i]);
            }
            printf("\n");
        }

    };

    /**
     * *************************
     * @brief Deso2            *
     * 
     * *************************
     */

    namespace Deso2
    {
        bool isPerfect(const int& _number)
        {
            int _sum = 0;
            int _i = 1;
            while (_i <= _number / 2)
            {
                if (_number % _i == 0)
                    _sum += _i;
                _i++;
            }
            
            if (_sum == _number)
            {
                return true;
            }
            return false;
        }

        bool perfectCharNumber(char* _number)
        {
            if (_number == NULL)
            {
                return false;
            }
            bool flag = false;

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
                    free(temp);
                    temp = NULL;
                    return false;
                }

                temp[_idexOfTemp] = _number[i];
                _idexOfTemp++;
            }

            int _intNumber = atoi(temp);

            if (Deso2::isPerfect(_intNumber))
            {
                printf(" %d ", _intNumber);
                flag = true;
            }

            free(temp);
            temp = NULL;
            return flag;
        }

        void solvingPerfectNumber(char* arr[], const int& _size)
        {
            for (int i = 0; i < _size; i++)
            {
                Deso2::perfectCharNumber(arr[i]);
            }
            printf("\n");
        }
    };

    /**
     * *************************
     * @brief Deso3            *
     * 
     * *************************
     */

    namespace Deso3
    {
        int C(int k, int n) 
        {
            if (k == 0 || k == n) return 1;
            if (k == 1) return n;
            return C(k - 1, n - 1) + C(k, n - 1);
        }

        bool perfectCharNumber(char* _number)
        {
            if (_number == NULL)
            {
                return false;
            }
            bool flag = false;

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
                    free(temp);
                    temp = NULL;
                    return false;
                }

                temp[_idexOfTemp] = _number[i];
                _idexOfTemp++;
            }

            int _intNumber = atoi(temp);

            if (!Deso2::isPerfect(_intNumber))
            {
                printf(" %d ", _intNumber);
                flag = true;
            }

            free(temp);
            temp = NULL;
            return flag;
        }
        
        void solvingRemovingPerfectNumber(char* arr[], const int& _size)
        {
            // allocate
            for (int i = 0; i < _size; i++)
                arr[i] = (char*)malloc(_size * sizeof(char));


            int malloc_size = _size * sizeof(char);
            char * rc;
            int _strlen;
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

            /** removing the prime number out of array */
            char* replaceArr[_size];
            int _index = 0;
            for (int i = 0; i < _size; i++)
            {
                if (!Deso3::perfectCharNumber(arr[i]))
                {
                    replaceArr[_index] = arr[i];
                    _index++;
                }
            }

            // deallocated memory
            for (int i = 0; i < _size; i++)
            {
                free(arr[i]);
                arr[i] = NULL;
            }

            // point arr to replaceArr;
            arr = replaceArr;

            // deallocate memory
            for (int i = 0; i < _size; i++)
            {
                replaceArr[i] = NULL;
            }

            printf("\n");
            
        }
    };
    


};