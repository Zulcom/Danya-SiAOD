/*

Задания:
Дан массив, состоящий из N целых случайных чисел. Отсортировать массив по возрастанию различными методами и оценить эффективность этих методов.
Методы:
•	Сортировка подсчетом 


 */
#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;
void counting_sort(int* vec, unsigned int len, int min, int max)
{
	assert(min <= max);
	assert(vec != NULL);

	int * cnt = new int[max - min + 1];

	for(int i = min; i <= max; ++i)
	{
		cnt[i - min] = 0;
	}

	for(int i = 0; i < len; ++i)
	{
		++cnt[vec[i] - min];
	}

	for(int i = min; i <= max; ++i)
	{
		for(int j = cnt[i - min]; j--;)
		{
			*vec++ = i;
		}
	}
	delete[] cnt;
}
int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int n;
	cout << "Input n:";
	cin >> n;
	int *m = new int[n];
	cout << "Несортированный массив:" <<endl;
	for(int i = 0; i < n; i++)
	{
		m[i] = rand() % 10;
		cout << m[i] << " ";
	}
	cout << endl;
	counting_sort(m, n, 0, 9);
	cout << "сортированный массив:" << endl;
	for(int i = 0; i < n; i++)
		cout << m[i] << " ";
	cout << endl;
	delete[] m;
	system("pause.exe");
	return 0;
}