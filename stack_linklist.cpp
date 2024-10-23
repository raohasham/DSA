#include <iostream> 
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};

class Stack {
    Node *head_node;

public:
    Stack() {
        this->head_node = nullptr;
    }

    bool is_empty() {
        return head_node == nullptr;
    }

    void push(int new_data) {
        Node *new_node = new Node(new_data);

        if (!new_node) {
            cout << "\nStack Overflow";
            return;
        }

        new_node->next = head_node;
        head_node = new_node;
    }

    void pop() {
        if (this->is_empty()) {
            cout << "\nStack Underflow" << endl;
        } else {
            Node *temp_node = head_node;
            head_node = head_node->next;
            delete temp_node;
        }
    }

    int peek() {
        if (!is_empty())
            return head_node->data;
        else {
            cout << "\nStack is empty";
            return -1;
        }
    }
};

int main() {
    Stack stack;

    stack.push(11);
    stack.push(22);
    stack.push(33);
    stack.push(44);

    cout << "Top element is " << stack.peek() << endl;


    cout << "Removing two elements" << endl;
    stack.pop();
    stack.pop();

    cout << "Top element is " << stack.peek() << endl;

    return 0;
  }