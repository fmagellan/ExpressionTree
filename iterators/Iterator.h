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

    protected:
        std::shared_ptr<ExpNode> m_index;

    public:
        explicit Iterator(std::shared_ptr<ExpNode> pNode)
            : m_root{ pNode }, m_index{ pNode }
        {
        }

        virtual ~Iterator() = default;

        ExpNode& operator * () {
            assert(m_index && "Node is a nullptr.");

            return (*m_index);
        }

        virtual void operator++ () = 0;

        bool isValid() const {
            return (m_index != nullptr);
        }
};

};  // namespace Magellan

#endif  // ITERATORS_ITERATOR_H_
