#pragma once
#include <set>
#include <algorithm>
#include <stdexcept>
#include <iterator>

using namespace std;

template <class T>
class TSet {
private:
	set<T> s;
public:
	TSet() = default;

	void clear() {
		s.clear();
	}

	void insert(const T &v) {
		s.insert(v);
	}

	void erase(const T& v) {
		s.erase(v);
	}

	bool is_empty() {
		return s.empty();
	}

	bool find(const T& v) {
		return s.find(v) != s.end();
	}

	bool contains(T elem) {
		return s.count(elem);
	}

	TSet<T> unite(const TSet<T> &t) {
		set<T> res;
		res.insert(s.begin(), s.end());
		res.insert(t.s.begin(), t.s.end());
		TSet<T> r;
		r.s = res;
		return r;
	}

	TSet<T> sub(const TSet<T> &t) {
		set<T> res;
		set_difference(s.begin(), s.end(), t.s.begin(), t.s.end(), inserter(res, res.end()));
		TSet<T> r;
		r.s = res;
		return r;
	}

	TSet<T> intersect(const TSet<T> &t) {
		set<T> res;
		set_intersection(s.begin(), s.end(), t.s.begin(), t.s.end(), inserter(res, res.end()));
		TSet<T> r;
		r.s = res;
		return r;
	}

	int size() {
		return s.size();
	}

	T get_element(int j) {
		if (j >= s.size()) {
			throw invalid_argument("Индекс больше, чем размер. Так нельзя, побойтесь Бога.");
		}
		auto it = s.begin();
		for (int i = 0; i < j; ++i) {
			++it;
		}
		return *it;
	}

};

