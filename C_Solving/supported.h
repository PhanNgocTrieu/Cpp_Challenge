#ifndef __SUPPORTED_H__
#define __SUPPORTED_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0


/* Forward-declaration */
void enter(char ** _arr, int _size, char * name);
int isInteger(char* arr, int _size);
int isDouble(char *arr, int _size);
int isOnlyString(char* arr, int _size);
void enterDoubleNumber(double* _number, char * _name);
void enterIntNumber(long long int* _number, char * _name);
void enter(char ** _arr, int _size, char * name);



/*	Implementation  */


/*
 * @brief : This function supporting for checking the input-string is integer number or not
 * @param : _arr <!! pointer to array saving the input for checking 
 * @param : _size <!! size of array
 */
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


/*
 * @brief : This function supporting for checking the input-string is double number or not
 * @param : _arr <!! pointer to array of saving the input for checking
 * @param : _size <!! size of array
 */
int isDouble(char *arr, int _size, int* isNegative)
{
    int _countDot = 0;
    int idex;
    
    if (arr[0] == '-')
    {
    	for (idex = 1 ; idex < _size - 1; ++idex)
	    {  	
	        if (arr[idex] == '.')
	        {
	            _countDot++;
	            if (_countDot > 1)
	            {
	                return false;
	            }
	        }
	        else
	        {
		        if (arr[idex] < '0' || arr[idex] > '9')
		        {
		            return false;
		        }
		    }
	    }
	}
	else
	{
		for (idex = 0 ; idex < _size - 1; ++idex)
	    {			    	
	        if (arr[idex] == '.')
	        {
	            _countDot++;
	            if (_countDot > 1)
	            {
	                return false;
	            }
	        }
	        else
	        {
		        if (arr[idex] < '0' || arr[idex] > '9')
		        {
		            return false;
		        }
		    }
	    }
	}    
    return true;
}

/*
 * @brief : This function supporting for checking whether is only string or having number.
 * @param : _arr <!! pointer to array
 * @param : _size <!! size of array
 */
int isOnlyString(char* arr, int _size)
{
	
}

/*
 * @brief : This function supporting for entering double number into _number
 * @param : _number <!! pointer to address of double number
 * @param : _name <!! name for double variable
 */
void enterDoubleNumber(double* _number, char * _name)
{
	int _countEnter = 0;
	char * __number = (char*) malloc(100 * sizeof(char));
	char * endptr;
	int isAllocated = false;
	int isNegative = false;
	
	if (_name == NULL)
	{
		_name = (char*)malloc(100);
		strcpy(_name,"number");
		isAllocated = true;
	}
	
	do
	{
		
		printf("Enter %s: ",_name);
		fgets(__number,100,stdin);
		if (isDouble(__number,strlen(__number),&isNegative) == true)
		{
			break;
		}
		_countEnter++;
		if (_countEnter = 5)
		{
			printf("You did enter incorrect way to much time\n");
			
			// Deallocated
			if (isAllocated == true)
			{
				free(_name);
				_name = NULL;
			}
			return;
		}
	}while(1);
	
	// when input already integer number
	// Converting from string to double
	if (isNegative == true)
	{
		*_number = strtod(__number + 1, &endptr);
	}
	else
	{
		*_number = strtod(__number,&endptr);	
	}
	
	// deallocating
	if (isAllocated == true)
	{
		free(_name);
		_name = NULL;
	}
	
	// clearing buffer;
	fflush(stdin);
}

/*
 * @brief : This function supporting for entering integer number into _number
 * @param : _number <!! pointer to address of integer number
 * @param : _name <!! name for integer variable
 */
void enterIntNumber(long long int* _number, char * _name)
{
	int isAllocated = false;
	int isNegative = false;
	int _countEnter = 0;
	char * __number = (char*) malloc(100 * sizeof(char));
	if (_name == NULL)
	{
		_name = (char*)malloc(100);
		strcpy(_name,"number");
		isAllocated = true;
	}
	
	do
	{
		printf("Enter %s: ",_name);
		
		fgets(__number,100,stdin);
		if (isInteger(__number,strlen(__number),&isNegative) == true)
		{
			break;
		}
		
		if (_countEnter >= 5)
		{
			printf("You did enter incorrect ways to much time\n");
			
			if (isAllocated == true)
			{
				free(_name);
				_name = NULL;
			}
			
			return;
		}
		
	}while(1);
	
	// when input already integer number
	// Converting from string to integer
	if (isNegative == true)
	{
		*_number = atoi(__number + 1);	
	}
	else
	{
		*_number = atoi(__number);
	}
	
	
	// deallocating
	if (isAllocated == true)
	{
		free(_name);
		_name = NULL;
	}
	// clearing buffer;
	fflush(stdin);
}

/*
 * @brief : This function supporting for enter a string from input
 * @param : _arr <!! the pointer to the string
 * @param : _size <!! the size of string
 * @param : name <!! name of input
 */
void enterString(char ** _arr, int _size, char * name)
{
	int isAllocated = false;
	
	if (*_arr == NULL)
	{
		*_arr = (char *) malloc(_size * sizeof(char));
	}
	
	// Checking for name of variables
	if (name == NULL)
	{
		name = (char*)malloc(_size*100);
		strcpy(name,"string");
		isAllocated = true;
	}
	
	// Enter the input
	printf("Enter %s: ",name);
	fgets(*_arr,_size,stdin);
	
	// Deallocated memory
	if (isAllocated == true)
	{
		free(name);
		name = NULL;		
	}	
	
	// Clearing the buffer
	fflush(stdin);
}


/*
 * @brief This method for entering the array of input
 */
void enterArray(char *** arr, int _size)
{
	if (*arr == NULL)
	{
		*(*arr) = (char*) malloc(_size*sizeof(char));
		int idex;
		for (idex = 0; idex < _size; idex++)
		{
			*(arr[idex]) = (char*) malloc(_size * sizeof(char));
		}
	}	
	
	
	int idex;
	for (idex = 0; idex < _size; idex++)
	{
		char * elem = (char*)malloc(_size);
		fgets(elem,_size,stdin);
		
		strcpy((*arr[idex]), elem);
		
		if (elem)
		{
			free(elem);
			elem = NULL;
		}
	}
	
}

#endif  // __SUPPORTEDFUNCTION_H__
