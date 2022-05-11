#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int x;
    Node *next, *prev;

    Node(int _val) : x(_val), next(nullptr) {};
};

class list {
public:

    Node *first;

    list() : first(nullptr) {};

    void Fill(int x, Node *ptr, Node *prev_node) {
        Node *new_node = new Node(x);
        int new_val;
        cin >> new_val;
        if (new_val != 0) {
            ptr->next = new_node;
            ptr->prev = prev_node;
            Fill(new_val, new_node, ptr);
        }
        else {
            ptr->next = nullptr;
            ptr->prev = prev_node;
        }
    }
};

int main() {
    list List;
    int x;
    cin >> x;
    List.Fill(x, List.first, nullptr);
    return 0;
}
