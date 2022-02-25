#ifndef ComplexNumber_h
#define ComplexNumber_h

class ComplexNumber
{
private:
    static int count;
    float real, imaginary;
    float radius, angle;
    

public:
    //ComplexNumber(char[] type, float q = 0, float b = 0);
    ComplexNumber(float real = 0, float imaginary = 0);
    //ComplexNumber(float radius = 0, float angle = 0);
    ComplexNumber(const ComplexNumber& cn);
    ComplexNumber& operator=(const ComplexNumber& cn);
    ComplexNumber operator+(const ComplexNumber& cn)const;
    ComplexNumber operator-(const ComplexNumber& cn)const;
    ComplexNumber operator*(const ComplexNumber& cn)const;
    ComplexNumber operator/(const ComplexNumber& cn)const;
    ~ComplexNumber();

    int getCount()const { return count; };

    void setKartesian(double real, double imaginary);

    void setPolar(double radius, double angle);

    void setReal(double real);

    void setImaginary(double imaginary);

    void setRadius(double radius);

    void setAngle(double angle);

    float getReal()const { return real; }

    float getImaginary()const { return imaginary; }

    float getRadius()const { return radius; }

    float getAngle()const { return angle; }

    void calculateRadiusAndAngle();

    void calculateRealAndImaginary();
};

#endif