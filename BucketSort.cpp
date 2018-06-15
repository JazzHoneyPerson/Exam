//карманная сортировка
//O(n+k)
//O(n*logk n)
//O(n*k)
//да

//Распределяем элементы в k карманов,
//сортируем элементы внутри карманов,
//из каждого кармана данные записываются в массив в порядке разбиения
void bucketSort(int *arr, int size, int max) {
    // Create buckets.
    // Use array of vector here.
    std::vector<int> *v = new std::vector<int>[size];
    int i = 0;
    int basis;
    double devisor=ceil(sqrt(max));

    // Insert array element to buckets.
    for (; i < size; i++) {
        basis = ceil((double)arr[i]/devisor);
        v[basis].push_back(arr[i]);
    }

    // Sort individual bucket.
    for (i = 0; i < size; i++) {
        std::sort(v[i].begin(), v[i].end());
    }

    // Concate all elements in buckets.
    for (i = 0; i < size; i++) {
        for (size_t j = 0; j < v[i].size(); j++) {
            *arr++= v[i][j];
        }
    }
    delete[] v;
}
