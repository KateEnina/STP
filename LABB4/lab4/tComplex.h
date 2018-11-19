#include "stdafx.h"
#include <sstream>
#include <string>

using namespace std;
class TComplex
{
private:
	float a, b;
public:
	TComplex(float, float);
	TComplex(std::string);
	TComplex Copy();
	TComplex Summ(TComplex d);
	TComplex Multiply(TComplex d);
	TComplex Square();
	TComplex Obratnoe();
	TComplex Vichest(TComplex d);
	TComplex Del(TComplex d);
	TComplex Minus();
	float Module();
	float AngleRad();
	float AngleGrad();
	TComplex Stepen(int n);
	TComplex Root(int n, int i);
	int fromStringtoINT(std::string);
	bool Equality(TComplex d);
	bool NoEquality(TComplex d);
	float GetRe();
	float GetIm();
	string GetReSTR();
	string GetImSTR();
	string GetTComplexSTR();
};

