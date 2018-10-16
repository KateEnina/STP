#include "stdafx.h"
#include <sstream>
#include <string>

using namespace std;
class tComplex
{
private:
	float a, b;
public:
	tComplex(float, float);
	tComplex(std::string);
	tComplex Copy();
	tComplex Summ(tComplex d);
	tComplex Multiply(tComplex d);
	tComplex Square();
	tComplex Obratnoe();
	tComplex Vichest(tComplex d);
	tComplex Del(tComplex d);
	tComplex Minus();
	float Module();
	float AngleRad();
	float AngleGrad();
	tComplex Stepen(int n);
	tComplex Root(int n, int i);
	int fromStringtoINT(std::string);
	bool Equality(tComplex d);
	bool NoEquality(tComplex d);
	float GetRe();
	float GetIm();
	string GetReSTR();
	string GetImSTR();
	string GetTComplexSTR();
	tComplex operator == (tComplex);

};



