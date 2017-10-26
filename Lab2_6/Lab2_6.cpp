//6.	Сформировать список, содержащий целые случайные числа в диапазоне[150..190] и вывести на экран.Удалить элемент списка со значением N, если он находится в списке.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cout << "Enter list size:";
	cin >> n;
	vector<int> list;
	for(int i = 0; i < n; i++) list.push_back(150 + (rand() % (int) (190 - 150 + 1)));
	for(int i : list) cout << i << " ";
	cout << endl;
	list.erase(remove(list.begin(), list.end(), n), list.end());
	for(int i : list) cout << i << " ";
	cout << endl;
	system("pause.exe");
	return 0;
}