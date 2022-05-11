#ifndef TASK7_2_STACK_H
#define TASK7_2_STACK_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class stack {
public:
    vector<int> val;

    stack() = default;;

    void push(int x) {
        val.push_back(x);
    }

    int pop() {
        int length = val.size();
        int last = val[length - 1];
        val.pop_back();
        return last;
    }
};

#endif
