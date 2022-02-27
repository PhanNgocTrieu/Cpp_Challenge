#ifndef __SUM_H__
#define __SUM_H__

#include <stdio.h>
#include <math.h>
#include "supported.h"


/*
 * @brief: S= x^n/n = 1 + x + x^2/2 + ... + x^n/n
 * 
 * @param : _x --- value of x
 * @param : _n --- n
 */
double sumOfN(double _x, long long int _n)
{
	double s = 1;
	long long int i = 0;
	
	for (i = 1; i < _n; ++i)
	{
		s = s + pow(_x,i)/i;
	}
	return s;
}

/*
 * @brief: S = x^n/n = 1 - 1/2 + 1/3 + ... + pow(-1,n + 1)/n
 * 
 * @param : _n --- value of n
 */
double sumOfDivideN(long long int _n)
{
	double sum = 0.0;
	double _pre;
	long long int _irun = 1;
	while(_irun <= _n)
	{
		if (_irun % 2 == 0)
			_pre = -1.0;
		else
			_pre = 1.0;
			
		sum = sum + (_pre/_irun);
		_irun++;		
	}
	
//	printf("Sum: %0.15f\n", sum);s
	return sum;
}

void solveOfSumOfN()
{
	double _x;
	long long int _n;
		
	printf("Sum : %0.15f\n",sumOfDivideN(2));
}



#endif // __SUM_H__
