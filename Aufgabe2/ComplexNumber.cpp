#include <iostream>
#include <cmath>
using namespace std;
#include "ComplexNumber.h"

int ComplexNumber::count = 0;

// ComplexNumber::ComplexNumber(char[] type,double q, double b)
// {
//     if (type == "kartesian" || type == "k")
//     {
//         setKartesian(q, b);
//     }
//     else if (type == "polar" || type == "p")
//     {
//         setPolar(q, b);
//     }
//     else
//     {
//         this->real = 0;
//         this->imaginary = 0;
//         this->radius = 0;
//         this->angle = 0;
//     }
//     count++;
// }

ComplexNumber::ComplexNumber(float real, float imaginary)
: real(real), imaginary(imaginary)
{
    count++;
    calculateRadiusAndAngle();
}

// ComplexNumber::ComplexNumber(float radius, float angle)
// {
//     this->radius = radius;
//     this->angle = angle;
//     calculateRealAndImaginary();
//     count++;
// }

ComplexNumber::ComplexNumber(const ComplexNumber& cn)
: real(cn.real), imaginary(cn.imaginary), radius(cn.radius), angle(cn.angle)
{
    count++;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& cn)
{
    this->real = cn.real;
    this->imaginary = cn.imaginary;
    this->radius = cn.radius;
    this->angle = cn.angle;
    return *this;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& cn)const
{
    ComplexNumber result;
    result.real = this->real + cn.real;
    result.imaginary = this->imaginary + cn.imaginary;
    result.calculateRadiusAndAngle();
    return result;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& cn)const
{
    ComplexNumber result;
    result.real = this->real - cn.real;
    result.imaginary = this->imaginary - cn.imaginary;
    result.calculateRadiusAndAngle();
    return result;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& cn)const
{
    ComplexNumber result;
    result.real = this->real * cn.real - this->imaginary * cn.imaginary;
    result.imaginary = this->real * cn.imaginary + this->imaginary * cn.real;
    result.calculateRadiusAndAngle();
    return result;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& cn)const
{
    ComplexNumber result;
    result.real = (this->real * cn.real + this->imaginary * cn.imaginary) / (cn.real * cn.real + cn.imaginary * cn.imaginary);
    result.imaginary = (this->imaginary * cn.real - this->real * cn.imaginary) / (cn.real * cn.real + cn.imaginary * cn.imaginary);
    result.calculateRadiusAndAngle();
    return result;
}

ComplexNumber::~ComplexNumber()
{
    count--;
}

void ComplexNumber::setKartesian(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
    calculateRadiusAndAngle();
}

void ComplexNumber::setPolar(double radius, double angle)
{
    this->radius = radius;
    this->angle = angle;
    calculateRealAndImaginary();
}

void ComplexNumber::setReal(double real)
{
    this->real = real;
    calculateRadiusAndAngle();
}

void ComplexNumber::setImaginary(double imaginary)
{
    this->imaginary = imaginary;
    calculateRadiusAndAngle();
}

void ComplexNumber::setRadius(double radius)
{
    this->radius = radius;
    calculateRealAndImaginary();
}

void ComplexNumber::setAngle(double angle)
{
    this->angle = angle;
    calculateRealAndImaginary();
}

void ComplexNumber::calculateRadiusAndAngle()
{
    this->radius = sqrt(real * real + imaginary * imaginary);
    this->angle = imaginary >= 0 ? acos(real / radius) : -acos(real / radius);
}

void ComplexNumber::calculateRealAndImaginary()
{
    this->real = radius * cos(angle);
    this->imaginary = radius * sin(angle);
}