#include <bits/stdc++.h>
using namespace std;
int getPriority(char sign)
{
    switch (sign)
    {
    case '*':
        return 3;
    case '/':
        return 3;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return 0;
    }
}
int perform(int a, int b, char op)
{
    switch (op)
    {
    case '/':
        return a / b;
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    default:
        return 0;
    }
}

int calculate(string s)
{
    stack<int> numbers;
    stack<char> operators;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue;
        else if (isdigit(s[i]))
        {
            int num = 0;
            while (i < s.length() && isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            numbers.push(num);
            i--;
        }
        else
        {
            while (!operators.empty() && getPriority(operators.top()) >= getPriority(s[i]))
            {
                int a = numbers.top();
                numbers.pop();
                int b = numbers.top();
                numbers.pop();
                int res = perform(b, a, operators.top());
                operators.pop();
                numbers.push(res);
            }
            operators.push(s[i]);
        }
    }
    while (numbers.size() != 1)
    {
        int a = numbers.top();
        numbers.pop();
        int b = numbers.top();
        numbers.pop();
        int res = perform(b, a, operators.top());
        operators.pop();
        numbers.push(res);
    }
    return numbers.top();
} // TC O(N) SC O(N)
  // efficient approach wihtout using stack

int calculate(string s)
{
    int length = s.length();
    if (length == 0)
        return 0;
    int currentNumber = 0, lastNumber = 0, result = 0;
    char sign = '+';
    for (int i = 0; i < length; i++)
    {
        char currentChar = s[i];
        if (isdigit(currentChar))
        {
            currentNumber = (currentNumber * 10) + (currentChar - '0');
        }
        if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1)
        {
            if (sign == '+' || sign == '-')
            {
                result += lastNumber;
                lastNumber = (sign == '+') ? currentNumber : -currentNumber;
            }
            else if (sign == '*')
            {
                lastNumber = lastNumber * currentNumber;
            }
            else if (sign == '/')
            {
                lastNumber = lastNumber / currentNumber;
            }
            sign = currentChar;
            currentNumber = 0;
        }
    }
    result += lastNumber;
    return result;
}
int main()
{
    return 0;
}