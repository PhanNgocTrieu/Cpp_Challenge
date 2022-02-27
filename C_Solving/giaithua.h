#ifndef __GIAITHUA_H__
#define __GIAITHUA_H__

#include <stdio.h>
#include "supported.h"

/*
 * @brief : This function using for calculating the numbers of zeros at last of n!
 * @param : _n <!! number of integer n
 *
 * @note: This function just return the result of 65! (could not do with n (> 65))
 */
long long int zerosCuoiCuaNGiaiThua(long long int _n)
{
	long long int _sum = 0;
	
	do
	{
		_sum += _n / 5;
		_n = _n / 5;
	}while(_n >= 5);
	
	return _sum;
}

/*
 * @brief : This function using for calculating n!! with recursion algorithm
 * @param : _n <!! number of integer n
 *
 */
long long int giaithuaChanLe(int _n)
{
	if (_n < 2)
	{
		return 1;
	}
	if (_n % 2 == 0)
	{	
		return _n * giaithuaChanLe(_n - 2);
	}
	
	return _n * giaithuaChanLe(_n - 2);	
}


/*
 * @brief : This function using for calculating n! with recursion algorithm
 * @param : _n <!! number of integer n
 *
 * @note: This function just return the result of 65! (could not do with n (> 65))
 */
long long int giaithua(long long int _n)
{
	if (_n < 1)
	{
		return 1;
	}
	return _n * giaithua(_n - 1);
}


/*
 * @brief : This function supporting for calling the solution of this problems - just calling solveGiaiThua() from main;
 * 
 */
void solveGiaiThua()
{
	long long int _N;

	enterIntNumber(&_N,(char*)"N");
	if (_N < 0)
	{
		printf("Error! - N have to be larger 0\n");
		return;
	}
	/* By this way -> just printing 65! is maximun */	
	printf("Giai thua cua %lld is : %lld\n", _N, giaithua(_N));
}

/*
 * @brief : This function supporting for calculating n! with n > 65
 * @param : _n <!! number of integer n
 *
 */
void giaiThuaMoRong(int _n)
{
	int A[500000],i,j,m=1;
	
	int remainder = 0, q;
	
	A[0] = 1;
	
	for (i = 2; i < _n + 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			
			q = remainder;
			// 20 -> take the last == 0 -> remainder = 2;
			// this one is taking remainder
			remainder = (A[j]*i + remainder)/10;
			
			// 20 -> pushing 0 into A[0] or (A[j])
			A[j] = (A[j]*i + q) % 10;
		}
		
		/*	Pushing remainder to the last of array */
		while(remainder > 0)
		{
			A[m] = remainder % 10;
			remainder = remainder / 10;
			m++;
		}
	}
	
	/*
	* printing the number of n!
	*/
	for (i = m - 1; i >= 0; i--)
	{
		printf("%d",A[i]);
	}
}

#endif // __GIAITHUA_H__e
