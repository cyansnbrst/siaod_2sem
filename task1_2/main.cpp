#include <iostream>

using namespace std;


// определяем число-палиндром
bool palindrome(string x) {
    int flag = 0;
    int l;
    l = x.length();
    if (l == 1) {
        return false;
    } else {
        for (int i = 0; i < l / 2; ++i) {
            if (x[i] != x[l - i - 1]) {
                ++flag;
                if (flag > 0) {
                    break;
                }
            }
        }
        if (flag == 0) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {

    // ввод длины исходного массива
    int N;
    cout << "Enter the length of the array: " << endl;
    cin >> N;
    if (N < 1) {
        cout << "Invalid length value" << endl;
        return 0;
    }

    // ввод исходного массива
    auto *array = new string[N];
    cout << "Enter the elements of the array of length " << N << ": " << endl;
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    // находим первый вход числа-палиндрома и его номер
    int pal;
    for (int i = 0; i < N; ++i) {
        if (palindrome(array[i])) {
            pal = i;
            break;
        }
    }
    // смещаем массив на pal элементов влево
    for (int i = 0; i < N - pal; ++i) {
        array[i] = array[i + 2];
    }

    // уменьшаем размер массива на pal элементов, при этом учитываем добавление еще одного
    realloc(array, sizeof(string) * (N - pal + 1));

    // вводим новый элемент
    cout << "Enter the new element for the new array: " << endl;
    string newElem;
    cin >> newElem;

    // смещаем массив на один элемент вправо, начиная со второго элемента
    for (int i = N - pal; i > 1; --i) {
        array[i] = array[i - 1];
    }

    // добавляем новый элемент
    array[1] = newElem;

    // вывод итогового массива
    cout << "New array: " << endl;
    for (int i = 0; i < N - pal + 1; ++i) {
        cout << array[i] << endl;
    }
    return 0;
}
