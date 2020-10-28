// Copyright 2020 Magellan

#include <iostream>
#include <memory>
#include <stack>

#include "components/ExpNode.h"

std::shared_ptr<Magellan::ExpNode> newNode(const int value) {
    std::shared_ptr<Magellan::ExpNode> pNode = std::make_shared<Magellan::ExpNode>();
    pNode->m_value = value;

    return (pNode);
}

int main() {
    std::shared_ptr<Magellan::ExpNode> pRoot = newNode(4);
    pRoot->m_left = newNode(2);
    pRoot->m_right = newNode(6);
    pRoot->m_left->m_left = newNode(1);
    pRoot->m_left->m_right = newNode(3);
    pRoot->m_right->m_left = newNode(5);
    pRoot->m_right->m_right = newNode(7);

    std::stack<std::shared_ptr<Magellan::ExpNode> > _stack;
    _stack.push(pRoot);
    std::shared_ptr<Magellan::ExpNode> pNode;

    std::cout << "Values: ";
    while (pNode || !_stack.empty()) {
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
