#pragma once
#include "vector"
using namespace std;

class BinMinHeap
{
private:
	vector<int> _vector;
	void BubbleDown(int index);
	void BubbleUp(int index);
	void Heapify();

public:
	BinMinHeap(int* array, int length);
	BinMinHeap(const vector<int>& vector);
	BinMinHeap();
	void remove(int index);
	int findItem(int value);
	void Insert(int newValue);
	int GetMin();
	void DeleteMin();
	void Display();
	int getSize();
	vector<int> BinMinHeap::extractLevel(int level);
};