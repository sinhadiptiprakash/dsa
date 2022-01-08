#include <bits/stdc++.h>
using namespace std;
/*
Below is complete algorithm. 
1) Find if A can be transformed to B or not by first creating a count array for all characters of A, then checking with B if B has same count for every character. 
2) Initialize result as 0. 
2) Start traversing from end of both strings. 
……a) If current characters of A and B match, i.e., A[i] == B[j] 
………then do i = i-1 and j = j-1 
……b) If current characters don’t match, then search B[j] in remaining 
………A. While searching, keep incrementing result as these characters 
………must be moved ahead for A to B transformation.

Below are the implementations based on this idea.  
*/
int min_operations_to_transform(string &A, string &B)
{
    int m = A.length(), n = B.length();

    // This parts checks whether conversion is possible or not
    if (n != m)
        return -1;
    int count[256];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n; i++) // count characters in A
        count[B[i]]++;
    for (int i = 0; i < n; i++)   // subtract count for
        count[A[i]]--;            // every character in B
    for (int i = 0; i < 256; i++) // Check if all counts become 0
        if (count[i])
            return -1;

    // This part calculates the number of operations required
    int res = 0;
    for (int i = n - 1, j = n - 1; i >= 0;)
    {
        // If there is a mismatch, then keep incrementing result 'res' until B[j] is not found in A[0..i]
        while (i >= 0 && A[i] != B[j])
        {
            i--;
            res++;
        }

        // If A[i] and B[j] match
        if (i >= 0)
        {
            i--;
            j--;
        }
    }
    return res;
}
int main()
{
    string A = "EACBD";
    string B = "EABCD";
    cout << min_operations_to_transform(A, B) << endl;
    return 0;
}