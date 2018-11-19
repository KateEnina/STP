#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class TFrac {
private:
	int chislitel;
	int znamenatel;

public:
	TFrac(int chislitel, int znamenatel) : chislitel(chislitel), znamenatel(znamenatel) {
		if (this->znamenatel == 0) throw logic_error("Деление на нуль!!!");
		simply();
	}
	TFrac() : chislitel(0), znamenatel(1) {}
	TFrac(int value) : chislitel(value), znamenatel(1) {}
	TFrac(std::string FractionString);
	~TFrac() 
	{}


	int getChislitel();

	int getZnamenatel();
	
	string getZnamenatelString();

	string getChislitelString();

	string getDrobString();

	int compareTo(const TFrac);

	int gcd(int, int);

	void simply(void);

	TFrac copy();

	TFrac summ(TFrac);
	TFrac vichest(TFrac);
	TFrac umnozh(TFrac);
	TFrac delit(TFrac);
	TFrac kvadrat(TFrac);
	void obratnoe();
	void negative();
	bool more(TFrac);
	bool less(TFrac);
	bool equela(TFrac);
};
