#pragma once
#include <cstdint>
#include <map>
#include <iostream>
#include "TMono.h"

class TPoly {
public:
	explicit TPoly(int deg = 0, int coeff = 0) {
		poly[deg] = TMono(deg, coeff);
	}

	int get_deg() {
		return (*poly.rbegin()).first;
	}

	int get_coeff(int deg) {
		return poly[deg].get_coeff();
	}

	void clear() {
		poly.clear();
		poly[0] = TMono(0, 0);
	}

	TPoly operator+(const TPoly &p) const {
		TPoly res;
		for (auto &v : poly) {
			res.poly[v.first] = res.poly[v.first] + v.second;
		}
		for (auto &v : p.poly) {
			res.poly[v.first] = res.poly[v.first] + v.second;
		}
		res.norm();
		return res;
	}

	TPoly operator*(const TPoly &p) const {
		TPoly res;
		for (auto &v : poly) {
			for (auto &t : p.poly) {
				TMono tmp = v.second * t.second;
				res.poly[tmp.get_degree()] = res.poly[tmp.get_degree()] + tmp;
			}
		}
		res.norm();
		return res;
	}

	TPoly operator-() const {
		TPoly res;
		for (auto &v : poly) {
			res.poly[v.first] = -v.second;
		}
		res.norm();
		return res;
	}

	TPoly operator-(const TPoly &t) const {
		return (*this) + (-t);
	}

	bool operator==(const TPoly &rhs) const {
		return poly == rhs.poly;
	}

	TPoly diff() {
		TPoly res;
		for (auto &v : poly) {
			TMono tmp = v.second.diff();
			res.poly[tmp.get_degree()] = tmp;
		}
		res.norm();
		return res;
	}

	double calc(double t) {
		double sum = 0;
		for (auto &v : poly) {
			sum += v.second.calc(t);
		}
		return sum;
	}

	TMono get_mono(int n) {
		if (n > poly.size()) {
			throw invalid_argument("Индекс больше, чем размер. Так нельзя, побойтесь Бога.");	
		}
		auto it = poly.begin();
		for (int i = 0; i < n; ++i) {
			++it;
		}
		return (*it).second;
	}

	string get_str() {
		std::string res;
		for (auto &v : poly) {
			res += v.second.get_string() + "+";
		}
		res.erase(res.size() - 1, 1);
		return res;
	}

	void norm() {
		vector<int> to_remove;
		for (auto &v : poly) {
			if (v.second.get_coeff() == 0) {
				to_remove.push_back(v.first);
			}
		}
		for (auto &v : to_remove) {
			poly.erase(v);
		}
		if (poly.empty()) {
			poly[0] = TMono(0, 0);
		}
	}
private:
	map<int, TMono> poly;
};

