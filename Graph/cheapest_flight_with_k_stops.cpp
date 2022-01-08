#include <bits/stdc++.h>
using namespace std;
//using DP
int findCheapestPriceUsingDP(int n, vector<vector<int>> &flights, int src, int dest, int k)
{
    // cost[i][j] represents the minimum cost of flight from source to j with at most i stops
    // initially we set the cost to 1e9+7 i.e. infinity (OVER ESTIMATIOn)
    vector<vector<int>> cost(k + 2, vector<int>(n, 1e9 + 7));
    //now source to source distance is 0 for all stops from 0 to k+1
    for (int i = 0; i <= k + 1; i++)
        cost[i][src] = 0;
    int u, v, price;
    for (int stop = 1; stop <= k + 1; stop++)
    {
        for (auto edge : flights)
        {
            u = edge[0], v = edge[1], price = edge[2];
            // updating cost from source to v node with at most stop no. of stops
            // if cost of reaching u node with at most stop-1 stops + price of reaching from u to v is less
            // here k-1 is because we are going from source to v using u as a stop
            cost[stop][v] = min(cost[stop][v], cost[stop - 1][u] + price);
        }
    }
    return cost[k + 1][dest] == 1e9 + 7 ? -1 : cost[k + 1][dest];
}
// we can solve the question using Bellman Ford Algorithm with the utilization of the fact that:
// after k-iteration of relaxation of the distances between vertices we will have distance of two vertices
// which are at most k vertices away

// However, like standard Bellman Ford Algorith a single distance array is not sufficient here
// because any values updated in a particular iteration cannot be used to update other values in the same iteration.
// Thus, we need another distance array which will kind of server as values in the previous iteration.
// So we essentially use 2 arrays of size V and we swap between them in each iteration
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    int u, v, w;
    //over estimation
    vector<int> distance(n, 1e8);
    // source to source distance is 0
    distance[src] = 0;
    //relaxation for exactly k+1 times to restrict to have at most k stops between source to destination
    for (int i = 0; i <= k; i++)
    {
        // copying the main distance vector to the temp to avoid doing relaxation based on a relaxation
        //  which is been done in this particular iteration
        // because any values updated in a particular iteration cannot be used to update other values in the same iteration.
        // Thus, we need another distance array which will kind of server as values in the previous iteration.
        vector<int> temp(distance);
        for (auto flight : flights)
        {
            u = flight[0], v = flight[1], w = flight[2];
            // notice we are here using previous distance of u not the curent distance which might be updated in this particular iteration
            temp[v] = min(temp[v], distance[u] + w);
        }
        distance = temp;
    }
    return distance[dst] == 1e8 ? -1 : distance[dst];
}
//we can solve it using Dijkstra
int main()
{
    int n, e, u, v, w;
    cin >> n >> e;
    vector<vector<int>> flights;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        flights.push_back({u, v, w});
    }
    cout << findCheapestPrice(n, flights, 0, 2, 0) << endl;
    return 0;
}