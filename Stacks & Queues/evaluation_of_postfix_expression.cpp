//leetcode problem
#include <bits/stdc++.h>
using namespace std;

int evaluate_postfix_expression(vector<string> tokens)
{
    stack<int> temp;
    int n = tokens.size();
    map<string, int> op;
    op["+"] = 1;
    op["-"] = 2;
    op["*"] = 3;
    op["/"] = 4;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (op.count(tokens[i]) != 0)
        {
            int num1 = temp.top();
            temp.pop();
            int num2 = temp.top();
            temp.pop();
            switch (op[tokens[i]])
            {
            case 1:
                num2 += num1;
                break;
            case 2:
                num2 -= num1;
                break;
            case 3:
                num2 *= num1;
                break;
            case 4:
                num2 /= num1;
                break;
            default:
                break;
            }
            temp.push(num2);
        }
        else
        {
            int num = stoi(tokens[i]);
            temp.push(num);
        }
    }
    int res = temp.top();
    temp.pop();
    return res;
}
int main()
{
    vector<string> tokens;
    cout << evaluate_postfix_expression(tokens) << endl;
    return 0;
}