//Быстрая сортировка
//Лучшее время:O(n*log n)
//Среднее:O(n*log n)
//Худшее: O(n^2)(маловеротно)
//Память: O(log n)(стек вызовов)
//Устойчивость: нет

//Один из самых широко используемых алгоритмов сортировки.
//Алгоритм состоит в выборе опорного элемента,
//раделении массива на 2 части относительно опорного
//(одна - все элементы, меньшие опорного элемента, вторая - большие),
//и в сортировке полученных частей рекурсивным вызовом себя от них
template<class T>
void quickSortR(T* arr, int start, int end) {
    if (end == start) return;
    int storeIndex = start;
    for (int i = start; i < end; i++)
        if (arr[i] <= arr[end])
        {
            swap(arr[i],arr[storeIndex]);
            storeIndex++;
        }
    swap(arr[storeIndex],arr[end]);
    if (storeIndex > start) quickSortR(arr, start, storeIndex - 1);
    if (storeIndex < end) quickSortR(arr, storeIndex + 1, end);
}
//Сортировка подсчетом
//Лучшее время: O(n)
//Среднее: O(n+k)
//Худшее:O(k)
// Устойчивость: Да
