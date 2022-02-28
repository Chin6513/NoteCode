#ifndef COMPLEX_H_
#define COMPLEX_H_
#include<iostream>

class Complex
{
private:
	double m_Real;
	double m_Imaginary;
public:
	Complex();
	Complex(double Real, double Imaginary);
	~Complex(){};
    Complex operator + (const Complex & c)const;
    Complex operator - (const Complex & c)const;
    Complex operator * (const Complex & c)const;
    Complex operator ~ ();
//friend
    friend Complex & operator * (const double num, Complex & c);
    friend Complex & operator ~ (const Complex & c);
    friend std::ostream & operator << (std::ostream & os, const Complex & c);
    friend std::istream & operator >> (std::istream & is, Complex & c);
};

#endif
