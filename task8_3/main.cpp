// быстрая сортировка

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void random_array(vector<int> &array) {
    srand(static_cast<unsigned int>(time(nullptr)));
    cout << "Initial array: ";
    for (int i = 0; i < array.size(); i++) {
        array[i] = rand();
        cout << array[i] << ' ';
    }
    cout << endl;
}

int Partition(vector<int>& values, int l, int r) {
    int x = values[r];
    int less = l;

    for (int i = l; i < r; i++) {
        if (values[i] <= x) {
            swap(values[i], values[less]);
            ++less;
        }
    }
    swap(values[less], values[r]);
    return less;
}

void QuickSortImpl(vector<int>& values, int l, int r) {
    if (l < r) {
        int q = Partition(values, l, r);
        QuickSortImpl(values, l, q - 1);
        QuickSortImpl(values, q + 1, r);
    }
}

void QuickSort(vector<int>& values) {
    if (not values.empty()) {
        QuickSortImpl(values, 0, values.size() - 1);
    }
}

int main() {
    int N;
    vector<int> array(5);
    cout << "Enter N:";
    cin >> N;
    random_array(array);
    QuickSort(array); //вызов функции
    cout << "Result array: ";
    for (int i = 0; i < array.size(); ++i)
        cout << array[i] << ' ';
    return 0;
}
