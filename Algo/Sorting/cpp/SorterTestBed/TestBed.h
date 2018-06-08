#ifndef TESTBED_H
#define TESTBED_H
#include "SelectionSorter.h"
#include "QuickSorter.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <chrono>

using namespace std;

typedef std::chrono::high_resolution_clock::time_point TimeVar;
#define timeNow() std::chrono::high_resolution_clock::now()
#define Duration(start, finish) std::chrono::duration_cast<std::chrono::microseconds>( finish - start ).count()

class TestBed
{
    public:
        TestBed();

        int*   GenerateRandomList(int lo, int hi, int len);
        int*   GenerateReverseOrderedList(int lo, int hi, int len);
        double RunOnce(Sorter& sorter, int* data, int len);
        double RunAndAverage(Sorter& sorter, int type, int lo, int hi, int len, int sets_num);   //type -> 0 == sorted, 1 == reversed;
        double RunExperient (Sorter& sorter,int type,int lo, int hi, int min_len, int max_len, int sets_num, int step);
        virtual ~TestBed();

    protected:

    private:
};

#endif // TESTBED_H
