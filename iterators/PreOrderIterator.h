// Copyright 2020 Magellan

#ifndef ITERATORS_PREORDERITERATOR_H_
#define ITERATORS_PREORDERITERATOR_H_

#include "iterators/Iterator.h"
#include "components/ExpNode.h"
#include <iostream>

namespace Magellan {

class PreOrderIterator : public Iterator {
    private:
        std::stack<std::shared_ptr<ExpNode> > m_stack;

    public:
        explicit PreOrderIterator(std::shared_ptr<ExpNode> pNode)
            : Iterator(pNode) {
            std::cout << "Preorder constructor\n";
        }

        virtual ~PreOrderIterator() = default;

        virtual void operator++ () override {
            assert (m_index && "Cannot advance the iterator.");
            if (m_index->m_right) {
                m_stack.push(m_index->m_right);
            }

            bool isIncremented{ false };
            if (m_index->m_left) {
                m_index = m_index->m_left;
                isIncremented = true;
            } else {
                if (!m_stack.empty()) {
                    m_index = m_stack.top();
                    m_stack.pop();
                    isIncremented = true;
                }
            }

            if (!isIncremented) {
                m_index = nullptr;
            }

            return;
        }
};

};  // namespace Magellan

#endif  // ITERATORS_PREORDERITERATOR_H_
