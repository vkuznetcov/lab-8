#pragma once
#include <iostream>
#include "OrderedVector.h"
#include "UnorderedSet.h"
#include "AVLTree.h"

class Results {
private:
	size_t sizes[5];
	double results_insert[5];
	double results_search[5];
	double results_delete[5];
public:
	Results() {
		for (size_t i = 0, size = 10; i < 5; ++i, size *= 10) {
			sizes[i] = size;
			results_insert[i] = 0;
			results_search[i] = 0;
			results_delete[i] = 0;
		}
	}

	~Results() = default;

	void write_insert(int i, double data) {
		results_insert[i] = data;
	}

	void write_search(int i, double data) {
		results_search[i] = data;
	}

	void write_delete(int i, double data) {
		results_delete[i] = data;
	}

	size_t get_size(int i) {
		return sizes[i];
	}

	double get_insert(int i) {
		return results_insert[i];
	}

	double get_search(int i) {
		return results_search[i];
	}

	double get_delete(int i) {
		return results_delete[i];
	}
};

void error() {
	std::cout << "ERROR : there is no such option.\n\n Press Enter to continue...";
	getchar(); getchar();
}

template <typename T>
void fill_vect(OrderedVector<T>& v) {
	for (auto i = 0; i < v.size(); ++i)
		v[i] = i;
}

template <typename T>
void fill_table(UnorderedSet<T>& t) {
	srand(time(0));
	for (auto i = 0; i < t.getSize(); ++i)
		t.Insert(rand());
}

template <typename T>
void fill_tree(Set<T>& t, size_t size) {
	srand(time(0));
	for (auto i = 0; i < size; ++i)
		t.Insert(rand());
}