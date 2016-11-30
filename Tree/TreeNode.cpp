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

#include "TreeNode.h"


using namespace Tree;

template <class T>
TreeNode::TreeNode(const T &value)
{
    this->left = nullptr;
    this->right = nullptr;
    this->data = value;
}

template <class T>
T TreeNode::getData() const
{
    return this->data;
}

template <class T>
TreeNode<T>* TreeNode::getLeftChildren() const
{
    return this->left;
}

template <class T>
TreeNode<T>* TreeNode::getRightChildren() const
{
    return this->right;
}