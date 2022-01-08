#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
/*
some useful formular: 
nth term in ap: an=a0+(n-1)*d
sum of n terms in ap: n/2(2a+(n-1)*d)
sum of squares in ap: [n*(n+1)*(2*n+1)]/6
sum of qubes in ap: [n*(n+1)/2]^2

now we will be using the sum of n terms in ap
if rank of a cook is R and he has to make P paratas, he will need at least 
time=P/2*[2+(P-1)*d] as a is initially no. of paratas which is 1, now we can get P from this equation we we have time
*/
//below function returns no. of paratas cook with rank Rank can make within given time
ULL get_num(int Rank, ULL time)
{
    ULL Parata = (ULL)sqrt(Rank * Rank + 8 * Rank * time);
    Parata -= Rank;
    return Parata / (2 * Rank);
}
//below is the function for checking wheather in given time all the L cooks can make P paratas or not
bool can_make(ULL ranks[], ULL L, ULL P, ULL time)
{
    ULL count = 0;
    for (ULL i = 0; i < L; i++)
    {
        count += get_num(ranks[i], time);
        if (count >= P)
            return true;
    }
    return false;
}
//below is the binary search function that generates times optimally and we check wheather within this generated time all L cooks
//can make P paratas or not
//the intially search space  will be from 1 to 10*P*(P+1)/2
ULL binary_search(ULL ranks[], ULL L, ULL P)
{
    ULL low = 1, high = (ULL)(10 * P * (P + 1)) / 2, time; //time is actually the mid
    while (low <= high)
    {
        time = low + (high - low) / 2;
        if (can_make(ranks, L, P, time))
        {
            //as we are required to find minimum time we should go to the left
            high = time - 1;
        }
        else
        {
            low = time + 1;
        }
    }
    return low;
}
int main()
{
    ULL t, L, P;
    cin >> t;
    while (t--)
    {
        cin >> P >> L;
        ULL *ranks = new ULL[L];
        for (ULL i = 0; i < L; i++)
        {
            cin >> ranks[i];
        }
        cout << binary_search(ranks, L, P) << endl;
        delete (ranks);
    }
    return 0;
}