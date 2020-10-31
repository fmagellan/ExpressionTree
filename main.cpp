// Copyright 2020 Magellan

#include <iostream>
#include <memory>
#include <stack>

#include "components/ExpNode.h"
#include "iterators/PreOrderIterator.h"
#include "iterators/PostOrderIterator.h"

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

    Magellan::PreOrderIterator preItr(pRoot);
    std::cout << "Pre-order: ";
    while (preItr.isValid()) {
        std::cout << (*preItr).m_value << ' ';
        ++preItr;
    }
    std::cout << '\n';

    Magellan::PostOrderIterator postItr(pRoot);
    std::cout << "Post-order: ";
    while (postItr.isValid()) {
        std::cout << (*postItr).m_value << ' ';
        ++postItr;
    }
    std::cout << '\n';


    return (0);
}
