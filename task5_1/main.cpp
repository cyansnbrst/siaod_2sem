/* Дан линейный однонаправленный список L, содержащий текст.
   В каждом узле один символ. Слова разделены одним пробелом.
1) Разработать функцию, которая находит последнее слово и переставляет его в начало списка.
2) Разработать функцию, которая удаляет второе слово.
3) Разработать функцию, которая заменяет k-ое слово на новое слово.
   Длина нового слова может быть больше длины k-ого слова.
 */


#include <iostream>
#include <string>

using namespace std;

// реализация узла
struct Node {
    char val;
    Node *next;

    Node(char _val) : val(_val), next(nullptr) {}
};

// реализация односвязного списка
struct list {
    Node *first;
    Node *last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    // добавление элементов в конец списка
    void push_back(char _val) {
        Node *p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    // добавление элементов в начало списка
    void push_front(char _val) {
        Node *p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        p->next = first;
        first = p;
    }

    // вывод списка
    void print() {
        if (is_empty()) return;
        Node *p = first;
        while (p) {
            cout << p->val;
            p = p->next;
        }
        cout << endl;
    }

    // поиск узла по значению
    Node *find(char _val) {
        Node *p = first;
        while (p && p->val != _val)
            p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    // удаление последнего узла
    void remove_last() {
        if (is_empty()) return;
        Node *p = first;
        while (p->next != last)
            p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    /*
     * удаление узла
    void remove(Node *p) {
        Node *prev = first;
        while (prev->next != p) {
            prev = prev->next;
        }
        prev->next = p->next;
        delete p;
    }
    */

    // перегрузка индексации
    Node *operator[](const int index) {
        if (is_empty()) return nullptr;
        Node *p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }

    // перестановка последнего слова на первое место
    void word_swap() {
        if (is_empty()) return;
        // Node *p = last;
        push_front(' ');
        while (last->val != ' ') {
            push_front(last->val);
            remove_last();
        }
    }

    // удаление второго слова
    void second_del() {
        Node *prev = find(' ');
        Node *p = prev->next;
        while (p->val != ' ') {
            p = p->next;
            delete prev->next;
            prev->next = p;
        }
        p = p->next;
        delete prev->next;
        prev->next = p;
    }

    // изменение некоторого слова
    void word_change(int num, string new_word) {
        int spaces = 0;
        int l1 = 1;
        int l2 = new_word.length();

        // ищем первый узел слова
        Node *w_begin = first;
        while (spaces < num - 1) {
            if (w_begin->val == ' ') {
                ++spaces;
            }
            w_begin = w_begin->next;
        }

        // ищем второй узел слова
        Node *w_end = w_begin;
        while (spaces < num) {
            if (w_end->next->next->val == ' ') {
                ++spaces;
            }
            w_end = w_end->next;
        }

        // ищем длину слова в списке
        Node *temp = w_begin;
        while (temp != w_end) {
            temp = temp->next;
            ++l1;
        }

        // заменяем слово по его длине
        for (int i = 0; i < l1; ++i) {
            w_begin->val = new_word[i];
            w_begin = w_begin->next;
        }

        // добавляем оставшиеся буквы
        for (int i = l1; i < l2; ++i) {
            Node *n = new Node(new_word[i]);
            temp = w_end->next;
            w_end->next = n;
            n->next = temp;
            w_end = n;
        }
    }
};

int main() {
    list text;
    string s = "Im feeling so sleepless right now";
    int N = s.length();
    for (int i = 0; i < N; ++i) {
        text.push_back(s[i]);
    }
    text.print();
    text.word_swap();
    text.print();
    text.second_del();
    text.print();
    cout << "Enter the number of the word being changed and the new word: " << endl;
    int num;
    string new_word;
    cin >> num >> new_word;
    text.word_change(num, new_word);
    text.print();
    return 0;
}