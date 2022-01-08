#include <bits/stdc++.h>
using namespace std;
/*
Let us take few examples to observe pattern 

5!  has 1 trailing zeroes 
[All numbers from 6 to 9
 have 1 trailing zero]

10! has 2 trailing zeroes
[All numbers from 11 to 14
 have 2 trailing zeroes]

15! to 19! have 3 trailing zeroes

20! to 24! have 4 trailing zeroes

25! to 29! have 6 trailing zeroes
We can notice that, the maximum value whose factorial contain n trailing zeroes is 5*n.
So, to find minimum value whose factorial contains n trailing zeroes, 
use binary search on range from 0 to 5*n. 
And, find the smallest number whose factorial contains n trailing zeroes. 
*/
//below function count the no. of trailing zeros in factorial of a number p
//and check wheather this no. contains atleast n trailing zeros
bool check(int p, int n)
{
    int temp = p, count = 0, f = 5;
    while (f <= temp)
    {
        count += temp / f;
        f = f * 5;
    }
    return (count >= n);
}
int binary_search(int n)
{
    if (n == 1)
        return 5;
    int low = 0, high = 5 * n, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        //if mid has atleast n trailing zeros we will go to the left as we need the smallest no
        if (check(mid, n))
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return low;
} //time complexity O(log5(N)*log2(N)) space complexity O(1)
int main()
{
    cout << binary_search(5) << endl;
    return 0;
}