#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct s_node
{
	int c;
	char ch;
	int n;
	vector<s_node*> br;
};

class my_ifstream: public ifstream
{
public:
	virtual my_ifstream& operator >> (char&);
	my_ifstream(const char *_Filename, ios_base::openmode _Mode = ios_base::in, int _Prot = (int) ios_base::_Openprot);
};

my_ifstream::my_ifstream(const char *_Filename, ios_base::openmode _Mode, int _Prot):ifstream(_Filename, _Mode, _Prot)
{}

my_ifstream& my_ifstream::operator >> (char& ch)
{
	ch = get();

	return *this;
}

void tree_walk(s_node *);
void tree_del(s_node *);
void write_message();

ofstream fout("output.txt");
string table[256];

int main()
{
	my_ifstream fin("input.txt", ios_base::in | ios_base::binary);

	if(!fin.is_open())
	{
		cout << "Input file not found" << endl;

		system("pause");

		return 0;
	}

	vector< char> ch_set;
	vector<s_node> nodes;
	char ch;
	int j = 0;

	while(fin >> ch)
	{
		int i;

		for(i = 0; i < ch_set.size() && ch_set[i] != ch; i++);

		if(i == ch_set.size())
		{
			s_node t;

			ch_set.push_back(ch);

			t.ch = ch;
			t.n = 0;
			t.c = 0;

			nodes.push_back(t);

			my_ifstream fin2("input.txt", ios_base::in | ios_base::binary);

			while(fin2 >> ch)
				if(ch == nodes[j].ch)
					nodes[j].n++;

			j++;
		}
	}

	for(int i = 0; i < nodes.size() - 1; i++)
		fout << "'" << nodes[i].ch << "'" << nodes[i].n << ", ";

	fout << "'" << nodes[nodes.size() - 1].ch << "'" << nodes[nodes.size() - 1].n << endl << endl;

	vector<s_node*> t;

	for(int i = 0; i < nodes.size(); i++)
	{
		t.push_back(new s_node);
		*t[i] = nodes[i];
	}

	while(t.size() > 1)
	{
		s_node *x;

		for(int i = 0; i < t.size(); i++)
			for(int j = 0; j < t.size(); j++)
				if(t[i]->n < t[j]->n)
					x = t[i], t[i] = t[j], t[j] = x;

		s_node *min1 = t[0];
		int c1 = 0;

		t.erase(t.begin() + c1);

		s_node *min2 = t[0];
		int c2 = 0;

		s_node *tmp = new s_node;

		tmp->br.push_back(min1);
		tmp->br.push_back(min2);

		tmp->c = 2;
		tmp->n = min1->n + min2->n;
		t[c2] = tmp;
	}

	tree_walk(t[0]);
	write_message();
	tree_del(t[0]);

	return 0;
}

void tree_walk(s_node *root)
{
	static string s = "";

	if(root->c)
	{
		s += "1";

		tree_walk(root->br[1]);
		s.erase(s.size() - 1, 1);

		s += "0";

		tree_walk(root->br[0]);
		s.erase(s.size() - 1, 1);
	}
	else
	{
		fout << "'" << root->ch << "'" << " = " << s << endl;
		table[root->ch] = s;
	}
}

void tree_del(s_node *root)
{
	if(root->c)
	{
		tree_del(root->br[1]);
		tree_del(root->br[0]);
	}
	else
		delete root;
}

void write_message()
{
	my_ifstream fin("input.txt");
	char ch;

	fout << endl;

	while(fin >> ch)
		fout << table[ch] << " ";
}