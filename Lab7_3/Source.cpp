/*
* 3.	Создать файл, содержащий данные: ФИО работника;  год рождения; стаж работы.  Просмотреть данные из файла. Определить фамилию работника, имеющего самый большой стаж работы.
*/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
using namespace  std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string temp,maxF;
	int max = 0;
	ifstream in("in.txt");
	while(getline(in, temp))
	{
		cout << temp << endl;
		istringstream iss(temp);
		vector<string> tokens{istream_iterator<string>{iss},
			istream_iterator<string>{}};
		if(stoi(tokens.at(4)) > max)
		{
			max = stoi(tokens.at(4));
			maxF = tokens.at(0);
		}
	}
	in.close();
	cout << "Максимальный стаж " << max << " найден у работника по фамилии " << maxF<<endl;
	
	system("pause.exe");
	return 0;
}
