/*

Задания:
Дан массив, состоящий из N целых случайных чисел. Отсортировать массив по возрастанию различными методами и оценить эффективность этих методов.
Методы:
•	Сортировка простым извлечением


*/
#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;

void extractSort(int *m,int n) {
	for(int i = n-1; i > 0; --i)
	{
		int maxIndex = 0;
		for(int j = 1; j <= i; j++)
			if(m[j] > m[maxIndex]) 
				maxIndex = j;
		swap(m[i], m[maxIndex]);
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int n;
	cout << "Input n:";
	cin >> n;
	int *m = new int[n];
	cout << "Несортированный массив:" << endl;
	for(int i = 0; i < n; i++)
	{
		m[i] = rand() % 10;
		cout << m[i] << " ";
	}
	cout << endl;
	extractSort(m, n);
	cout << "сортированный массив:" << endl;
	for(int i = 0; i < n; i++)
		cout << m[i] << " ";
	cout << endl;
	delete[] m;
	system("pause.exe");
	return 0;
}