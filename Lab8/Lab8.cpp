/*
 * Необходимо разработать программу, которая дает ответы на следующие вопросы:
•	фамилии студентов, имеющих задолженности хотя бы по одному предмету;
•	название предмета, который был сдан лучше всех;
•	процент студентов, сдавших все экзамены на 5 и 4;
•	номера групп в порядке убывания средней успеваемости.

 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <map>
using namespace  std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string temp, maxF;
	int max = 0, sumF = 0, sumI = 0, sumH = 0, studentCounter = 0, otlCounter = 0;
	vector<vector<double>> groupsAVG(3);
	ifstream in("in.txt");
	multimap<int, string> courses;
	while(getline(in, temp))
	{
		studentCounter++;
		istringstream iss(temp);
		vector<string> tokens{istream_iterator<string>{iss},
			istream_iterator<string>{}};
		if(tokens.size() < 7) cout << "Должник " << tokens.at(1); //если у студента пустое поле в одной из оценок, токенов будет меньше.
		sumF += stoi(tokens.at(4));
		sumI += stoi(tokens.at(5));
		sumH += stoi(tokens.at(6));
		if(stoi(tokens.at(4)) > 3 && stoi(tokens.at(5)) > 3 && stoi(tokens.at(6)) > 3) otlCounter++;
		double avg =( stoi(tokens.at(6)) + stoi(tokens.at(5)) + stoi(tokens.at(4)) )/3.;
		groupsAVG[stoi(tokens.at(0)) - 1].push_back(avg);

	}
	in.close();
	cout << "Лучше всех сдана ";
	if(sumF > sumI && sumF > sumH) cout << "Физика";
	if(sumI > sumF && sumI>sumH) cout << "Информатика";
	if(sumH > sumI && sumH>sumF) cout << "История";
	cout << endl;
	cout << "Процент студентов 4 и 5: " << otlCounter* (studentCounter/100.)*100 << "%" << endl;
	int groupNum[3] = {1,2,3};
	double groups[3] = {0};
	for(int i = 0; i < 3; i++)
	{
		double avg = 0;
		for(int j = 0; j < groupsAVG[i].size(); j++)
			avg += groupsAVG[i][j];
		
		groups[i] = avg / groupsAVG.size();
	}

	for(int i = 3 - 1; i >= 0; i--)
		for(int j = 0; j < i; j++)
			if(groups[j] < groups[j + 1])
			{
				swap(groups[j], groups[j + 1]);
				swap(groupNum[j], groupNum[j + 1]);
			}
	cout << "Группы в порядке убывания средней успеваемости:" << endl;
	for(int i = 0;i < 3;++i) cout << groupNum[i] << endl;
	
	system("pause.exe");
	return 0;
}
