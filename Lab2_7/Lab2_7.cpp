// 7.	Используя стек, напечатать содержимое введенной строки, выписывая литеры в обратном порядке.
#include <stack>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	stack<char> s;
	string inp;
	cout << "Enter string: ";
	getline(cin, inp);
	for(int i : inp) s.push(i);
	while(!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	cout << endl;
	system("pause.exe");
	return 0;
}