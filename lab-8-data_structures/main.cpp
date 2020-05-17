#include <iomanip>
#include <chrono>
#include <stdlib.h>
#include "OrderedVector.h"
#include "UnorderedSet.h"
#include "AVLTree.h"
#include "Menu.h"
#include "Service.h"

using namespace std;
using namespace std::chrono;

int main() {
	Results vect_info, table_info, tree_info;
	int simulations;
	cout << "How many simulations do you want to perform?\nYour answer: ";
	cin >> simulations; getchar();
	double result = 0;
	while (true) {
		try {
			MainMenu();
			switch (getchar()) {
			case '1': {
				system(CLEAR);
				getchar();
				SubMenuOperations();
				switch (getchar()) {
				case '1': {
					getchar();
					system(CLEAR);
					int data;
					cout << endl << "Enter data you want to insert: ";
					cin >> data;
					for (int i = 0; i < 5; ++i) {
						for (int j = 0; j < simulations; ++j) {
							OrderedVector<int> Vector(vect_info.get_size(i));
							fill_vect(Vector);
							auto start = steady_clock::now();
							auto iterator = Vector.Insert(data);
							auto stop = steady_clock::now();
							duration<double> diff = (stop - start);
							result += diff.count();
						}
						vect_info.write_insert(i, result / simulations);
					}
					result = 0;
					getchar();
				}break;
				case '2': {
					system(CLEAR);
					int data;
					cout << endl << "Enter data you want to delete: ";
					cin >> data;
					for (int i = 0; i < 5; ++i) {
						for (int j = 0; j < simulations; ++j) {
							OrderedVector<int> Vector(vect_info.get_size(i));
							fill_vect(Vector);
							auto start = steady_clock::now();
							auto iterator = Vector.Remove(data);
							auto stop = steady_clock::now();
							duration<double> diff = (stop - start);
							result += diff.count();
						}
						vect_info.write_delete(i, result / simulations);
					}
					result = 0;
					getchar();
				}break;
				case '3': {
					system(CLEAR);
					int data;
					cout << endl << "Enter data you want to search: ";
					cin >> data;
					for (int i = 0; i < 5; ++i) {
						for (int j = 0; j < simulations; ++j) {
							OrderedVector<int> Vector(vect_info.get_size(i));
							fill_vect(Vector);
							auto start = steady_clock::now();
							auto iterator = Vector.Search(data);
							auto stop = steady_clock::now();
							duration<double> diff = (stop - start);
							result += diff.count();
						}
						vect_info.write_search(i, result / simulations);
					}
					result = 0;
					getchar();
				}break;
				case '0': getchar(); break;
				default: error();
				}
			}break;
			case '2': {
				system(CLEAR);
				getchar();
				SubMenuOperations();
				switch (getchar()) {
				case '1': {
					getchar();
					system(CLEAR);
					int data;
					cout << endl << "Enter data you want to insert: ";
					cin >> data;
					for (int i = 0; i < 5; ++i) {
						for (int j = 0; j < simulations; ++j) {
							UnorderedSet<int> Table(table_info.get_size(i));
							fill_table(Table);
							auto start = steady_clock::now();
							auto iterator = Table.Insert(data);
							auto stop = steady_clock::now();
							duration<double> diff = (stop - start);
							result += diff.count();
						}
						//table_info.write_insert(i, result / simulations);
						if (i == 0) {
							table_info.write_insert(i, result / simulations);	
						}
						else {
							table_info.write_insert(i, (result / simulations) - table_info.get_insert(i - 1));
						}
					}
					result = 0;
					getchar();
				}break;
				case '2': {
					system(CLEAR);
					int data;
					cout << endl << "Enter data you want to delete: ";
					cin >> data;
					for (int i = 0; i < 5; ++i) {
						for (int j = 0; j < simulations; ++j) {
							UnorderedSet<int> Table(table_info.get_size(i));
							fill_table(Table);
							auto start = steady_clock::now();
							auto iterator = Table.Remove(data);
							auto stop = steady_clock::now();
							duration<double> diff = (stop - start);
							result += diff.count();
						}
						if (i == 0) {
							table_info.write_delete(i, result / simulations);
						}
						else {
							table_info.write_delete(i, (result / simulations) - table_info.get_insert(i - 1));
						}
					}
					result = 0;
					getchar();
				}break;
				case '3': {
					system(CLEAR);
					int data;
					cout << endl << "Enter data you want to search: ";
					cin >> data;
					for (int i = 0; i < 5; ++i) {
						for (int j = 0; j < simulations; ++j) {
							UnorderedSet<int> Table(table_info.get_size(i));
							fill_table(Table);
							auto start = steady_clock::now();
							auto iterator = Table.Search(data);
							auto stop = steady_clock::now();
							duration<double> diff = (stop - start);
							result += diff.count();
						}
						if (i == 0) {
							table_info.write_search(i, result / simulations);
						}
						else {
							table_info.write_search(i, (result / simulations) - table_info.get_insert(i - 1));
						}
					}
					result = 0;
					getchar();
				}break;
				case '0': getchar(); break;
				default: error();
				}
			}break;
			case '3': {
				system(CLEAR);
				getchar();
				SubMenuOperations();
				switch (getchar()) {
				case '1': {
					getchar();
					system(CLEAR);
					int data;
					cout << endl << "Enter data you want to insert: ";
					cin >> data;
					for (int i = 0; i < 5; ++i) {
						for (int j = 0; j < simulations; ++j) {
							Set<int> Tree;
							fill_tree(Tree, tree_info.get_size(i));
							auto start = steady_clock::now();
							Tree.Insert(data);
							auto stop = steady_clock::now();
							duration<double> diff = (stop - start);
							result += diff.count();
						}
						//table_info.write_insert(i, result / simulations);
						if (i == 0) {
							tree_info.write_insert(i, result / simulations);
						}
						else {
							tree_info.write_insert(i, (result / simulations) - tree_info.get_insert(i - 1));
						}
					}
					result = 0;
					getchar();
				}break;
				case '2': {
					getchar();
					system(CLEAR);
					int data;
					cout << endl << "Enter data you want to delete: ";
					cin >> data;
					for (int i = 0; i < 5; ++i) {
						for (int j = 0; j < simulations; ++j) {
							Set<int> Tree;
							fill_tree(Tree, tree_info.get_size(i));
							auto start = steady_clock::now();
							Tree.Remove(data);
							auto stop = steady_clock::now();
							duration<double> diff = (stop - start);
							result += diff.count();
						}
						//table_info.write_insert(i, result / simulations);
						if (i == 0) {
							tree_info.write_delete(i, result / simulations);
						}
						else {
							tree_info.write_delete(i, (result / simulations) - tree_info.get_delete(i - 1));
						}
					}
					result = 0;
					getchar();
				}break;
				case '3': {
					getchar();
					system(CLEAR);
					int data;
					cout << endl << "Enter data you want to insert: ";
					cin >> data;
					for (int i = 0; i < 5; ++i) {
						for (int j = 0; j < simulations; ++j) {
							Set<int> Tree;
							fill_tree(Tree, tree_info.get_size(i));
							auto start = steady_clock::now();
							Tree.Search(data);
							auto stop = steady_clock::now();
							duration<double> diff = (stop - start);
							result += diff.count();
						}
						//table_info.write_insert(i, result / simulations);
						if (i == 0) {
							tree_info.write_search(i, result / simulations);
						}
						else {
							tree_info.write_search(i, (result / simulations) - tree_info.get_search(i - 1));
						}
					}
					result = 0;
					getchar();
				}break;
				case '0': getchar(); break;
				default: error();
				}
			}break;
			case '4': {
				PrintResults(vect_info, table_info, tree_info);
				getchar();
			}break;
			case '0': return 0;
			default: error();
			}
		}
		catch (const char* error_msg) {
			cout << endl << endl;
			cerr << error_msg;
		}
	}
}