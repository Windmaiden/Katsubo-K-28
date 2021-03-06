// ConsoleApplication65.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <queue>
#include "PolyTree.h"

using namespace std;

int NumberOfElementsInArray = 3;
const int NumberOfArrays = 3;

int main()
{
	queue<int> data[NumberOfArrays];

	for (int i = 0; i < NumberOfArrays; i++)
	{
		int x = 0;
		for (int j = 0; j < NumberOfElementsInArray; j++)
		{
			x += rand() % 100;
			data[i].push(x);
			cout << x << " ";
		}
		cout << endl;
	}

	cout << "\n\n";

	PolyTree tree;

	for (int i = 0; i < NumberOfArrays; i++)
	{
		PolyTreeItem item;
		item.OriginIndex = i;
		item.value = data[i].front();
		tree.Add(item);

		data[i].pop();
	}
	//Пока дерево не пустое. Т.е пока остались неотсортированные элементы
	while (!tree.IsEmpty())
	{
		PolyTreeItem smallest = tree.ReturnAndRemoveMinimum();

		int index = smallest.OriginIndex;

		if (!data[index].empty())
		{
			PolyTreeItem item;
			item.OriginIndex = index;
			item.value = data[index].front();
			tree.Add(item);

			data[index].pop();
		}

		cout << smallest.value << " ";

	}
}
