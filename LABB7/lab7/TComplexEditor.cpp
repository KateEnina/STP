#include "stdafx.h"
#include "..\..\lab2\lab2\tComplex.h"
#include "TComplexEditor.h"
#include <regex>


TComplexEditor::TComplexEditor() : number("0"), isRealPartEdit(true) {
}

TComplexEditor:: ~TComplexEditor() {}

bool TComplexEditor::isZero() {
	return TComplex(number).GetTComplexSTR() == TComplex(0, 0).GetTComplexSTR();
}


string TComplexEditor::AddSign() {
	if (isRealPartEdit) {
		if (number[0] == '-') {
			number.erase(number.begin());
		}
		else {
			if (number[0] != '0') {
				number = "-" + number;
			}
		}
	}
	else {
		auto pos = number.find("i*");
		number[pos - 1] = (number[pos - 1] == '-') ? '+' : '-';
	}
	return number;
}


string TComplexEditor::AddNumber(unsigned int numbr) {
	auto pos = isRealPartEdit ? 0 : number.find('*') + 1;
	if (number[pos] == '0') {
		number.pop_back();
	}
	if (numbr >= 0 && numbr <= 9)
	number += (char)('0' + numbr);
	return number;
}


string TComplexEditor::AddZero() {
	return AddNumber(0);
}


string TComplexEditor::BackSpace() {
	number.pop_back();
	if (isRealPartEdit) {
		if (number == "-" || number.empty()) {
			number = "0";
		}
	}
	else {
		if (number.find('*')) {
			number.erase(number.end() - 2, number.end());
			isRealPartEdit = true;
		}
	}
	return number;
}


string TComplexEditor::Clear() {
	number = "0";
	isRealPartEdit = true;
	return number;
}

string TComplexEditor::AddSplit() {
	if (number.find("+i *" ) == string::npos) {
		number = number + "+i*";
		isRealPartEdit = false;
	}
	return number;
}

string setNumString(string numbr)
{
	int plus_c = 0;
	int minus_c = 0;
	int i_c = 0;
	int zv_c = 0;

	if (numbr[0] > '9' && numbr[0] < 0 && numbr[0] != '+' && numbr[0] != '-') {
		return ("0+i");
	}
	for (int i = 1; i < numbr.size(); ++i) {
		if ((numbr[i] >'0' && numbr[i] < '9') || numbr[i] == '+' ||
			numbr[i] == '-' || numbr[i] == 'i' || numbr[i] == '*') {

			if (numbr[i] == '+') {
				plus_c++;
				if (i != 0) {
					if (numbr[(i + 1) % numbr.size()] != 'i') {
						return("0+i");
					}
				}
				else {
					if (numbr[1] < '0' || numbr[1] > '9') {
						return("0+i");
					}
				}
			}
			else if (numbr[i] == '-') {
				minus_c++;
				if (i != 0) {
					if (numbr[(i + 1) % numbr.size()] != 'i') {
						return("0+i");
					}
				}
				else {
					if (numbr[1] < '0' || numbr[1] > '9') {
						return("0+i");
					}
				}
			}
			else if (numbr[i] == 'i') {
				i_c++;
				if (numbr[i - 1] != '-' && numbr[i - 1] != '+') {
					return ("0+i");
				}
				if (numbr[(i + 1) % numbr.size()] != '*') {
					return ("0+i");
				}
			}
			else if (numbr[i] == '*') {
				zv_c++;
				if (numbr[i - 1] != 'i') {
					return ("0+i");
				}
				if (numbr[(i + 1) % numbr.size()] > '9' || numbr[(i + 1) % numbr.size()] < '0') {
					return ("0+i");
				}
			}
		}
		else {
			return ("0+i");
		}
	}
	if (plus_c > 2 || minus_c > 2 || i_c > 1 || zv_c > 1) {
		return ("0+i");
	}
	else {
		return numbr;
	}
}


void TComplexEditor::SetNumber(string &numbr) {
	string tmp = setNumString(numbr);
	number = TComplex(tmp).GetTComplexSTR();
}


string TComplexEditor::GetNumber()  {
	return TComplex(number).GetTComplexSTR();
}