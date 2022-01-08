#include <bits/stdc++.h>
using namespace std;
//as we have to see every element time complexity cant be less than O(N)
//but we can reduce the number of comparisons using tournament method rather than using simple linear search
//below is the implementation of tournament method which actually uses divide and conquer
//below is the recursive code
pair<int, int> min_max_recursive(int a[], int low, int high)
{
    if (low == high)
        return {a[low], a[low]};
    //deviding the array into two parts
    int mid = low + (high - low) / 2;
    //getting the min,max in the left subarray
    auto left = min_max_recursive(a, low, mid);
    //getting the min,max int the right subarray
    auto right = min_max_recursive(a, mid + 1, high);
    //return the min and max of left and righ
    return {min(left.first, right.first), max(left.second, right.second)};
}
/*
Time Complexity: O(n) 
Total number of comparisons: let the number of comparisons be T(n). T(n) can be written as follows: 
Algorithmic Paradigm: Divide and Conquer 
      
  T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2  
  T(2) = 1
  T(1) = 0
If n is a power of 2, then we can write T(n) as: 
   T(n) = 2T(n/2) + 2
After solving the above recursion, we get 
  T(n)  = 3n/2 -2
Thus, the approach does 3n/2 -2 comparisons if n is a power of 2. And it does more than 3n/2 -2 comparisons if n is not a power of 2.
*/

int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(int);
    auto res = min_max_recursive(arr, 0, n - 1);
    cout << res.first << ' ' << res.second << endl;
    return 0;
}