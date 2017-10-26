#include <iostream>
#include <queue>
using namespace std;


// 8.	Создать очередь N целых случайных чисел и вывести на экран. Найти элемент R и увеличить в 2 раза, поместить его на место.
int main(){
	queue<int> s;
	queue<int> s2;
	int n, r;
	cout << "Enter list size:";
	cin >> n;
	for (int i = 0; i < n; ++i) s.push(rand() % 10);
	cout << "Enter R:";
	cin >> r;
	while (!s.empty())
	{
		cout << s.front() << ' ';
		if (s.front() == r) s2.push(s.front() * 2);
		else s2.push(s.front());
		s.pop();
	}
	cout << endl;

	while (!s2.empty())
	{
		cout << s2.front() << ' ';
		s2.pop();
	}
	cout << endl;
	system("pause.exe");
	return 0;
}
