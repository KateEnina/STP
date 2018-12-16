#include "stdafx.h"
#include "..\lab8\TPNumberEditor.h"
#include "..\..\lab3\lab3\TPNumber.h"
#include <cmath>


TPNumberEditor::TPNumberEditor() : number("0"), base(10) {
}

TPNumberEditor:: ~TPNumberEditor() {}

bool TPNumberEditor::isZero() {
	return TPNumber(number, base, 6).GetFloatPNumber() == 0.0;
}


string TPNumberEditor::AddSign() {
	if (number[0] == '-') {
		number.erase(number.begin());
	}
	else {
		if (number != "0") {
			number = "-" + number;
		}
	}
	return number;
}


std::string TPNumberEditor::AddNumber(unsigned int numbr) {
		if (numbr <= 9) {
			if (numbr < base) {
				if (number == "0") {
					number = "";
				}
				number += (char)('0' + numbr);
			}
		}
		else if ((numbr + 'A' - 10) <= (base + 'F' - 10) && (numbr + 'A' - 10) >= (base + 'A' - 10)) {
			number += (char)('A' + numbr - base);
		}
		return number;
}


std::string TPNumberEditor::AddZero() {
	return AddNumber(0);
}


std::string TPNumberEditor::BackSpace() {
	number.pop_back();
	if (number == "-" || number.empty()) {
		number = "0";
	}
	return number;
}


std::string TPNumberEditor::Clear() {
	number = "0";
	return number;
}

string TPNumberEditor::AddSplit() {
	if (number.find('.') == string::npos) {
		number = number + '.';
	}
	return number;
}


void TPNumberEditor::SetNumber(string &numbr) {
	try {
		TPNumber t = TPNumber(numbr, base, 6);
		number = t.GetPString();
	}
	catch (int) {
		number = "0";
	}
}


std::string TPNumberEditor::GetNumber() {
	return TPNumber(number, base, 6).GetPString();
}