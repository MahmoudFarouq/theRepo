#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <float.h>
#include <cmath> 
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class Type>
void Merge(Type* a, int n, bool (*IsBefore)(Type& a, Type& b))
{
    int mid = n / 2 , i = 0 , j = mid ;
    Type * tmp = new Type [n];
   for(int h = 0 ; h<n ; h++)
   {
       if(j == n || (i<mid && IsBefore(a[i],a[j])))
       {
           tmp[h] = a[i++];
       }
       else
       {
           tmp[h] = a[j++];
       }
   }
   for(int h = 0 ; h<n ; h++)
   {
       a[h] = tmp[h];
   }
   delete[]tmp;
}

template<class Type>
void MergeSort(Type* a, int n, bool (*IsBefore)(Type& a, Type& b))
{
    int mid = n/2;
    if(n <= 1) return;
    MergeSort(a,mid,IsBefore);
    MergeSort(a+mid, n-mid,IsBefore) ;
    Merge(a,n,IsBefore) ;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Point
{
	double x,y;
};

bool IsBeforeX(Point& a, Point& b){
    return a.x < b.x;
}
bool IsBeforeY(Point& a, Point& b){
    return a.y < b.y;
}


double dist(Point& a, Point& b)
{
return sqrt( (a.x - b.x)*(a.x - b.x) +(a.y - b.y)*(a.y - b.y) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Sort the points p according to x before calling this function
double ClosestPair(Point* p, int n){


    if(n<=3){
        double min=DBL_MAX;
        //MergeSort(p,n,IsBeforeY);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double m=dist(p[i],p[j]);
                if(m<min){
                    min=m;
                }
            }
        }
        return min;
    }
    MergeSort(p,n,IsBeforeY);
    int mid=n/2;
    Point midPoint = p[mid];
    double x_mid=0.5 * (p[mid-1].x + p[mid].x);

    double a=ClosestPair(p,mid);
    double b=ClosestPair(p+mid,n-mid);

    double m=a;
    if(b<m)m=b;
    double d=m;

    MergeSort(p,n,IsBeforeY);

    Point pi[n];
    int idx = 0;
    for (int i = 0; i < n; i++){
        if (abs(p[i].x - x_mid) < d)pi[idx++] = p[i];
    }

    MergeSort(pi,idx,IsBeforeY);

    for(int i = 0 ; i<n ; i++)
    {
       for(int j = i+1 ; j<n ; j++)
       {
             if(pi[j].y - pi[i].y < d)break;
             if(dist(pi[i] , pi[j]) < d) d = dist(pi[i] , pi[j]);
       }
    }
    if(d<m)
        return d;
    return m;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int n;
    cin>>n;
    while(n!=0){
        Point* p=new Point[n];
        for(int i=0;i<n;i++){

            cin>>p[i].x>>p[i].y;
        }
        double ans = ClosestPair(p,n);
        if(ans >= 10000.0)
          printf("INFINITY\n");
        else 
          printf("%.4lf\n", ans);
        cin>>n;
        delete []p;
    }


	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
