/*
 * Цель: изучить основные алгоритмы обработки графов.
Задания:
Разработать программу, которая:
- запрашивает пользователя о количестве вершин и ребер взвешенного неориентированного графа, а также перечень существующих ребер и их вес;
- формирует по полученной информации матрицу смежности графа;
- запрашивает начальную и конечную вершину графа;
- выводит на экран кратчайший путь между заданными вершинами и его вес;
Задачу решить с помощью алгоритма Дейкстры
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
int Dijkstra(vector<vector<int >> w,int st,int ed,int n)
{
	/*
	 visited - массив посещенных вершин( индекс равен номеру вершины);
	  w - матрицы путей(хранит вес ребер), где несуществующие ребра имеют бесконечный вес;
	  D - массив минимальных путей;
	  INT_MAX - Максимальный размер типа int, принимаемый за бесконечность;
	st - номер источника
	 */
	bool *visited = new bool[n];
	int * D = new int[n];
	for(int i = 0;i<n;i++)
	{
		D[i] = w[st][i];
		visited[i] = false;
	}
	D[st] = 0;
	int index = 0, u = 0;
	vector<vector<int>> path(n);
	for(int i = 0;i<n;i++)
	{
		int min = INT_MAX;
		for(int j = 0;j<n;j++)
		{
			if(!visited[j] && D[j]<min )
			{
				min = D[j];
				index = j;
			}
		}
		u = index;
		visited[u] = true;
		for(int j = 0;j<n;j++)
		{
			if(!visited[j] // не заглядывали
				&& w[u][j] != INT_MAX // путь существует
				&& D[u] != INT_MAX // этот путь сушествует до нашей вершины
				&& (D[u] + w[u][j]<D[j])) // путь кротчайший
			{
				D[j] = D[u] + w[u][j];
				path[j].push_back(u);
				path[j].push_back(j);
			}
		}
	}
	cout << "Кратчайший путь из начальной вершины до конечной:\t\n";
		
	if(D[ed] != INT_MAX)
	{
		cout << st ; 
		for(int k : path[ed])
		{
				
			if(path[k].size() > 0)
			{
				for(int j = 0; j < path[k].size(); j++)
				{
					cout << " -> " << path[k][j];
				}
			}
			else 
				cout << "->" << k;
		}	
		cout << endl;
	}
	else
		cout << st << " -> " << ed << " = " << "маршрут недоступен" << endl;
	int pathCost = D[ed];
	delete[] visited;
	delete[] D;
	return pathCost;
	
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество вершин:";
	cin >> n;
	vector<vector<int>> m(n);
/*	Если не хочется заполнять с консоли
 *	m = {
		{0,0,21,71,0,0,63},
		{0,0,9,83,7,0,70},
		{21,9,0,0,0,18,0},
		{71,83,0,0,57,87,93},
		{0,7,0,57,0,6,59},
		{0,0,18,87,6,0,66},
		{63,70,0,93,59,66,0}
	};
*/
	/* Заполнение матрицы смежности с консоли*/
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
			m[row][(int) (temp - '0') ] = 1;
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
	int st,ed;
	cout << "Введите  начальную и конечную вершину графа:";
	cin >> st >> ed;
	cout << "Вес этого пути: " << Dijkstra(m, st, ed, n) << endl;
	system("pause.exe");
}