#include <iostream>

using namespace std;

bool search(int value, int values[], int n) {
    // проверим количество элементов в массиве
    if (n <= 0)
        return false;

    // находим середину массива
    int middle = n / 2;
    if (value > values[middle])
        return search(value, values + middle + 1, n - middle - 1);
    else if (value < values[middle])
        return search(value, values, middle);

    return true;
}

int main() {
    int N;
    int x;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    cin >> x;
    if (search(x, arr, N))
        cout << "True";
    else
        cout << "False";
    return 0;
}
