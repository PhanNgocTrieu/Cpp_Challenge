#ifndef __SINE_H__
#define __SINE_H__

#include <stdio.h>
#include <math.h>

#define PI 3.142
#define epsilon 0.000001

double Factor(int _number)
{
	if (_number > 1)
		return _number * Factor(_number - 1);
	else
		return 1.0;
}

double Sine(double x)
{
    double sine = 0;
    double temp = 0;
    int n = 0;
    do
    {
        temp = pow(x,2*n+1)/Factor(2*n+1);
        sine += pow(-1.0,n)*temp;
        n++;		  
    } while (fabs(temp) >= epsilon);
    printf("sum: %lf\n",sine);
    return sine;
}

void calculateSine_Solving()
{
	double _x;
	double radius;
	
    printf("Enter x: ");
    scanf("%lf",&_x);
	radius = _x * (PI/180);
	
    if (fabs(Sine(radius) - sin(radius)) < epsilon) // comparasion with sine of lib ---> if fabs(Sine(x) - sine(x)) < epsilon --> equal
    {
    	printf("Result of calculating Sine: %lf\n",Sine(radius));
    	printf("Sine(x) from library: %lf\n",sin(radius));
    }
    else
    {
        printf("Comparing to the sin(x) from lirary: False!\n");
    }
}

#endif // __SINE_H__
