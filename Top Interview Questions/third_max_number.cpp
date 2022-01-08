#include <bits/stdc++.h>
using namespace std;
int thirdMax(vector<int> &nums)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long firstMax = LONG_MIN, secondMax = LONG_MIN, thirdMax = LONG_MIN; // Minimum Initialisation at values lesser than the constraints
    for (int num : nums)
    {
        if (num > firstMax) // firstMax = first, if num > first; pass down the values to secondMax(second) and thirdMax(third)
        {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = num;
        }
        else if (num > secondMax && num != firstMax) // if(num > second such that num is not equal to firstMax, which means  firstMax > num > secondMax
        {
            thirdMax = secondMax;
            secondMax = num;
        }
        else if (num > thirdMax && num != secondMax && num != firstMax) // if (firstMax > secondMax > num > thirdMax)  is satisfied modify thirdMax, where thirdMax is our third maximum
        {
            thirdMax = num;
        }
    }
    return ((thirdMax == LONG_MIN) ? firstMax : thirdMax); // if third max == LONG_MIN, then this means our array has two or less distinct values
} // TC O(N) SC O(1)
int main()
{
    return 0;
}