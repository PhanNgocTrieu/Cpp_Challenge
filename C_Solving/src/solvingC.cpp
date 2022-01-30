#include "solvingC.h"

namespace C_Solving_Unit
{
    namespace Deso12
    {
        void CheckingSine()
        {
            int rand_num;
            srand(time(NULL));
            double radius;
            for (int i = 0; i < 50; i++)
            {
                rand_num = rand() % 360 + 1;
                radius = rand_num*PI/180;
                if (fabs(support::Sine(radius) - sin(radius)) < epsilon) //epsilon = 0.000001
                {
                    std::cout << "\nTest #" << i << ": x = " << rand_num << ", True";
                }
                else
                {
                    std::cout << "\nTest #" << i << ": x = " << rand_num << ", False";
                }
            }
        }
    };

    /**
     * @brief Lib for some features which is neccesary for hanlding - especially of I/O functionality
     * 
     */
    namespace InputAndOutput
    {
        void enterArray(char** arr, const int& _size)
        {
            int _sizeForAllo = _size * sizeof(char);

            /**
             * Allocating the memory for the array
             * 
             */
            for (int i = 0; i < _size; i++)
            {
                arr[i] = (char*) malloc(_sizeForAllo);
            }

            for (int i = 0; i < _size; i++)
            {
                /**
                 *  initialzing buffer variables for getting input 
                 */
                char* buffer = (char*)malloc(_sizeForAllo);
                int rc;

                do
                {
                    printf("Enter %d-th elems:",i);
                    rc = getdelim(&buffer, (size_t*)&_sizeForAllo, '\n' ,stdin);
                    // sizeEnter = strlen(buffer) - 1;
                } while (rc == -1);

                /**
                 *  copying from buffer to the i-th element of array
                 * 
                 */
                strcpy(arr[i],  buffer);

                /**
                 *  deallocating memory
                 * 
                 */
                free(buffer);
                buffer = nullptr;
            }

        }

        void printArray(char* arr[], const int& _size)
        {
            if (!arr)
            {
                return;
            }
            for (int i = 0; i < _size; i++)
            {
                std::cout << arr[i] << " ";
            }
        }

    };

    namespace support
    {
        long double Factor(long n)
        {
            if (n == 1 || n == 0)
            {
                return 1;
            }
            
            return n*Factor(n-1);
        }

        
        double Sine(double x)
        {
            double sine = 0;
            double temp;
            long int n = 0;
            do
            {
                temp = pow(x,2*n+1)/Factor(2*n+1);
                sine = sine + pow(-1,n)*temp;
                n = n + 1;
            } while (fabs(temp) >= epsilon);
            
            return sine;
        }
    };
};