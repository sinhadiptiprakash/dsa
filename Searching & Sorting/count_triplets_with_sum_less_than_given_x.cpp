#include <bits/stdc++.h>
using namespace std;
int count_triplets(int a[], int n, int x)
{
    int cnt = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (a[i] + a[j] + a[k] < x)
                    cnt++;
            }
        }
    }
    return cnt;
} //time complexity O(N^3) space complexity O(1)
//we can use sorting+two pointer
int count_triplets2(int a[], int n, int x)
{
    sort(a, a + n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int low = i + 1, high = n - 1;
        while (low < high)
        {
            //if the sum < x then all the elements between low and high will also satisfy the conditions
            //i.e. the first second element of the triplet are a[i],a[low]
            //and all the elements between low and high will be part of these triplets with the first and second element
            //so the counts would be + (high-low) and we should increase low to change the second elements and retaining the first
            // this is because we have sorted the array
            if (a[i] + a[low] + a[high] < x)
            {
                cnt += (high - low);
                low++;
            }
            //else if the sum>=x we cant get triplet with the a[high] so we should decrease it
            else
                high--;
        }
    }
    return cnt;
} //time complexity O(N^2) space complexity O(1)
int main()
{
    int arr[] = {5, 1, 3, 4, 7};
    int n = sizeof(arr) / sizeof(int);
    cout << count_triplets2(arr, n, 12) << endl;
    return 0;
}