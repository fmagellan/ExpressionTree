// Copyright 2020 Magellan

#ifndef ITERATORS_POSTORDERITERATOR_H_
#define ITERATORS_POSTORDERITERATOR_H_

#include "iterators/Iterator.h"
#include "components/ExpNode.h"

namespace Magellan {

class PostOrderIterator : public Iterator {
    private:
        std::stack<std::shared_ptr<ExpNode> > m_stack;

    public:
        explicit PostOrderIterator(std::shared_ptr<ExpNode> pNode)
            : Iterator(pNode) {
                while (m_index->m_left) {
                    m_stack.push(m_index);
                    m_index = m_index->m_left;
                }
        }

        virtual ~PostOrderIterator() = default;

        virtual void operator++ () override {
            assert (m_index && "Cannot advance the iterator.");

            if (m_index->m_right) {
                m_index = m_index->m_right;
                while (m_index->m_left) {
                    m_stack.push(m_index);
                    m_index = m_index->m_left;
                }

                return;
            }

            if (!m_stack.empty()) {
                m_index = m_stack.top();
                m_stack.pop();

                return;
            }

            m_index = nullptr;

            return;
        }
};

};  // namespace Magellan

#endif  // ITERATORS_POSTORDERITERATOR_H_
