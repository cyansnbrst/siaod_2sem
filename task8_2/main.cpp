// шейкерная сортировка

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

void myShakerSort(vector<int> &arr, int size) {
    int leftMark = 1;
    int rightMark = size - 1;
    while (leftMark <= rightMark) {
        for (int i = rightMark; i >= leftMark; i--)
            if (arr[i - 1] > arr[i])
                swap(arr[i - 1], arr[i]);
        leftMark++;

        for (int i = leftMark; i <= rightMark; i++)
            if (arr[i - 1] > arr[i])
                swap(arr[i - 1], arr[i]);
        rightMark--;
    }
}

int main() {
    int N;
    vector<int> array(5);
    cout << "Enter N:";
    cin >> N;
    random_array(array);
    myShakerSort(array, N); //вызов функции
    cout << "Result array: ";
    for (int i = 0; i < array.size(); ++i)
        cout << array[i] << ' ';
    return 0;
}
