/*
Учет проданных на поезд билетов.
Структура элемента: номер поезда, номер вагона, номер места, дата отправления, стоимость билета.
Таблица хранит данные по всем вагонам поезда.
Операции:
1)	Добавить запись о продаже билета в таблицу.
2)	Определить количество билетов, проданных на поезд заданного номера и дате отправления.
3)	Удалить запись из таблицы по проданному билету.
4)	Вывести сведения о количестве проданных билетов в каждый вагон поезда.
 */

#include <iostream>
#include "Ticket.h"


void add_ticket(Ticket t, Ticket *a, int &k) {
    a[k] = t;
    ++k;
}

int train_num(int t, string d, Ticket *a, int k) {
    int n = 0;
    for (int i = 0; i < k; ++i) {
        if ((a[i].train == t) && (a[i].date == d)) {
            ++n;
        }
    }
    return n;
}

void delete_info(int n, Ticket *a, int L) {
    a[n] = Ticket();
    for (int i = n; i < L - 1; ++i) {
        a[i] = a[i + 1];
    }
}

int van_num(int t, int v, Ticket *a, int L) {
    int n = 0;
    for (int i = 0; i < L; ++i) {
        if ((a[i].train == t) && (a[i].van == v)) {
            ++n;
        }
    }
    return n;
}


int main() {
    int N = 5;
    auto *table = new Ticket *[N];
    for (int i = 0; i < N; ++i) {
        table[i] = new Ticket[N];
    }
    int train, van, seat, command;
    float price;
    string date;
    int count = 0;

    cout << "1: Add a ticket sale record to the table" << endl <<
         "2: Determine the number of tickets sold for a train of a given number and departure date" << endl <<
         "3: Delete an entry from the table for a sold ticket" << endl <<
         "4: Display information about the number of tickets sold in each car of the train" << endl;

    while (true) {

        cin >> command;

        if (command == 1) {
            Ticket ticket;
            cout << "Enter the train, the van, the seat, the price and the date: " << endl;
            cin >> ticket.train >> ticket.van >> ticket.seat >> ticket.price >> ticket.date;
            add_ticket(ticket, *table, count);
            cout << "Success" << endl;
        } else if (command == 2) {
            cout << "Enter the train and the date: " << endl;
            cin >> train >> date;
            cout << train_num(train, date, *table, count) << endl;
        } else if (command == 3) {
            int num;
            cout << "Enter the number of ticket: " << endl;
            cin >> num;
            delete_info(num, *table, N);
            cout << "Success" << endl;
        } else if (command == 4) {
            cout << "Enter the train: " << endl;
            cin >> train;
            for (int i = 0; i < 13; ++i) {
                cout << i + 1 << ": " << van_num(train, i, *table, N) << endl;
            }
        } else
            break;
    }
    return 0;
}

/* 5 6 23 3478 24.03
 * 5 8 34 2345 34.34
 * 5 10 45 349 32.04
 * 7 4 93 3984 05.05
 * 9 5 123 345 02.03
 */