#ifndef __CDCS_H__
#define __CDCS_H__

#include <stdio.h>

const char CHAR_55 = 55;
const char CHAR_48 = 48;

/*
 * @brief: this function using for convert number to _number with complicited base 
 */
int chuyenDoiCoSo(long long int _number, int _base)
{
	if (_number < 0)
	{
		printf("Gia tri chuyen doi khong hop le\n");
		return 0;
	}
	if (_base < 2 || _base > 16)
	{
		printf("Co so chuyen doi khong hop le\n");
		return 0;
	}
	
	char _arrayOfNumber[50];
	long long int _savedNumber = _number;
	// Counting index of array
	int _count = 0;
	int _idex;
	int _value;	
	
	while (_number > 0)
	{
		if (_base > 10)
		{
			_value = _number % _base;	
			if (_value >= 10)
			{
				_arrayOfNumber[_count] = (char)(_value + CHAR_55);
				_count++;
			}
			else
			{
				_arrayOfNumber[_count] = (char)(_value + CHAR_48);
				_count++;
			}
		}
		else
		{
			_arrayOfNumber[_count] = (char)((_number % _base) + CHAR_48);
			_count++;
		}
		
		_number = _number / _base;
	}
	
	printf("Convert %lld to base of %d : ", _savedNumber, _base);
	for (_idex = _count - 1; _idex >= 0; --_idex)
	{
		printf("%c",_arrayOfNumber[_idex]);
	}
	printf("\n");
	
	return 1;
}

#endif // __CDCS_H__
