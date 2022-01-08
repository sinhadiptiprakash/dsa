#include <bits/stdc++.h>
using namespace std;
//as the vector contains vector of arrival, deparature, platform no.
//we will sort the whole vector according to the deparature time
bool comp(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}
int maximum_trains(vector<vector<int>> &trains, int n)
{
    if (n == 0)
        return 0;
    //sort the trains on deparature times
    sort(trains.begin(), trains.end(), comp);
    unordered_map<int, int> platforms; //stores the platform and their respective deparature time
    //we always allocate 1 train first
    platforms[trains[0][2]] = trains[0][1];
    int max_trains = 1;
    for (int i = 1; i < n; i++)
    {
        //if we have already allocate a train to this platform, we can again allocate another train to this platform
        //if and only if the arrival time of the curent time is greater than the deparature time of the last allocated train to this very platform
        if (platforms.find(trains[i][2]) != platforms.end())
        {
            if (trains[i][0] > platforms[trains[i][2]])
            {
                max_trains += 1;
                //allocating curent train to this platform
                platforms[trains[i][2]] = trains[i][1];
            }
        }
        else //otherwise we just allocate this curent train to its respective platform as this platform is empty
        {
            max_trains += 1;
            platforms[trains[i][2]] = trains[i][1];
        }
    }
    return max_trains;
} //time complexity O(N*Log(N)) space complexity O(P), wheere P is the no. of platforms
int main()
{
    vector<vector<int>> trains = {{1000, 1030, 1},
                                  {1010, 1020, 1},
                                  {1025, 1040, 1},
                                  {1130, 1145, 2},
                                  {1130, 1140, 2}};
    vector<vector<int>> trains2 = {{1000, 1030, 1},
                                   {1010, 1030, 1},
                                   {1000, 1020, 1},
                                   {1030, 1230, 1},
                                   {1200, 1230, 2},
                                   {9000, 1005, 1}};
    cout << maximum_trains(trains2, trains2.size()) << endl;
    return 0;
}