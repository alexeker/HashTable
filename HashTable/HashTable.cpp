// HashTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
template <typename Tval> class Table
{
private:
	std::vector<Tval> *a;
	int SIZE;
	int HashFunc(Tval value) {
		std::string str;
		str = value;
		//Простая функция хеширования: приводит переменную к строке
		//и суммирует ascii значения каждого символа
		//для возврата корректного значения сумма делится на размер таблицы
		int sum = 0;
		
		for (int i = 0; i < str.length(); i++) {
			sum += str[i];
		}
		return sum % SIZE;
	}
public:
	
	Table(int size) {
		//С помощью конструктора создаем скелет таблицы размером SIZE
		//Объявляем массив векторов, где индексы массива - ячейкм,
		//а вектор разрешает проблему коллизий
		this->SIZE = size;
		a = new vector<Tval>[size];
	}
	
	void ShowTable() {
		//функция вывода таблицы в консоль
		for (int i = 0; i < SIZE; i++) {
			cout << i+1;
			for (auto x : a[i])
				cout << " --> " << x;
			cout << endl;
		}
	}
	void Add(Tval val) {
		Tval res;
		res = val;
		//функция добавления значения в таблицу
		//для того, чтобы знать в какую ячейку впихнуть значение вызываем Хеш_Функцию
		//Получая ключ для ячейки таблицы, добавляем элемент в конец вектора
		auto key = HashFunc(val);
		a[key].push_back(res) ;
	}
	bool Find(Tval val) {
		Tval res;
		res = val;
		//Функция поиска в таблице некоторого значения
		//Опять же берем хеш даного значения и затем в полученой ячейки
		//проходим по вектору в поиске значения
		auto key = HashFunc(val);
		auto it = std::find(a[key].begin(), a[key].end(),res);
		if (it != a[key].end())
			return true;
		else
			return false;
	}
	void Delete(Tval val) {
		Tval res;
		res = val;
		//Функция удаления элементов из таблицы.
		//Опять же берем хеш даного значения и затем в полученой ячейке
		//есть нужное значение и итератор указывает на нужное значение
		//то мы удаляем его
		auto key = HashFunc(val);
		auto it = std::find(a[key].begin(), a[key].end(), res);
		if (it != a[key].end())
			a[key].erase(it);
	}
};

int main()
{
	//ввиду того, что класс использует шаблоны
	//можно создать хеш таблицу любого типа
	Table<string> tab =  Table<string>(10);
	
	tab.Add("256");
	tab.Add("12e3");
	tab.Add("157");
	tab.Add("22");

	tab.ShowTable();

	cout << ((tab.Find("157") == 1) ? "Found\n" : "Not found\n");
	cout << ((tab.Find("12") == 1) ? "Found\n" : "Not found\n");


	tab.Delete("256");
	tab.ShowTable();
	cout << "Executed";
}
