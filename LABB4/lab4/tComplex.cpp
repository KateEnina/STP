#include "stdafx.h"
#include <iostream>
#include "TComplex.h"
#include <string>
#include <cmath>
#include <iomanip>


#define M_PI 3.14
using namespace std;

TComplex::TComplex(float im, float re)
{
	a = im;
	b = re;
}
TComplex::TComplex(string str)
{
	size_t p = str.find("i"), t = str.find("*");
	this->a = stof(str.substr(0, p - 1));
	this->b = stof(str.substr(t + 1));
	if (str.at(p - 1) == '-') this->b *= -1;
}
int TComplex::fromStringtoINT(string str) {
	long long c = 0; int n = str.size();
	for (int i = 0; i < n; i++) {
		c += (str.at(n - i - 1) - '0') * pow(10, i);
	}
	return c;
}
TComplex TComplex::Copy()
{
	TComplex copy(a, b);
	return copy;
}
TComplex TComplex::Summ(TComplex d)
{
	TComplex summ((a + d.a), (b + d.b));
	return summ;
}
TComplex TComplex::Multiply(TComplex d)
{
	TComplex multiply(((a*d.a) - (b*d.b)), ((a*d.b) + (b*d.a)));
	return multiply;
}
TComplex TComplex::Square()
{
	TComplex square(((a*a) - (b*b)), ((a*b) + (a*b)));
	return square;
}
TComplex TComplex::Obratnoe()
{
	return TComplex((a / (a*a + b * b)), ((-b / (a*a + b * b))));
}
TComplex TComplex::Vichest(TComplex d)
{
	TComplex subtract((a - d.a), (b - d.b));
	return subtract;
}
TComplex TComplex::Del(TComplex d)
{
	TComplex del(((a*d.a + b * d.b) / (d.a*d.a + d.b*d.b)), ((d.a*b - d.b*a) / (d.a*d.a + d.b*d.b)));
	return del;
}
TComplex TComplex::Minus()
{
	a = -a;
	b = -b;
	TComplex minus(a, b);
	a = -a;
	b = -b;
	return minus;
}
float TComplex::Module()
{
	return sqrt(a*a + b * b);
}
float TComplex::AngleRad()
{
	if (a == 0 && b > 0) return M_PI / 2;
	if (a == 0 && b < 0) return -M_PI / 2;
	if (a == 0 && b == 0) return 0;
	if (a > 0) return atan2(b, a);
	else
		return atan2(b, a) + M_PI;
}
float TComplex::AngleGrad()
{
	return (AngleGrad() * 180) / M_PI;
}
TComplex TComplex::Stepen(int n)
{
	return TComplex((pow(Module(), n)*cos(n*AngleRad())), (pow(Module(), n)*sin(n*AngleRad())));
}
TComplex TComplex::Root(int n, int i)
{
	int k = i - 1;
	return TComplex((pow(Module(), 1 / n)*cos((AngleRad() + 2 * k*M_PI) / n)), (sin((AngleRad() + 2 * k*M_PI) / n)));
}
bool TComplex::Equality(TComplex d)
{
	if (a == d.a && b == d.b)return true;
	else return false;
}
bool TComplex::NoEquality(TComplex d)
{
	if (a != d.a || b != d.b) return true;
	else return false;
}

float TComplex::GetRe()
{
	return a;
}

float TComplex::GetIm()
{
	return b;
}

string TComplex::GetReSTR()
{
	return to_string(a);
}

string TComplex::GetImSTR()
{
	return to_string(b);
}

string TComplex::GetTComplexSTR()
{
	if (b >= 0) return to_string(a) + "+i*" + to_string(b);
	else return to_string(a) + "-i*" + to_string(-b);
}