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


#ifndef BTREENODE_H
#define BTREENODE_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BTree {

    class BTreeNode {
        friend class BTree;
    private:
        bool isLeaf;
        int order;
        vector<long int> keys;
        BTreeNode **children;
        BTreeNode *ascendant;
        BTreeNode *leftBrother;
        BTreeNode *rightBrother;

    public:
        /**
         * Constructor
         * @param order B Tree order
         * @param isLeaf
         */
        BTreeNode(int order, bool isLeaf = true)
        {
            this->isLeaf = isLeaf;
            this->order = order;
            this->ascendant = nullptr;
            this->leftBrother = nullptr;
            this->rightBrother = nullptr;

            this->keys.reserve(order);

            /* Children vector */
            if (!isLeaf) {
                this->children = new BTreeNode *[order + 1];
            }

            if (this->keys.empty() || (!isLeaf && this->children))
                throw new exception;

            /*Initialize the children*/
            if (this->children not_eq nullptr) {
                for (int i = 0; i < order + 1; i++) {
                    this->children[i] = nullptr;
                }
            }
        }

        /**
         * is this a leaf node
         * @return
         */
        bool isLeafNode()
        {
            return this->isLeaf;
        }

        /**
         * Verify if given node is an child
         * @param bTreeNode
         * @return
         */
        bool isChild(BTreeNode* bTreeNode)
        {
            if(this->isLeafNode())
                return false;

            for(int i = 0; i < this->keys.size() + 1; i++) {
                if(this->children[i] == bTreeNode)
                    return true;
            }

            return false;
        }

        /**
         * Checks if this node has a given key
         * @param key
         * @return
         */
        bool hasKey(long int key)
        {
            for(unsigned int i = 0; i < this->keys.size(); i++) {
                if(this->keys.at(i) == key)
                    return true;
            }
        }
        /**
         * How many keys are stored in the node
         * @return
         */
        long int size()
        {
            return this->keys.size();
        }

        BTreeNode *getAscendant()
        {
            return this->ascendant;
        }

        BTreeNode *getLeftBrother()
        {
            return this->leftBrother;
        }

        BTreeNode *getRightBrother()
        {
            return this->rightBrother;
        }

        void setAscendant(BTreeNode *ascendant)
        {
            this->ascendant = ascendant;
        }

        void setLeftBrother(BTreeNode *leftBrother)
        {
            this->leftBrother = leftBrother;
        }

        void setRightBrother(BTreeNode *rightBrother)
        {
            this->rightBrother = rightBrother;
        }

        /**
         * Get child node at position
         * @param position
         * @return
         */
        BTreeNode *getChildAt(unsigned int position)
        {
            if (!this->isLeafNode() && position < this->keys.size() + 1) {
                return this->children[position];
            }

            return nullptr;
        }

        /**
         * Get key at position
         * @param position
         * @return
         */
        long int getKeyAt(unsigned int position)
        {
            if (position < this->keys.size())
                return this->keys.at(position);

            return false;
        }

        /**
         * Adds a key in the node
         * @param key
         */
        void addKey(long int key)
        {
            this->keys.push_back(key);
            std::sort(this->keys.begin(), this->keys.end());
        }

        /**
         * Add a child node to this node
         */
        void addChild(BTreeNode *bTreeNode, unsigned int position)
        {
            if (bTreeNode == nullptr || position > this->order)
                return;

            BTreeNode *node = position > 0 ? this->children[position - 1] : nullptr;
            bTreeNode->setLeftBrother(node);

            if (node != nullptr)
                node->setRightBrother(bTreeNode);

            node = position < this->keys.size() + 1 ? this->children[position] : nullptr;
            bTreeNode->setRightBrother(node);

            if (node != nullptr)
                bTreeNode->setLeftBrother(node);

            delete node;

            for (long i = this->keys.size(); i > position; i--)
                this->children[i] = this->children[i - 1];

            this->children[position] = bTreeNode;

        }

        /**
         * Split node keys
         * @return
         */
        vector<long int> splitKeys()
        {
            int ceil = (int) this->order / 2;

            if (this->order % 2 != 0)
                ceil++;

            vector<long int> splittedKeys(this->keys.size() - ceil);

            for (int i = ceil; i < this->keys.size(); i++) {
                splittedKeys[i - ceil] = this->keys.at(i);
                this->keys[i] = 0;
            }

            return splittedKeys;
        }

        /**
         * Split node children
         * @return
         */
        BTreeNode **splitChildren()
        {
            if (this->isLeaf)
                return nullptr;

            int ceil = (int) this->order / 2;

            if (this->order % 2 != 0)
                ceil++;

            BTreeNode **splittedChildren = new BTreeNode *[this->keys.size() + 1 - ceil];

            this->children[ceil]->setLeftBrother(nullptr);

            for (int i = ceil; i < this->keys.size() + 1; i++) {
                splittedChildren[i - ceil] = this->children[i];
                splittedChildren[i - ceil]->setAscendant(nullptr);
                this->children[i] = nullptr;
            }

            this->children[ceil - 1]->setRightBrother(nullptr);
            return splittedChildren;
        }


        /**
         * Pop last child
         * @return
         */
        BTreeNode *popLastChild()
        {
            return this->popChildrenAt();
        }

        /**
         * Pop first child
         * @return
         */
        BTreeNode *popFirstChild()
        {
            return this->popChildrenAt(0);
        }

        /**
         * Pop last key
         * @return
         */
        long int popLastKey()
        {
            return this->popKeyAt(this->keys.size() - 1);
        }

        /**
         * Pop first key
         * @return
         */
        long int popFirstKey()
        {
            return this->popKeyAt();
        }

        /**
         * Remove child at the given position
         * @param position
         */
        void removeChildAt(unsigned int position)
        {
            BTreeNode *bTreeNode = this->popChildrenAt(position);
            if (bTreeNode != nullptr)
                delete bTreeNode;
        }

        /**
         * Remove key at the given position
         * @param position
         */
        void removeKeyAt(unsigned int position = 0)
        {
            this->popKeyAt(position);
        }

        /**
         * Removes a key
         * @param key
         */
        long int removeKey(long int key)
        {
            unsigned int position = this->getKeyPosition(key);
            this->removeKeyAt(position);
            return position;
        }

        /**
         * Destructor
         */
        ~BTreeNode()
        {
            if (!this->isLeaf) {
                for (int i = 0; i < this->keys.size(); i++) {
                    delete this->children[i];
                }
            }

            delete this->children;
            delete this->keys;
        }

    private:

        /**
         * Get key position if it exists at node
         * @param key
         * @return
         */
        unsigned int getKeyPosition(long int key)
        {
            for (unsigned int i = 0; i < this->keys.size(); i++) {
                if (key == this->keys.at(i))
                    return i;
            }

            throw new exception;
        }

        /**
         * Get child position if it exists at node
         * @param bTreeNode
         * @return
         */
        unsigned int getChildPosition(BTreeNode *bTreeNode)
        {
            if (isLeaf)
                throw new exception;

            for (unsigned int i = 0; i < this->keys.size() + 1; i++) {
                if (this->children[i] == bTreeNode)
                    return i;
            }

            throw new exception;
        }

        /**
         * Pop a child in position
         * @param position
         * @return
         */
        BTreeNode *popChildrenAt(unsigned long int position = this->keys.size())
        {
            if (!isLeaf && position < this->keys.size() + 1) {
                BTreeNode *bTreeNode = this->children[position];

                if (position > 0)
                    this->children[position - 1]->setRightBrother(bTreeNode->getRightBrother());

                if (position < this->keys.size())
                    this->children[position + 1]->setLeftBrother(bTreeNode->getLeftBrother());

                bTreeNode->setAscendant(nullptr);
                bTreeNode->setLeftBrother(nullptr);
                bTreeNode->setRightBrother(nullptr);

                for (unsigned long int i = position; i < this->keys.size(); i++)
                    this->children[i] = this->children[i + 1];

                this->children[this->keys.size()] = nullptr;
                return bTreeNode;
            }

            return nullptr;
        }

        /**
         * Pop a key in position
         * @param position
         * @return
         */
        long int popKeyAt(unsigned int position = 0)
        {
            if (position < this->keys.size()) {
                long int key = this->keys.at(position);

                for (int i = position; i < this->keys.size(); i++)
                    this->keys[i] = this->keys[i + 1];

                this->keys.pop_back();
                return key;
            }

            return false;
        }

        /**
         * Gets the child to insert the key
         * @param key
         * @return
         */
        BTreeNode* getNextKeyNode(long int key)
        {
            if(this->isLeafNode())
                return nullptr;

            for(unsigned int i = 0; i < this->keys.size(); i++){
                if(key < this->keys[i])
                    return this->children[i];
            }

            return this->children[this->keys.size()];
        }

        /**
         * Gets the position to insert new key
         * @param key
         * @return
         */
        int getNextKeyPosition(long int key)
        {
            int position = 0;

            for(int i = 0; i < this->keys.size(); i++){
                if(key < this->keys.at(i))
                    break;

                position++;
            }

            return position;
        }
    };
}
#endif