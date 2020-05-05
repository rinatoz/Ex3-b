#pragma once
#include <iostream>
#include <complex>

using namespace std;
namespace solver
{
	class RealVariable
	{

	private:
		double a;
		double b;
		double c;

	public:

		RealVariable() { this->a = 0; this->b = 1; this->c = 0; }
		RealVariable(double a1, double b1, double c1) { this->a = a1; this->b = b1; this->c = c1; }

		double getA() { return this->a; };
		double getB() { return this->b; };
		double getC() { return this->c; };

		friend RealVariable operator+(RealVariable r,double n);
		friend RealVariable operator+( double n,  RealVariable r);
		friend RealVariable operator+( RealVariable l, RealVariable r);

		friend RealVariable operator*(RealVariable r, double n);
		friend RealVariable operator*(double n, RealVariable r);
		friend RealVariable operator*(RealVariable l, RealVariable r);

		friend RealVariable operator-(RealVariable r, double n);
		friend RealVariable operator-(double n, RealVariable r);
		friend RealVariable operator-(RealVariable l, RealVariable r);

		friend RealVariable operator==(RealVariable r, double n);
		friend RealVariable operator==(double n, RealVariable r);
		friend RealVariable operator==(RealVariable l, RealVariable r);

		friend RealVariable operator^(RealVariable r, double n);
		friend RealVariable operator/(RealVariable r, double n);
		friend RealVariable operator/(RealVariable l, RealVariable r);

	};

	class ComplexVariable
	{
	private:
		complex<double> a;
		complex<double> b;
		complex<double> c;

	public:
		ComplexVariable() { this->a = 0; this->b = 1; this->c = 0; }
		ComplexVariable(complex<double> a, complex<double> b, complex<double> c) { this->a =a; this->b =b; this->c =c; }
		complex<double> getA() { return a; }
		complex<double> getB() { return b; }
		complex<double> getC() { return c; }

		friend ComplexVariable operator+(ComplexVariable r, complex<double> n);
		friend ComplexVariable operator+(complex<double> n, ComplexVariable r);
		friend ComplexVariable operator+(ComplexVariable l, ComplexVariable r);

		friend ComplexVariable operator*(ComplexVariable r, complex<double> n);
		friend ComplexVariable operator*(complex<double> n, ComplexVariable r);
		friend ComplexVariable operator*(ComplexVariable l, ComplexVariable r);

		friend ComplexVariable operator-(ComplexVariable r, complex<double> n);
		friend ComplexVariable operator-(complex<double> n, ComplexVariable r);
		friend ComplexVariable operator-(ComplexVariable l, ComplexVariable r);

		friend ComplexVariable operator==(ComplexVariable r, complex<double> n);
		friend ComplexVariable operator==(complex<double> n, ComplexVariable r);
		friend ComplexVariable operator==(ComplexVariable l, ComplexVariable r);

		friend ComplexVariable operator^(ComplexVariable r, double n);
		friend ComplexVariable operator/(ComplexVariable r, complex<double> n);
		friend ComplexVariable operator/(ComplexVariable l, ComplexVariable r);

	};


	double solve(RealVariable ex);
	double solve(bool ex);
	complex<double> solve(ComplexVariable ex);


}

