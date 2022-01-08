#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//dry run the code with the problem test case given you will get the logic
void solve();

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
        cout << endl;
    }
}

void solve()
{
    int w, h, n;
    cin >> w >> h >> n;

    int x[n + 1], y[n + 1];
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    x[n] = w + 1;
    y[n] = h + 1;
    priority_queue<int, vector<int>, greater<int>> mhx(x, x + n + 1), mhy(y, y + n + 1);

    int cx, cy, px, py;
    int mdx = px = mhx.top();
    int mdy = py = mhy.top();

    mhx.pop();
    mhy.pop();

    while (!mhx.empty())
    {
        cx = mhx.top();
        cy = mhy.top();

        mhx.pop();
        mhy.pop();

        mdx = max(mdx, cx - px);
        mdy = max(mdy, cy - py);

        px = cx;
        py = cy;
    }

    --mdx;
    --mdy;

    cout << mdx * mdy;
}