#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
string::size_type KMP(const string& S, int begin, const string& pattern)
{
	std::vector<int> pf(pattern.length());

	pf[0] = 0;
	for(int k = 0, i = 1; i < pattern.length(); ++i)
	{
		while((k > 0) && (pattern[i] != pattern[k]))
			k = pf[k - 1];

		if(pattern[i] == pattern[k])
			k++;

		pf[i] = k;
	}

	for(int k = 0, i = begin; i < S.length(); ++i)
	{
		while((k > 0) && (pattern[k] != S[i]))
			k = pf[k - 1];

		if(pattern[k] == S[i])
			k++;

		if(k == pattern.length())
			return (i - pattern.length() + 1); //либо продолжаем поиск следующих вхождений
	}

	return string::npos;
}
int main()
{
	ifstream in("in.txt");
	string find;
	setlocale(LC_ALL, "Russian");
	cout << "Введите слово:";
	getline(cin, find);
	string temp;
	getline(in, temp);
	cout << "Слово найдено в позиции " << KMP(temp, 0, find) <<endl;
	in.close();
	system("pause.exe");
	return 0;
}