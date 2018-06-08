// GROUP:   4
// ID:      20150239
// Assign:  01
// Assign:  ArrayHeap
// UVA:     10954
// Name:    mahmoud reda farouk

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class Value>
struct Array
{
    int  n, sz;
    Value* arr;

    void Initialize(int n){
        arr = new Value[n];
        sz = 0;
        this->n = n;
    }
    void Destroy(){
        delete arr;
    }
    void AddLast(Value v){
        if(sz == n)
            return;
        arr[sz++] = v;
    }
    void RemoveLast(){
        if(sz == 0)
            return;
        sz--;
    }
    Value& operator[](long long i){
        if(i >= sz)
            throw "IndexOutOfBounds";
        return arr[i];
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class Elem>
struct Heap
{
    Array<Elem> a;
    bool (*IsBefore)(long long&, long long&);

    void Initialize(bool (*_IsBefore)(long long&, long long&)){
        IsBefore = _IsBefore;
        a.Initialize(10000);
        a.AddLast(-1);
    }
    void Destroy(){
        a.Destroy();
    }
    int Child(int i){
        int childIndex = i*2+1;
        childIndex = (IsBefore(a[childIndex], a[childIndex+1]) ? childIndex:childIndex+1);
        return childIndex;
    }
    int Parent(int i){
        int pIndex = i%2 == 0 ? i/2-1:i/2;
        return pIndex;
    }
    void MoveUp(int ind){
        int pIndex = Parent(ind);
        if( !IsBefore(a[ind], a[pIndex]) )
            return;
        Elem temp = a[ind];
        a[ind] = a[pIndex];
        a[pIndex] = temp;
    }
    void MoveDown(int ind){
        int childIndex = Child(ind);
        if( IsBefore(a[ind], a[childIndex]) )
            return;
        Elem temp = a[ind];
        a[ind] = a[childIndex];
        a[childIndex] = temp;
    }
    void Add(Elem e){
        a.AddLast(e);
        long long k = a.sz-1;
        while(k > 1 && IsBefore(a[k], a[k/2]))
        {
            Elem temp = a[k];
            a[k] = a[k/2];
            a[k/2] = temp;
            k /= 2;
        }
    }
    Elem GetFirst(){
        return a[1];
    }
    Elem RetrieveFirst(){
        Elem min = a [1];
        a[1] = a[a.sz-1];
        a.RemoveLast();

        long long k = 1;
        while(k*2 <= a.sz-1)
        {
            long long j = 2 * k;
            if(j == a.sz-1){}
            else if (j < a.sz && IsBefore (a [j+1], a [j])) {
                j++;
            }
            if (IsBefore (a [k], a [j])) {
                break;
            }
            Elem temp = a[k];
            a[k] = a[j];
            a[j] = temp;
            k = j;
        }
        return min;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool IsBeforeInt(long long& a, long long& b)
{
    return a<b;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    long long n;
    while(cin >> n && n){
        Heap<long long> pq;   pq.Initialize(IsBeforeInt);
        for(long long i = 0; i < n; i++){
            long long t;
            cin >> t;
            pq.Add( t );
        }
        long long cost = 0;
        while(pq.a.sz > 2){
            long long min = pq.RetrieveFirst() + pq.RetrieveFirst();
            cost += min;
            pq.Add(min);
        }
        pq.Destroy();
        cout << cost << endl;
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
