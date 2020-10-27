// Copyright 2020 Magellan

#ifndef _COMPONENTS_EXP_NODE_H_
#define _COMPONENTS_EXP_NODE_H_

#include <cassert>

namespace Magellan {

// class Iterator;

class ExpNode {
    friend class Iterator;

    public:
        ExpNode *m_left{ nullptr };
        ExpNode *m_right{ nullptr };
        int m_value;

    public:
        ExpNode() = default;
        ~ExpNode() = default;

};

};  // namespace Magellan

#endif  // _COMPONENTS_EXP_NODE_H_
