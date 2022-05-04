#include "complex.h"

Complex::Complex() {
    this->_real = 0.0;
    this->_img = 0.0;
}

Complex::Complex(const double& real, const double& img) : _real(real), _img(img) {
}

Complex::~Complex() {

}

void Complex::setImg(const double& img) {
    this->_img = img;
}

void Complex::setReal(const double& real) {
    this->_real = real;
}

double Complex::getImg() const {
    return this->_img;
}

double Complex::getReal() const {
    return this->_real;
}

Complex Complex::operator+(const Complex& _other) {
    Complex newComplex;
    newComplex.setReal(this->_real + _other._real);
    newComplex.setImg(this->_img + _other._img);
    return newComplex;
}

Complex Complex::operator*(const Complex& _other) {
    Complex newComplex;
    newComplex.setReal((this->_real*_other._real) - (this->_img + _other._img));
    newComplex.setImg((this->_real*this->_img) + (this->_img*_other._real));

    return newComplex;
}

Complex& Complex::operator=(const Complex& _other) {
    
    this->_img = _other._img;
    this->_real = _other._real;

    return *this;
}