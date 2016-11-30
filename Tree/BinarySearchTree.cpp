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

#include <cassert>
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;
using namespace Tree;

/**
 * Construtor
 * @tparam NodeType
 */
template <class NodeType>
BinarySearchTree::BinarySearchTree()
{
    this->root = nullptr;
    this->elements = 0;
}

/**
 * Insere um elemento na arvore
 * @tparam NodeType Tipo de dados
 * @param node valor do novo no
 */
template <class NodeType>
void BinarySearchTree::insertNode(const NodeType &node)
{
    this->insertNodeHelper(&this->root, node);
}

/**
 * Insere recursivamente elementos na arvore
 * @tparam NodeType
 * @param pTreeNode
 * @param value
 */
template <class NodeType>
void BinarySearchTree::insertNodeHelper(TreeNode<NodeType> **pTreeNode, const NodeType &value)
{
    if(*pTreeNode == nullptr) {
        *pTreeNode = new TreeNode<NodeType>(value);
        assert(*pTreeNode != nullptr);
        this->elements++;
        return;
    }

    if(value < (*pTreeNode)->getData()){
        this->insertNodeHelper(&((*pTreeNode)->left), value);
        return;
    }

    if(value > (*pTreeNode)->getData()){
        this->insertNodeHelper(&((*pTreeNode)->right), value);
        return;
    }
}

/**
 * Metodos para percurso em pre-ordem
 * @tparam NodeType
 */
template <class NodeType>
void BinarySearchTree::preOrderTraversal()
{
    this->preOrderHelper(this->root);
}

template <class NodeType>
void BinarySearchTree::preOrderHelper(TreeNode<NodeType> *rootPtr) const
{
    if(rootPtr != nullptr){
        cout << rootPtr->getData() << endl;
        preOrderHelper(rootPtr->getLeftChildren());
        preOrderHelper(rootPtr->getRightChildren());
    }
}

/**
 * Metodos para percursos in-ordem
 * @tparam NodeType
 */
template <class NodeType>
void BinarySearchTree::inOrderTraversal()
{
    this->inOrderHelper(this->root);
}

template <class NodeType>
void BinarySearchTree::inOrderHelper(TreeNode<NodeType> *rootPtr) const
{
    if(rootPtr != nullptr){
        preOrderHelper(rootPtr->getLeftChildren());
        cout << rootPtr->getData() << endl;
        preOrderHelper(rootPtr->getRightChildren());
    }
}

/**
 * Metodos para percursos pos-ordem
 * @tparam NodeType
 */
template <class NodeType>
void BinarySearchTree::postOrderTraversal()
{
    this->preOrderHelper(this->root);
}

template <class NodeType>
void BinarySearchTree::postOrderHelper(TreeNode<NodeType> *rootPtr) const
{
    if(rootPtr != nullptr){
        preOrderHelper(rootPtr->getLeftChildren());
        preOrderHelper(rootPtr->getRightChildren());
        cout << rootPtr->getData() << endl;
    }
}

/**
 * Retorna a quantidade de elementos na arvore
 * @tparam NodeType
 * @return
 */
template <class NodeType>
long int BinarySearchTree::size()
{
    return this->elements;
}

