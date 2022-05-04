#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <iostream>

class Complex {
    public:
        Complex();
        Complex(const double& real, const double& img);
        ~Complex();

        void setImg(const double& img);
        void setReal(const double& real);
        double getImg() const;
        double getReal() const;

        Complex operator+(const Complex& _other);
        Complex operator*(const Complex& _other);

        Complex& operator=(const Complex& _other);

    private:
        double _real;
        double _img;
};

#endif