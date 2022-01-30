#ifndef __SOLVING_C_H__
#define __SOLVING_C_H__

#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <limits>


using namespace std;

// For calculating Sine(x) problem
#define PI 3.1415
#define epsilon 0.000001


namespace C_Solving_Unit
{
    namespace Deso12 
    {
        void CheckingSine();
    };
    
    namespace InputAndOutput
    {
        void enterArray(char** arr, const int& _size);
        void printArray(char* arr[], const int& _size);
    };

    namespace support
    {
        long double Factor(long n);
        double Sine(double x);
    };
};

#endif