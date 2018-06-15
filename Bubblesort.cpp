#include <cstddef>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;

template< class T >
//Идея метода : шаг сортировки состоит в проходе снизу вверх по массиву.
//По пути просматриваются пары соседних элементов.
//Если элементы некоторой пары находятся в неправильном порядке, то меняем их местами.
//Сложность:O(n^2)
void bubbleSort(T* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j + 1] < arr[j])//сравниваем элемент с соседним(правым)элементом
			{
				swap(arr[j],arr[j+1]);//если правый меньше, то меняем местами
			}
		}
	}
}
//Обоснование корректности сортировки пузырьком
//1)алгоритм завершает свою работу так как цикл for(i=0; i<n;i++) не является бесконечным
//2)Он действительно сортирует массив
template< class T >
//Сортировка чет-нечет
// - модификация пузырьковой сортировки,
//основання на сравнении элементов стоящих на четных и нечетных позициях
//независимо друг от друга. Сложность - О(n^2)
//Преимущество этой сортировки - на нескольких процессорах она выполняется быстрее,
// так как четные и нечетные индексы сортирутся параллельно
void oddEvenSort(T* arr, int size)
{
	for(int i=0; i<size;i++) {
		if (i % 2 == 0) {//если индекс четный, то начинаем сортировать с нечетного элемента
			for (int j = 2; j < size; j += 2) {
				if (arr[j] < arr[j - 1])
					swap(arr[j - 1], arr[j]);
			}
		}
		else//иначе с нечетного
		{
			for (int j=1; j<size;j+=2)
			{
				if (arr[j]<arr[j-1])
					swap(arr[j-1],arr[j]);
			}
		}
	}
}
template< class T >
//Сортировка росческой -
//модификация пузырьковой сортировки , основанной на сравнении
//элементов на расстоянии.
//Сложность О(n^2), но стремится к О(n*log n).
//Является самой быстрой квадратичной сортировкой.
//Недостаток - она не устойчива
//Пояснения: Изначально расстояние между сравниваемыми элементами равно n/k
//где k=1.3 - оптимальное число для этого алгоритма
//Сортируем по этому расстоянию, потом уменьшаем его по этому же правилу
//Когда расстояние между сравниваемыми элементами достигает единицы,
//массив досортировывается обычным пузырьком
void combSort(T* arr, int size)
{
	double k=1.3;
	int jump=size;
	while(jump>1)
	{
		if (jump > 1)
			jump /= k;
		for (int i=0; i<size-jump;i++)
		{
			if(arr[i+jump]<arr[i])
			{
				swap(arr[i], arr[i + jump]);
			}
		}
	}
}
template< class T >
//Сортировка перемешиванием - разновидность
//пузырьковой сортировки, сортирующая массив в двух направлениях
//на каждой итерации. В среднем, сортировка перемешиванием работает в два
//раза быстрее пузырька. Сложность О(n^2), но стремится она к О( k*n),
//где k- максимальное расстояние элемента в неотсортированном массиве от
//его позиции в отсортированном.Псевдокод указан ниже
void shakerSort(T array[], int size)
{
	for (int left = 0, right = size - 1;left < right;)
	{
		for (int i = left; i < right; i++)
		{
			if (array[i + 1] < array[i])// всплывает самый большой пузырь
			{
				swap(array[i], array[i + 1]);
			}
		}
		right--;//исключаем этот пузырь из массива)

		for (int i = right; i > left; i--)
		{
			if (array[i - 1] >  array[i])//тонет самый маленький
			{
				swap(array[i - 1], array[i]);
			}
		}
		left++;//исключаем самый маленький пузырь
	}
}
//Итог:
//Лучшее время:O(n)
//Среднее: О(n^2)
//Худшее: О(n^2)
//Память О(1)
//Устойчивость: Да
//Алгоритм состоит в повторяющихся проходах по сортируемому массиву.
// На каждой итерации последовательно сравниваются
// соседние элементы, и, если порядок в паре неверный, то элементы меняют места
