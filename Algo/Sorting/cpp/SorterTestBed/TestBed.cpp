#include "TestBed.h"

TestBed::TestBed(){}
TestBed::~TestBed(){}

int* TestBed::GenerateRandomList(int lo, int hi, int len)
{
    int* ls = new int[len];
    for(int i = 0; i < len; i++)
    {
        ls[i] = rand()%(hi-lo) + lo;
    }
    return ls;
}

bool Compare(int x, int y){return x > y;}
int* TestBed::GenerateReverseOrderedList(int lo, int hi, int len)
{
    int* ls = GenerateRandomList(lo, hi, len);
    sort(ls, ls+len, Compare);
    return ls;
}

double TestBed::RunOnce(Sorter& sorter, int* data, int len)
{
    TimeVar start = timeNow();
    sorter.Sort(data, len);
    TimeVar finish = timeNow();
    return Duration(start, finish);
}

double TestBed::RunAndAverage(Sorter& sorter, int type, int lo, int hi, int len, int sets_num)   //type -> 0 == sorted, 1 == reversed;
{
    long totalTime = 0;
    for(int i = 0; i < sets_num; i++)
    {
        int* test;
        if(type == 0)
            test = GenerateRandomList(lo, hi, len);
        else
            test = GenerateReverseOrderedList(lo, hi, len);
        totalTime += RunOnce(sorter, test, len);
        delete test;
    }
    return (totalTime/sets_num);
}

double TestBed::RunExperient (Sorter& sorter,int type,int lo, int hi, int min_len, int max_len, int sets_num, int step)
{
    long totalAvg = 0;
    for(int i = min_len; i < max_len; i+=step)
    {
        totalAvg += RunAndAverage(sorter, type, lo, hi, min_len, sets_num);
    }
    return (totalAvg/((max_len-min_len)/step));
}















