// Copyright 2020 Magellan

#ifndef ITERATORS_ITERATOR_H_
#define ITERATORS_ITERATOR_H_

#include <cassert>
#include <memory>
#include <stack>

#include "components/ExpNode.h"

namespace Magellan {

class Iterator {
    private:
        std::shared_ptr<ExpNode> m_root;
        std::shared_ptr<ExpNode> m_index;
        std::stack<std::shared_ptr<ExpNode> > m_stack;

    public:
        explicit Iterator(std::shared_ptr<ExpNode> pNode)
            : m_root{ pNode }, m_index{ pNode }
        {
            // m_stack.push(m_root);
        }

        ~Iterator() = default;

        ExpNode& operator * () {
            assert(m_index && "Node is a nullptr.");

            return (*m_index);
        }

        Iterator& operator++ () {
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

            return (*this);
        }

        bool isValid() const {
            return (m_index != nullptr);
        }
};

};  // namespace Magellan

#endif  // ITERATORS_ITERATOR_H_
