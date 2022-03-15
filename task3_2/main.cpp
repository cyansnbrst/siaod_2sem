/*
 * Дано предложение и управляющий символ, значением которого может быть
 * один из символов Y, N. Вывести этот текст без входящих в него цифр,
 * если значение символа управления = Y, а если этот символ = N, то
 * перенести все цифры текста в конец предложения так, чтобы первая
 * встреченная в исходном тексте цифра была последней цифрой,
 * а последняя первой и был сохранен порядок следования остальных цифр.
 */

#include <iostream>
#include <string>

using namespace std;

void ycase(string &x, string &y) {
    for (int i = 0; i < x.size(); ++i) {
        if (!(x[i] >= '0' && x[i] <= '9')) {
            y.push_back(x[i]);
        }
    }
}

void ncase(string &x, string &y) {
    string nums("");
    ycase(x, y);
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] >= '0' && x[i] <= '9') {
            nums.push_back(x[i]);
        }
    }
    swap(nums[0], nums[nums.size() - 1]);
    y.append(nums);
}


int main() {

    // дано предложение
    string snt = "He5ll1o 7 wo4rl10d";
    string str("");

    // объявляем и вводим управляющий символ
    cout << "Enter the control symbol: " << endl;
    char ctrl;
    cin >> ctrl;
    if (toupper(ctrl) == 'Y') {
        ycase(snt, str);
    } else if (toupper(ctrl) == 'N') {
        ncase(snt, str);
    }
    cout << str;
    return 0;
}