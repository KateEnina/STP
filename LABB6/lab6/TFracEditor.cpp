#include "stdafx.h"
#include "TFracEditor.h"
#include "..\..\Lab1\ProjectX\tFrac.h"

TFracEditor::TFracEditor() : number("0") {
}

TFracEditor::~TFracEditor() {}


bool TFracEditor:: isZero() {
	return TFrac(number).getDrobString() == "0/1";
}

string TFracEditor::AddSign() {
	if (number[0] == '-') {
		number.erase(number.begin());
	}
	else {
		if (!isZero()) {
			number = "-" + number;
		}
	}
	return number;
}

string TFracEditor::AddNumber(unsigned int numbr) {
	if (number == "0") {
		number = "";
	}
	if (numbr >= 0 && numbr <=9)
		number += (char)('0' + numbr);
	return number;
}

string TFracEditor::AddZero() {
	return number.back() != '/' ? AddNumber(0) : number;
}
string TFracEditor::BackSpace() {
	number.pop_back();
	if (number == "-" || number.empty()) {
		number = "0";
	}
	return number;
}
string TFracEditor::Clear() {
	number = "0";
	return number;
}

string TFracEditor::GetNumber() {
	return TFrac(number).getDrobString();
}

string TFracEditor::SetNumber(string &numbr) {
	int count=0;
	for (int i = 0; i < numbr.size(); i++) 
	{
		if ((numbr[i] >= '0' && numbr[i] <= '9') || numbr[i] == '/' || numbr[i] == '-')
		{
			try
			{
				if (numbr[i] == '/')
				{
					count++;
				}
				if (count > 1)
					throw 1;
			}
			catch (int e)
			{
				cout << "Îøèáêà " << e << endl;
				throw e;
			}
			 
			try
			{
				if (numbr[i] == '-')
				{
					if (i != 0) throw 2;
				}
			}
			catch (int e)
			{
				cout << "Îøèáêà " << e << endl;
				throw e;
			}
		}
	}
	return number = TFrac(numbr).getDrobString();
}

string TFracEditor::AddSplit() {
	if (number.find('/') == string::npos) {
		number = number + '/';
	}
	return number;
}
