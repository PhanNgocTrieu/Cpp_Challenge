#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "supported.h"

/*
 * @brief:  problems on test 1:
 * 			a) Enter an array
 *			b) Print primeNumber on array
 */

void printPrimeNumber(char ** arr, int _size)
{
	int idex = 0;
	for (idex; idex < _size; idex++)
	{
		if (isPrimeNumber(arr[idex], strlen(arr[idex])))
		{
			printf("%s", arr[idex]);
		}
	}
}

void solvePrintingPrimeNumber()
{
	char ** arr = NULL;
	int _size;
	printf("Enter size of array: ");
	scanf("%d",_size);
	enterArray(&arr,_size, NULL);
	printPrimeNumber(arr,_size);
}


#endif // __ARRAY_H__
