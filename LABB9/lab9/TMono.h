#pragma once
#include <cstdint>
#include <string>
#include <cmath>
#include <stdexcept>
#include <vector>
using namespace std;

class TMono {
private:
	int degree;
	int coeff;

public:
	explicit TMono(int degree = 0, int coeff = 0) : degree(degree), coeff(coeff) { }

	int get_degree() const {
		return degree;
	}

	void set_degree(int degree) {
		TMono::degree = degree;
	}

	int get_coeff() const {
		return coeff;
	}

	void set_coeff(int coeff) {
		TMono::coeff = coeff;
	}

	bool operator==(const TMono &rhs) const {
		return degree == rhs.degree &&
			coeff == rhs.coeff;
	}

	bool operator!=(const TMono &rhs) const {
		return !(rhs == *this);
	}

	bool operator<(const TMono &rhs) const {
		if (degree < rhs.degree)
			return true;
		if (rhs.degree < degree)
			return false;
		return coeff < rhs.coeff;
	}

	TMono diff() {
		return TMono(degree - 1, coeff * degree);
	}

	double calc(double t) {
		return coeff * pow(t, degree);
	}

	string get_string() {
		return to_string(coeff) + "*x^" + to_string(degree);
	}

	TMono operator+(const TMono &t) const {
		if (degree == 0 && coeff == 0) {
			return t;
		}
		if (t.degree != degree) {
			throw invalid_argument("Невозможно суммировать.");
		}
		return TMono(degree, t.coeff + coeff);
	}

	TMono operator*(const TMono &t) const {
		return TMono(degree + t.degree, t.coeff * coeff);
	}

	TMono operator-() const {
		return TMono(degree, -coeff);
	}

	TMono operator-(const TMono &t) const {
		return (*this) + (-t);
	}


};
