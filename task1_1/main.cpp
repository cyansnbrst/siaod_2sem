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

    // ввод нужной длины массива
    int N1;
    cout << "Enter the length of the array: " << endl;
    cin >> N1;
    if (N1 < 1) {
        cout << "Invalid length value" << endl;
        return 0;
    }

    // ввод исходного массива
    string array1[N1];
    cout << "Enter the elements of the array of length " << N1 << ": " << endl;
    for (int i = 0; i < N1; ++i) {
        cin >> array1[i];
    }

    // находим первый вход числа-палиндрома и его номер
    int pal;
    int N2;
    for (int i = 0; i < N1; ++i) {
        if (palindrome(array1[i])) {
            pal = i;
            N2 = N1 - i;
            break;
        }
    }

    // создаем второй массив и заполняем его
    string array2[N2];
    for (int i = 0; i < N2; ++i) {
        array2[i] = array1[i + pal];
    }

    // вводим новый элемент
    cout << "Enter the new element for the new array: " << endl;
    string newElem;
    cin >> newElem;

    // добавляем его в новый массив
    string array3[N2 + 1];
    array3[0] = array2[0];
    array3[1] = newElem;
    for (int i = 2; i < N2 + 1; ++i) {
        array3[i] = array2[i - 1];
    }

    // вывод итогового массива
    cout << "New array: " << endl;
    for (int i = 0; i < N2 + 1; ++i) {
        cout << array3[i] << endl;
    }
    return 0;
}
