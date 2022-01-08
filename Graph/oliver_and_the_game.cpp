#include <bits/stdc++.h>
using namespace std;

int vertex;
vector<vector<int>> tree; //used for representing the tree
vector<bool> visited;

vector<int> starttime; // starttime[i] notes the time at which DFS enters node i
vector<int> endtime;   // endtime[i] notes the time at which DFS exits node i
int timer = 0;         // a global variable that stores the timer at that instant

void makeTree() // takes the input and creates a directed graph representing the tree
{
    scanf("%d", &vertex);
    tree.resize(vertex + 1);

    for (int i = 1; i < vertex; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);

        tree[x].push_back(y);
    }
}

void measureTime(int v) // Performs Depth First Search
{
    visited[v] = 1;

    starttime[v] = timer++;

    for (int i = 0; i < tree[v].size(); i++) // calling measureTime() for adjacent nodes of node v and performing DFS
    {
        if (visited[tree[v][i]] == 0)
            measureTime(tree[v][i]);
    }
    endtime[v] = timer++;
}

int check(int x, int y)
{
    if (starttime[x] > starttime[y] && endtime[x] < endtime[y]) // checks weather node x lies in the subtree of node y or not
        return 1;
    return 0;
}

int main()
{
    makeTree();

    visited.resize(vertex + 1, 0);
    starttime.resize(vertex + 1, 0);
    endtime.resize(vertex + 1, 0);

    measureTime(1);

    int q;
    scanf("%d", &q);

    while (q--)
    {
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);

        if (!check(x, y) && !check(y, x))
        {
            printf("NO\n");
            continue;
        }

        if (type == 0)
        {
            if (check(y, x) == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            if (check(x, y) == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
