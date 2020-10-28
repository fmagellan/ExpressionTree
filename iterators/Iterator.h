// Copyright 2020 Magellan

#ifndef ITERATORS_ITERATOR_H_
#define ITERATORS_ITERATOR_H_

#include <cassert>
#include <memory>
#include <stack>

#include "components/Node.h"

namespace Magellan {

class Iterator {
    private:
        std::shared_ptr<ExpNode> m_node;
        std::shared_ptr<ExpNode> m_index;
        std::stack<std::shared_ptr<ExpNode> > m_stack;

    public:
        explicit Iterator(std::shared_ptr<ExpNode> pNode)
            : m_node{ pNode }, m_index{ nullptr }
        {
            m_stack.push_back(m_node);
        }

        ~Iterator() = default;

        ExpNode& operator * () {
            assert(!m_index && "Node is a nullptr.");

            return (*m_index);
        }

        Iterator& operator++ () {
            ++m_index;
            return (*this);
        }

        void start() {
            m_index = m_node;
        }

        bool isValid() const {
            return (m_index);
        }
};

};  // namespace Magellan

#endif  // ITERATORS_ITERATOR_H_
