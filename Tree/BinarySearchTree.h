/*
 Paalg

 Copyright (C) 2016  Lucas S. Vieira

 This program is free software: you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License,
 or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"

namespace Tree {
    template  <class NodeType>
    class BinarySearchTree {
    public:
        BinarySearchTree();
        void insertNode(const NodeType & node);
        void preOrderTraversal();
        void inOrderTraversal();
        void postOrderTraversal();
        long int size();

    protected:
        TreeNode<NodeType> *root;
        long int elements;
        void insertNodeHelper(TreeNode<NodeType> **, const NodeType &value);
        void preOrderHelper(TreeNode<NodeType> *) const;
        void inOrderHelper(TreeNode<NodeType> *) const;
        void postOrderHelper(TreeNode<NodeType> *) const;

    };
}


#endif //BINARYSEARCHTREE_H
