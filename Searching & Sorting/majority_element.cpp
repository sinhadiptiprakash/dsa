#include <bits/stdc++.h>
using namespace std;
//we can solve the problem using sorting time complexity O(N*log(N))
//using unordered map
int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> elements;
    for (int i = 0; i < nums.size(); i++)
    {
        elements[nums[i]]++;
    }
    int majority = elements.begin()->first, value = elements.begin()->second;
    for (auto i = elements.begin(); i != elements.end(); i++)
    {
        if (i->second > value)
        {
            majority = i->first;
            value = i->second;
        }
    }
    return majority;
} //time complexity O(N) space O(N)

/*
Boyer-Moore Voting Algorithm:
If we had some way of counting instances of the majority element as +1+1 
and instances of any other element as -1−1, summing them would make it obvious that 
the majority element is indeed the majority element.
*/
int majorityElement_boyer_moore(vector<int> &nums)
{
    int count = 1;
    int size = nums.size();
    //we let that first element is manority
    int majority = nums[0];
    for (int i = 1; i < size; i++)
    { //if the curent element is same as majority element we increase count
        if (majority == nums[i])
            count++;
        //else if the curent element is not same as majority element we decrease the count
        else if (majority != nums[i])
            count--;
        // if the count gets equal to zero we make the curent element as the majority element and increase count
        if (count < 0)
        {
            majority = nums[i];
            count++;
        }
    }
    //now check wheather majority is truely a majority element or not
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == majority)
            count++;
    }
    return (count > size / 2 ? majority : -1);
}
int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement_boyer_moore(nums) << endl;
    return 0;
}