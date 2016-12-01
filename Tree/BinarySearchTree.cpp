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
#include <functional>

using namespace Tree;

/**
 * Constructor
 */
BinarySearchTree::BinarySearchTree()
{
    this->root = nullptr;
    this->elements = 0;
}

/**
 * Inserts a node at the tree
 * @param node
 */
void BinarySearchTree::insert(const long int &node)
{
    this->insertHelper(&this->root, node);
}
/**
 * Traversal Algorithms
 */

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

/**
 * Returns the quantity of nodes in tree
 * @return
 */
long int BinarySearchTree::size()
{
    return this->elements;
}

/**
 *
 * @return
 */
long int BinarySearchTree::heigth()
{
    return this->heightHelper(this->root);
}

/**
 * Insert helper method
 * @param pTreeNode
 * @param value
 */
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

/**
 * Checks if the tree is empty
 * @return bool
 */
bool BinarySearchTree::isEmpty()
{
    return this->root == nullptr;
}

/**
 * Searchs a node on tree
 * @param value
 * @return
 */
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

/**
 * Remove a node from tree
 * @param root
 * @param value
 * @return
 */
bool BinarySearchTree::remove(const long value)
{
    if(!this->search(value))
        return false;

    return this->removeHelper(&(this->root), value);
}

/**
 * Tree height helper
 * @param root
 * @return
 */
long int BinarySearchTree::heightHelper(TreeNode *root)
{
    if(root == nullptr)
        return 0;

    long int leftHeight = this->heightHelper(root->getLeftChildren()) + 1;
    long int rightHeight = this->heightHelper(root->getRightChildren()) + 1;

    if(leftHeight < rightHeight)
        return rightHeight;
    else
        return leftHeight;
}


/**
 * Returns the most left node at the subtree
 * @param root
 * @return
 */
void *BinarySearchTree::mostLeft(TreeNode *root) const
{
    if(root->getLeftChildren() != nullptr)
        return this->mostLeft(root->getLeftChildren());

    TreeNode* mostLeft = root;
    if(root->getRightChildren() != nullptr)
        mostLeft = root->getRightChildren();

    return mostLeft;
}

/**
 * Returns the most right node at the subtree
 * @param root
 * @return
 */
void *BinarySearchTree::mostRight(TreeNode *root) const
{
    if(root->getRightChildren() != nullptr)
        return this->mostRight(root->getRightChildren());

    TreeNode* mostRight = root;
    if(root->getLeftChildren() != nullptr)
        mostRight = root->getLeftChildren();

    return mostRight;
}

// TODO review this
/**
 * Remove helper method
 * @param root
 * @param value
 * @return
 */
bool BinarySearchTree::removeHelper(TreeNode **root, long int value) const
{
    if(value < (*root)->getData())
        return removeHelper(&(*root)->left, value);

    if(value > (*root)->getData())
        return removeHelper(&(*root)->right, value);

    TreeNode* pTreeNode = (*root);

    // has no children
    if((*root)->hasChildren() == 0){
        delete pTreeNode;
        (*root) = nullptr;
    }

    // has only right children
    if((*root)->left == nullptr){
        (*root) = (*root)->right;
        pTreeNode->right = nullptr;
        delete pTreeNode;
        pTreeNode = nullptr;
    }

    // has only left children
    if((*root)->right == nullptr){
        (*root) = (*root)->left;
        pTreeNode->left = nullptr;
        delete pTreeNode;
        pTreeNode = nullptr;
    }

    // has two children
    if(((*root)->left != nullptr) && ((*root)->right != nullptr)){
        pTreeNode = (TreeNode*) this->mostLeft((*root));
        pTreeNode->left = (*root)->left;
        pTreeNode->right = (*root)->right;
        (*root)->left = (*root)->right = nullptr;
        delete (*root);
        (*root) = pTreeNode;
        pTreeNode = nullptr;
    }

    return true;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree()
{
    std::function<void(TreeNode*)> destroy;

    destroy = [&destroy](TreeNode* root) -> void
    {
        if(root == nullptr)
            return;

        destroy(root->getLeftChildren());
        destroy(root->getRightChildren());
        delete root;
    };
}




