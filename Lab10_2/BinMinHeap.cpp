#include "BinMinHeap.h"
#include "iostream"
#include <algorithm>
BinMinHeap::BinMinHeap(int* array, int length): _vector(length)
{
	for(int i = 0; i < length; ++i)
	{
		_vector[i] = array[i];
	}

	Heapify();
}

BinMinHeap::BinMinHeap(const vector<int>& vector): _vector(vector)
{
	Heapify();
}

BinMinHeap::BinMinHeap()
{}

void BinMinHeap::Heapify()
{
	int length = _vector.size();
	for(int i = length - 1; i >= 0; --i)
	{
		BubbleDown(i);
	}
}

void BinMinHeap::BubbleDown(int index)
{
	int length = _vector.size();
	int leftChildIndex = 2 * index + 1;
	int rightChildIndex = 2 * index + 2;

	if(leftChildIndex >= length)
		return; //index is a leaf

	int minIndex = index;

	if(_vector[index] > _vector[leftChildIndex])
	{
		minIndex = leftChildIndex;
	}

	if((rightChildIndex < length) && (_vector[minIndex] > _vector[rightChildIndex]))
	{
		minIndex = rightChildIndex;
	}

	if(minIndex != index)
	{
		int temp = _vector[index];
		_vector[index] = _vector[minIndex];
		_vector[minIndex] = temp;
		BubbleDown(minIndex);
	}
}

void BinMinHeap::BubbleUp(int index)
{
	if(index == 0)
		return;

	int parentIndex = (index - 1) / 2;

	if(_vector[parentIndex] > _vector[index])
	{
		int temp = _vector[parentIndex];
		_vector[parentIndex] = _vector[index];
		_vector[index] = temp;
		BubbleUp(parentIndex);
	}
}
void BinMinHeap::remove(int index) {
	_vector.erase(_vector.begin() + index);
	this->Heapify();
}

int BinMinHeap::findItem(int value) {
	
	return find(_vector.begin(), _vector.end(), value) - _vector.begin();
}

void BinMinHeap::Insert(int newValue)
{
	//int length = _vector.size();
	_vector.push_back(newValue);

	BubbleUp(_vector.size() - 1);
}

int BinMinHeap::GetMin()
{
	return _vector[0];
}

void BinMinHeap::DeleteMin()
{
	int length = _vector.size();

	if(length == 0)
	{
		return;
	}

	_vector[0] = _vector[length - 1];
	_vector.pop_back();

	BubbleDown(0);
}
void BinMinHeap::Display()
{
	for(int i = 0;i<_vector.size();i++)
	{
		std::cout << i << " " << _vector[i] << endl;
	}
	cout << endl;

}
vector<int> BinMinHeap::extractLevel(int level)
{
	vector<int> levelElements;
	int amont = pow(2, level); // количество на уровне x
	int first = pow(2, level) - 1; // самый левый на уровне x
	int last = first + amont > _vector.size() ? _vector.size() : first + amont;
	for(int i = first;i<last;++i)
		levelElements.push_back(_vector[i]); // запоминаем элементы с уровня
	_vector.erase(_vector.begin() + first, _vector.begin() + last);
	this->Heapify();
	return levelElements;
}
int BinMinHeap::getSize()
{
	return _vector.size();
}