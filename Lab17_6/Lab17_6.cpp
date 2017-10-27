/*

Задания:
Дан массив, состоящий из N целых случайных чисел. Отсортировать массив по возрастанию различными методами и оценить эффективность этих методов.
Методы:
• Быстрая сортировка (Хоара)


*/
#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;

void quickSortR(int* a, int N)
{

	long i = 0, j = N;      // поставить указатели на исходные места
	int  p;
	p = a[N >> 1];      // центральный элемент
						// процедура разделения
	do
	{
		while(a[i] < p) i++;
		while(a[j] > p) j--;

		if(i <= j)
		{	
			swap(a[i], a[j]);
			i++; j--;
		}
	} while(i <= j);

	// рекурсивные вызовы, если есть, что сортировать 
	if(j > 0) quickSortR(a, j);
	if(N > i) quickSortR(a + i, N - i);
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
	quickSortR(m, n-1);
	cout << "сортированный массив:" << endl;
	for(int i = 0; i < n; i++)
		cout << m[i] << " ";
	cout << endl;
	delete[] m;
	system("pause.exe");
	return 0;
}