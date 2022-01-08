#include <bits/stdc++.h>
using namespace std;
void rearrange_array_in_alternating_negative_postive_without_constant_space(int a[], int n)
{
    vector<int> neg, pos;
    for (int i = 0; i < n; i++)
    {
        //storing negative and positives to the vectors
        if (a[i] < 0)
            neg.push_back(a[i]);
        else
            pos.push_back(a[i]);
    }
    int neg_pointer = 0, pos_pointer = 0, index = 0;
    //filling the array with negative and positive alternatively
    while (index < n)
    {
        while (neg_pointer < neg.size() && pos_pointer < pos.size())
        {
            if (index % 2 == 0)
                a[index++] = neg[neg_pointer++];
            else
                a[index++] = pos[pos_pointer++];
        }
        while (neg_pointer < neg.size())
        {
            a[index++] = neg[neg_pointer++];
        }
        while (pos_pointer < pos.size())
        {
            a[index++] = pos[pos_pointer++];
        }
    }
} //time complexity O(N) space complexity O(N)

//below approach is O(N) time and O(1) space but it does not maintain the order of the elements
//this apporach simply uses the approach of shifting all the negatives to the left side and positives to the right
void rearrange_array_in_alternating_negative_postive_with_constant_space(int a[], int n)
{
    // shifting all positives to right and all negatives to left
    int low = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            swap(a[i], a[low++]);
    }
    // now at this point low-1 points to the last negative number in the array after shifting all the negatives to the left
    //as the first positive will always at index 1 and the first positive element is at low
    int pos = 1, right = low;
    //while one of negative or positive pointer doesnt reach the end of the array
    while (pos < n && right < n)
    {
        //we are increasing pos by 2 everytime and each time we check if there is a postive element at pos or not
        //if pos does'nt point a positive element we just swap it with a positive element and increase the right pointer by 1
        if (a[pos] < 0)
        {
            swap(a[pos], a[right++]);
            pos += 2;
        }
        //if a positive element is already there at pos we just simply increment pos by 1
        else
            pos++;
    }
}
//below approach will do the work in O(1) space as well as maintain the order of elements
//here we say an element is at wrong position if one of the followoing is true
//1.at even position there is a poitive or
//2. at odd position there is a negative
// the simple approach is whenever we get an element at a wrong position we right rotate from this index to correct it
// for right roatation we have a function which right rotate the array from from to to index
void right_rotate(int a[], int from, int to)
{
    int temp = a[to];
    for (int i = to; i > from; i--)
        a[i] = a[i - 1];
    a[from] = temp;
}
void rearrange(int a[], int n)
{
    // -1 value of wrongIndex indicates that we don'nt have any wrongIndex yet
    int wrongIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (wrongIndex != -1)
        {
            if ((a[wrongIndex] >= 0 && a[i] < 0) || (a[wrongIndex] < 0 && a[i] >= 0))
            {
                // find the item which must be moved into the wrongIndex entry if wrongIndex entry is
                // positive and current entry is negative OR if wrongIndex entry is negative and current
                // entry is positive then right rotate
                right_rotate(a, wrongIndex, i);
                // the new out-of-place entry is now 2 steps ahead
                //if there are 2 or more elements in between i and wrongIndex
                if (i - wrongIndex >= 2)
                    wrongIndex += 2;
                else
                    wrongIndex = -1;
            }
        }
        else
        {
            //if at even position there is a positive or at odd position there is a negative it is a wrongIndex
            if ((a[i] < 0 && i % 2 == 1) || (a[i] >= 0 && i % 2 == 0))
                wrongIndex = i;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, -4, -1, 4};
    int n = sizeof(arr) / sizeof(int);
    int a[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int m = sizeof(a) / sizeof(int);
    rearrange(a, m);
    for (int i = 0; i < m; i++)
        cout << a[i] << ' ';
    cout << '\n';
    return 0;
}