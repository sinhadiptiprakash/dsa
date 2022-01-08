#include<bits/stdc++.h>
using namespace std;
// optimized approach using sorting
int findUnsortedSubarray(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0 || n == 1)
        return 0;
    vector<int> copy = nums;
    sort(copy.begin(), copy.end());
    int i = 0, j = n - 1;
    bool iflag = 1, jflag = 1;
    while (i <= j && (iflag || jflag))
    {
        if (nums[i] != copy[i])
            iflag = 0;
        else
            i++;
        if (nums[j] != copy[j])
            jflag = 0;
        else
            j--;
    }
    return (j - i >= 0 ? j - i + 1 : 0);
}
int main(){
    return 0;
}