#include <bits/stdc++.h>
using namespace std;
//the calculation of cost is simple: we we cut the board horizontally with a cost c
//then total cost for this operation would be: cost=c*(no. of vertical pieces through which this cut goes)
//and now this cut will increase the horizontal pieces as we cut horizontally
int cost_to_cut_board_into_square(int x[], int n, int y[], int m)
{
    int cost = 0, i = 0, j = 0;
    // at first sort the arrays of horizontal and vertical cutting costs in a descending order
    //because to minimize the cost we have to start with more costier cut
    //because the no. of opposite pieces will gradually be increased after each cut
    sort(x, x + n, greater<int>());
    sort(y, y + m, greater<int>());
    //initially remaining horizontal pieces and vertical pieces is 1 because no cut has been performed
    int horizontal_pieces = 1, vertical_pieces = 1;
    // while we dont perform all the vertical and horizontal cuts
    while (i < n && j < m)
    {
        //if curent horizontal cut is more costier we select it to to cut the board horizontally to minimize the cost
        if (x[i] > y[j])
        {
            //cost for this operation would be: cost=c*(no. of vertical pieces through which this cut goes)
            cost += x[i] * vertical_pieces;
            // after cutting horizontally, the no. of horizontal pieces will be increased
            horizontal_pieces++;
            i++;
        }
        else
        { // we cut vertically
            //cost for this operation would be: cost=c*(no. of horizontal pieces through which this cut goes)
            cost += y[j] * horizontal_pieces;
            // after cutting vertically, the no. of vertical pieces will be increased
            vertical_pieces++;
            j++;
        }
    }
    //if some horizontal cuts remains we use them to cut
    int total = 0;
    while (i < n)
    {
        total += x[i++];
    }
    cost += vertical_pieces * total;
    total = 0;
    while (j < m)
    {
        total += y[j++];
    }
    cost += horizontal_pieces * total;
    return cost;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int *x = new int[n - 1];
        int *y = new int[m - 1];
        for (int i = 0; i < n - 1; i++)
            cin >> x[i];
        for (int i = 0; i < m - 1; i++)
            cin >> y[i];
        cout << cost_to_cut_board_into_square(x, n - 1, y, m - 1) << endl;
    }
    return 0;
}