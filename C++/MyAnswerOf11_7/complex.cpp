#include"complex.h"

//默认构造函数
Complex::Complex()
{
	m_Real = 0.0;
	m_Imaginary = 0.0;
}

//构造函数
Complex::Complex(double Real, double Imaginary)
{
	m_Real = Real;
	m_Imaginary = Imaginary;
}

//加法运算符重载
Complex Complex::operator+ (const Complex & c) const
{
	Complex temp;
	temp.m_Real = m_Real + c.m_Real;
	temp.m_Imaginary = m_Imaginary + c.m_Imaginary;
	return temp;
}

//减法运算符重载
Complex::Complex & operator- (const & Complex c) const
{
	Complex temp;
	temp.m_Real = m_Real - c.m_Real;
	temp.m_Imaginary = m_Imaginary - c.m_Imaginary;
	return temp;
}

//两个复数乘法重载
Complex::Complex & operator* (const & Complex c) const
{
	Complex temp;
	temp.m_Real = ((m_Real * c.m_Real) - (m_Imaginary * c.m_Imaginary));
	temp.m_Imaginary = ((m_Real * c.m_Imaginary) + (m_Imaginary * c.m_Real));
	return temp;
}

//实数和复数乘法运算符重载
Complex & operator* (const double num, const & Complex c)
{
	Complex temp;
	temp.m_Real = num * c.m_Real;
	temp.m_Imaginary = num * m_Imaginary;
	return temp;
}

//共轭运算符重载
Complex & operator~ (void, const & Complex c)
{
	c.m_Imaginary = 0 - m_Imaginary;
	return c;
}

std::ostream & operator<<(std::ostream os, const Complex & c)
{
	os << '(' << c.m_Real << ',' << c.m_Imaginary << "i)";
	return os;
}

std::istream & operator>>(std::istream is, Complex & c)
{
	std::cout << "real: ";
	is >> c.m_Real;
	std::cout << "imaginary: ";
	is >> c.m_Imaginary;
}
