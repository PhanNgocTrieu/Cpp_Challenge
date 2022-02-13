#include <stdio.h>

int soTrungGian(double _x, double _y, double _z)
{
    return ((_x > _y && _x < _z) || (_x > _z && _x < _y) ? _x : (_y < _x && _y > _z) || (_y > _z && _y < _x) ? _y : _z);
}

int main()
{
    int _x,_y,_z;

    do 
    {
        fflush(stdin);
        printf("Nhap x: ");
    } while (scanf("%lf",&_x) != 1);

    do 
    {
        fflush(stdin);
        printf("Nhap y: ");
    } while (scanf("%lf",&_y) != 1);

    do 
    {
        fflush(stdin);
        printf("Nhap z: ");
    } while (scanf("%lf",_z) != 1);

    printf("So trung gian: %lf\n",soTrungGian(_x,_y,_z));

    return 0;
}