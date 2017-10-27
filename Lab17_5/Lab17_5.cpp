/*

Задания:
Дан массив, состоящий из N целых случайных чисел. Отсортировать массив по возрастанию различными методами и оценить эффективность этих методов.
Методы:
• Сортировка методом пузырька


*/
#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;

void bubbleSort(int* arr, int size)
{
	for(int i = 0; i < size - 1; ++i) // i - номер прохода
		for(int j = 0; j < size - 1; ++j) // внутренний цикл прохода
			if(arr[j + 1] < arr[j])
				swap(arr[j], arr[j + 1]);
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
	bubbleSort(m, n);
	cout << "сортированный массив:" << endl;
	for(int i = 0; i < n; i++)
		cout << m[i] << " ";
	cout << endl;
	delete[] m;
	system("pause.exe");
	return 0;
}