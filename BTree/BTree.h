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

#ifndef BTREE_H
#define BTREE_H

#include "BTreeNode.h"

namespace BTree {

    class BTree {
    private:
        BTreeNode* root;
        int order;
        long int keys;

    public:
        BTree(int order)
        {
            this->order = order;
            this->root = nullptr;
            this->keys = 0;
        }

        /**
         * Return B Tree root
         * @return
         */
        BTreeNode* getRoot()
        {
            return this->root;
        }

        /**
         * Return keys quantity
         * @return
         */
        long int getTotalKeys()
        {
            return this->keys;
        }

    private:

        /**
         * Return the most left child
         * @param root
         * @return
         */
        BTreeNode* getMostLeftChild(BTreeNode* root)
        {

        }

        /**
         * Return the brother with less keys that minimum ( ceil + 1 )
         * @param bTreeNode
         * @param ceil
         * @return
         */
        BTreeNode* getMoreMinimumKeysBrother(BTreeNode* bTreeNode, int ceil)
        {
            BTreeNode* brother = bTreeNode->getLeftBrother();

            if(brother != nullptr && brother->size() > ceil + 1)
                return brother;

            brother = bTreeNode->getRightBrother();

            if(brother != nullptr && brother->size() > ceil + 1)
                return brother;

            return nullptr;
        }

        /**
         * May be non-direct child, but the most right child from left child
         * or the most left child from right child. If any one has more keys than the
         * minimum, returns the most right child from left child.
         * @param key
         * @param bTreeNode
         * @param ceil
         * @param levelsBelow
         * @return
         */
        BTreeNode* getMoreMinimumKeysChild(long int key, BTreeNode* bTreeNode, int ceil, int levelsBelow = 0)
        {
            // Todo

            return nullptr;
        }
    };
}

#endif //BTREE_H
