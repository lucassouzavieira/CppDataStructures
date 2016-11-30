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

#include "BinarySearchTree.h"

using namespace Tree;

BinarySearchTree::BinarySearchTree()
{
    this->root = nullptr;
    this->elements = 0;
}

void BinarySearchTree::insert(const long int &node)
{
    this->insertHelper(&this->root, node);
}

void BinarySearchTree::preOrderTraversal()
{
    std::cout << "Pre-Order Traversal" << std::endl;
    this->preOrderHelper(this->root);
}

void BinarySearchTree::inOrderTraversal()
{
    std::cout << "In-Order Traversal" << std::endl;
    this->inOrderHelper(this->root);
}

void BinarySearchTree::postOrderTraversal()
{
    std::cout << "Post-Order Traversal" << std::endl;
    this->postOrderHelper(this->root);
}

long int BinarySearchTree::size()
{
    return this->elements;
}

void BinarySearchTree::insertHelper(TreeNode **pTreeNode, const long int &value)
{
    if(*pTreeNode == nullptr){
        *pTreeNode = new TreeNode(value);
        assert(*pTreeNode != nullptr);
        this->elements++;
        return;
    }

    if(value < (*pTreeNode)->getData()){
        this->insertHelper(&(*pTreeNode)->left, value);
    }

    if(value > (*pTreeNode)->getData()){
        this->insertHelper(&(*pTreeNode)->right, value);
    }
}

void BinarySearchTree::preOrderHelper(TreeNode *root) const
{
    if(root != nullptr) {
        std::cout << root->getData() << std::endl;
        preOrderHelper(root->getLeftChildren());
        preOrderHelper(root->getRightChildren());
    }
}

void BinarySearchTree::inOrderHelper(TreeNode *root) const
{
    if(root != nullptr) {
        inOrderHelper(root->getLeftChildren());
        std::cout << root->getData() << std::endl;
        inOrderHelper(root->getRightChildren());
    }
}

void BinarySearchTree::postOrderHelper(TreeNode *root) const
{
    if(root != nullptr) {
        inOrderHelper(root->getLeftChildren());
        inOrderHelper(root->getRightChildren());
        std::cout << root->getData() << std::endl;
    }
}

bool BinarySearchTree::isEmpty()
{
    return this->root == nullptr;
}

bool BinarySearchTree::search(const long int value) const
{
    return this->searchHelper(this->root, value);
}

bool BinarySearchTree::searchHelper(TreeNode *root, long int value) const
{
    if(root == nullptr)
        return false;

    if(root->getData() == value)
        return true;

    if(root->getData() > value)
        return this->searchHelper(root->getLeftChildren(), value);

    if(root->getData() < value)
        return this->searchHelper(root->getRightChildren(), value);

}

bool BinarySearchTree::remove(const long value)
{
    return this->removeHelper(this->root, value);
}

bool BinarySearchTree::removeHelper(TreeNode *root, long int value) const
{
    if(!this->search(value))
        return false;

    return false;
}




