#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

void enterArray(char arr[500][500], int _size)
 {
	int idex = 0;
	for (idex; idex < _size; ++idex) {
		char * __number = (char*) malloc(100 * sizeof(char));
		printf("Enter elem[%d]: ", idex);
		fgets(__number,100,stdin);
		
		strcpy(arr[idex], __number);
		
		
		if (__number) {
			free(__number);
			__number = NULL;
		}

		// Clear the buffer
		fflush(stdin);
	}
 }
 
void printArray(char a[500][500], int _size) {
	int idex = 0;
	printf("Array: ");
	for (idex; idex < _size; idex++) {
		// this one would print line by line
		// a[0]
		// a[1]
		// printf("%s ", a[idex]);
		
		int jdex = 0;
		// The way of priting an array: a[0] - a[1] - .... - a[n]
		for (jdex; jdex < strlen(a[idex]) - 1; jdex++) {
			printf("%c", a[idex][jdex]);
		}
		printf(" ");
	}
	printf("\n");
}

int isInteger(char* arr, int _size, int* isNegative)
{
	int idex;
	// because of removing the '\n' letter -> running from 1 -> size - 1
    if (arr[0] == '-')
    {
    	for (idex = 1; idex < _size - 1; idex++)
	    {	
	        if (arr[idex] > '9' || arr[idex] < '0')
	        {
	            return false;
	        }
	    }
	}
	else
	{
		for (idex = 0; idex < _size - 1; idex++)
	    {	
	        if (arr[idex] > '9' || arr[idex] < '0')
	        {
	            return false;
	        }
	    }
	}
    return true;
}

int isPerfect(long long int n)
{
    
    long long int sum = 1;
    for (long long int i=2; i*i<=n; i++)
    {
        if (n%i==0)
        {
            if(i*i!=n)
                sum = sum + i + n/i;
            else
                sum=sum+i;
        }
    }
    
     if (sum == n && n != 1)
          return 1;
  
     return 0;
}
 
int  isPrime(int n) {
	int _i;
	int limit = n/2;
	for (_i = 2; _i <= limit; _i++) {
		if (n % _i == 0) {
			return 0;
		 }
	 }
	return 1;
}
 
 int Prime(char arr[500][500], int _size) {
 	int idex;
 	int sum = 0;
 	
 	printf("prime number array: ");
 	
 	for (idex = 0; idex < _size; ++idex) {
 		int isNegative = 0;
 		if (isInteger(arr[idex],strlen(arr[idex]),&isNegative) == 1) 
 		{
 			int number = atoi(arr[idex]);
 			
			if (isNegative == 1) {
 				number *= -1;
			}
			
 			if (isPrime(number) == 1) {
	 			printf("%d ", arr[idex]);
	 			sum += number;
			}
		}
	 }
	 printf("\n");
	 return sum;
 }
 
 
 int Perfect(char arr[500][500], int _size) {
 	int idex;
 	int sum = 0;
 	
 	printf("perfect number array: ");
 	
 	for (idex = 0; idex < _size; ++idex) {
 		int isNegative = 0;
 		if (isInteger(arr[idex],strlen(arr[idex]),&isNegative) == 1) 
 		{
 			int number = atoi(arr[idex]);
 			if (isNegative == 1) {
 				number *= -1;
			 }

			if (isPerfect(number) == 1) {
	 			printf("%d ", number);
	 			sum += number;
			}
		}
	 }
	 printf("\n");
	 return sum;
 }
 
int main()
{
	char arr[500][500];
	int _size;
	printf("Enter size: ");
	scanf("%d", &_size);
	fflush(stdin);
	
	enterArray(arr, _size);
	printArray(arr, _size);
	
	// Bai 1:
//	printf("Sum of prime numbers: %d\n", Prime(arr,_size));
	
	// Bai 2:
	printf("Sum of perfect numbers: %d\n", Perfect(arr,_size));
	return 0;
}


