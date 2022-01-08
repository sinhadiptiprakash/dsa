#include <bits/stdc++.h>
using namespace std;
/*
Below are various methods to solve the problems: 
Method 1 (Use Sorting)
Approach: 
    Sort the input array.
    Traverse the array and check for missing and repeating.
    Time Complexity: O(nLogn)
*/
pair<int, int> repeating_missing(int a[], int n)
{
    sort(a, a + n);
    int missing = -1, repeating = -1;
    //now check for edge cases ror missing number
    if (a[0] != 1)
        missing = 1;
    else if (a[n - 1] != n)
        missing = n;
    for (int i = 1; i < n; i++)
    {
        if (missing != -1 && repeating != -1)
            break;
        if (a[i] == a[i - 1])
            repeating = a[i];
        if (a[i - 1] + 1 != a[i] && missing == -1)
            missing = a[i - 1] + 1;
    }
    return {missing, repeating};
} //time complexity O(Nlog(N))
//below is the another approach
pair<int, int> repeating_missing2(int a[], int n)
{
    bool check[n + 1] = {0};
    int repeating, missing;
    //finding the repeating no
    for (int i = 0; i < n; i++)
    {
        if (check[a[i]])
            repeating = a[i];
        else
            check[a[i]] = 1;
    }
    //finding the missing no.
    for (int i = 1; i <= n; i++)
        if (!check[i])
            missing = i;
    return {missing, repeating};
} //time complexity O(N) space O(N)
//below is the mathematical approach
//we know the sum of n natural no. is n*(n+1)/2, and sum of squares of n natural numbers n*(n+1)*(2n+1)/6
// so expected sum=n*(n+1)/2, expected square sum=n*(n+1)*(2n+1)/6
//now let missing and repeating be two variables
//now let sum of array elents is sum, and sum of squares of aray elements is square_sum
// (now expected_sum-sum)=(missing-repeating) and (expected_square_sum-square_sum)=(missing*missing-repeating*repeating)
// now by doing simple algebra we can get missing and repeating number
pair<int, int> repeating_missing3(int a[], int n)
{
    int expected_sum, expected_square_sum, sum = 0, square_sum = 0;
    expected_square_sum = (n * (n + 1) * (2 * n + 1)) / 6;
    expected_sum = (n * (n + 1)) / 2;
    // now we will get the sum and square sum
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        square_sum += (a[i] * a[i]);
    }
    //now sub squre_sub stores the (missing-repeating) and (missing*missing-repeating*repeating)
    int sub = expected_sum - sum;
    int square_sub = expected_square_sum - square_sum;
    // if we divide square_sub by add we get (missing+repeating) and sub stores (missing-repeating)
    int add = square_sub / sub;
    //now add+sub will be 2*missing so missing=(add+sub)/2; and repeating=add-missing
    int missing = (add + sub) / 2;
    int repeating = add - missing;
    return {missing, repeating};
} //time complexity O(N) space O(1) this method is not feeasible for large n
// best approach
pair<int, int> findTwoElement(int *arr, int N)
{
    pair<int, int> res;
    for (int i = 0; i < N; i++)
        arr[i] -= 1;
    for (int i = 0; i < N; i++)
        arr[arr[i] % N] += N;
    for (int i = 0; i < N; i++)
    {
        arr[i] /= N;

        if (arr[i] == 2)
            res.first = i + 1;
        if (arr[i] == 0)
            res.second = i + 1;
    }
    return res;
} //O(N) and O(1)
int main()
{
    int arr[] = {5,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    auto res = findTwoElement(arr, n);
    cout << res.first << ' ' << res.second << endl;
    return 0;
}