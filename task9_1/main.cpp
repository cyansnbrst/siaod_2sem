// линейный поиск (lenSearch) - поиск с барьером (barSearch) - поиск Фибоначчи (fibSearch)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct refTable {
    int code;
    string name;
};

ostream &operator<<(ostream &out, const vector<refTable> &array) {
    for (refTable i: array)
        out << "Direction code: " << i.code << " | University title: " << i.name << endl;
    return out;
}

string linSearch(int key, const vector<refTable> &table) {
    for (int i = 0; i < table.size(); i++)
        if (table[i].code == key)
            return table[i].name;
    return "Not found";
}

string barSearch(int key, vector<refTable> table) {
    table.push_back(refTable{key, "Not found"});
    int i = 0;
    while (table[i].code != key)
        i++;
    return table[i].name;
}

int fib(int n) {
    if (n == 1 or n == 0)
        return n;
    else if (n >= 2)
        return fib(n - 1) + fib(n - 2);
}

bool comp(refTable a, refTable b) {
    return a.code < b.code;
}

string fibSearch(int key, vector<refTable> table) {
    sort(table.begin(), table.end(), comp);
    int size = table.size();
    int k = 1;
    while (fib(k) < size + 1)
        ++k; // ищем подходящий коэффициент
    int mid = size - fib(k - 2) + 1;
    int f1 = fib(k - 2);
    int f2 = fib(k - 3);
    bool finish = false;
    while (!finish)
        if (mid < 0)
            if (f1 == 1)
                finish = false;
            else {
                mid += f2;
                f1 -= f2;
                f2 -= f1;
            }
        else if (mid >= size)
            if (f2 == 0)
                finish = true;
            else {
                mid -= f2;
                int t = f1 - f2;
                f1 = f2;
                f2 = t;
            }
        else if (key < table[mid].code)
            if (f2 == 0)
                finish = true;
            else {
                mid -= f2;
                int t = f1 - f2;
                f1 = f2;
                f2 = t;
            }
        else if (key > table[mid].code)
            if (f1 == 1)
                finish = false;
            else {
                mid += f2;
                f1 -= f2;
                f2 -= f1;
            }
        else if (key == table[mid].code)
            return table[mid].name;
    return "Not found";
}

int main() {
    int key;
    int size;

    cout << "Enter the size of the table:";
    cin >> size;

    vector<refTable> table;
    vector<refTable> table_;

    for (int i = 0; i < size; i++)
        table.push_back(refTable{i, "MSU" + to_string(i)});
    for (int i = size - 1; i >= 0; i--)
        table_.push_back(refTable{i, "MSU" + to_string(i)});

    cout << "First table" << endl << table;
    cout << "Enter key for search in first table:";
    cin >> key;

    cout << "Result of linSearch for this table: " << linSearch(key, table) << endl;
    cout << "Result of barSearch for this table: " << barSearch(key, table) << endl;
    cout << "Result of fibSearch for this table: " << fibSearch(key, table) << endl;

    cout << endl;

    cout << "Second table" << endl << table_;
    cout << "Enter key for search in second table:";
    cin >> key;

    cout << "Result of linSearch for this table: " << linSearch(key, table_) << endl;
    cout << "Result of barSearch for this table: " << barSearch(key, table_) << endl;
    cout << "Result of fibSearch for this table: " << fibSearch(key, table_) << endl;

}