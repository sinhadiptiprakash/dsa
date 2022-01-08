#include <bits/stdc++.h>
using namespace std;
int nibbles[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
//count by nibbles,
int count_set_bits(int n)
{
    int count = 0;
    while (n > 0)
    {
        //for detecting the least significant 4 bits we simply do and operation between n and 15(i.e. 0xF)
        //bcz wheather n is greater than 15 or not we always get Least Significant 4 bits
        //then we check for the corresponding nible in the table how much set bit are there for this nible
        count += nibbles[n & 0xF];
        //as we are examining nible by nible we divide n by 4 i.e. right shift n by 4 bits
        n >>= 4;
    }
    return count;
} //time complexity O(log4(n))

//below is the custom compare function for sorting the array of nums based on their set bit count
bool comp(const int &a, const int &b)
{
    int cnt_a = count_set_bits(a), cnt_b = count_set_bits(b);
    return cnt_a > cnt_b;
}
void sort_by_set_bit_count(int a[], int n)
{
    sort(a, a + n, comp);
}

//we can also use __builtin_popcount funtion to count the set bits of a number bool comp(int a, int b)
bool compare(int a, int b)
{
    int a1 = __builtin_popcount(a);
    int b1 = __builtin_popcount(b);

    if (a1 == b1)
        return a < b;
    return a1 < b1;
}
vector<int> sort_by_set_bit_coun2(vector<int> &arr)
{
    sort(arr.begin(), arr.end(), compare);
    return arr;
}
int main()
{
    int nums[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    int n = sizeof(nums) / sizeof(int);
    sort_by_set_bit_count(nums, n);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
    return 0;
}