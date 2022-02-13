#include <stdio.h>
#include <math.h>

#define epsilon 0.000001

double Sine(double x)
{
    double sine = 0;
    double temp;
    long int n = 0;
    do
    {
        temp = pow(x,2*n+1)/Factor(2*n+1);
        sine = sine + pow(-1,n)*temp;
        n = n + 1;
    } while (fabs(temp) >= epsilon);
    
    return sine;
}

void CheckingSine()
{
    int rand_num;
    srand(time(NULL));
    double radius;
    for (int i = 0; i < 50; i++)
    {
        rand_num = rand() % 360 + 1;
        radius = rand_num*PI/180;
        if (fabs(Sine(radius) - sin(radius)) < epsilon) //epsilon = 0.000001
        {
            std::cout << "\nTest #" << i << ": x = " << rand_num << ", True";
        }
        else
        {
            std::cout << "\nTest #" << i << ": x = " << rand_num << ", False";
        }
    }
}


int main()
{
    CheckingSine();
    return 0;
}
