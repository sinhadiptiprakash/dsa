#include <bits/stdc++.h>
using namespace std;
//below all approaches not modify the input array
//below is the implementation in O(N) time as well as O(N) space complexity using unordered map
int find_duplicate_number(int a[], int n)
{
    unordered_map<int, int> table;
    for (int i = 0; i < n; i++)
    {
        //if the ith element is already in the table then this element is the duplicate element
        if (table.find(a[i]) != table.end())
            return a[i];
        //else we store it in the table
        table[a[i]] = i;
    }
    //below statement is optional it is used to avoid warning that there is no return statement
    return a[n - 1];
}

//below is another very interesting approach based on floyd cycle finding algorithm for linked list(hare-tortoise)
//here we run two iteration one for finding cycle and another for finding the intersection point
//in first run the slow pointer runs one step at a time and the fast pointer runs at 2 steps at a time we stop loop if both meets
//in the second run we again initialize the slow pointer at starting possition and while fast and slow pointer does'nt meet we continue iteration
//for more visit https://leetcode.com/problems/find-the-duplicate-number/solution/
int find_duplicate_number_using_flyod_cycle_finding(int a[], int n)
{
    //initialize both the pointers
    int hare = a[0], tortoise = a[0];
    //at first we will be finding the intersection point of the runners
    do
    {
        //tortoise runs one step at a time
        tortoise = a[tortoise];
        //hare runs two steps at a time
        hare = a[a[hare]];
    } while (tortoise != hare);
    //now we will be finding the starting point of the cycle, i.e. the duplicate element
    //initialize the tortoise to the start again remaining hare at same position
    tortoise = a[0];
    while (hare != tortoise)
    {
        //both runs at same pace
        tortoise = a[tortoise];
        hare = a[hare];
    }
    return hare;
}
int main()
{
    int a[] = {3, 1, 2, 4, 2};
    int n = sizeof(a) / sizeof(int);
    cout << find_duplicate_number_using_flyod_cycle_finding(a, n) << endl;
    return 0;
}