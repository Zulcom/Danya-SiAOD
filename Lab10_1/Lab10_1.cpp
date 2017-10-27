/*
 * 1. Написать программу, которая:
- запрашивает у пользователя размер массива и ключ поиска;
- формирует массив случайных чисел;
- возвращает количество совпадений и их номера.

 */
#include <iostream>
#include <vector>
using namespace  std;
int main() {
	setlocale(LC_ALL, "Russian");
	int n, key;
	std::cout << "Enter n and key:";
	cin >> n >> key;
	vector<int> arr;
	int counter = 0;
	for(int i = 0; i < n; i++)
	{
		arr.push_back(rand() % 10);
		cout << arr.at(i) << " ";
		if(arr.at(i) == key) counter++;
	}
	cout <<endl << "Количество совпадений:" << counter <<endl;
	cout << "Номера сопадений:" << endl;
	for(int i = 0; i < n; i++) { if(arr.at(i) == key) cout << i+1 << " "; }
	cout << endl;
	system("pause.exe");
}
