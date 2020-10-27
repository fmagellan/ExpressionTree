// Copyright 2020 Magellan

#ifndef _ITERATORS_ITERATOR_H_
#define _ITERATORS_ITERATOR_H_

#include "components/Node.h"

#include <stack>
#include <cassert>

namespace Magellan {

class Iterator {
    private:
        ExpNode *m_node{ nullptr };
        ExpNode *m_index{ nullptr };
        std::stack<ExpNode *> m_stack;

    public:
        explicit Iterator(ExpNode *pNode)
            : m_node{ pNode }, m_index{ nullptr }
        {
            m_stack.push_back(m_node);
        }

        ~Iterator() = default;

        ExpNode& operator * () {
            assert(!m_index && "Node is a nullptr.");

            return (*m_index);
        }

        Iterator& operator ++ () {
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

#endif  //_ITERATORS_ITERATOR_H_ 
