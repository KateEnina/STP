#pragma once
#include <string>
using namespace std;

class TPNumberEditor {
private:
	string number;
	unsigned int base;
public:
	TPNumberEditor();
	~TPNumberEditor();
	bool isZero();
	string AddSign();
	string AddNumber(unsigned int numbr);
	string AddZero();
	string BackSpace();
	string Clear();
	string AddSplit();
	void SetNumber(std::string &numbr);
	string GetNumber();

};