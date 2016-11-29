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

#ifndef ARRAYSORTING_H
#define ARRAYSORTING_H


#include <array>
#include <vector>

using namespace std;

namespace Sorting {

    /**
     * ArraySorting Class
     */
    class ArraySorting {

    public:

        static void ShellSort(vector<long int> &set);

        static void QuickSort(vector<long int> &set);

    private:
        ArraySorting() {};

        static void ShellSortPhase(vector<long int> &set, long int jump);

        static void Quick(vector<long int> &set, long int startPosition, long int endPosition);
    };

}

#endif //ARRAYSORTING_H
