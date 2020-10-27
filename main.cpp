// Copyright 2020 Magellan

#include "components/ExpNode.h"

#include <iostream>
#include <stack>

Magellan::ExpNode* newNode(const int value) {
    Magellan::ExpNode *pNode = new Magellan::ExpNode;
    pNode->m_value = value;

    return (pNode);
}

int main() {
    Magellan::ExpNode *pRoot = newNode(4);
    pRoot->m_left = newNode(2);
    pRoot->m_right = newNode(6);
    pRoot->m_left->m_left = newNode(1);
    pRoot->m_left->m_right = newNode(3);
    pRoot->m_right->m_left = newNode(5);
    pRoot->m_right->m_right = newNode(7);

    std::stack<Magellan::ExpNode *> _stack;
    _stack.push(pRoot);
    Magellan::ExpNode *pNode{ nullptr };

    std::cout << "Values: ";
    while(pNode || !_stack.empty()) {
        if (pNode) {
            std::cout << pNode->m_value << ' ';
            _stack.push(pNode->m_right);
            pNode = pNode->m_left;
        } else {
            pNode = _stack.top();
            _stack.pop();
        }
    }
    std::cout << '\n';

    return (0);
}
