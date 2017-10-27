#include <fstream>
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main() {
	ifstream in("input.txt");
	map<string, char> dict;
	string temp;
	while(getline(in, temp))
	{
		dict.insert(std::pair<string, char>(temp.substr(6,10), temp.at(1)));
	}
	in.close();
	ifstream in_code("input_code.txt");
	string inpCode;
	while(in_code >> inpCode)
	{
		map<string, char>::const_iterator pos = dict.find(inpCode);
		if(pos == dict.end())
		{
			//handle the error
		}
		else
		{
			char value = pos->second;
			cout << value;
		}
	}
	in_code.close();
	system("pause.exe");
	return 0;
}
