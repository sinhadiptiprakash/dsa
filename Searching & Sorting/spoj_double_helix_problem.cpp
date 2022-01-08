#include <bits/stdc++.h>
using namespace std;
//simple two pointer approach
int double_helix_simple(int a[], int n, int b[], int m)
{
    int sum1 = 0, sum2 = 0;
    int i = 0, j = 0;
    int max_sum = 0;
    while (i < n && j < m)
    {
        //we always add smaller element to the sum1 and increase the i
        if (a[i] < b[j])
            sum1 += a[i++];
        //we always add larger element to the sum2 and increase j, this way we will always get same elements i.e. intersection point at i and j.
        else if (b[j] < a[i])
            sum2 += b[j++];
        else
        { //when both the elements are same i.e. we are at an intersection point
            max_sum += max(sum1, sum2) + a[i];
            i++;
            j++;
            sum1 = 0, sum2 = 0;
        }
    }
    while (i < n)
    {
        sum1 += a[i++];
    }
    while (j < m)
    {
        sum2 += b[j++];
    }
    max_sum += max(sum1, sum2);
    return max_sum;
}
int main()
{
    int n, m;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        else
        {
            int *a = new int[n];
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            cin >> m;
            int *b = new int[m];
            for (int i = 0; i < m; i++)
            {
                cin >> b[i];
            }
            cout << double_helix_simple(a, n, b, m) << endl;
            delete (a);
            delete (b);
        }
    }
    return 0;
}