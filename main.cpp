// Copyright 2020 Magellan

#include <iostream>
#include <memory>
#include <stack>

#include "components/ExpNode.h"
#include "iterators/PreOrderIterator.h"
#include "iterators/InOrderIterator.h"
#include "iterators/IteratorFactory.h"

std::shared_ptr<Magellan::ExpNode> newNode(const int value) {
    std::shared_ptr<Magellan::ExpNode> pNode = std::make_shared<Magellan::ExpNode>();
    pNode->setValue(value);

    return (pNode);
}

int main() {
    std::shared_ptr<Magellan::ExpNode> pRoot = newNode(4);

    std::shared_ptr<Magellan::ExpNode> pLeft = newNode(2);
    pLeft->setLeft(newNode(1));
    pLeft->setRight(newNode(3));

    std::shared_ptr<Magellan::ExpNode> pRight = newNode(6);
    pRight->setLeft(newNode(5));
    pRight->setRight(newNode(7));

    pRoot->setLeft(pLeft);
    pRoot->setRight(pRight);

    Magellan::IteratorFactory *pFactory = Magellan::IteratorFactory::getInstance();

    std::shared_ptr<Magellan::Iterator> pPreItr1{ pFactory->make_iterator("preorder", pRoot) };
    std::cout << "Pre-order with factory: ";
    while (pPreItr1->isValid()) {
        std::cout << (*(*pPreItr1)).getValue() << ' ';
        ++(*pPreItr1);
    }
    std::cout << '\n';

    std::shared_ptr<Magellan::Iterator> pInItr1{ pFactory->make_iterator("inorder", pRoot) };
    std::cout << "In-order with factory: ";
    while (pInItr1->isValid()) {
        std::cout << (*(*pInItr1)).getValue() << ' ';
        ++(*pInItr1);
    }
    std::cout << '\n';


    return (0);
}
