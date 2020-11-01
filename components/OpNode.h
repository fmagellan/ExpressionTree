// Copyright 2020 Magellan

#ifndef COMPONENTS_OPNODE_H_
#define COMPONENTS_OPNODE_H_

#include <iostream>
#include <memory>
#include <cassert>

namespace Magellan {

class OpNode : public ExpNode {
    private:
        char m_op;

    public:
        OpNode() = default;
        virtual ~OpNode() {
            std::cout << "OpNode is deleted with value: " << m_op << '\n';
        }

        void setOp(const int op) {
            m_op = op;
        }

        int getOp() const {
            return (m_op);
        }

        virtual void print() {
            std::cout << m_op;
        }
};

};  // namespace Magellan

#endif  // COMPONENTS_OPNODE_H_
