#include "LinkedStack.hpp"

Node::Node(int value, Node* next) : value(value), next(next) {}

Stack::Stack() : stk_top(nullptr), stk_size(0) {}

void Stack::push(int x) {
    Node* new_node = new Node(x, stk_top);
    stk_top = new_node;
    stk_size++;
}

int Stack::pop() {
    if (empty()) {
        throw std::out_of_range("Stack underflow");
    }
    Node* temp = stk_top;
    int popped_value = stk_top->value;
    stk_top = stk_top->next;
    delete temp;
    stk_size--;
    return popped_value;
}

int Stack::size() {
    return stk_size;
}

bool Stack::empty() {
    return stk_size == 0;
}
