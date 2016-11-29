
#ifndef ARRAYSORTING_H
#define ARRAYSORTING_H


#include <array>
#include <vector>

using namespace std;

namespace Sorting {

    class ArraySorting {

    public:

        static vector<long int> ShellSort(vector<long int>);

        static vector<long int> QuickSort(vector<long int>);

    private:
        ArraySorting() {};
    };

}

#endif //PAALG_ARRAYSORTING_H
