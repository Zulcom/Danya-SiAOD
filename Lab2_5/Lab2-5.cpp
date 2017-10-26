//5.	Сформировать и вывести на экран множество из n символов латинского алфавита (n< 20). Если вводимая буква уже есть в множестве, выдать соответствующее сообщение.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cout << "ENter n:";
	cin >> n;
	vector<char> mn;
	for(int i = 0; i < n; i++)
	{
		char temp;
		cout << "enter char:";
		cin >> temp;
		if(std::find(mn.begin(), mn.end(), temp) != mn.end()) cout << "Char already in list!" << endl;
		else mn.push_back(temp);
	}
	for(char i : mn) { cout << i << " "; }
	system("pause.exe");
	return 0;
}