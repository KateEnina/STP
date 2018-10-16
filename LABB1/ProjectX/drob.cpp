//#include "stdafx.h"
#include <iostream>
#include "drob.h"

using namespace std;

Drobi::Drobi(string FractionString) {
	this->convertStringToFraction(FractionString);
}

bool Drobi::convertStringToFraction(string FractionString) {
	std::size_t pos = FractionString.find("/");
	if (pos != std::string::npos) {
		try {
			this->chislitel = atol(FractionString.substr(0, pos).c_str());
			this->znamenatel = atol(FractionString.substr(pos + 1).c_str());
		}
		catch (...) {
			return false;
		}

		return (this->znamenatel == 0) ? false : true;
	}

	return false;
}

int Drobi::getChislitel() {
	return this->chislitel;
}

int Drobi::getZnamenatel() {
	return this->znamenatel;
}

string Drobi::getChislitelString() {
	char tmp[10];
	//itoa(this->chislitel, tmp, 10);
	_itoa_s(this->chislitel, tmp, 10);
	std::string str = tmp;
	return str;
}

string Drobi::getZnamenatelString() {
	char tmp[10];
	_itoa_s(this->znamenatel, tmp, 10);
	std::string str = tmp;
	return str;
}

string Drobi::getDrobString() {
	char tmp[10];
	_itoa_s(this->chislitel, tmp, 10);
	std::string str = tmp;
	_itoa_s(this->znamenatel, tmp, 10);
	str += '/';
	str += tmp;
	return str;
}

int Drobi::compareTo(Drobi other) {
	return getChislitel() * other.getZnamenatel() - getZnamenatel() * other.getZnamenatel();
}

int Drobi::gcd(int chislitel, int znamenatel) {
	while (chislitel != 0 && znamenatel != 0) {
		if (abs(chislitel) > abs(znamenatel))
			chislitel = abs(chislitel) % abs(znamenatel);
		else
			znamenatel = abs(znamenatel) % abs(chislitel);
	}
	return (abs(znamenatel) + abs(chislitel));
}

void Drobi::simply() {
	int del = gcd(this->chislitel, this->znamenatel);
	this->chislitel /= del;
	this->znamenatel /= del;
	if (this->znamenatel < 0) {
		this->chislitel *= (-1);
		this->znamenatel *= (-1);
	}
}

Drobi Drobi::summ(Drobi a){
	int corpChislitel = this->getChislitel() * a.getZnamenatel() + a.getChislitel() * this->getZnamenatel();
	int corpZnamenatel = this -> getZnamenatel() * a.getZnamenatel();
	return Drobi(corpChislitel, corpZnamenatel);
}
	
Drobi Drobi::vichest(Drobi a) {
	a.chislitel *= -1;
	return summ(a);
}
	
Drobi Drobi::umnozh(Drobi a) {
	return Drobi(this->chislitel * a.chislitel, this->znamenatel * a.znamenatel);
}
Drobi Drobi::delit(Drobi a) {
	return Drobi(this->getChislitel() * a.getZnamenatel(), this->getZnamenatel() * a.getChislitel());
}

Drobi Drobi::kvadrat(Drobi drobi) {
	return Drobi(drobi.getChislitel()*drobi.getChislitel(), drobi.getZnamenatel()*drobi.getZnamenatel());
	}	


void Drobi::obratnoe() {
	int tmp = this->chislitel;
	this->chislitel = this->znamenatel;
	this->znamenatel = tmp;
}

Drobi Drobi::copy() {
	return Drobi(this->chislitel, this->znamenatel);
}

void Drobi::negative() {
	this->chislitel *= -1;
}

bool Drobi::less(Drobi fraction) {
	return (this->chislitel * (this->znamenatel * fraction.getZnamenatel())) < (fraction.getChislitel() * (this->znamenatel * fraction.getZnamenatel()));
}

bool Drobi::more(Drobi fraction) {
	return (this->chislitel * (this->znamenatel * fraction.getZnamenatel())) > (fraction.getChislitel() * (this->znamenatel * fraction.getZnamenatel()));
}

bool Drobi::equela(Drobi fraction) {
	return (this->chislitel * (this->znamenatel * fraction.getZnamenatel())) == (fraction.getChislitel() * (this->znamenatel * fraction.getZnamenatel()));
}

