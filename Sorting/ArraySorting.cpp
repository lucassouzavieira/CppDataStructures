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

#include "ArraySorting.h"

using namespace std;
using namespace Sorting;

void ArraySorting::QuickSort(vector<long int> &set)
{

}

void ArraySorting::Quick(vector<long int> &set, long int startPosition, long int endPosition)
{

}

/**
 * @param set vetor de elementos a serem ordenados
 */
void ArraySorting::ShellSort(vector<long int> &set)
{
    static const array<int, 8> jump = {1, 4, 10, 23, 57, 132, 301, 701};

    for(long int sizeIndex = (jump.size() / sizeof(jump[0]) - 1); sizeIndex >= 0; --sizeIndex){
        ArraySorting::ShellSortPhase(set, jump.at(sizeIndex));
    }
}

/**
 * @param set vetor de elementos a serem ordenados
 * @param jump
 */
void ArraySorting::ShellSortPhase(vector<long int> &set, long int jump)
{
    for(long int i = jump; i < set.size(); i++){
        long int value = set.at(i);

        long int j;

        for (j = (i - jump); j >= 0 && set.at(j) > value ; j = j - jump){
            set.at(j + jump) = set.at(j);
        }

        set.at(j + jump) = value;
    }
};
