#include <iostream>

using namespace std;

int main() {

    // ввод нужной длины массива
    int N1;
    cout << "Enter the length of the array: " << endl;
    cin >> N1;
    if (N1 < 2) {
        cout << "Invalid length value" << endl;
        return 0;
    }

    //ввод исходного массива
    auto *array1 = new int *[N1];
    for (int i = 0; i < N1; ++i) {
        array1[i] = new int [N1];
    }
    cout << "Enter the elements of the array of length " << N1 << ": " << endl;
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N1; ++j) {
            cin >> array1[i][j];
        }
    }

    // поиск минимума
    int min = array1[1][0];
    for (int i = 1; i < N1; ++i) {
        for (int j = 0; j < i; ++j) {
            if (array1[i][j] < min) {
                min = array1[i][j];
            }
        }
    }

    //вывод минимума
    cout << "The minimum number under the main diagonal is " << min;
    return 0;
}
