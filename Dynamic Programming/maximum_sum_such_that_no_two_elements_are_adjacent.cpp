#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int a[], int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return a[0];
        int before_prev = a[0], prev = (a[0] > a[1] ? a[0] : a[1]), temp;
        for (int i = 2; i < n; i++)
        {
            temp = prev;
            prev = max(before_prev + a[i], prev);
            before_prev = temp;
        }
        return prev;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking number of houses
        int n;
        cin >> n;
        int a[n];

        //inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        //calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends