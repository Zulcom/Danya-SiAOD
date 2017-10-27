/*
 * 2.	Протабулировать функцию y= ex+cos x для  -1<=x<=1.5 с шагом 0.1,  записать данные в файл и просмотреть данные из файла.
 */
#include <fstream>
#include <iostream>
using namespace  std;
int main()
{
	ofstream out("in.txt");
	double sum = 0, temp = 0;
	int counter = 0;
	while(in >> temp)
	{
		sum += temp;
		counter++;
	}
	cout << "Sum: " << sum << " AVG:" << sum / counter << endl;
	system("pause.exe");
	return 0;
}
