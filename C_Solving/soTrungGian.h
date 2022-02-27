#ifndef __STG_H__
#define __STG_H__

#include <stdio.h>
#include <math.h>

/*
 * @brief : This function using for finding out the median between 3 numbers
 * @param : _n <!! number of integer n
 *
 * @note: This function just return the result of 65! (could not do with n (> 65))
 */
double soTrungGian(double _x, double _y, double _z)
{
	if (abs(_x - _y) < 1e-10 || abs(_x - _z) < 1e-10 || abs(_y - _z) < 1e-10)
	{
		printf("Could not finding out the median because there are 2 numbers which is equal\n");
		return 0.0;
	}
    return ((_x > _y && _x < _z) || (_x > _z && _x < _y) ? _x : (_y > _x && _y < _z) || (_y > _z && _y < _x) ? _y : _z);
}


/*
 * @brief : This function using for calling from main to having solve of SoTrungGian
 *
 */
void solveSoTrungGian()
{
	double _x, _y, _z;
	
	do
	{
		enterDoubleNumber(&_x,(char*)"x");
		enterDoubleNumber(&_y,(char*)"y");
		enterDoubleNumber(&_z,(char*)"z");
	}while(0);

    printf("Number x: %lf\n", _x);
    printf("Number y: %lf\n", _y);
    printf("Number z: %lf\n", _z);
    
	printf("So trung gian: %lf", soTrungGian(_x,_y,_z));
}

#endif // __STD_H__
