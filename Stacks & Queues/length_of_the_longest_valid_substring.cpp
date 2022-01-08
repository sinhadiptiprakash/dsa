#include <bits/stdc++.h>
using namespace std;
//using stack
/*
An Efficient Solution can solve this problem in O(n) time. 
The idea is to store indexes of previous starting brackets in a stack. 
The first element of the stack is a special element that provides index before the beginning of valid substring 
(base for next valid string). 

Algorithm:
1) Create an empty stack and push -1 to it. 
   The first element of the stack is used 
   to provide a base for the next valid string. 

2) Initialize result as 0.

3) If the character is '(' i.e. str[i] == '('), 
   push index'i' to the stack. 
   
2) Else (if the character is ')')
   a) Pop an item from the stack (Most of the 
      time an opening bracket)
   b) If the stack is not empty, then find the
      length of current valid substring by taking 
      the difference between the current index and
      top of the stack. If current length is more 
      than the result, then update the result.
   c) If the stack is empty, push the current index
      as a base for the next valid substring.

3) Return result.
*/
int longest_valid_substring_using_stack(string s)
{
    int res = 0;
    //for storing the indexes of the string characters
    stack<int> stack;
    //as we assume that the first index of the string is the starting index of the next valid substring we push -1 into the stack
    stack.push(-1);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            stack.push(i);
        else
        { //else if it is a closing bracket
            //first pop the stack to get the index before the last stored index at the top of the stack
            if (!stack.empty())
                stack.pop();
            //now if the stack is not empty that means curent character increasing the previous length does'nt end the continuation
            if (!stack.empty())
                res = max(res, i - stack.top()); //because stack.top now stores the starting index of this valid substring
            else
            { // if the stack is empty
                // we store this index as the starting index of the next valid substring
                stack.push(i);
            }
        }
    }
    return res;
}
//most efficient approach
int longest_valid_substring_efficient(string s)
{
    int left = 0, right = 0, maxlength = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            left++;
        else
            right++;
        if (left == right)
            maxlength = max(maxlength, 2 * right);
        else if (right > left)
            left = right = 0;
    }
    left = right = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
            left++;
        else
            right++;
        if (left == right)
            maxlength = max(maxlength, 2 * left);
        else if (left > right)
            left = right = 0;
    }
    return maxlength;
}
int main()
{
    string s;
    cin >> s;
    cout << longest_valid_substring_efficient(s) << endl;
    return 0;
}