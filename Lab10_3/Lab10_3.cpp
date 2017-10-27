/*
 * 3. В текстовом файле хранится текст. Осуществить прямой поиск введенного пользователем слова.
 */
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	ifstream in("in.txt");
	string find;
	setlocale(LC_ALL, "Russian");
	cout << "Введите слово:";
	getline(cin, find);
	string temp;
	while(in >> temp)
		if(temp == find) cout << "Слово найдено. ";
	in.close();
	system("pause.exe");
	return 0;
}
