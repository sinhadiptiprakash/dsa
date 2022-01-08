#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define vl vector<ll>
#define fl(k, n, l) for (int i = k; i < n; (l > 0 ? i += l : i -= l))
#define el endl;
#define bn begin()
#define rbn rbegin()
#define ed end()
#define red rend()
#define all(n) (n).bn, (n).ed
#define sz size()
#define mt empty()
#define psb push_back
#define pb pop_back();
#define fnt front();
#define bk back()
#define ps push
#define pp pop()
#define tp top()
const int mod = 1e9 + 7;
#define speedup                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
int dp[1005][1005][4];
int sol(int h, int a, int pos)
{
    if (a <= 0 || h <= 0)
        return 0;
    if (dp[h][a][pos] != -1)
        return dp[h][a][pos];
    if (pos == 1)
        return dp[h][a][pos] = 1 + max(sol(h - 5, a - 10, 2), sol(h - 20, a + 5, 3));
    if (pos == 2)
        return dp[h][a][pos] = 1 + max(sol(h + 3, a + 2, 1), sol(h - 20, a + 5, 3));
    return dp[h][a][pos] = 1 + max(sol(h + 3, a + 2, 1), sol(h - 5, a - 10, 2));
}
int main()
{
    speedup int t;
    cin >> t;
    while (t--)
    {
        int h, a;
        memset(dp, -1, sizeof dp);
        cin >> h >> a;
        cout << max(sol(h, a, 1), max(sol(h, a, 2), sol(h, a, 3))) - 1 << el;
    }
    return 0;
}