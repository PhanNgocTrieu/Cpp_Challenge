#ifndef __COUNT_ZEROS_H__
#define __COUNT_ZEROS_H__

int calNumOfZeros(long long int a, long long int b) 
{
	long long int i;
	int _count = 0;
	for (i = a; i <= b; i++)
	{
		long long int _powNum = 5;
		while (_powNum <= i)
		{
			if (i % _powNum == 0) {	
				_count++;
				_powNum *= 5;	
			}
			else {
				break;
			}
		}
	}
	return _count;
}



#endif
