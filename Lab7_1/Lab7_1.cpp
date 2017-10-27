/*
 * 1.	Создать файл, содержащий вещественные числа. Найти сумму и среднее арифметическое этих чисел.
 */
#include <fstream>
#include <iostream>
using namespace  std;
int main() {
	ifstream in("in.txt");
	double sum = 0, temp = 0;
	int counter = 0;
	while(in >> temp)
	{
		sum += temp;
		counter++;
	}
	in.close();
	cout << "Sum: " << sum << " AVG:" << sum / counter <<endl;
	system("pause.exe");
	return 0;
}
