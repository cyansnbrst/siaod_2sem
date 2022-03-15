/*
 * Дано предложение и управляющий символ, значением которого может быть
 * один из символов Y, N. Вывести этот текст без входящих в него цифр,
 * если значение символа управления = Y, а если этот символ = N, то
 * перенести все цифры текста в конец предложения так, чтобы первая
 * встреченная в исходном тексте цифра была последней цифрой,
 * а последняя первой и был сохранен порядок следования остальных цифр.
 */

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

void ycase(char *x, char *y) {
    int k = 0;
    for (int i = 0; i < strlen(x); ++i) {
        if (!(x[i] >= '0' && x[i] <= '9')) {
            y[k] = x[i];
            ++k;
        }
    }
}

void ncase(char *x, char *y) {
    int k = 0;

    // считаем кол-во цифр в числе
    int count = 0;
    for (int i = 0; i < strlen(x); ++i) {
        if (x[i] >= '0' && x[i] <= '9') {
            ++count;
        }
    }
    char *nums = new char[count - 1];
    for (int i = 0; i < strlen(x); ++i) {
        if (x[i] >= '0' && x[i] <= '9') {
            nums[k] = x[i];
            ++k;
        }
    }
    y = strcat(y, nums);
}


int main() {

    // дано предложение
    char snt[] = "He5ll1o 7 wo4rl10d";
    char *str = new char[50];

    // объявляем и вводим управляющий символ
    cout << "Enter the control symbol: " << endl;
    char ctrl;
    cin >> ctrl;
    if (toupper(ctrl) == 'Y') {
        ycase(snt, str);
    } else if (toupper(ctrl) == 'N') {
        ycase(snt, str);
        int len = strlen(str);
        ncase(snt, str);
        str[strlen(str) - 1] = ' ';
        swap(str[len], str[strlen(str) - 2]);
    }
    cout << str;
    return 0;
}