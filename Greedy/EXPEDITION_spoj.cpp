#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvpl vector<vector<pair<ll, ll>>>
#define pi pair<int, int>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define mpi map<int, int>
#define si set<int>
#define vl vector<ll>
#define st stack<int>
#define umpi unordered_map<int, int>
#define el endl;
#define bn begin()
#define rbn rbegin()
#define ed end()
#define red rend()
#define sz size()
#define mt empty()
#define psb push_back
#define ppb pop_back
#define fnt front()
#define bk back()
#define ps push
#define pp pop()
#define tp top()
#define speedio                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
const int mod = 1e9 + 7;
int fuel, dis, t, n;
vvi station;
int sol()
{
    //at first we have fuel amount of fuel in truck
    int cur = fuel, cnt = 0, i = 0;
    //max heap, for storing the fuel amounts of such station which are reachable by the curent fuel in the truck
    //as we choose the station which is at max distance from the truck reachable by using the curent fuel
    priority_queue<int> pq;
    //while cur amount of fuel is not equal of greater than the distance of the town from the truck
    while (cur < dis)
    {
        //cnt is for storing the no. of refuelling
        cnt++;
        //we are pushing the amount of fuels of those station which are reachable by usng curent amount of fuel
        while (i < n && station[i][0] <= cur)
        {
            pq.ps(station[i][1]);
            i++;
        }
        //if we cant reach any fuel station by curent fuel break the loop
        if (pq.mt)
            break;
        cur += pq.tp;
        pq.pp;
    }
    //if curent fuel is equal to the dis or grater than the dis i.e. truck is reachable otherwise the truck is not reachable
    return cur >= dis ? cnt : -1;
}
int main()
{
    speedio;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> dis >> fuel;
            station.psb({dis, fuel});
        }
        cin >> dis >> fuel;
        for (int i = 0; i < n; i++)
        {
            // as the distances are from town we are getting the distances from the source/truck
            station[i][0] = dis - station[i][0];
        }
        sort(station.bn, station.ed);
        cout << sol() << el station.clear();
    }
    return 0;
}