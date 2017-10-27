/*

Задания:
Дан массив, состоящий из N целых случайных чисел. Отсортировать массив по возрастанию различными методами и оценить эффективность этих методов.
Методы:
• Сортировка простым включением


*/
#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;
void inclusionSort(int *num, int size)
{
	// Для всех элементов кроме начального
	for(int i = 1; i < size; i++)
	{
		int value = num[i]; // запоминаем значение элемента
		int index = i;     // и его индекс
		while((index > 0) && (num[index - 1] > value))
		{   // смещаем другие элементы к концу массива пока они меньше index
			num[index] = num[index - 1];
			index--;    // смещаем просмотр к началу массива
		}
		num[index] = value; // рассматриваемый элемент помещаем на освободившееся место
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
	inclusionSort(m, n);
	cout << "сортированный массив:" << endl;
	for(int i = 0; i < n; i++)
		cout << m[i] << " ";
	cout << endl;
	delete[] m;
	system("pause.exe");
	return 0;
}