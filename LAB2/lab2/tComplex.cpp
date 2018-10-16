#include "stdafx.h"
#include <iostream>
#include "tComplex.h"
#include <string>
#include <cmath>
#include <iomanip>


#define M_PI 3.14
using namespace std;

tComplex::tComplex(float im, float re)
{
	a = im;
	b = re;
}
tComplex::tComplex(string str)
{
	size_t p = str.find("i"), t = str.find("*");
	this->a = stof(str.substr(0, p - 1));
	this->b = stof(str.substr(t + 1));
	if (str.at(p - 1) == '-') this->b *= -1;
}
int tComplex::fromStringtoINT(string str) {
	long long c = 0; int n = str.size();
	for (int i = 0; i < n; i++) {
		c += (str.at(n - i - 1) - '0') * pow(10, i);
	}
	return c;
}
tComplex tComplex::Copy()
{
	tComplex copy(a, b);
	return copy;
}
tComplex tComplex::Summ(tComplex d)
{
	tComplex summ((a + d.a), (b + d.b));
	return summ;
}
tComplex tComplex::Multiply(tComplex d)
{
	tComplex multiply(((a*d.a) - (b*d.b)), ((a*d.b) + (b*d.a)));
	return multiply;
}
tComplex tComplex::Square()
{
	tComplex square(((a*a) - (b*b)), ((a*b) + (a*b)));
	return square;
}
tComplex tComplex::Obratnoe()
{
	return tComplex((a / (a*a + b * b)), ((-b / (a*a + b * b))));
}
tComplex tComplex::Vichest(tComplex d)
{
	tComplex subtract((a - d.a), (b - d.b));
	return subtract;
}
tComplex tComplex::Del(tComplex d)
{
	tComplex del(((a*d.a + b * d.b) / (d.a*d.a + d.b*d.b)), ((d.a*b - d.b*a) / (d.a*d.a + d.b*d.b)));
	return del;
}
tComplex tComplex::Minus()
{
	a = -a;
	b = -b;
	tComplex minus(a, b);
	a = -a;
	b = -b;
	return minus;
}
float tComplex::Module()
{
	return sqrt(a*a + b * b);
}
float tComplex::AngleRad()
{
	if (a == 0 && b > 0) return M_PI / 2;
	if (a == 0 && b < 0) return -M_PI / 2;
	if (a == 0 && b == 0) return 0;
	if (a > 0) return atan2(b, a);
	else
		return atan2(b, a) + M_PI;
}
float tComplex::AngleGrad()
{
	return (AngleGrad() * 180) / M_PI;
}
tComplex tComplex::Stepen(int n)
{
	return tComplex((pow(Module(), n)*cos(n*AngleRad())), (pow(Module(), n)*sin(n*AngleRad())));
}
tComplex tComplex::Root(int n, int i)
{
	int k = i - 1;
	return tComplex((pow(Module(), 1 / n)*cos((AngleRad() + 2 * k*M_PI) / n)), (sin((AngleRad() + 2 * k*M_PI) / n)));
}
bool tComplex::Equality(tComplex d)
{
	if (a == d.a && b == d.b)return true;
	else return false;
}
bool tComplex::NoEquality(tComplex d)
{
	if (a != d.a || b != d.b) return true;
	else return false;
}

float tComplex::GetRe()
{
	return a;
}

float tComplex::GetIm()
{
	return b;
}

string tComplex::GetReSTR()
{
	return to_string(a);
}

string tComplex::GetImSTR()
{
	return to_string(b);
}

string tComplex::GetTComplexSTR()
{
	if (b >= 0) return to_string(a) + "+i*" + to_string(b);
	else return to_string(a) + "-i*" + to_string(-b);
}
