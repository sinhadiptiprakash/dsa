#include <bits/stdc++.h>
using namespace std;
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    //N.B. important point to note that we have to handle the case when array contains 0s
    vector<long long int> product(n);
    long long int prod = 1, flag = 0;
    for (int i = 0; i < n; i++)
    {
        //ignoring 0 we get the product
        if (nums[i] != 0)
            prod *= nums[i];
        //counting the numbers of 0s
        else
            flag++;
    }
    for (int i = 0; i < n; i++)
    {
        //if there is only one 0 zero in the nums then except it all the elements in product array will be 0
        //and at the positon of zero the product will contain prod
        if (flag == 1 && nums[i] == 0)
            product[i] = prod;
        //if the nums contains more than 1 zeros at all positions product will contain 0
        if (flag > 1)
            product[i] = 0;
        else if (flag == 0)
            product[i] = prod / nums[i];
    }
    return product;
} //time complexity O(N) space complexity O(1)
int main()
{
    vector<long long int> nums = {10, 0, 5, 6, 0};
    int n = nums.size();
    auto res = productExceptSelf(nums, n);
    for (auto i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}