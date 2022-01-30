#include "IOLibrary.h"

namespace IOlib
{
    int integerInput()
    {
        int _s = (100*sizeof(char));
        char* input =  (char*) malloc(_s);
        int _result;
        do
        {
            printf("Enter integer number: ");
            std::cin.getline(input, _s);

            if (isInteger(input) == 0)
            {
                break;
            }

        } while (1); 

        // casting frome char* to int
        _result = atoi(input);

        // deallocating memory
        free(input);
        input = nullptr;

        
        return _result;
    }

    double doubleInput()
    {
        int _s = (100*sizeof(char));
        char* input =  (char*) malloc(_s);
        int _result;
        do
        {
            printf("Enter double number: ");
            std::cin.getline(input, _s);

            if (isDouble(input) == 0)
            {
                break;
            }

        } while (1); 

        // casting frome char* to int
        _result = std::stod(input);

        // deallocating memory
        free(input);
        input = nullptr;

        
        return _result;
    }

    int isInteger(const char * _src)
    {
        if (!_src)
            return 1;

        size_t _s = strlen(_src);
        for (size_t _i = 0; _i < _s; _i++)
        {
            if (_src[_i] == '.')
            {
                fputs("Could not writing the double number\n", stderr);
                return 1;
            }

            if (_src[_i] < '0' || _src[_i] > '9')
            {
                fputs("Could not writing the string\n", stderr);
                return 1;
            }
        }
        return 0;
    }

    int isDouble(const char* _src)
    {
        if (!_src)
            return 1;

        size_t _s = strlen(_src);
        for (size_t _i = 0; _i < _s; _i++)
        {
            if (_src[_i] < '0' || _src[_i] > '9')
            {
                fputs("Could not writing the string\n", stderr);
                return 1;
            }
        }
        return 0;
    }
};