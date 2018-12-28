#pragma once


#include <set>
#include <algorithm>
#include <stdexcept>
#include <iterator>

using namespace std;

template<class T>
class TSetInher : public set<T> {
public:
	TSetInher();

	bool contains(T x);

	TSetInher<T> unite(TSetInher<T> &x);

	TSetInher<T> sub(TSetInher<T> &x);

	TSetInher<T> intersect(TSetInher<T> &x);

	T get_element(int i);
};

template<class T>
TSetInher<T>::TSetInher() = default;

template<class T>
bool TSetInher<T>::contains(T x) {
	return (bool)this->count(x);
}


template<class T>
TSetInher<T> TSetInher<T>::unite(TSetInher<T> &x) {
	TSetInher res;

	set_union(this->begin(), this->end(), x.begin(), x.end(), inserter(res, res.begin()));

	return res;
}

template<class T>
TSetInher<T> TSetInher<T>::sub(TSetInher<T> &x) {
	TSetInher res;

	set_difference(this->begin(), this->end(), x.begin(), x.end(), inserter(res, res.begin()));

	return res;
}

template<class T>
TSetInher<T> TSetInher<T>::intersect(TSetInher<T> &x) {
	TSetInher res;

	set_intersection(this->begin(), this->end(), x.begin(), x.end(), inserter(res, res.begin()));

	return res;
}

template<class T>
T TSetInher<T>::get_element(int i) {
	return *next(set<T>::begin(), i);
}