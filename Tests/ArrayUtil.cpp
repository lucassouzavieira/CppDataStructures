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

#include <random>
#include <functional>
#include "ArrayUtil.h"

using namespace Tests;

vector<long int> ArrayUtil::RandomArray(const long int size)
{
    vector<long int> randomVector;
    std::default_random_engine generator;
    std::uniform_int_distribution<long int> distribution(-4294967296, 4294967296);
    auto bindGen = std::bind (distribution, generator);

    for(long int i = 0; i < size; i++){
        randomVector.push_back(bindGen());
    }

    return randomVector;
}