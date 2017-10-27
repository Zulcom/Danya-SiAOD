/*
Задания:
Дан массив, состоящий из N целых случайных чисел. Отсортировать массив по возрастанию различными методами и оценить эффективность этих методов.
Методы:
• 	Сортировка распределением
*/
#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>
using namespace std;
const int THRESHOLD = 75;
const int CLASS_SIZE = 75; /* minimum value for m */

void flashsort(int * a, int n, int m, int* ctr) {
	int *l, nmin, nmax, i, j, k, nmove, nx, mx;
	float c1, c2, flash, hold;
	l = new int[m];
	nmin = nmax = 0;
	for (i = 0; i < n; i++)
		if (a[i] < a[nmin]) nmin = i;
		else if (a[i] > a[nmax]) nmax = i;
	if ((a[nmax] == a[nmin]) && (ctr == 0))
	{
		cout << "All the numbers are identical, the list is sorted\n";
		return;
	}
	c1 = (m - 1.0) / (a[nmax] - a[nmin]);
	c2 = a[nmin];
	l[0] = -1;
	for (k = 1; k < m; k++) l[k] = 0;
	for (i = 0; i < n; i++)
	{
		k = floor(c1 * (a[i] - c2));
		l[k] += 1;
	}
	for (k = 1; k < m; k++) l[k] += l[k - 1];
	swap(a[nmax], a[0]);
	nmove = 0;
	j = 0;
	k = m - 1;
	while (nmove < n)
	{
		while (j > l[k])
		{
			j++;
			k = floor(c1 * (a[j] - c2));
		}
		flash = a[j];
		while (j <= l[k])
		{
			k = floor(c1 * (flash - c2));
			hold = a[l[k]];
			a[l[k]] = flash;
			l[k]--;
			flash = hold;
			nmove++;
		}
	}
	for (k = 0; k < (m - 1); k++)
		if ((nx = l[k + 1] - l[k]) > THRESHOLD)
		{
			flashsort(&a[l[k] + 1], nx, CLASS_SIZE, ctr);
			(*ctr)++;
		}
		else
		for (i = l[k + 1] - 1; i > l[k]; i--)
			if (a[i] > a[i + 1])
			{
				hold = a[i];
				j = i;
				while (hold > a[j + 1]) a[j++] = a[j + 1];
				a[j] = hold;
			}
	delete[] l;

}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int n;
	cout << "Input n:";
	cin >> n;
	int* m = new int[n];
	cout << "Несортированный массив:" << endl;
	for (int i = 0; i < n; i++)
	{
		m[i] = rand() % 10;
		cout << m[i] << " ";
	}
	cout << endl;
	flashsort(m, n, n, 0);
	cout << "сортированный массив:" << endl;
	for (int i = 0; i < n; i++) cout << m[i] << " ";
	cout << endl;
	delete[] m;
	system("pause.exe");
	return 0;
}
