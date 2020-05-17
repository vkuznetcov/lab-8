#pragma once
#include <iomanip>
#include "OrderedVector.h"
#include "UnorderedSet.h"
#include "AVLTree.h"
#include "Service.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void MainMenu() {
	system(CLEAR);
	cout << "With which data structure do you want to work? "
		<< endl << "1. OrderedVector (Based on lab-3's Vector)"
		<< endl << "2. UnorderedSet (hash-table)"
		<< endl << "3. OrderedSet (AVL Tree)"
		<< endl << "4. Print results"
		<< endl << "0. Exit"
		<< endl << endl << "Your answer: ";
}

void SubMenuOperations() {
	system(CLEAR);
	cout << "Which operation do you want to perform?"
		<< endl << "1. Insert element"
		<< endl << "2. Delete element"
		<< endl << "3. Search element"
		<< endl << "0. Cansel current action"
		<< endl << endl << "Your answer: ";
}

//void PrintResultsVector(int parameter, Results& vect) {
//	cout << "Ordered Vector(vector)" << endl << endl;
//	cout << setw(15) << "size" << setw(15);
//	for (int i = 0; i < 5; ++i) {
//		cout << vect.get_size(i);
//		cout << setw(15);
//	}
//	cout << endl;
//
//	cout << setw(15) << "insertion" << setw(15);
//	for (int i = 0; i < 5; ++i) {
//		if (vect.get_insert(i) == 0)
//			cout << " - ";
//		else cout << vect.get_insert(i);
//		cout << setw(15);
//	}
//	cout << endl;
//
//	cout << setw(15) << "searching" << setw(15);
//	for (int i = 0; i < 5; ++i) {
//		if (vect.get_search(i) == 0)
//			cout << " - ";
//		else cout << vect.get_search(i);
//		cout << setw(15);
//	}
//	cout << endl;
//
//	cout << setw(15) << "deleting" << setw(15);
//	for (int i = 0; i < 5; ++i) {
//		if (vect.get_delete(i) == 0)
//			cout << " - ";
//		else cout << vect.get_delete(i);
//		cout << setw(15);
//	}
//	cout << endl << endl;
//}

//void PrintResultsTable(int parameter, Results& table) {
//	cout << "Unordered Set(hash-table)" << endl << endl;
//	cout << setw(15) << "size" << setw(15);
//	for (int i = 0; i < 5; ++i) {
//		cout << table.get_size(i);
//		cout << setw(15);
//	}
//	cout << endl;
//
//	cout << setw(15) << "insertion" << setw(15);
//	for (int i = 0; i < 5; ++i) {
//		if (table.get_insert(i) == 0)
//			cout << " - ";
//		else cout << table.get_insert(i);
//		cout << setw(15);
//	}
//	cout << endl;
//
//	cout << setw(15) << "searching" << setw(15);
//	for (int i = 0; i < 5; ++i) {
//		if (table.get_search(i) == 0)
//			cout << " - ";
//		else cout << table.get_search(i);
//		cout << setw(15);
//	}
//	cout << endl;
//
//	cout << setw(15) << "deleting" << setw(15);
//	for (int i = 0; i < 5; ++i) {
//		if (table.get_delete(i) == 0)
//			cout << " - ";
//		else cout << table.get_delete(i);
//		cout << setw(15);
//	}
//	cout << endl << endl;
//}

void PrintResults2(int parameter, Results& res) {
	switch (parameter) {
	case 1: {
		cout << "Ordered Vector(vector)" << endl << endl;
	}break;
	case 2: {
		cout << "Unordered Set(hash-table)" << endl << endl;
	}break;
	case 3: {
		cout << "Set(AVL Tree)" << endl << endl;
	}break;
	}
	cout << setw(15) << "size" << setw(15);
	for (int i = 0; i < 5; ++i) {
		cout << res.get_size(i);
		cout << setw(15);
	}
	cout << endl;

	cout << setw(15) << "insertion" << setw(15);
	for (int i = 0; i < 5; ++i) {
		if (res.get_insert(i) == 0)
			cout << " - ";
		else cout << res.get_insert(i);
		cout << setw(15);
	}
	cout << endl;

	cout << setw(15) << "searching" << setw(15);
	for (int i = 0; i < 5; ++i) {
		if (res.get_search(i) == 0)
			cout << " - ";
		else cout << res.get_search(i);
		cout << setw(15);
	}
	cout << endl;

	cout << setw(15) << "deleting" << setw(15);
	for (int i = 0; i < 5; ++i) {
		if (res.get_delete(i) == 0)
			cout << " - ";
		else cout << res.get_delete(i);
		cout << setw(15);
	}
	cout << endl << endl;
}

void PrintResults(Results& vector, Results& table, Results& tree) {
	system(CLEAR);
	PrintResults2(1, vector);
	PrintResults2(2, table);
	PrintResults2(3, tree);
	cout << endl << endl << "Press Enter to return to main menu...";
	getchar();
}