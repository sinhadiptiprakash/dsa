#include <bits/stdc++.h>
using namespace std;
//brute force approach
void four_elements(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (a[i] + a[j] + a[k] + a[l] == x)
                    {
                        cout << a[i] << ' ' << a[j] << ' ' << a[k] << ' ' << a[l] << endl;
                    }
                }
            }
        }
    }
} //time complexity O(N^4) space complexity O(1)
//below is the approach based on two pointer approach
vector<vector<int>> four_elements2(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    if (n < 4)
        return res;
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int low = j + 1, high = n - 1, sum = target - nums[i] - nums[j];
            while (low < high)
            {
                if (nums[low] + nums[high] == sum)
                {
                    res.push_back({nums[i], nums[j], nums[low], nums[high]});
                    while (low < high and nums[low] == nums[low + 1])
                        low++;
                    while (low < high and nums[high] == nums[high - 1])
                        high--;
                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] < sum)
                    low++;
                else
                    high--;
            }
            //below loop is for avoiding the duplicates
            while (j < n - 2 and nums[j] == nums[j + 1])
                j++;
        }
        //below loop is also for avoiding the duplicates
        while (i < n - 3 and nums[i] == nums[i + 1])
            i++;
    }
    return res;
} //time complexity O(N^3)
//below is the map based approach
//it checks wheather the four elements are duplicates i.e. duplicates at original position
bool duplicates(pair<int, int> p, int a, int b)
{
    if (p.first == a || p.first == b || p.second == a || p.second == b)
        return true;
    return false;
}
vector<vector<int>> four_elements3(vector<int> &nums, int x)
{
    int n = nums.size();
    vector<vector<int>> res;
    unordered_map<int, pair<int, int>> map;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            map[(nums[i] + nums[j])] = {i, j};
        }
    }
    unordered_set<int> included;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = nums[i] + nums[j];
            // and this combination of elements does'nt contain eny duplicates store the combination into the result
            // if the elements are not already included
            if (map.find(x - sum) != map.end() && !duplicates(map[x - sum], i, j))
            {

                auto p = map[x - sum];
                //if the combination of the elements at index i,j,p.first,p.second is not pushed yet
                //we actually store the sum of these indexes as true if elements at this very indexes are included,otherwise false
                if (included.find(i + j + p.first + p.second) == included.end())
                {
                    res.push_back({nums[p.first], nums[p.second], nums[i], nums[j]});
                    // making the elements included
                    included.emplace(i + j + p.first + p.second + 4);
                }
            }
        }
    }
    return res;
} //time complexity O(N^2) space complexity O(N^2)
int main()
{
    vector<int> arr = {10, 20, 30, 40, 1, 2, 40};
    int x = 91;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int y = 0;
    vector<int> nums2 = {2, 2, 2, 2, 2};
    int z = 8;
    auto res = four_elements3(nums2, z);
    for (auto it : res)
    {
        for (auto i : it)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}