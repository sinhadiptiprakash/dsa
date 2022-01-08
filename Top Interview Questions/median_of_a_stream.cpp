#include <bits/stdc++.h>
using namespace std;
//below is a famous algorithm based on heap RUNNING MEDIAN OF AN ARRAY
/*MEDIAN: the middle element in an sorted array of odd size, 
we choose the average of two medians in case of even size array
ALGORITHM:
1.CREATE A MAX HEAP LEFT FOR STORING THE LEFT SIDE ELEMENTS OF PREVIOUS MEDIAN
2.CREATE A MIN HEAP RIGHT FOR STORING THE RIGHT SIDE ELEMENTS OF PREVIOUS MEDIAN
3. FOR EVERY ELEMENT IN THE ARRAY:
    (i)IF THE LEFT.SIZE>RIGHT.SIZE:
        (a) IF THE ELEMENT<PREVIOUS MED:
            RIGHT.PUSH(LEFT.TOP)
            LEFT.POP
            LEFT.PUSH(ELEMENT)
            PREVIOUS MED=LEFT.TOP
        ELSE:
            RIGHT.PUSH(ELEMENT)
            PREVIOUS MED=RIGHT.TOP
    (ii)ELSE IF THE LEFT.SIZE<RIGHT.SIZE:
        (a) IF THE ELEMENT<PREVIOUS MED:
            LEFT.PUSH(ELEMENT)
            PREVIOUS MED=LEFT.TOP
        ELSE:
            LEFT.PUSH(RIGHT.TOP)
            RIGHT.POP
            RIGHT.PUSH(ELEMENT)
            PREVIOUS MED=RIGHT.TOP
    (iii)ELSE IF LEFT.SIZE==RIGHT.SIZE:
        (a)IF ELEMENT<PREVIOUS MED:
            LEFT.PUSH(ELEMENT)
            PREVIOUS MED=LEFT.TOP
        ELSE:
            RIGHT.PUSH(ELEMENT)
            PREVIOUS MED=RIGHT.TOP

based on the above algorithm the code will be as follows
*/
void runningMedian(int a[], int n)
{
    //max heap
    priority_queue<int> left;
    //min heap
    priority_queue<int, vector<int>, greater<int>> right;
    double prev_med = a[0];
    left.push(a[0]);
    cout << prev_med << " ";
    for (int i = 1; i < n; i++)
    {
        int element = a[i];
        if (left.size() > right.size())
        {
            if (element < prev_med)
            {
                right.push(left.top());
                left.pop();
                left.push(element);
            }
            else
                right.push(element);
            prev_med = (left.top() + right.top()) / 2.0;
        }
        else if (left.size() < right.size())
        {
            if (element < prev_med)
            {
                left.push(element);
            }
            else
            {
                left.push(right.top());
                right.pop();
                right.push(element);
            }
            prev_med = (left.top() + right.top()) / 2.0;
        }
        else
        {
            if (element < prev_med)
            {
                left.push(element);
                prev_med = left.top();
            }
            else
            {
                right.push(element);
                prev_med = right.top();
            }
        }
        cout << prev_med << " ";
    }
}
int main()
{
    int a[] = {3, 1, 6, 7, 2, 0, 2, 1, 6};
    int n = sizeof(a) / sizeof(int);
    runningMedian(a, n);
    return 0;
}