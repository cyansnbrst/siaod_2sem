#include "Stack.h"

using namespace std;

int main() {
    string exp;
    stack num;
    cout << "Enter the expression:";
    cin >> exp;
    for (int i = 0; i < exp.length(); ++i) {
        if (string("0123456789").find(exp[i]) != string::npos)
            num.push(exp[i] - '0');
        else {
            int a = num.pop();
            int b = num.pop();
            switch (exp[i]) {
                case ('*'):
                    num.push(a * b);
                    break;
                case ('/'):
                    num.push(b / a);
                    break;
                case ('+'):
                    num.push(a + b);
                    break;
                case ('-'):
                    num.push(b - a);
                    break;
                default:
                    break;
            }
        }
        for (auto elem: num.val)
            cout << elem << ' ';
        cout << endl;
    }
    cout << "The answer is: " << num.pop();
}