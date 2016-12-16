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
        BTreeNode* getMoreMinimumKeysChild(
                long int key,
                BTreeNode* bTreeNode,
                int ceil,
                int *levelsBelow
        )
        {
            *levelsBelow = 1;

            // Gets the child at left from key
            long int leftLevel = 0;

            BTreeNode* child = this->getLeftChild(key, bTreeNode);
            BTreeNode* moreRightChild = this->getMoreRightChild(bTreeNode, &leftLevel);

            *levelsBelow += leftLevel;

            // Preferes left node
            if(moreRightChild != nullptr && moreRightChild->size() > ceil - 1)
                return moreRightChild;

            // Gets the child at right from key
            long int rightLevel = 0;

            child = this->getRightChild(key, bTreeNode);
            BTreeNode* moreLeftChild = this->getMoreLeftChild(bTreeNode, &rightLevel);

            if(moreLeftChild != nullptr && moreLeftChild->size() > ceil - 1){
                *levelsBelow += rightLevel;
                return moreLeftChild;
            }

            return moreRightChild;
        }

        /**
         * Get child from given key
         * @param key
         * @param bTreeNode
         * @param isFromRight
         * @return
         */
        BTreeNode* getChild(long int key, BTreeNode* bTreeNode, bool isFromRight = false)
        {
            int position = bTreeNode != NULL ? bTreeNode->getKeyPosition(key) : -1;

            if(position < 0)
                return nullptr;

            return bTreeNode->getChildAt((unsigned int) (isFromRight ? position + 1 : position));
        }

        /**
         * Get left children from a given key
         * @param key
         * @param bTreeNode
         * @return
         */
        BTreeNode* getLeftChild(long int key, BTreeNode* bTreeNode)
        {
            return this->getChild(key, bTreeNode);
        }

        /**
         * Get right children from a given key
         * @param key
         * @param bTreeNode
         * @return
         */
        BTreeNode* getRightChild(long int key, BTreeNode* bTreeNode)
        {
            return this->getChild(key, bTreeNode, true);
        }

        /**
         * Returns more left child from a given node
         * @param bTreeNode
         * @param level
         * @return
         */
        BTreeNode* getMoreLeftChild(BTreeNode* bTreeNode, long int* level)
        {
            if(bTreeNode == nullptr)
                return nullptr;

            if(bTreeNode->isLeafNode())
                return bTreeNode;

            long int key = bTreeNode->getKeyAt(0);

            return this->getExtremeChild(key, bTreeNode, false, level);
        }

        /**
         * Returns more right child from a given node
         * @param bTreeNode
         * @param level
         * @return
         */
        BTreeNode* getMoreRightChild(BTreeNode* bTreeNode, long int* level)
        {
            if(bTreeNode == nullptr)
                return nullptr;

            if(bTreeNode->isLeafNode())
                return bTreeNode;

            long int key = bTreeNode->getKeyAt((unsigned int) bTreeNode->size() - 1);

            return this->getExtremeChild(key, bTreeNode, true, level);
        }

        /**
         * Returns the extreme child at right or left from a given node
         * @param key
         * @param bTreeNode
         * @param isFromRight
         * @param level
         * @return
         */
        BTreeNode* getExtremeChild(
                long int key,
                BTreeNode* bTreeNode,
                bool isFromRight = false,
                long int* level
        )
        {
            BTreeNode* bTreeNodeAux = isFromRight ? this->getRightChild(key, bTreeNode) : this->getLeftChild(key, bTreeNode);
            BTreeNode* actualBTreeNode = bTreeNode;

            *level = 0;

            while(bTreeNodeAux != nullptr){
                *level += 1;

                actualBTreeNode = bTreeNodeAux;
                int position = isFromRight ? (int) bTreeNodeAux->size() - 1 : 0;

                long int keyAt = bTreeNodeAux->getKeyAt(position);
                bTreeNodeAux = isFromRight ? this->getRightChild(keyAt, bTreeNodeAux) : this->getLeftChild(key, bTreeNodeAux);
            }

            return actualBTreeNode;
        }

        /**
         * Search and returns the node where the new key will be inserted
         * @param key
         * @param stopLevel
         * @param nodeLevel
         * @return
         */
        BTreeNode* toInsert(long int key, int stopLevel, long int* nodeLevel)
        {
            *nodeLevel = 1;

            BTreeNode* bTreeNode = this->root;

            while(bTreeNode != nullptr){
                if((stopLevel == *nodeLevel) || bTreeNode->isLeafNode())
                    return bTreeNode;

                bTreeNode = bTreeNode->getNextKeyNode(key);
                *nodeLevel++;
            }

            return nullptr;
        }

        /**
         * insert key helper
         * @param key
         * @param nodeLevel
         * @param bTreeNode
         * @param leftChild
         * @param rightChild
         * @throws exception
         */
        void insertHelper(
                long int key,
                long int nodeLevel,
                BTreeNode* bTreeNode = nullptr,
                BTreeNode* leftChild = nullptr,
                BTreeNode* rightChild = nullptr
        )
        {
            //If the B Tree has no nodes, try create it
            if(this->root == nullptr){
                try {
                    this->root = new BTreeNode(this->order);

                    this->root->addKey(key);

                    if(leftChild != nullptr && rightChild != nullptr){
                        this->root->addChild(leftChild, 0);
                        this->root->addChild(rightChild, 1);

                        leftChild->setAscendant(this->root);
                        rightChild->setAscendant(this->root);
                    }

                    return;
                } catch(exception e) {
                    throw e;
                }
            }

            // The B Tree already had nodes
            if(bTreeNode != nullptr){
                try {
                    bTreeNode->addKey(key);
                    unsigned int position = bTreeNode->getKeyPosition(key);

                    if(rightChild != nullptr){
                        rightChild->setAscendant(bTreeNode);
                        bTreeNode->addChild(rightChild, position + 1);
                    }

                    // Conditions for replacement and split nodes
                    if(bTreeNode->size() == this->order){
                        BTreeNode** newChildren = bTreeNode->splitChildren();
                        vector<long int> splittedKeys = bTreeNode->splitKeys();

                        long int keysLeft = this->order - bTreeNode->size();
                        BTreeNode* newNode = new BTreeNode(this->order, false);

                        // Update pointers references
                        newNode->setRightBrother(bTreeNode->getRightBrother());
                        newNode->setLeftBrother(bTreeNode);

                        if(bTreeNode->getRightBrother() != nullptr)
                            bTreeNode->getRightBrother()->setLeftBrother(newNode);

                        bTreeNode->setRightBrother(newNode);

                        // Add keys to new node
                        for(int i = 0; i < keysLeft; i++){
                            newNode->addKey(splittedKeys.at(i));
                        }

                        delete splittedKeys;

                        // If is no a leaf, add old pointers from old node
                        if(newChildren != nullptr){
                            BTreeNode* node = nullptr;

                            for(unsigned int i = 0; i <= keysLeft; i++){
                                node = newChildren[i];
                                node->setAscendant(newNode);
                                newNode->addChild(node, i);
                            }

                            delete newChildren;
                            delete node;
                        }

                        // Gets the key to up and withdraw from node
                        long int promotedKey = bTreeNode->popLastKey();

                        // Updates pointers to new element going to up
                        leftChild = bTreeNode == this->root ? bTreeNode : nullptr;
                        rightChild = newNode;

                        if(bTreeNode == this->root){
                            this->root = nullptr;
                            bTreeNode = nullptr;
                        } else {
                            bTreeNode = bTreeNode->getAscendant();
                        }

                        // Re-insert the node one level up
                        this->insertHelper(
                                promotedKey,
                                nodeLevel - 1,
                                bTreeNode,
                                leftChild,
                                rightChild
                        );

                        return;
                    }

                } catch (exception e){
                    throw e;
                }
            }
        }

        /**
         * In case the one does not have some brother with more keys than the minimum
         * and the redistribution of the keys between them and the ascendant is realized
         * @param bTreeNode Node that had a newly removed key
         * @param ascendant Father node from bTreeNode and brother
         * @param brother Brother who has more keys than the minimum
         * @param key Removed key
         * @param movePointer If true it is a non-leaf node and this is being treated as leaf (in the removal)
         * and thus one of the children of the key that will be promoted
         * from the brother will be added to the list of children of the node
         * @throw exception
         */
        void redistributesKeys(
                BTreeNode* bTreeNode,
                BTreeNode* ascendant,
                BTreeNode* brother,
                long int key,
                bool movePointer = false
        )
        {
            long int promotedKey    = -1;
            int positionDecrease    = 0;

            if(bTreeNode == nullptr || ascendant == nullptr || brother == nullptr)
                throw new exception;

            long int firstKey = bTreeNode->size() > 0 ? bTreeNode->getKeyAt(0) : key;
            long int nodePosition = 0;
            BTreeNode* pointer = nullptr;

            if(firstKey < brother->getKeyAt(0)){
                if(movePointer){
                    pointer = brother->popFirstChild();
                    nodePosition = bTreeNode->size() + 1;
                }

                promotedKey = brother->popFirstKey();
                positionDecrease++;
            } else {
                if(movePointer)
                    pointer = brother->popLastChild();

                promotedKey = brother->popLastKey();
            }

            int promotedKeyPosition = ascendant->getNextKeyPosition(key) - positionDecrease;

            long int loweredKey = ascendant->getKeyAt(promotedKeyPosition);

            ascendant->removeKeyAt(promotedKeyPosition);
            ascendant->addKey(promotedKey);

            bTreeNode->addKey(loweredKey);

            if(pointer != nullptr){
                pointer->setAscendant(bTreeNode);
                bTreeNode->addChild(pointer, nodePosition);
            }
        }

        /**
         * In case the node, not root, does not have a
         * brother with more keys than the minimum and the
         * merge between one of his siblings and the parent key is performed
         * @param key
         * @param nodeLevel
         * @param ceil
         * @param bTreeNode
         * @param ascendant
         */
        void mergeNodes(
                long int key,
                int nodeLevel,
                int ceil,
                BTreeNode* bTreeNode,
                BTreeNode* ascendant)
        {
            try{
                if(bTreeNode == nullptr ||  ascendant == nullptr)
                    throw new exception;

                BTreeNode* brother = bTreeNode->getRightBrother();
                long int nodePosition = ceil - 1;
                long int totalNodes = nodePosition;

                if(brother == nullptr)
                    brother = bTreeNode;
                else
                    totalNodes = brother->size() + 1;

                long int firstKey = brother->size() > 0 ? brother->getKeyAt(0) : key;
                long int loweredKeyPosition = ascendant->getNextKeyPosition(firstKey);

                if(loweredKeyPosition > 0)
                    loweredKeyPosition--;

                long int loweredKey = ascendant->getKeyAt((unsigned)loweredKeyPosition);

                if(brother == bTreeNode){
                    bTreeNode = bTreeNode->getLeftBrother();
                    nodePosition = bTreeNode->size() + 1;
                }

                bTreeNode->addKey(loweredKey);

                for(unsigned int i = 0; i < brother->size(); i++)
                    bTreeNode->addKey(brother->getKeyAt(i));

                if(!brother->isLeafNode()){
                    BTreeNode* node = nullptr;

                    for(unsigned int i = 0; i < totalNodes; i++){
                        node = brother->getChildAt(i);

                        if(node != nullptr){
                            node->setAscendant(bTreeNode);
                            bTreeNode->addChild(node, i + (unsigned)nodePosition);
                        }
                    }
                }

                if(loweredKeyPosition > 0 && ascendant->hasKey(firstKey))
                    loweredKeyPosition--;

                ascendant->removeChildAt((unsigned)loweredKeyPosition + 1);
                brother = ascendant->getChildAt((unsigned)loweredKeyPosition + 1);
                bTreeNode->setRightBrother(brother);

                if(brother != nullptr)
                    brother->setLeftBrother(bTreeNode);

                if(ascendant == this->root && ascendant->size() == 1){
                    this->root = bTreeNode;
                    bTreeNode->setAscendant(nullptr);
                    delete ascendant;
                    return;
                }

                // TODO call remove();


            } catch (exception e){
                throw e;
            }
        }
    };
}

#endif
