#pragma once
#include <string>
using namespace std;

class TComplexEditor {
	private:
		string number;
		bool isRealPartEdit;
	public:
		TComplexEditor();
		~TComplexEditor();
		bool isZero();
		string AddSign();
		string AddNumber(unsigned int numbr);
		string AddZero();
		string BackSpace();
		string Clear();
		string AddSplit();
		void SetNumber(string &numbr);
		string GetNumber();

};