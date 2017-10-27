/*

Задания:
Дан массив, состоящий из N целых случайных чисел. Отсортировать массив по возрастанию различными методами и оценить эффективность этих методов.
Методы:
•	Сортировка методом Шелла


*/
#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;
int increment(long inc[], long size)
{
	int p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
	do
	{
		if(++s % 2)
		{
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else
		{
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while(3 * inc[s] < size);

	return s > 0 ? --s : 0;
}


void shellSort(int a[], int size)
{
	long inc, i, j, seq[40];
	int s;

	s = increment(seq, size); // вычисление последовательности приращений
	while(s >= 0)  // сортировка вставками с инкрементами inc[] 
	{
		inc = seq[s--];
		for(i = inc; i < size; ++i)
		{
			int temp = a[i];
			for(j = i; (j >= inc) && (temp < a[j - inc]); j -= inc)
			{
				a[j] = a[j - inc];
			}
			a[j] = temp;
		}
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
	shellSort(m, n);
	cout << "сортированный массив:" << endl;
	for(int i = 0; i < n; i++)
		cout << m[i] << " ";
	cout << endl;
	delete[] m;
	system("pause.exe");
	return 0;
}