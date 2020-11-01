// Copyright 2020 Magellan

#ifndef COMPONENTS_NUMBERNODE_H_
#define COMPONENTS_NUMBERNODE_H_

#include <iostream>
#include <memory>
#include <cassert>

namespace Magellan {

class NumberNode : public ExpNode {
    private:
        int m_value;

    public:
        NumberNode() = default;
        virtual ~NumberNode() {
            std::cout << "NumberNode is deleted with value: " << m_value << '\n';
        }

        void setValue(const int value) {
            m_value = value;
        }

        int getValue() const {
            return (m_value);
        }

        virtual void print() {
            std::cout << m_value;
        }
};

};  // namespace Magellan

#endif  // COMPONENTS_NUMBERNODE_H_
