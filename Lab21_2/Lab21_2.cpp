/*
* Цель: изучить основные алгоритмы обработки графов.
Задания:
Разработать программу, которая:
- запрашивает пользователя о количестве вершин и ребер взвешенного неориентированного графа, а также перечень существующих ребер и их вес;
- формирует по полученной информации матрицу смежности графа;
- запрашивает начальную и конечную вершину графа;
- выводит на экран вес кратчайшего пути;
Задачу решить с помощью алгоритма Флойда
*/
#include <vector>
#include <iostream>
using namespace std;
void printMatrix(vector<vector<int>> m, int n)
{
	for(int row = 0; row < n; row++)
	{
		for(int col = 0; col < n; col++) { cout << m[row][col] << " "; }
		cout << endl;
	}
	cout << endl;
}
int FU(vector<vector<int>>  d, int n, int st, int ed)
{
	vector<vector<int>> path(n);
	for(int k = 0; k<n; ++k)
		for(int i = 0; i<n; ++i)
			for(int j = 0; j<n; ++j)
				if(d[i][j] > d[i][k] + d[k][j] && (d[k][j] != INT_MAX && d[i][k] != INT_MAX))
				{
					d[i][j] = d[i][k] + d[k][j];

				}
	return d[st][ed];
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество вершин:";
	cin >> n;
	vector<vector<int>> m(n);
	/*
	 *Если не хочется заполнять с консоли
	m = {
	{0,0,21,71,0,0,63},
	{0,0,9,83,7,0,70},
	{21,9,0,0,0,18,0},
	{71,83,0,0,57,87,93},
	{0,7,0,57,0,6,59},
	{0,0,18,87,6,0,66},
	{63,70,0,93,59,66,0}
	};
	*/
	 /* Заполнение матрицы смежности с консоли */
	for(int row = 0;row < n;++row)
	{
		m[row].resize(n);
		fill(m[row].begin(), m[row].end(), 0);
	}
	for(int row = 0; row < n; row++)
	{
		cout << "Введите номера вершин, в c которыми связана вершина " << row
			<< endl << "Поставьте '%' , если связей больше нет" << endl;
		char temp = '1';
		while(true)
		{
			cin >> temp;
			if(temp == '%') break;
			m[row][(int) (temp - '0')] = 1;
			if(m[(int) (temp - '0')][row] == 1) m[row][(int) (temp - '0')] = 1;
		}
	}
	for(int row = 0; row < n; row++)
	{
		for(int col = 0; col < n; col++)
		{
			if(m[col][row] != 0 && m[col][row] > 1) m[row][col] = m[col][row];
			if(m[row][col] == 1)
			{
				int temp;
				cout << "Введите вес ребра между вершинами " << row << " и " << col << ": ";
				cin >> temp;
				m[row][col] = temp;
			}
		}
	}
	/* Конец заполнения матрицы смежности с консоли*/
	cout << "Матрица смежности:" << endl;
	printMatrix(m, n);
	for(int row = 0; row < n; row++)
		for(int col = 0; col < n; col++)
			if(m[row][col] == 0)
				m[row][col] = INT_MAX;
	int st, ed;
	cout << "Введите  начальную и конечную вершину графа:";
	cin >> st >> ed;
	
	cout << "Вес кратчайшего пути: " << FU(m, n, st, ed) << endl;
	system("pause.exe");
}