/*

Задания:
Дан массив, состоящий из N целых случайных чисел. Отсортировать массив по возрастанию различными методами и оценить эффективность этих методов.
Методы:
• 	Сортировка слиянием


*/
#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>
using namespace std;

static void merge(int * buf, size_t left, size_t right, size_t middle)
{
	if(left >= right || middle < left || middle > right) return;
	if(right == left + 1 && buf[left] > buf[right])
	{
		swap(buf[left], buf[right]);
		return;
	}

	vector<int> tmp(&buf[left], &buf[left] + (right + 1));

	for(size_t i = left, j = 0, k = middle - left + 1; i <= right; ++i)
	{
		if(j > middle - left)
		{
			buf[i] = tmp[k++];
		}
		else if(k > right - left)
		{
			buf[i] = tmp[j++];
		}
		else
		{
			buf[i] = (tmp[j] < tmp[k]) ? tmp[j++] : tmp[k++];
		}
	}
}
void MergeSort(int * buf, size_t left, size_t right)
{
	//! Условие выхода из рекурсии
	if(left >= right) return;

	size_t middle = left + (right - left) / 2;

	//! Рекурсивная сортировка полученных массивов
	MergeSort(buf, left, middle);
	MergeSort(buf, middle + 1, right);
	merge(buf, left, right, middle);
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
	MergeSort(m,0, n-1);
	cout << "сортированный массив:" << endl;
	for(int i = 0; i < n; i++)
		cout << m[i] << " ";
	cout << endl;
	delete[] m;
	system("pause.exe");
	return 0;
}