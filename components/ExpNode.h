// Copyright 2020 Magellan

#ifndef COMPONENTS_EXPNODE_H_
#define COMPONENTS_EXPNODE_H_

#include <iostream>
#include <memory>
#include <cassert>

namespace Magellan {

class ExpNode {
    friend class Iterator;
    friend class PreOrderIterator;
    friend class InOrderIterator;

    private:
        std::shared_ptr<ExpNode> m_left;
        std::shared_ptr<ExpNode> m_right;
        int m_value;

    public:
        ExpNode() = default;
        ~ExpNode() {
            std::cout << "ExpNode is deleted with value: " << m_value << '\n';
        }

        void setValue(const int value) {
            m_value = value;
        }

        int getValue() const {
            return (m_value);
        }

        void setLeft(std::shared_ptr<ExpNode> pLeft) {
            m_left = pLeft;
        }

        void setRight(std::shared_ptr<ExpNode> pRight) {
            m_right = pRight;
        }
};

};  // namespace Magellan

#endif  // COMPONENTS_EXPNODE_H_
