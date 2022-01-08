//Slowest Key
#include <bits/stdc++.h>
using namespace std;
char slowestKey(vector<int> &releaseTimes, string keysPressed)
{
    int maxTime = releaseTimes[0];
    char key = keysPressed[0];
    int n = releaseTimes.size();
    for (int i = 1; i < n; i++)
    {
        if (releaseTimes[i] - releaseTimes[i - 1] > maxTime)
        {
            maxTime = releaseTimes[i] - releaseTimes[i - 1];
            key = keysPressed[i];
        }
        if (releaseTimes[i] - releaseTimes[i - 1] == maxTime)
        {
            if (keysPressed[i] > key)
                key = keysPressed[i];
        }
    }
    return key;
}
int main()
{
    int n;
    cin >> n;
    vector<int> releaseTimes(n);
    string keysPressed;
    for (int i = 0; i < n; i++)
        cin >> releaseTimes[i];
    cin >> keysPressed;
    cout << slowestKey(releaseTimes, keysPressed) << endl;
    return 0;
}