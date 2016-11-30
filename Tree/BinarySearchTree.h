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

#include <cassert>
#include <iostream>
#include "TreeNode.h"

class TreeNode;

namespace Tree {

    class BinarySearchTree {
    public:
        BinarySearchTree();

        void insert(const long int &node);
        void preOrderTraversal();
        void inOrderTraversal();
        void postOrderTraversal();

        long int size();
        long int heigth();

        bool isEmpty();
        bool search(const long int value) const;
        bool remove(const long int value);

    private:
        TreeNode *root;
        long int elements;

        void insertHelper(TreeNode **pTreeNode, const long int &value);
        void preOrderHelper(TreeNode *root) const;
        void inOrderHelper(TreeNode *root) const;
        void postOrderHelper(TreeNode *root) const;

        bool searchHelper(TreeNode *root, long int value) const;
        bool removeHelper(TreeNode *root, long int value) const;
    };

}

#endif //BINARYSEARCHTREE_H
