// Exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



template< class T >
//Идея метода : шаг сортировки состоит в проходе снизу вверх по массиву.
//По пути просматриваются пары соседних элементов.
//Если элементы некоторой пары находятся в неправильном порядке, то меняем их местами.
//Сложность:O(n^2)
void bubbleSort(T* arr, int size)
{
	T tmp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
void oddEvenSort(T* arr, int size)
{
	for(int i=0; i<)
}
int main()
{
	int arr[5] = {1,3,2,4,5};
	bubbleSort(arr, 5);
    return 0;
}

