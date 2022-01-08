#include <bits/stdc++.h>
using namespace std;
//below is the brute force approach
bool subarray_with_0_sum_bf(int a[], int n)
{
    int sum;
    for (int i = 0; i < n; i++)
    {
        sum = a[i];
        if (sum == 0)
            return true;
        for (int j = i + 1; j < n; j++)
        {
            sum += a[j];
            if (sum == 0)
                return true;
        }
    }
    return false;
} //time complexity O(N*N) space complexity O(1)
//below is an efficient approach using unordered set
//Approach is: we contineously store the sums from the first index to last index and store them in the set
//if the curent sum is 0 or curent sum is already there then it means that there is a zero sum after curent sum stored in set
//that is why we get the same sum again
bool subarray_with_0_sum(int arr[], int n)
{
    unordered_set<int> sumSet;
    // Traverse through array
    // and store prefix sums
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        // If prefix sum is 0 or
        // it is already present
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;

        sumSet.insert(sum);
    }
    return false;
} //time complexity O(N) space complexity is O(1)
int main()
{
    int a[] = {4, 2, -3, 1, 6};
    int n = sizeof(a) / sizeof(int);
    cout << subarray_with_0_sum(a, n) << endl;
    return 0;
}