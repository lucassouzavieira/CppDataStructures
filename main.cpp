/*
 Sorting Algorithms

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

#include <iostream>
#include "Sorting/ArraySorting.h"
#include "Tests/ArrayUtil.h"
#include "Tree/TreeNode.h"
#include "Tree/BinarySearchTree.h"

using namespace std;
using namespace Tree;
using namespace Sorting;
using namespace Tests;


int main() {

    vector<long int> set = Tests::ArrayUtil::RandomArray(5);

    Tree::TreeNode *node = new Tree::TreeNode();
    Tree::BinarySearchTree *binarySearchTree = new Tree::BinarySearchTree();

    binarySearchTree->insert(10);
    binarySearchTree->insert(16);
    binarySearchTree->insert(15);
    binarySearchTree->insert(17);
    binarySearchTree->insert(6);

    binarySearchTree->inOrderTraversal();
}