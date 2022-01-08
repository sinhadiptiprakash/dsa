#include <bits/stdc++.h>
using namespace std;
//brute force approach
/*
Algorithm: 
Run two nested loops the outer loop from start to end and the inner loop from i+1 to end.
For every iteration of the outer loop find the count of intervals that intersect with the current interval.
Update the answer with the maximum count of overlap in each iteration of the outer loop.
Print the answer.*/
// Returns minimum number of platforms reqquired
int findPlatform(int arr[], int dep[], int n)
{

    // plat_needed indicates number of platforms
    // needed at a time
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;

    // run a nested  loop to find overlap
    for (int i = 0; i < n; i++)
    {
        // minimum platform
        plat_needed = 1;

        for (int j = i + 1; j < n; j++)
        {
            // check for overlap
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                (arr[j] >= arr[i] && arr[j] <= dep[i]))
                plat_needed++;
        }

        // update result
        result = max(result, plat_needed);
    }

    return result;
} //time complexity O(N^2) space complexity O(1)

//using greedy technique its similar like merging two sorted arrays
/*
Algorithm:

1.Sort the arrival and departure times of trains.
2.Create two pointers i=0, and j=0 and a variable to store ans and current count plat
3.Run a loop while i<n and j<n and compare the ith element of arrival array and jth element of departure array.
4.If the arrival time is less than or equal to departure then one more platform is needed so increase the count, i.e. plat++ and increment i
5.Else if the arrival time greater than departure then one less platform is needed so decrease the count, i.e. plat– and increment j
6.Update the ans, i.e ans = max(ans, plat).
*/
int minimum_platforms(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int needed = 1, res = 1;
    int i = 1, j = 0; //we took i=1 as we have to allocate the first train to one of the platforms
    while (i < n & j < n)
    {
        // If next event in sorted order is arrival, increment count of platforms needed
        // as we have to allocate this train tooo
        if (arr[i] <= dep[j])
        {
            needed += 1;
            //as we have allocate the train we have to increse i
            i++;
        }
        // Else if its a deparature time we have now 1 platform free
        // so we have to decrement count of platforms needed
        else if (arr[i] > dep[j])
        {
            needed--;
            //as we deallocate the platform we increase j
            j++;
        }
        res = max(needed, res);
    }
    return res;
} //time complexity O(N*log(N)) space complexity O(1)
/*
Method 3: If all the arrival and departure occur on the same day 
then we can use and auxiliary array to compute the required number of the platform in O(n).
Whenever an arrival occurs we increase the count of the required platform 
when a departure occurs we decrease the required platform at that point of time, after that, 
we take the cumulative sum, which would provide the required number of platform for all point of time, 
out of these values maximum value is our answer.
*/
int minPlatform(int arrival[], int departure[], int n)
{

    // as time range from 0 to 2359 in 24 hour clock,
    // we declare an array for values from 0 to 2360
    int platform[2361] = {0};
    int requiredPlatform = 1;
    for (int i = 0; i < n; i++)
    {

        // increment the platforms for arrival
        ++platform[arrival[i]];

        // once train departs we decrease the platform count
        --platform[departure[i] + 1];
    }

    // We are running loop till 2361 because maximum time value
    // in a day can be 23:60
    for (int i = 1; i < 2361; i++)
    {

        // taking cumulative sum of platform give us required
        // number of platform fro every minute
        platform[i] = platform[i] + platform[i - 1];
        requiredPlatform = max(requiredPlatform, platform[i]);
    }
    return requiredPlatform;
}
int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr) / sizeof(int);
    cout << minimum_platforms(arr, dep, n) << endl;
    return 0;
}