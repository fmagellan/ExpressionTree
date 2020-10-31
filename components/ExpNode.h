// Copyright 2020 Magellan

#ifndef COMPONENTS_EXPNODE_H_
#define COMPONENTS_EXPNODE_H_

#include <iostream>
#include <memory>
#include <cassert>

namespace Magellan {

class ExpNode {
    friend class Iterator;

    public:
        std::shared_ptr<ExpNode> m_left;
        std::shared_ptr<ExpNode> m_right;
        int m_value;

    public:
        ExpNode() = default;
        ~ExpNode() {
            std::cout << "ExpNode is deleted with value: " << m_value << '\n';
        }
};

};  // namespace Magellan

#endif  // COMPONENTS_EXPNODE_H_
