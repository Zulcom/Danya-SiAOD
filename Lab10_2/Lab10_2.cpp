/*
2. Осуществить алгоритм упорядоченного дерева поиска. Найти ключ поиска и удалить его из дерева.
*/
#include <iostream>
#include <vector>
using namespace  std;
int main()
{
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
	cout << endl << "Количество совпадений:" << counter << endl;
	cout << "Номера сопадений:" << endl;
	for(int i = 0; i < n; i++) { if(arr.at(i) == key) cout << i + 1 << " "; }
	cout << endl;
	system("pause.exe");
}
