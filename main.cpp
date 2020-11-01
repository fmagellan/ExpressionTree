// Copyright 2020 Magellan

#include <iostream>
#include <memory>
#include <stack>

#include "components/ExpNode.h"
#include "iterators/InOrderIterator.h"
#include "iterators/IteratorFactory.h"
#include "components/NumberNode.h"
#include "components/OpNode.h"
#include "iterators/PreOrderIterator.h"

std::shared_ptr<Magellan::ExpNode> newNumberNode(const int value) {
    std::shared_ptr<Magellan::NumberNode> pNode = std::make_shared<Magellan::NumberNode>();
    pNode->setValue(value);

    return (pNode);
}

std::shared_ptr<Magellan::ExpNode> newOpNode(const char op) {
    std::shared_ptr<Magellan::OpNode> pNode = std::make_shared<Magellan::OpNode>();
    pNode->setOp(op);

    return (pNode);
}

int main() {
    std::shared_ptr<Magellan::ExpNode> pRoot = newOpNode('*');

    std::shared_ptr<Magellan::ExpNode> pLeft = newOpNode('+');
    pLeft->setLeft(newNumberNode(1));
    pLeft->setRight(newNumberNode(3));

    std::shared_ptr<Magellan::ExpNode> pRight = newOpNode('+');
    pRight->setLeft(newNumberNode(5));
    pRight->setRight(newNumberNode(7));

    pRoot->setLeft(pLeft);
    pRoot->setRight(pRight);

    Magellan::IteratorFactory *pFactory = Magellan::IteratorFactory::getInstance();

    std::shared_ptr<Magellan::Iterator> pPreItr1{ pFactory->make_iterator("preorder", pRoot) };
    std::cout << "Pre-order with factory: ";
    while (pPreItr1->isValid()) {
//        std::cout << (*(*pPreItr1)).getValue() << ' ';
        (*(*pPreItr1)).print();
        ++(*pPreItr1);
    }
    std::cout << '\n';

    std::shared_ptr<Magellan::Iterator> pInItr1{ pFactory->make_iterator("inorder", pRoot) };
    std::cout << "In-order with factory: ";
    while (pInItr1->isValid()) {
//        std::cout << (*(*pInItr1)).getValue() << ' ';
        (*(*pInItr1)).print();
        ++(*pInItr1);
    }
    std::cout << '\n';


    return (0);
}
