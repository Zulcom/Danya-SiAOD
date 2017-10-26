#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct vedomost{
	int id;
	string FIO;
	int ocenki[3];
};

// Из ведомости 3-х студентов с их оценками (порядковый  номер,  Ф.И.О. и три оценки) определить количество отличников и средний бал каждого студента.
void quest4()
	{
	vedomost vedomosti[3];
	int OTLcounter = 0;
	for (int i = 0; i < 3; i++)
	{
		vedomosti[i].id = i;
		cout << "Input FIO and ocenki:";
		cin >> vedomosti[i].FIO;

		int avg = 0;
		for (int j = 0; j < 3; j++)
		{
			cin >> vedomosti[i].ocenki[j];
			avg += vedomosti[i].ocenki[j];
		}
		if (avg == 15) OTLcounter++;
		cout << "FIO: " << vedomosti[i].FIO << " AVG: " << avg / 3. << endl;
	}
	cout << "Otlicnik count:" << OTLcounter;
	}

//5.	Сформировать и вывести на экран множество из n символов латинского алфавита (n< 20). Если вводимая буква уже есть в множестве, выдать соответствующее сообщение.
void quest5()
	{
	int n;
	cout << "ENter n:";
	cin >> n;
	vector<char> mn;
	for (int i = 0; i < n; i++)
	{
		char temp;
		cout << "enter char:";
		cin >> temp;
		if (std::find(mn.begin(), mn.end(), temp) != mn.end()) cout << "Char already in list!" << endl;
		else mn.push_back(temp);
	}
	for (char i : mn) { cout << i << " "; }
	}

//6.	Сформировать список, содержащий целые случайные числа в диапазоне[150..190] и вывести на экран.Удалить элемент списка со значением N, если он находится в списке.

void quest6()
	{
	int n;
	cout << "Enter list size:";
	cin >> n;
	vector<int> list;
	for (int i = 0; i < n; i++) list.push_back(150 + (rand() % (int)(190 - 150 + 1)));
	for (int i : list) cout << i << " ";
	cout << endl;
	list.erase(remove(list.begin(), list.end(), n), list.end());
	for (int i : list) cout << i << " ";
	cout << endl;
	}

// 7.	Используя стек, напечатать содержимое введенной строки, выписывая литеры в обратном порядке.
void quest7()
	{
	stack<char> s;
	string inp;
	cout << "Enter string: ";
	getline(cin, inp);
	for (int i : inp) s.push(i);
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	cout << endl;
	}

// 8.	Создать очередь N целых случайных чисел и вывести на экран. Найти элемент R и увеличить в 2 раза, поместить его на место.
void quest8()
	{
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
	}

int main()
	{
	int choice = 0;
	while (choice < 4 && choice > 8)
	{
		cout << "Input correct quest number(4-8):";
		cin >> choice;
	}
	switch (choice)
	{
	case 4: quest4();
		break;
	case 5: quest5();
		break;
	case 6: quest6();
		break;
	case 7: quest7();
		break;
	case 8: quest8();
		break;
	default: return 0;
	}

	system("pause.exe");
	return 0;
	}
