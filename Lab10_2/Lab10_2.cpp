/*
 * 2. Осуществить алгоритм упорядоченного дерева поиска. Найти ключ поиска и удалить его из дерева.
 * Делаем бинарное дерево поиска с минимумом наверху.
 */
#include "BinMinHeap.h"
#include <iostream>
#include <vector>
int main()
{
	
	int array2[] = {117, 42, 56, 29, 37, 50,48,2,15,1,12};

	
	BinMinHeap bin_heap(array2, 11);
	
	cout << " binary heap: " << endl;
	bin_heap.Display();

	cout << "Enter value to remove from heap:" << endl;
	int remove;cin >> remove;
	cout << endl;
	int pos = bin_heap.findItem(remove);
	if(pos == 0) cout << "Element not found."; 
	else bin_heap.remove(pos);
	cout << "binary heap after remove:" << endl;
	bin_heap.Display();
	cout << endl;

	system("pause.exe");
	return 0;
}