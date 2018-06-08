//https://github.com/mvillaloboz/5problems

#include <iostream>
using namespace std;

//problem 1
int for_loop(int *arr, int len){
    int sum = 0;
    for(int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}
int while_loop(int *arr, int len){
    int sum = 0;
    while(len > 0)
    {
        sum += arr[--len];
    }
    return sum;
}
int recursive(int* arr, int len){
    if(len == 0)
        return 0;
    return arr[--len]+recursive(arr, len);
}


//problem 2
int* compine(int* list1, int len1, int* list2, int len2){
    int* result = new int[len1+len2];
    int i = 0, l1 = 0, l2 = 0;
    while(len1 > l1 && len2 > l2)
    {
        result[i++] = list1[l1++];
        result[i++] = list2[l2++];
    }
    if(len1 > l1)
    {
        for(int j = l1; j < len1; j++ )
            result[i++] = list1[j];
    }
    else
    {
        for(int j = l2; j < len2; j++ )
            result[i++] = list2[j];
    }
    return result;
}


//problem 3
void fibonacci(long long* arr){
    arr[0] = 0; arr[1] = 1;
    for(int i = 2; i < 100; i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
}


//problem 4
int MSB(int x){ // most segnificant bit
    while(x/10 != 0){
        x /= 10;
    }
    return x;
}
void sortBiased(int* arr,int len){
    for(int i = 1; i < len; i++)
    {
        for(int j = 1; j < len; j++)
        {
            if(MSB(arr[j-1]) < MSB(arr[j])){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


//problem 5
void sumToHundred()
{
    string x = "1+2+3+4+5+6+7+8+9";


}



int main()
{
    //problem 1 test
    /*int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << for_loop(arr, 10) << endl;
    cout << while_loop(arr, 10) << endl;
    cout << recursive(arr, 10) << endl;*/

    //problem 2 test
    /*int list1[5] = {1,2,3,4,5};
    int list2[8] = {6,7,8,9,10,11,12,13};

    int* res = compine(list1, 5, list2, 8);
    for(int i = 0; i < 13; i++)
        cout << res[i] << " ";*/

    //problem 3 test
    /*long long* arr = new long long[100];
    fibonacci(arr);
    for(int i = 0; i < 100; i++)
        cout << arr[i] << " ";*/

    //problem 4 test
    /*int arr[] = {50, 2, 1, 9};
    sortBiased(arr, 4);
    for(int i = 0; i < 4; i++)
        cout << arr[i] << " ";*/

    return 0;
}
