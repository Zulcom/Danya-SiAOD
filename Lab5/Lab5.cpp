#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> m, int n) {
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++) { cout << m[row][col] << " "; }
		cout << endl;
	}
	cout << endl;
}

vector<vector<int>> prodMatrix(vector<vector<int>> p1, vector<vector<int>> p2) {
	int n = p1.size();
	vector<vector<int>> res(n);
	for (int row = 0; row < n; row++)
	{
		res[row].resize(n);
		fill(res[row].begin(), res[row].end(), 0);
		for (int col = 0; col < n; col++)
			for (int inner = 0; inner < n; inner++) 
				res[row][col] += p1[row][inner] * p2[inner][col]; // Multiply the row of A by the column of B to get the row, column of product.
	}
	return res;
}

vector<vector<int>> powMatrix(vector<vector<int>> m, int powder) {
	vector<vector<int>> powered = m;
	for (int i = 0; i < powder - 1; i++)  powered = prodMatrix(powered, m); 
	return powered;
}

vector<vector<int>> sumMatrix(vector<vector<int>> p1, vector<vector<int>> p2, int n) {
	vector<vector<int>> res(n);
	for (int row = 0; row < n; row++)
		for (int col = 0; col < n; col++)
		{
			res[row].resize(n);
			res[row][col] = p1[row][col] + p2[row][col];
		}
	return res;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество вершин:";
	cin >> n;
	vector<vector<int>> m(n);
	for (int row = 0; row < n; row++)
	{
		cout << "Введите номера вершин, в которые ведёт вершина " << row + 1
			<< endl << "Поставьте '%' , если связей больше нет" << endl;
		char temp = '1';
		m[row].resize(n);
		fill(m[row].begin(), m[row].end(), 0);
		while (true)
		{
			cin >> temp;
			if (temp == '%') break;
			m[row][(int) (temp - '0') - 1] = 1;
		}
	}
	cout << "Матрица смежности:" << endl;
	printMatrix(m, n);
	int ti, tj, tk;
	cout << "Введите данные для поиска транзитарных путей(i,j,k): ";
	cin >> ti >> tj >> tk;
	vector<vector<int>> powered = powMatrix(m, tk);
	cout << "Число транзитных путей: " << powered[ti - 1][tj - 1] << endl;
	int ish = 0;
	int pv;
	cout << "Полустепень исхода какой вершины отобразить?:";
	cin >> pv;
	for (int i = 0; i < n; i++) 
			ish += m[pv - 1][i];
	cout << "Полустепень исхода вершины " << pv << ": " << ish << endl;
	int pz;
	cout << "Полустепень захода какой вершины отобразить?:";
	cin >> pz;
	int zah = 0;
	for (int i = 0; i < n; i++) 
			zah += m[i][pz - 1];
	cout << "Полустепень захода вершины " << pz << ": " << zah << endl;
	cout << "Матрица связанности:" << endl;
	/*Суммируем матрицы в степени 1-5*/
	vector<vector<int>> comminicationMatrix =
					sumMatrix(
								sumMatrix(
										sumMatrix(
													sumMatrix(
															m,
															powMatrix(m, 2), n),
													powMatrix(m, 3), n),
										powMatrix(m, 4), n),
								powMatrix(m, 5), n);
	
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			if (comminicationMatrix[i][j] != 0) 
					comminicationMatrix[i][j] = 1;
	printMatrix(comminicationMatrix, n);
	cout << "Структурная избыточность:";
	int allInmatrixSum = 0;
	for (vector<int> i : m) 
		for (int j : i) 
			allInmatrixSum += j;
	double izb = 1. / 2 * allInmatrixSum * (1. / (n - 1)) - 1;
	cout << izb;
	if (izb < 0) cout << endl << "Система не связана" << endl;
	system("pause.exe");
	return 0;
}
