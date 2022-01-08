#include <bits/stdc++.h>
using namespace std;
//
int longest_consequtive_sequence(int arr[], int n)
{
    int ans = 0, count = 0;
    // sort the array
    sort(arr, arr + n);
    vector<int> v;
    v.push_back(arr[0]);
    //insert repeated elements only once in the vector actually storing only the distinct elements
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            v.push_back(arr[i]);
    }
    // find the maximum length
    // by traversing the array
    for (int i = 0; i < v.size(); i++)
    {
        // Check if the current element is equal
        // to previous element +1
        if (i > 0 && v[i] == v[i - 1] + 1)
            count++;
        // reset the count
        else
            count = 1;

        // update the maximum
        ans = max(ans, count);
    }
    return ans;
} //time complexity O(n*log(n)) space complexity O(n)
//below is the efficient approach
int longest_consequtive_sequence_efficient(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;
    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);
    // check each possible sequence from
    // the start then update optimal length
    for (int i = 0; i < n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i] - 1) == S.end())
        {
            // Then check for next elements
            // in the sequence
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;

            // update  optimal length if
            // this length is more
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
} //time complexity O(N) space complexity O(N)
int main()
{
    int a[] = {2, 6, 1, 9, 4, 5, 3};
    int n = sizeof(a) / sizeof(int);
    int b[] = {6, 6, 2, 3, 1, 4, 1, 5, 6, 2, 8, 7, 4, 2, 1, 3, 4, 5, 9, 6};
    int m = sizeof(b) / sizeof(int);
    cout << longest_consequtive_sequence_efficient(b, m) << endl;
    return 0;
}