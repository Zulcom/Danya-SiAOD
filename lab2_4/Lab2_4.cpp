#include <string>
#include <iostream>
using namespace std;
struct vedomost
{
	int id;
	string FIO;
	int ocenki[3];
};

// Из ведомости 3-х студентов с их оценками (порядковый  номер,  Ф.И.О. и три оценки) определить количество отличников и средний бал каждого студента.
int main()
{
	vedomost vedomosti[3];
	int OTLcounter = 0;
	for(int i = 0; i < 3; i++)
	{
		vedomosti[i].id = i;
		cout << "Input FIO and ocenki:";
		cin >> vedomosti[i].FIO;

		int avg = 0;
		for(int j = 0; j < 3; j++)
		{
			cin >> vedomosti[i].ocenki[j];
			avg += vedomosti[i].ocenki[j];
		}
		if(avg == 15) OTLcounter++;
		cout << "FIO: " << vedomosti[i].FIO << " AVG: " << avg / 3. << endl;
	}
	cout << "Otlicnik count:" << OTLcounter;
	system("pause.exe");
	return 0;
}