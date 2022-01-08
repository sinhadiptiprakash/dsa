#include <bits/stdc++.h>
using namespace std;
/*
This problem is mainly an extension of Search an element in an array where difference between adjacent elements is 1. 
A Simple Approach is to traverse the given array one by one and compare every element with the given element ‘x’.If matches, then return index.
The above solution can be Optimized using the fact that the difference between all adjacent elements is at most k.
The idea is to start comparing from the leftmost element and 
find the difference between the current array element and x.Let this difference be ‘diff’.
From the given property of the array, we always know that x must be at least ‘diff / k’ away, 
so instead of searching one by one, we jump ‘diff / k’.Below is the implementation of the above idea.
*/
int search(int arr[], int n, int x, int k)
{
    // Traverse the given array starting from leftmost element
    int i = 0;
    while (i < n)
    {
        // If x is found at index i
        if (arr[i] == x)
            return i;

        // Jump the difference between current
        // array element and x divided by k
        // We use max here to make sure that i
        // moves at-least one step ahead.
        i = i + max(1, abs(arr[i] - x) / k);
    }

    cout << "number is not present!";
    return -1;
}
int main()
{
    int arr[] = {70, 60, 50, 40, 40, 40};
    int x = 60;
    int k = 20;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Element " << x << " is present at index "
         << search(arr, n, x, k);
    return 0;
}