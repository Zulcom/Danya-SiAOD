/*
 * 1. Написать программу, которая:
- запрашивает у пользователя размер массива и ключ поиска;
- формирует массив случайных чисел;
- возвращает количество совпадений и их номера.
Реализовать программу с помощью следующих алгоритмов: Последовательный (линейный) поиск, Бинарный поиск.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace  std;
int binary_search(const vector<int>& sorted_vec, int key)
{
	int mid, left = 0;
	int right = sorted_vec.size(); 
	while(left < right)
	{
		mid = left + (right - left) / 2;
		if(key > sorted_vec[mid] )
			left = mid + 1;
		else 
			if(key < sorted_vec[mid])
				right = mid;
			else
				return mid;
	}

	return false;
}
int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
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
	counter = 1;
	sort(arr.begin(),arr.end());
	cout << endl << "Отскортированный массив:" << endl;
	for(int i : arr) cout << i << " ";
	cout << endl << "Номера сопадений(бинарный поиск):" << endl;
	int pos = binary_search(arr, key);

	/*Если элемент найден, очевидно, что в отсортированном массиве одинаковые элементы будут рядом. Проверяем в обе стороны:*/
	for(int i=1; ;++i)
		if(pos - i >= 0 && arr.at(pos - i) == key)
		{
			cout << pos - i +1 << " ";
			counter++;
		}
		else break;
		cout << pos +1<< " ";
	for(int i=1;;++i)
	{
		if(arr.at(pos + i) == key)
		{
			cout << pos + i+1 << " ";
			counter++;
		}
		else break;
	}

	cout << endl << "Количество совпадений(бинарный поиск):" << counter << endl;
	
	cout << endl;
	system("pause.exe");
}
