// простая вставка

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

int i, j, key = 0, temp = 0;

void InsertSort(vector<int> &mas, int n) { //сортировка вставками
    key = 0, temp = 0;
    for (int i = 0; i < n - 1; i++) {
        key = i + 1; // наш указатель переводим на первый элемент, так как в цикле мы идём от 0
        temp = mas[key]; //temp - это тот элемент, который мы будем пробовать вставлять
        for (j = i + 1; j > 0; j--) {
            if (temp < mas[j -
                           1]) // если тот элемент, который мы хотим переставить меньше элемента, расположенного слева от него, то
            {
                mas[j] = mas[j - 1]; // меняем их местами
                key = j - 1; // указатель сдвигаем, и он выйдет в отрицательный диапозон, вследствие чего цикл прервётся
            }

        }
        mas[key] = temp;
    }
    cout << "Result array: ";
    for (i = 0; i < n; i++) // вывод массива
        cout << mas[i] << " ";
}

int main() {
    int N;
    vector<int> array(5);
    cout << "Enter N:";
    cin >> N;
    random_array(array);
    InsertSort(array, N); //вызов функции
    cout << endl;
    return 0;
}
