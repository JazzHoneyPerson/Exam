//сортировка вставками:
// Лучшее время - О(n)
//Среднее О(n^2)
//Худшее О(n^2)
//Память О(1)
//устойчивость - да

//На кадом шаге алгоритма мы выбираем один из элементов входных данных и вставляем его на нужную позицию
// в уже осортированной части массива до тех пор,
// пока весь набор входных данных не будет отсортирован
template< class T >
void insertionSort(T* arr, int size, int step=1)
{
	for (int i=0; i<size-step; i+=step)// переходим к следующиму элементу
	{
		int j=i;
		while(j>=0&&arr[j]>arr[j+step])//ищем куда его вставить
		{
			swap(arr[j],arr[j+step]);
			j-=step;
		}

	}
}
//Доказательство корректности:
//1)алгоритм завершает свою работу так как цикл for(i=0; i<size-step;i+=step) не является бесконечным
// и условие внутри цикла while подразумевает конечность, то есть j - положительное число, постоянно уменьшается
//на положительную велечину 1 и наступит момент, когда  j<0 и цикл завершит свою работу
//2) Алгоритм действительно сортирует массив
//

//Сортировка Шелла
//Лучшее время: O(n*log^2 n)
//Среднее:зависит от шага
//Лучшее время:O(n^2)
//Память О(1)
//Устойчивость: нет

//Является модификацией сортировки вставками,
//сортирует между собой элементы стоящие на кратных нашему шагу местах
template<class T>
void shellSort(T* arr, int size)
{
	for(int h=size/2; h>0; h/=2 )
	{
		insertionSort(arr,size,h);
	}
}