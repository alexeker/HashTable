// HashTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <vector>
#include <string>
using namespace std;
template <typename Tval> class Table
{

public:
	std::vector<Tval> *a;
	int SIZE;
	Table(int size) {
		this->SIZE = size;
		a = new vector<Tval>[size];
	}
	int HashFunc(Tval value) {
		std::string str;
		str = value;
		std::hash<std::string> hasher;
		auto hashed = hasher(str); //returns std::size_t
		

		return hashed % SIZE;
	}
	void displayHash() {
		for (int i = 0; i < SIZE; i++) {
			cout << i+1;
			for (auto x : a[i])
				cout << " --> " << x;
			cout << endl;
		}
	}
	void Add(Tval val) {
		auto key = HashFunc(val);
		Tval res;
		res = val;
		a[key].push_back(res) ;
	}
};

int main()
{
	Table<string> tab =  Table<string>(10);
	
	tab.Add("123");
	tab.Add("123");
	tab.Add("1232");
	tab.Add("13");
	tab.displayHash();
	std::cout << "Executed";
}
