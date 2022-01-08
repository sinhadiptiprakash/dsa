#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    if (nums.size() < 3)
        return res;

    //1. Sort the given vector
    sort(nums.begin(), nums.end());

    //a+b+c = 0 => b+c = -a
    //Moving for value of 'a' (a=num[i]) which is not a duplicate
    for (int i = 0; i < nums.size() - 2; i++)
    {

        if (i == 0 || nums[i] != nums[i - 1])
        {
            int low = i + 1, high = nums.size() - 1, sum = 0 - nums[i];
            //sum is the pair we are finding in the array

            while (low < high)
            {
                //If a pair is found, insert triplet in res
                if (nums[low] + nums[high] == sum)
                {
                    res.push_back({nums[i], nums[low], nums[high]});

                    //Now move low forward and high backwards, until they skip the duplicates of current element
                    while (low < high && nums[low] == nums[low + 1])
                        low++;
                    while (low < high && nums[high] == nums[high - 1])
                        high--;
                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] < sum)
                    low++;
                else if (nums[low] + nums[high] > sum)
                    high--;
            }
        }
    }
    return res;
}
int main(){
    return 0;
}