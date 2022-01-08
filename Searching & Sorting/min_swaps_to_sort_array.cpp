#include <bits/stdc++.h>
using namespace std;
/*
Method using HashMap:

Make a new array (called temp), which is the sorted form of the input array. 
We know that we need to transform the input array to the new array (temp) in the minimum number of swaps. 
Make a map that stores the elements and their corresponding index, of the input array.

So at each i starting from 0 to N in the given array, where N is the size of the array:
    1. If i is not in its correct position according to the sorted array, then
    2. We will fill this position with the correct element from the hashmap we built earlier. 
        We know the correct element which should come here is temp[i], 
        so we look up the index of this element from the hashmap. 
    3. After swapping the required elements, we update the content of the hashmap accordingly, 
        as temp[i] to the ith position, and arr[i] to where temp[i] was earlier.
*/
// N.B. this method modifies the original array/vector to sorted order
int min_swaps_to_sort(vector<int> &arr)
{
    int ans = 0;
    vector<int> temp = arr;
    int N = arr.size();
    // Hashmap which stores the indexes of the input array
    unordered_map<int, int> h;

    sort(temp.begin(), temp.end());
    //storing the original position of a particular element in the map
    for (int i = 0; i < N; i++)
        h[arr[i]] = i;
    for (int i = 0; i < N; i++)
    {
        // This is checking whether the current element is at the right place or not
        if (arr[i] != temp[i])
        {
            ans++;
            int init = arr[i];

            // If not, swap this element with the index of the element which should come here
            swap(arr[i], arr[h[temp[i]]]);

            // Update the indexes in the hashmap accordingly
            h[init] = h[temp[i]];
            h[temp[i]] = i;
        }
    }
    return ans;
} //time  complexity O(N*log(n)) space complexity O(N)
// below is the method which does not modify the original array
int min_swaps_to_sort2(vector<int> a)
{
    vector<pair<int, int>> v(a.size());
    for (int i = 0; i < a.size(); i++)
        v[i] = {a[i], i};
    sort(v.begin(), v.end());
    int swaps = 0;
    for (int i = 0; i < v.size();)
    {
        if (i == v[i].second)
            i++;
        else
        {
            swap(v[i], v[v[i].second]);
            swaps++;
        }
    }
    return swaps;
}
int main()
{
    vector<int> a = {1, 5, 4, 3, 2};
    cout << min_swaps_to_sort2(a) << endl;
    for (int i : a)
        cout << i << ' ';
    cout << endl;
    return 0;
}