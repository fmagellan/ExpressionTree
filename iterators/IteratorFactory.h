// Copyright 2020 Magellan

#ifndef ITERATORS_ITERATORFACTORY_H_
#define ITERATORS_ITERATORFACTORY_H_

#include <memory>
#include <map>
#include <string>

#include "iterators/Iterator.h"
#include "iterators/PreOrderIterator.h"
#include "iterators/InOrderIterator.h"

namespace Magellan {

class IteratorFactory {
    public:
        static IteratorFactory* getInstance();
        std::shared_ptr<Iterator> make_iterator(std::string type, std::shared_ptr<ExpNode>);

    private:
        static IteratorFactory *m_instance;

        using PTMF = std::shared_ptr<Iterator> (IteratorFactory::*)(std::shared_ptr<ExpNode>);
        using COMMAND_MAP = std::map<std::string, PTMF>;
        COMMAND_MAP m_commandMap;

        IteratorFactory();
        ~IteratorFactory() = default;

        std::shared_ptr<Iterator> make_preorder_iterator(std::shared_ptr<ExpNode> pRoot) {
            return (std::make_shared<PreOrderIterator> (pRoot));
        }

        std::shared_ptr<Iterator> make_inorder_iterator(std::shared_ptr<ExpNode> pRoot) {
            return (std::make_shared<InOrderIterator> (pRoot));
        }


};

};

#endif  // ITERATORS_ITERATORFACTORY_H_
