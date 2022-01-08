#include <bits/stdc++.h>
using namespace std;
// below is the approach using two array traversal
void three_way_partitioning(int arr[], int n, int a, int b)
{
    //last is the index at which the next swapping is to be done if needed
    //as we first storing the elements greater than b at the end last is initially n-1
    int last = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        //if the curent element is greater than b we swap this element with element at last
        if (arr[i] > b)
        {
            swap(arr[last], arr[i]);
            // update postition of last
            last--;
        }
    }
    //now we are storing the elements in range [a,b] in the array before the stored elements which are greater than b
    for (int i = last; i >= 0; i--)
    {
        // again if the element is in range [a,b] swap it with the element at index last
        //to store all the elements in the range before the larger element
        if (arr[i] >= a && arr[i] <= b)
        {
            swap(arr[i], arr[last]);
            last--;
        }
    }
    // now automatically the smaller elements at the beginning
} //time complexity O(2N)=> O(N) space complexity is O(1)
// we can do the above same thing by using a single traversal
// Partitions arr[0..n-1] around [lowVal..highVal]
void three_way_partitioning2(int arr[], int n, int lowVal, int highVal)
{
    // Initialize ext available positions for
    // smaller (than range) and greater lements
    int start = 0, end = n - 1;

    // Traverse elements from left
    for (int i = 0; i <= end;)
    {
        // If current element is smaller than
        // range, put it on next available smaller
        // position.
        if (arr[i] < lowVal)
            swap(arr[i++], arr[start++]);

        // If current element is greater than
        // range, put it on next available greater
        // position.
        else if (arr[i] > highVal)
            swap(arr[i], arr[end--]);

        else
            i++;
    }
}
int main()
{
    int arr[] = {2, 1, 7, 3, 1, 4, 0, 9};
    int arr2[] = {4, 1, 3, 0, 2, 9, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    three_way_partitioning2(arr, n, 4, 6);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}