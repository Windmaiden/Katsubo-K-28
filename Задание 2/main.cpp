// ConsoleApplication66.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

int a[10000];
int N = 11;// кол-во элементов массива
int d = 2;

void heapify(int n, int k)
{
	int maxNum = k;

	for (int i = k * d + 1; i < n && i <= d * k + d; i++)
	{
		if (a[i] > a[maxNum])
			maxNum = i;
	}

	if (k != maxNum)
	{
		swap(a[k], a[maxNum]);
		heapify(n, maxNum);
	}
}

void printArray(int * a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << "\n\n";
}


void GenerateArray()
{
	for (int i = 0; i < N; i++)
		a[i] = rand() % 100;
}

int main()
{
	GenerateArray();
	printArray(a, N);
	
	//строим сортирующую пирамиду
	for (int i = N -1; i >= 0; i--)
	{
		heapify(N, i);
	}

	for (int last = N - 1; last >= 0; last--)
	{
		// переместить текущий макс. элемент в конец
		swap(a[0], a[last]);

		// найти новый макс. элемент
		heapify(last, 0);
	}

	printArray(a, N);
}

