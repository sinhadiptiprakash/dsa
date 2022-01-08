#include <bits/stdc++.h>
using namespace std;
//by calculating indegree and outdegree of a person i.e. if A knows B, then increase A's outdegree and B's indegree
//and the celebrity will be the person with indegree N-1 and outdegree 0
int find_celebrity(vector<vector<int>> persons)
{
    int n = persons.size();
    vector<int> indegree(n, 0), outdegree(n, 0);
    //filling up the indegree and outdegree according to the persons matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (persons[i][j])
            {
                outdegree[i]++;
                indegree[j]++;
            }
        }
    }
    //checking for the celebrity
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == n - 1 && outdegree[i] == 0)
            return i;
    }
    return -1;
} //time complexity O(N^2) space complexity O(N)

////////////////////////////////////////////////////////////////////
//using recursion
bool knows(int a, int b, const vector<vector<int>> &persons) { return persons[a][b]; }

// Returns -1 if a 'potential celebrity' is not present.
// If present, returns id (value from 0 to n-1).
int findPotentialCelebrity(const vector<vector<int>> &persons, int n)
{
    // base case - when n reaches 0 , returns -1
    // since n represents the number of people,
    // 0 people implies no celebrity(= -1)
    if (n == 0)
        return -1;

    // find the celebrity with n-1
    // persons
    int id = findPotentialCelebrity(persons, n - 1);

    // if there are no celebrities
    if (id == -1)
        return n - 1;

    // if the id knows the nth person
    // then the id cannot be a celebrity, but nth person
    // could be one
    else if (knows(id, n - 1, persons))
    {
        return n - 1;
    }
    // if the nth person knows the id,
    // then the nth person cannot be a celebrity and the id
    // could be one
    else if (knows(n - 1, id, persons))
    {
        return id;
    }

    // if there is no celebrity
    return -1;
}

// Returns -1 if celebrity is not present.
// If present, returns id (value from 0 to n-1).

// a wrapper over findCelebrity
int Celebrity(const vector<vector<int>> &persons)
{
    // find the celebrity
    int n = persons.size();
    int id = findPotentialCelebrity(persons, n);

    // check if the celebrity found is really the celebrity
    if (id == -1)
        return id;
    else
    {
        int c1 = 0, c2 = 0;

        // check the id is really the
        // celebrity
        for (int i = 0; i < n; i++)
            if (i != id)
            {
                c1 += knows(id, i, persons);
                c2 += knows(i, id, persons);
            }

        // if the person is known to
        // everyone.
        if (c1 == 0 && c2 == n - 1)
            return id;

        return -1;
    }
} //time complexity O(N) space complexity O(N) for recursion overhead

//////////////////////////////////////////////////
//using stack
/*
Algorithm: 

1.Create a stack and push all the id’s in the stack.
2.Run a loop while there are more than 1 element in the stack.
3.Pop top two element from the stack (represent them as A and B)
4.If A knows B, then A can’t be a celebrity and push B in stack. 
    Else if A doesn’t know B, then B can’t be a celebrity push A in stack.
5.Assign the remaining element in the stack as the celebrity.
6.Run a loop from 0 to n-1 and find the count of persons who knows the celebrity 
    and the number of people whom the celebrity knows. if the count of persons who knows the celebrity 
    is n-1 and the count of people whom the celebrity knows is 0 
    then return the id of celebrity else return -1.
*/
int find_celebrity_stack(const vector<vector<int>> &persons)
{
    int n = persons.size();
    stack<int> stack;
    for (int i = 0; i < n; i++)
        stack.push(i);
    while (stack.size() > 1)
    {
        //pop two ids from the top of the stack
        int a = stack.top();
        stack.pop();
        int b = stack.top();
        stack.pop();
        // if a knows b then,a cant be a celebrity but b can be so push b in stack
        if (knows(a, b, persons))
            stack.push(b);
        // els if b knows a, b cant be a celebrity but a can be so push a in stack
        else if (knows(b, a, persons))
            stack.push(a);
    }
    if (stack.empty())
        return -1;
    //now we have a celebrity in our stack
    int potential_celebrity = stack.top();
    stack.pop();
    //checking if celebrity is really a celebrity or not
    for (int id = 0; id < n; id++)
    {
        if (id != potential_celebrity)
        {
            //if id does'nt know potential_celebrity or potential_celebrity knows id return -1
            //because potential_celebrity is violating the rule of being a celbrity
            if (!knows(id, potential_celebrity, persons) || knows(potential_celebrity, id, persons))
                return -1;
        }
    }
    //if above cases didnt return anything then potential_celebrity is the Celebrity
    return potential_celebrity;
} //time complexity is O(N) and space complexity O(N)

//////////////////////////////////////////////////////////////
/*two pointer approach: Approach: The idea is to use two pointers, one from start and one from the end. 
Assume the start person is A, and the end person is B. If A knows B, 
then A must not be the celebrity. Else, B must not be the celebrity. 
At the end of the loop, only one index will be left as a celebrity. 
Go through each person again and check whether this is the celebrity. 

we actually do the stack's work using two-pointer to reduce the space complexity*/
int find_celebrity_two_pointer(const vector<vector<int>> &persons)
{
    int n = persons.size();
    if (n == 0)
        return -1;
    int A = 0, B = n - 1;
    int potential_celebrity;
    while (A < B)
    {
        //if A knows B then A cant be a potential celebrity but B can be
        if (knows(A, B, persons))
        {
            A++;
        }
        //else if B knows A, then B cnat be a potential celebrity but A can be
        else if (knows(B, A, persons))
        {
            B--;
        }
        //else when both doesnt know each other no one can't be a potential celebrity
        else
            A++, B--;
    }
    potential_celebrity = A;
    //now check if the potential_celebrity is the Celebrity
    for (int id = 0; id < n; id++)
    {
        if (id != potential_celebrity)
        {
            if (!knows(id, potential_celebrity, persons) || knows(potential_celebrity, id, persons))
                return -1;
        }
    }
    return potential_celebrity;
}
int main()
{
    vector<vector<int>> persons = {{0, 0, 1, 0},
                                   {0, 0, 1, 0},
                                   {0, 0, 0, 0},
                                   {0, 0, 1, 0}};
    vector<vector<int>> persons2 = {{0, 1, 0},
                                    {0, 0, 0},
                                    {0, 1, 0}};
    vector<vector<int>> persons3 = {{0, 1},
                                    {1, 0}};
    cout << find_celebrity_two_pointer(persons3) << endl;
    return 0;
}