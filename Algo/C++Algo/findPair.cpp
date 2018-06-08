#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// Naive method to find a pair in an array with given sum
void findPair_naive(int arr[], int n, int sum)
{
    // consider each element except last element
    for (int i = 0; i < n - 1; i++)
    {
        // start from i'th element till last element
        for (int j = i + 1; j < n; j++)
        {
            // if desired sum is found, print it and return
            if (arr[i] + arr[j] == sum)
            {
                printf("Pair found at index %d and %d", i, j);
                return;
            }
        }
    }

    // No pair with given sum exists in the array
    printf("Pair not found");
}
#include <bits/stdc++.h>

// Function to find a pair in an array with given sum using Sorting
void findPair_nlogn(int arr[], int n, int sum)
{
    // sort the array in ascending order
    std::sort(arr, arr + n);

    // maintain two indexes pointing to end-points of the array
    int low = 0;
    int high = n - 1;

    // reduce search space arr[low..high] at each iteration of the loop

    // loop till low is less than high
    while (low < high)
    {
        // sum found
        if (arr[low] + arr[high] == sum)
        {
             std::cout << "Pair found";
             return;
        }

        // increment low index if total is less than the desired sum
        // decrement high index is total is more than the sum
        (arr[low] + arr[high] < sum)? low++: high--;
    }

    // No pair with given sum exists in the array
    std::cout << "Pair not found";
}
// Function to find a pair in an array with given sum using Hashing
void findPair_hashing(int arr[], int n, int sum)
{
    // create an empty map
    unordered_map<int, int> map;

    // do for each element
    for (int i = 0; i < n; i++)
    {
        // check if pair (arr[i], sum-arr[i]) exists

        // if difference is seen before, print the pair
        if (map.find(sum - arr[i]) != map.end())
        {
            cout << "Pair found at index " << map[sum - arr[i]] <<
                    " and " << i;
            return;
        }

        // store index of current element in the map
        map[arr[i]] = i;
    }

    // we reach here if pair is not found
    cout << "Pair not found";
}
// main function
int main()
{
    int arr[] = { 8, 7, 2, 5, 3, 1};
    int sum = 10;

    int n = sizeof(arr)/sizeof(arr[0]);

    findPair_hashing(arr, n, sum);

    return 0;
}
