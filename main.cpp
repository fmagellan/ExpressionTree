// Copyright 2020 Magellan

#include <iostream>
#include <memory>
#include <stack>

#include "components/ExpNode.h"
#include "iterators/Iterator.h"

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

    Magellan::Iterator itr(pRoot);
    std::cout << "Values: ";
    while (itr.isValid()) {
        std::cout << (*itr).m_value << ' ';
        ++itr;
    }
    std::cout << '\n';

    return (0);
}
