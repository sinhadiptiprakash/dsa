/*
Let countDer(n) be count of derangements for n elements. Below is the recursive relation to it.  

countDer(n) = (n - 1) * [countDer(n - 1) + countDer(n - 2)]
How does above recursive relation work? 

There are n – 1 way for element 0 (this explains multiplication with n – 1). 
Let 0 be placed at index i. There are now two possibilities, depending on whether or not element i is placed at 0 in return. 
    i is placed at 0: 
        This case is equivalent to solving the problem for n-2 elements as two elements have just swapped 
        their positions.
    i is not placed at 0: 
        This case is equivalent to solving the problem for n-1 elements as now there are n-1 elements, 
        n-1 positions and every element has n-2 choices
*/
// A Dynamic programming based C++
// program to count derangements
#include <bits/stdc++.h>
using namespace std;

int countDer(int n)
{
    // Create an array to store
    // counts for subproblems
    int der[n + 1] = {0};

    // Base cases
    der[1] = 0;
    der[2] = 1;

    // Fill der[0..n] in bottom up manner
    // using above recursive formula
    for (int i = 3; i <= n; ++i)
        der[i] = (i - 1) * (der[i - 1] +
                            der[i - 2]);

    // Return result for n
    return der[n];
} //time complexity O(N) space complexity O(n)
int countDer(int n)
{

    // base case
    if (n == 1 or n == 2)
    {
        return n - 1;
    }

    // Variable for just storing
    // previous values
    int a = 0;
    int b = 1;

    // using above recursive formula
    for (int i = 3; i <= n; ++i)
    {
        int cur = (i - 1) * (a + b);
        a = b;
        b = cur;
    }

    // Return result for n
    return b;
} //time complexity O(N) space O(1)
// Driver code
int main()
{
    int n = 4;
    cout << "Count of Derangements is "
         << countDer(n);
    return 0;
}
