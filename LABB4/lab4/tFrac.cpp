#include "stdafx.h"
#include <iostream>
#include "TFrac.h"

using namespace std;

TFrac::TFrac(string TFractionString) {
	this->StringToTFraction(TFractionString);
}

bool TFrac::StringToTFraction(string TFractionString) {
	std::size_t pos = TFractionString.find("/");
	if (pos != std::string::npos) {
		try {
			this->chislitel = atol(TFractionString.substr(0, pos).c_str());
			this->znamenatel = atol(TFractionString.substr(pos + 1).c_str());
		}
		catch (...) {
			return false;
		}

		return (this->znamenatel == 0) ? false : true;
	}

	return false;
}

int TFrac::getChislitel() {
	return this->chislitel;
}


int TFrac::getZnamenatel() {
	return this->znamenatel;
}

string TFrac::getChislitelString() {
	char tmp[10];
	//itoa(this->chislitel, tmp, 10);
	_itoa_s(this->chislitel, tmp, 10);
	std::string str = tmp;
	return str;
}

string TFrac::getZnamenatelString() {
	char tmp[10];
	_itoa_s(this->znamenatel, tmp, 10);
	std::string str = tmp;
	return str;
}

string TFrac::getDrobString() {
	char tmp[10];
	_itoa_s(this->chislitel, tmp, 10);
	std::string str = tmp;
	_itoa_s(this->znamenatel, tmp, 10);
	str += '/';
	str += tmp;
	return str;
}

int TFrac::compareTo(TFrac other) {
	return getChislitel() * other.getZnamenatel() - getZnamenatel() * other.getZnamenatel();
}

int TFrac::gcd(int chislitel, int znamenatel) {
	while (chislitel != 0 && znamenatel != 0) {
		if (abs(chislitel) > abs(znamenatel))
			chislitel = abs(chislitel) % abs(znamenatel);
		else
			znamenatel = abs(znamenatel) % abs(chislitel);
	}
	return (abs(znamenatel) + abs(chislitel));
}

void TFrac::simply() {
	int del = gcd(this->chislitel, this->znamenatel);
	this->chislitel /= del;
	this->znamenatel /= del;
	if (this->znamenatel < 0) {
		this->chislitel *= (-1);
		this->znamenatel *= (-1);
	}
}

TFrac TFrac::summ(TFrac a){
	int corpChislitel = this->getChislitel() * a.getZnamenatel() + a.getChislitel() * this->getZnamenatel();
	int corpZnamenatel = this -> getZnamenatel() * a.getZnamenatel();
	return TFrac(corpChislitel, corpZnamenatel);
}
	
TFrac TFrac::vichest(TFrac a) {
	a.chislitel *= -1;
	return summ(a);
}
	
TFrac TFrac::umnozh(TFrac a) {
	return TFrac(this->chislitel * a.chislitel, this->znamenatel * a.znamenatel);
}
TFrac TFrac::delit(TFrac a) {
	return TFrac(this->getChislitel() * a.getZnamenatel(), this->getZnamenatel() * a.getChislitel());
}

TFrac TFrac::kvadrat(TFrac drobi) {
	return TFrac(drobi.getChislitel()*drobi.getChislitel(), drobi.getZnamenatel()*drobi.getZnamenatel());
	}	


void TFrac::obratnoe() {
	int tmp = this->chislitel;
	this->chislitel = this->znamenatel;
	this->znamenatel = tmp;
}

TFrac TFrac::copy() {
	return TFrac(this->chislitel, this->znamenatel);
}

void TFrac::negative() {
	this->chislitel *= -1;
};

bool TFrac::less(TFrac TFraction) {
	return (this->chislitel * (this->znamenatel * TFraction.getZnamenatel())) < (TFraction.getChislitel() * (this->znamenatel * TFraction.getZnamenatel()));
};

bool TFrac::more(TFrac TFraction) {
	return (this->chislitel * (this->znamenatel * TFraction.getZnamenatel())) > (TFraction.getChislitel() * (this->znamenatel * TFraction.getZnamenatel()));
}

bool TFrac::equela(TFrac TFraction) {
	return (this->chislitel * (this->znamenatel * TFraction.getZnamenatel())) == (TFraction.getChislitel() * (this->znamenatel * TFraction.getZnamenatel()));
}

