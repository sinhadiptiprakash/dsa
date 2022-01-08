#include <bits/stdc++.h>
using namespace std;
int get_max_index(vector<int> &distance, int n)
{
    int max_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (distance[max_index] < distance[i])
            max_index = i;
    }
    return max_index;
}
vector<int> k_centers(vector<vector<int>> &weights, int n, int k)
{
    vector<int> distance(n, INT_MAX);
    vector<int> centers;
    // index of city having the maximum distance to it's closest center
    int max_index = 0;
    for (int i = 0; i < k; i++)
    {
        centers.push_back(max_index);
        for (int j = 0; j < n; j++)
        {
            // updating the distance of the cities to their closest centers
            distance[j] = min(distance[j], weights[max_index][j]);
        }
        // updating the index of the city with the maximum distance to it's closest center
        max_index = get_max_index(distance, n);
    }
    //Printing the maximum distance of a city to a center that is our answer
    cout << distance[max_index] << endl;
    return centers;
}
int main()
{
    int n = 4;
    vector<vector<int>> weights = {{0, 4, 8, 15},
                                   {4, 0, 1, 7},
                                   {8, 2, 0, 9},
                                   {5, 7, 19, 0}};
    int k = 2;
    auto res = k_centers(weights, n, k);
    for (int i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}