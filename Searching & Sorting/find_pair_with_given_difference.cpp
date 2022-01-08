#include <bits/stdc++.h>
using namespace std;
//brute force approach is to search for every element in the array and check is thre other element which gives that diff
//time complexity for that approach is O(N*N)
//we can do it better by using set
pair<int, int> get_pair(int a[], int n, int dif)
{
    unordered_set<int> set;
    for (int i = 0; i < n; i++)
    {
        if (set.find(abs(a[i] - dif)) != set.end())
            return {abs(a[i] - dif), a[i]};
        else
            set.emplace(a[i]);
    }
    return {-1, -1};
}
// we can do it  by searching the second element of the pair using binary search
// but before that we have to sort the array to apply the binary search
bool binary_search(int a[], int start, int n, int target)
{
    int low = start, high = n - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] == target)
            return true;
        else if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
pair<int, int> get_pair_binary_search(int a[], int n, int dif)
{
    sort(a, a + n);
    //now for every element in the array we search for the second element using binary search
    for (int i = 0; i < n; i++)
    {
        if (binary_search(a, i + 1, n, a[i] + dif))
            return {a[i], a[i] + dif};
    }
    return {-1, -1};
} //time complexity O(Nlog(N)) space O(1)
//below is the approach using sorting+two pointer approach
pair<int, int> get_pair_sorting_two_pointer(int a[], int n, int dif)
{
    sort(a, a + n);
    int i = 0, j = 0;
    while (i < n & j < n)
    {
        if (a[j] - a[i] == dif && i != j)
            return {a[i], a[j]};
        else if (a[j] - a[i] < dif)
            j++;
        else
            i++;
    }
    return {-1, -1};
} //time complexity O(N*log(N)), space complexity O(1)
int main()
{
    int a[] = {5, 20, 3, 2, 5, 80};
    int n = sizeof(a) / sizeof(int);
    auto res = get_pair_sorting_two_pointer(a, n, 78);
    cout << res.first << ' ' << res.second << endl;
    return 0;
}