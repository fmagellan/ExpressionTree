// Copyright 2020 Magellan

#include "iterators/IteratorFactory.h"

namespace Magellan {

IteratorFactory* IteratorFactory::m_instance = nullptr;

IteratorFactory::IteratorFactory() {
    m_commandMap["preorder"] = &IteratorFactory::make_preorder_iterator;
    m_commandMap["inorder"] = &IteratorFactory::make_inorder_iterator;
}

IteratorFactory* IteratorFactory::getInstance() {
    if (!m_instance) {
        m_instance = new IteratorFactory();
    }

    return (m_instance);
}

std::shared_ptr<Iterator> IteratorFactory::make_iterator(std::string type, std::shared_ptr<ExpNode> pRoot) {
    return (this->*m_commandMap[type])(pRoot);
}

};
