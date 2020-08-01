/* viết một vòng for từ 1-50, trong vòng for thực hiện các việc sau:
1. sinh ra x ngẫu nhiên (dùng random), có giá trị từ 1-360
2. tính sin với x ở bước 1, dùng 2 cách tạo và hàm chuẩn, sau đó lấy 2 kết quả trừ cho nhau
3. kiểm tra nếu giá trị tuyệt đối của phép trừ ở bước 2 < 0.00xxxx thì in ra True, còn ko thì in ra False. In theo kiểu này: 
   Test #1 : x = ..., True
   Test #2 : x = ..., True
    ...
   Test #50 : x = ..., True
*/

#include <iostream>
#include <math.h>
#include <time.h>

#define PI 3.1415
#define epsilon 0.000001


long double Factor(long n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n*Factor(n-1);
}


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

void Checking()
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
    int x;
    //int rand_x[3];

    // Initialize random seed: 
    
    Checking();
    //printf("Nhap vao do: ");
    //scanf("%d",&x);
    //double radius = x*PI/180;
    
    //std::cout << "\nSine_by_Trieu: " << Sine(radius) << std::endl;
    //std::cout << "\nSine_by_C: " << sin(radius) << std::endl;
    */
    return 0;
}


//Result:
Test #0: x = 304, True
Test #1: x = 304, True
Test #2: x = 44, True 
Test #3: x = 48, True
Test #4: x = 13, True
Test #5: x = 172, True
Test #6: x = 167, True
Test #7: x = 294, True
Test #8: x = 229, True
Test #9: x = 104, True
Test #10: x = 111, True
Test #11: x = 48, True
Test #12: x = 341, True
Test #13: x = 94, True
Test #14: x = 118, True
Test #15: x = 292, True
Test #16: x = 299, True
Test #17: x = 56, True
Test #18: x = 22, True
Test #19: x = 112, True
Test #20: x = 184, True
Test #21: x = 25, True
Test #22: x = 79, True
Test #23: x = 349, True
Test #24: x = 293, True
Test #25: x = 137, True
Test #26: x = 228, True
Test #27: x = 263, True
Test #28: x = 356, True
Test #29: x = 175, True
Test #30: x = 25, True
Test #31: x = 66, True
Test #32: x = 192, True
Test #33: x = 322, True
Test #34: x = 224, True
Test #35: x = 151, True
Test #36: x = 104, True
Test #37: x = 25, True
Test #38: x = 124, True
Test #39: x = 263, True
Test #40: x = 120, True
Test #41: x = 156, True
Test #42: x = 269, True
Test #43: x = 247, True
Test #44: x = 248, True
Test #45: x = 74, True
Test #46: x = 126, True
Test #47: x = 100, True
Test #48: x = 208, True
Test #49: x = 164, True
