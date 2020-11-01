// Copyright 2020 Magellan

#ifndef COMPONENTS_EXPNODE_H_
#define COMPONENTS_EXPNODE_H_

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

    public:
        ExpNode() = default;
        virtual ~ExpNode() {
        }

        void setLeft(std::shared_ptr<ExpNode> pLeft) {
            m_left = pLeft;
        }

        void setRight(std::shared_ptr<ExpNode> pRight) {
            m_right = pRight;
        }

        virtual void print() = 0;
};

};  // namespace Magellan

#endif  // COMPONENTS_EXPNODE_H_
