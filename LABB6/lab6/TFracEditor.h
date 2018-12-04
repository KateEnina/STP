#pragma once
#include"..\..\Lab1\ProjectX\tFrac.h"
#include <string>

using namespace std;

class TFracEditor {
	private:
		string number;
	public:
		TFracEditor();
		~TFracEditor();

		bool isZero();
		string AddSign();
		string AddNumber(unsigned int digit);
		string AddZero();
		string BackSpace();

		string Clear();
		string GetNumber();
		string SetNumber(string &num);
		string AddSplit();

};