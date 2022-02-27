#ifndef __PTRINH_H__
#define __PTRING_H__

#include "supported.h"
#include <math.h>

void ptBac2(double _a, double _b, double _c)
{
	if (_a == 0)
	{
		printf("Error: a != 0!\n");
		return;
	}
	
	double delta = _b * _b - 4 * _c * _a;
	
	if (delta < 0)
	{
		printf("Phuong trinh vo nghiem\n");
	}
	else
	{
		if (delta == 0)
		{
			printf("Phuong trinh co nghiem kep x1 = x2 = %llf", -_b / (2*_a));
		}
		else
		{
			delta = sqrt(delta);
			printf("Phuong trinh co nghiem x1 = %llf; x2 = %llf\n\n",(-_b + delta)/(2 * _a),(-_b - delta)/(2 * _a));
		}
	}
}

void solvePhuongTrinhBac2()
{
	double _x;
	double _y;
	double _z;
	
	enterDoubleNumber(&_x, (char*)"_x");
	enterDoubleNumber(&_y, (char*)"_y");
	enterDoubleNumber(&_z, (char*)"_z");
	
	ptBac2(_x, _y, _z);
}

#endif // __PTRINH_H__
