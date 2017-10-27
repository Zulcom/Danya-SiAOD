/*
 * 2.	Протабулировать функцию y= e^x+cos(x) для  -1<=x<=1.5 с шагом 0.1,  записать данные в файл и просмотреть данные из файла.
 */
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace  std;
int main()
{
	ofstream out("out.txt");
	out << "x   y(x)" << endl;
	for (double x=-1;x<=1.6;x= x+0.1)
	{
		if(x == -1.3877787807814457e-16) x = 0; // Компилятор искренне считает, что -0.1+ 0.1 = -1.3877787807814457e-16
		out << x << " "<< exp(x) + cos(x) <<endl;
	}
	out.close();
	string temp;
	ifstream in("out.txt");
	while(getline(in,temp))
		cout << temp <<endl;
	in.close();
	system("pause.exe");
	return 0;
}
