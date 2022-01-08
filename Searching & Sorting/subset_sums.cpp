#include <bits/stdc++.h>
using namespace std;
// below function generates vector of sum of all individual subsets of set s
void subset(int s[], vector<int> &v, int n, int start)
{
    int i;
    int j;
    int sum;

    for (i = 0; i < (1 << n); i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum = sum + s[j + start];
            }
        }
        v.push_back(sum);
    }
}
int main()
{
    int n;
    int a;
    int b;
    int s[40];
    int i;
    int j;
    //left and right are the two vectors containing the sums of all individual subsets of left and right half
    vector<int> left, right;
    int hi;
    int lo;
    long long int sum;
    sum = 0;

    scanf("%d%d%d", &n, &a, &b);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }

    subset(s, left, n / 2, 0);
    subset(s, right, (n & 1) ? n / 2 + 1 : n / 2, n / 2);
    //sort the right vector to make it elgible for the binary search as we will be doing binary search to find upper, lowe bound
    sort(right.begin(), right.end());
    //for each sum in left vector we are finding lower_bound of a-left[i] and upper bound of b-left[i]
    for (i = 0; i < left.size(); i++)
    {
        lo = lower_bound(right.begin(), right.end(), a - left[i]) - right.begin();
        hi = upper_bound(right.begin(), right.end(), b - left[i]) - right.begin();
        sum = sum + (hi - lo);
    }
    printf("%lld\n", sum);
}