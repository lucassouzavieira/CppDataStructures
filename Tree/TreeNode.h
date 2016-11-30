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


#ifndef TREENODE_H
#define TREENODE_H

#include "BinarySearchTree.h"

namespace Tree {

    class TreeNode {
        friend class BinarySearchTree;
    public:
        TreeNode(const long int value)
        {
            this->right = nullptr;
            this->left = nullptr;
            this->data = value;
        }

        TreeNode()
        {
            this->right = nullptr;
            this->left = nullptr;
            this->data = 0;
        }

        long int getData() const
        {
            return this->data;
        }

        TreeNode* getLeftChildren() const
        {
            return this->left;
        }

        TreeNode* getRightChildren() const
        {
            return this->right;
        }

    private:
        TreeNode *left;
        TreeNode *right;
        long int data;
    };

}


#endif //TREENODE_H
