#include "solver.hpp"
using namespace solver;
using namespace std;
using solver::solve; using solver::RealVariable; using solver::ComplexVariable;
RealVariable  solver::operator+( RealVariable r, double n)
{
	return RealVariable(r.getA(), r.getB(), r.getC() + n);
}

RealVariable  solver::operator+(double n, RealVariable r)
{
	return RealVariable(r.getA(), r.getB(), r.getC() + n);
}

RealVariable  solver::operator+(RealVariable l,RealVariable r)
{
	return RealVariable(l.getA() + r.getA(), l.getB() + r.getB(), l.getC() + r.getC());
}

RealVariable  solver::operator*(RealVariable r, double n)
{
	return RealVariable(r.getA() * n, r.getB() * n, r.getC() * n);
}

RealVariable  solver::operator*(double n, RealVariable r)
{
	return RealVariable(r.getA() * n, r.getB() * n, r.getC() * n);
}

RealVariable  solver::operator*(RealVariable l, RealVariable r)
{
	if (l.getA() != 0 && r.getA() != 0) throw invalid_argument("power is too big");
	if (l.getA()!= 0 && r.getB() != 0) throw invalid_argument("power is too big");
	if (l.getB() != 0 && r.getA()!= 0) throw invalid_argument("power is too big");

	return RealVariable(l.getA() * r.getC() + r.getA() * l.getC() + l.getB() * r.getB(),
		l.getB() * r.getC()+ r.getB() * l.getC(),
		l.getC() * r.getC());
}

RealVariable  solver::operator-(RealVariable r, double n)
{
	return RealVariable(r.getA(),r.getB(),r.getC()-n);
}

RealVariable  solver::operator-(double n, RealVariable r)
{
	return RealVariable(-1*r.getA(),-1*r.getB(), n-r.getC());
}

RealVariable  solver::operator-(RealVariable l, RealVariable r)
{
	return RealVariable(l.getA()-r.getA(),l.getB()-r.getB(),l.getC()-r.getC());
}

RealVariable  solver::operator==(RealVariable r, double n)
{
	return r-n;
}

RealVariable  solver::operator==(double n, RealVariable r)
{
	return n-r;
}

RealVariable  solver::operator==(RealVariable l, RealVariable r)
{
	return l-r;
}

RealVariable  solver::operator^(RealVariable r, double n)
{
	if (n == 2) {
		return r*r;
	}
	if (n == 1) {
		return r;
	}
	if (n == 0)
	{
		return RealVariable(0, 0, 1);
	}
	throw invalid_argument("power is not vaild: ");
}

RealVariable  solver::operator/(RealVariable r, double n)
{
	if (n==0) throw invalid_argument("cannot divided by zero");

	return RealVariable(r.getA()/n,r.getB()/n,r.getC()/n);
}

RealVariable  solver::operator/(RealVariable l, RealVariable r)
{
	if (r.getA()==0&&r.getB()==0&&r.getC()==0)  throw invalid_argument("cannot divided by zero");
	if (r.getA() == l.getA() && r.getB() == l.getB() && r.getC() == l.getC())  return RealVariable(0, 0, 1);
	if (l.getA() == 0 && l.getB() == 0 && l.getC() == 0) return RealVariable(0,0,1);
	if (l.getA()==r.getA() && l.getC()==0&&r.getC()==0&& r.getB() != 0) return RealVariable(0,l.getB()/r.getB(), 0);
	if (l.getB() == r.getB() && l.getC() == 0 && r.getC() == 0&& r.getA() != 0) return RealVariable(l.getA() / r.getA(),0, 0);
	if (l.getB() == r.getB() && l.getA() == 0 && r.getA() == 0&&r.getC()!=0) return RealVariable(0, 0, l.getC() / r.getC());

	throw invalid_argument("no option to divid in this class");
}

ComplexVariable  solver::operator+(ComplexVariable r, complex<double> n)
{
	return ComplexVariable(r.getA(),r.getB(),r.getC()+n);
}

ComplexVariable  solver::operator+(complex<double> n, ComplexVariable r)
{
	return ComplexVariable(r.getA(),r.getB(),r.getC()+n);
}

ComplexVariable  solver::operator+(ComplexVariable l, ComplexVariable r)
{
	return ComplexVariable(l.getA()+r.getA(),r.getB()+l.getB(),r.getC()+l.getC());
}

ComplexVariable  solver::operator*(ComplexVariable r, complex<double> n)
{
	return ComplexVariable(r.getA() * n, r.getB() * n, r.getC() * n);
}

ComplexVariable  solver::operator*(complex<double> n, ComplexVariable r)
{
	return ComplexVariable(r.getA() * n, r.getB() * n, r.getC() * n);
}

ComplexVariable  solver::operator*(ComplexVariable l, ComplexVariable r)
{
	if (l.getA() != complex<double>(0.0,0.0) && r.getA() != complex<double>(0.0, 0.0)) throw invalid_argument("power is too big");
	if (l.getA() != complex<double>(0.0, 0.0) && r.getB() != complex<double>(0.0, 0.0)) throw invalid_argument("power is too big");
	if (l.getB() != complex<double>(0.0, 0.0) && r.getA() != complex<double>(0.0, 0.0)) throw invalid_argument("power is too big");

	return ComplexVariable(l.getA() * r.getC() + r.getA() * l.getC() + l.getB() * r.getB(),
		l.getB() * r.getC() + r.getB() * l.getC(),
		l.getC() * r.getC());
}

ComplexVariable  solver::operator-(ComplexVariable r, complex<double> n)
{
	return ComplexVariable(r.getA(), r.getB(), r.getC() - n);
}

ComplexVariable  solver::operator-(complex<double> n, ComplexVariable r)
{
	return ComplexVariable(-r.getA(), -r.getB(), n - r.getC());
}

ComplexVariable  solver::operator-(ComplexVariable l, ComplexVariable r)
{
	return ComplexVariable(l.getA()-r.getA(),l.getB()-r.getB(),l.getC()-r.getC());
}

ComplexVariable  solver::operator==(ComplexVariable r, complex<double> n)
{
	return r-n;
}

ComplexVariable  solver::operator==(complex<double> n, ComplexVariable r)
{
	return n-r;
}

ComplexVariable  solver::operator==(ComplexVariable l, ComplexVariable r)
{
	return l-r;
}

ComplexVariable  solver::operator^(ComplexVariable r, double n)
{
	if (n == 2) {
		return r * r;
	}
	if (n == 1) {
		return r;
	}
	if (n == 0)
	{
		return ComplexVariable(0, 0, 1);
	}
	throw invalid_argument("power is not vaild: ");
}

ComplexVariable  solver::operator/(ComplexVariable r, complex<double> n)
{
	if (n == complex<double>(0, 0))throw invalid_argument("cannot divid by zero");
	return ComplexVariable(r.getA()/n,r.getB()/n,r.getC()/n);
}

double solver::solve(RealVariable ex)
{
	double a = ex.getA(), b = ex.getB(), c = ex.getC();

	if (a==0&&b==0&&c==0) return INFINITY;

	if (a == 0) { // The equation is linear
		if ((b == 0) && (c != 0)) throw invalid_argument("There is no solution");
		else
		{
			return -c/b;
		}
	}

	double x1,x2, discriminant;

	discriminant = b * b - 4 * a * c;

	if (discriminant >= 0) {
		x1 = (-b + sqrt(discriminant)) / (2 * a);
		x2 = (-b + sqrt(discriminant)) / (2 * a);
		return x1;
	}
	throw invalid_argument("There is no real solution");
}

double solver::solve(bool ex)
{
	return 0.0;
}

complex<double> solver::solve(ComplexVariable ex)
{
	complex<double> a = ex.getA(), b = ex.getB(), c = ex.getC();

	if (ex.getA()== complex<double> (0,0)&&ex.getB()== complex<double> (0,0)&&ex.getC()== complex<double>(0,0)) return INFINITY;

	if (a == complex<double>(0.0, 0.0)) { 
		if ((b == complex<double>(0.0, 0.0)) && (c != complex<double>(0.0, 0.0))) throw invalid_argument("There is no solution");
		else 
		return -c / b;
	}

	complex<double> x1, discriminant;

	discriminant = b * b - complex<double>(4.0, 0.0) * a * c;

	x1 = (-b + sqrt(discriminant)) / (complex<double>(2.0, -0.0) * a);
	
	return x1;
}

ComplexVariable solver::operator/(ComplexVariable l, ComplexVariable r)
{
	if (r.getA() == complex<double>(0,0) && r.getB() == complex<double>(0, 0) && r.getC() == complex<double>(0, 0))  throw invalid_argument("cannot divided by zero");
	if (r.getA() == l.getA() && r.getB() == l.getB() && r.getC() == l.getC())  return ComplexVariable(0, 0, 1);
	if (l.getA() == complex<double>(0, 0) && l.getB() == complex<double>(0, 0) && l.getC() == complex<double>(0, 0)) return ComplexVariable(0, 0, 1);
	if (l.getA() == r.getA() && l.getC() == complex<double>(0, 0) && r.getC() == complex<double>(0, 0) && r.getB() != complex<double>(0, 0)) return ComplexVariable(0, l.getB() / r.getB(), 0);
	if (l.getB() == r.getB() && l.getC() == complex<double>(0, 0) && r.getC() == complex<double>(0, 0) && r.getA() != complex<double>(0, 0)) return ComplexVariable(l.getA() / r.getA(), 0, 0);
	if (l.getB() == r.getB() && l.getA() == complex<double>(0, 0) && r.getA() == complex<double>(0, 0) && r.getC() != complex<double>(0, 0)) return ComplexVariable(0, 0, l.getC() / r.getC());

	throw invalid_argument("no option to divid in this class");
}
