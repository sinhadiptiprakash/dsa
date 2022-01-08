#include <bits/stdc++.h>
using namespace std;
/*
This question is based on greedy approach.

Main idea is  a^b < b^a (if a>b and not valid for a=3 and b=3) ,
 so place all the amplifiers with higher amplification first . 
If there is amplifier with amplification 1 the place all these amplifier first.
*/
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int *array = new int[n];
        int count1 = 0, count = 0, data, j = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> data;
            //if there is a 1 then we dont store it in the array rather we count the ones only
            //as we always print ones first in the arrangement
            if (data == 1)
                count1++;
            //else we count the no. of elements other than 1 and store this no. in array
            else
            {
                array[j++] = data;
                count++;
            }
        }
        //sorting the array containing the numbers other than 1
        sort(array, array + count);
        //printing all ones first because one to the power something is 1
        for (int i = 0; i < count1; i++)
            cout << 1 << ' ';
        if (count == 2 && array[0] == 2 && array[1] == 3)
        {
            cout << 2 << ' ' << 3 << ' ';
        }
        else
        {
            for (int i = count - 1; i >= 0; i--)
            {
                cout << array[i] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}