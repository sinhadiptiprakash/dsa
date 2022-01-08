#include <bits/stdc++.h>
using namespace std;
//below is the approach using binary search watch take_u_forward
/*
intuition is similar to the aggresive cow problem: 
1.as we have to alocate at least one book to each student
we can allocate minimum the minimum element in the books array and at most we can allocate sum of the book array,
so our search space is within the min_of_array and the sum_of_array
2. within this seach space we will optimally generate a barrier upto which we can allocate pages to an individual student not beyond that
3. if by allocating at most this barrier no. of pages to each student we can allocate all the books to all the m student,
    we will decrease the barrier to minimize the ans
4. if by allocating at most this barrier no. of pages to each student,
    we end up with allocating all books to more than m no. of students, 
        now we need to increase this barrier because increasing this barrier allow us 
        to allocate more pages to individual student and we can allocate books to m students not more than m
            as barrier is inversely proportional to the no of student
5. continue above steps until the while loop of binary seach terminate
*/
//below is the function which checks wheather we can allocate all the books
//to all the m students with a certain barrier
bool is_possible_to_allocate(int barrier, int books[], int n, int students)
{
    int allocated = 0, pages = 0;
    for (int i = 0; i < n; i++)
    {
        // if adding the of curent books to the curent student we should allocate this book to the next student
        if (pages + books[i] > barrier)
        {
            allocated++;
            pages = books[i];
            if (pages > barrier)
                return false;
        }
        else //else we allocate this book to this stuent
            pages += books[i];
    }
    if (allocated < students)
        return true;
    return false;
}
int binary_search(int books[], int n, int students)
{
    if (students > n)
        return -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += books[i];
    int low = books[0], high = sum, mid;
    int ans = INT_MAX;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (is_possible_to_allocate(mid, books, n, students))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    int books[] = {15, 17, 20};
    int n = sizeof(books) / sizeof(int);
    int students = 2;
    cout << binary_search(books, n, students) << endl;
    return 0;
}