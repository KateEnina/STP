#include "stdafx.h"
#include "TPNumber.h"

TPNumber::TPNumber(float a, int b, int c)
{
	if (b < 2 || b>16 || c < 0)
		throw 1;
	this->a = a;
	this->b = b;
	this->c = c;
}

float TPNumber::Power(int num, int pow)
{
	float res = 1;
	if (pow == 0)
		return 1;

	else if (pow > 0) {
		for (int i = 0; i < pow; i++)
			res *= num;
	}
	else if (pow < 0) {
		for (int i = 0; i < -pow; i++)
			res /= (float)num;
	}
	return res;
}

int TPNumber::CharInt(char c)
{
	c = tolower(c);
	if (c >= '0'&&c <= '9')
		return c - '0';
	else if (c >= 'a'&&c <= 'f')
		return c - 'a' + 10;
	else return -1;
}

char TPNumber::IntChar(int num)
{
	if (num >= 0 && num <= 9)
		return num + '0';
	if (num >= 10 && num <= 15)
		return 'A' + num - 10;
	else return 0;
}

TPNumber::TPNumber(string a, int b, int c)
{
	string integer, fraction;
	if (b < 2 || b>16 || c < 0)
		throw 1;
	bool sign = (a[0] == '-');
	if (sign)
		a.erase(0, 1);

	if (a.find('.', 0) != string::npos) {
		integer = a.substr(0, a.find('.', 0));
		fraction = a.substr(a.find('.', 0) + 1, a.size());
	}
	else {
		integer = a;
		fraction[0] = 0;
	}
	this->a = 0;

	for (int i = 0; i < integer.size(); i++) {
		if (!((integer[i] >= '0' && integer[i] <= '9') || (tolower(integer[i]) >= 'a') && (tolower(integer[i]) <= 'f')) || (CharInt(integer[i]) >= b))
			throw 1;
		this->a += CharInt(integer[i])*Power(b, integer.size() - i - 1);
	}
	for (int i = 0; i < fraction.size(); i++) {
		if (!((fraction[i] >= '0' && fraction[i] <= '9') || (tolower(fraction[i]) >= 'a') && (tolower(fraction[i]) <= 'f')) || (CharInt(fraction[i]) >= b))
			throw 1;
		this->a += CharInt(fraction[i])*Power(b, -(i + 1));
	}
	if (sign)
		this->a = -this->a;
	this->b = b;
	this->c = c;
}

TPNumber TPNumber::Copy()
{
	return *this;
}

TPNumber TPNumber::Reverse()
{
	if (!a) throw 1;
	return TPNumber(1 / a, b, c);
}

TPNumber TPNumber::Sqr()
{
	return TPNumber(a*a, b, c);
}

string TPNumber::GetPString()
{
	stringstream ss;
	string part1 = "", part2 = "";
	bool sign = (a < 0);
	int integer = (int)fabs(a);
	float fraction = fabs(a) - integer;
	while (integer)
	{
		part1.insert(0, 1, IntChar(integer%b));
		integer /= b;
	}
	for (int i = 0; i < c; i++) {
		float tmp = Power(b, -(i + 1));
		int n = 0;
		while (tmp*(n + 1) <= fraction)
		{
			n++;
		}
		fraction -= tmp * (n);
		part2 += IntChar(n);
	}
	if (part1 == "")
		part1 += '0';
	if (sign)
		part1.insert(0, 1, '-');
	return part1 + "." + part2;
}

string TPNumber::GetBString()
{
	int num = b; string res = "";
	while (num)
	{
		res.insert(0, 1, IntChar(num % 10));
		num /= 10;
	}
	return res;
}

string TPNumber::GetCString()
{
	int num = c; string result = "";
	while (num) {
		result.insert(0, 1, IntChar(num % 10));
		num /= 10;
	}
	return result;
}

void TPNumber::SetBString(string bs)
{
	int num = 0;
	for (int i = 0; i < bs.size(); i++)
		num += CharInt(bs[i])*Power(10, bs.size() - i - 1);
	if (num < 2 || num>10)
		throw 1;
	b = num;
}

void TPNumber::SetCString(string cs)
{
	int num = 0;
	for (int i = 0; i < cs.size(); i++)
		num += CharInt(cs[i])*Power(10, cs.size() - i - 1);
	if (c < 0) throw 1;
	c = num;
}

TPNumber TPNumber::Summ(TPNumber member) {
	if (b != member.b || c != member.c) {
		throw invalid_argument("Invalid addition");
	}
	return TPNumber(a + member.a, b, c);
}

TPNumber TPNumber::Substruct(TPNumber member) {
	if (b != member.b || c != member.c) {
		throw invalid_argument("Invalid addition");
	}
	return TPNumber(a - member.a, b, c);
}

TPNumber TPNumber::Multiply(TPNumber member) {
	if (b != member.b || c != member.c) {
		throw invalid_argument("Invalid addition");
	}
	return TPNumber(a * member.a, b, c);
}

TPNumber TPNumber::Divide(TPNumber member) {
	if (b != member.b || c != member.c) {
		throw invalid_argument("Invalid addition");
	}
	return TPNumber(a / member.a, b, c);
}