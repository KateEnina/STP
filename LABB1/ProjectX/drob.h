#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Drobi {
private:
	int chislitel;
	int znamenatel;

public:
	Drobi(int chislitel, int znamenatel) : chislitel(chislitel), znamenatel(znamenatel) {
		if (this->znamenatel == 0) throw logic_error("Деление на нуль!!!");
		simply();
	}
	Drobi() : chislitel(0), znamenatel(1) {}
	Drobi(int value) : chislitel(value), znamenatel(1) {}
	Drobi(std::string FractionString);
	~Drobi() 
	{}

	bool convertStringToFraction(string);

	int getChislitel();

	int getZnamenatel();

	string getZnamenatelString();

	string getChislitelString();

	string getDrobString();

	int compareTo(const Drobi);

	int gcd(int, int);

	void simply(void);

	Drobi copy();

	Drobi summ(Drobi);
	Drobi vichest(Drobi);
	Drobi umnozh(Drobi);
	Drobi delit(Drobi);
	Drobi kvadrat(Drobi);
	void obratnoe();
	void negative();
	bool more(Drobi);
	bool less(Drobi);
	bool equela(Drobi);
};
