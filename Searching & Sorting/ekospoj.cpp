#include <bits/stdc++.h>
using namespace std;
//this problem is similar to the book-allocation and aggressive cows problem so its a great example for binary search
//below function checks wheather it is possible to obtain at least required_woods
// by setting the blade height at blade_height
bool is_possible(vector<int> heights, int blade_height, int required_woods)
{
    int n = heights.size();
    int woods = 0;
    for (int i = 0; i < n; i++)
    {
        // if a single unit of wood can be obtained by cutting heights[i] at blade_height
        //i.e. wheather this blade_height going to cut a single unit of wood or not if so then add the obtained wood
        if (heights[i] > blade_height)
            woods += (heights[i] - blade_height);
        //check earlier if we have already obtained atleast required amount of woods then return true;
        if (woods >= required_woods)
            return true;
    }
    // if we did'nt get atleast the required amount of woods return false
    return false;
}
int binary_search(vector<int> heights, int required_woods)
{
    int n = heights.size();
    //as we know our search space will be in between 0 to maximum height of trees so we need to set high as max_height
    int max_height = *max_element(heights.begin(), heights.end());
    //blade height is actually the mid in binary search
    int low = 0, high = max_height, blade_height;
    //as we are going to get some maximum value of blade_height we set it a negative value initially
    int max_blade_height = -1;
    while (low <= high)
    {
        //we get the mid of our curent search space and set it as our blade_height
        blade_height = low + (high - low) / 2;
        // if setting this very blade_height make us able to obtain at least required unit of woods
        // this is one of our answer, so we should update our max_blade height if its greater than that
        if (is_possible(heights, blade_height, required_woods))
        {
            max_blade_height = max(max_blade_height, blade_height);
            // as we are trying to maximize the max_blade_height we should increase the blade_height and check again
            // so now our search space will be from blade_hight+1 to high
            // as we know we can obtain at least required woods by cutting at this blade height
            low = blade_height + 1;
        }
        // if we are not able to obtain required_woods by setting height at blade_height,
        // we should decrease the height, so our search space will be now from low to blade_height-1
        else
            high = blade_height - 1;
    }
    return max_blade_height;
}
int main()
{
    int n, required_woods;
    cin >> n >> required_woods;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    cout << binary_search(heights, required_woods) << endl;
    return 0;
}