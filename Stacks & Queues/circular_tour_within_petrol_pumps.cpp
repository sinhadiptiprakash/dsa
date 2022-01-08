#include <bits/stdc++.h>
using namespace std;
//watch tech dose videofor better understanding
struct PetrolPump
{
    int petrol;
    int distance;
};
int circular_tour(PetrolPump arr[], int n)
{
    int start;

    for (int i = 0; i < n; i++)
    {
        // Identify the first petrol pump from where we
        // might get a full circular tour
        if (arr[i].petrol >= arr[i].distance)
        {
            start = i;
            break;
        }
    }

    // To store the excess petrol
    int curr_petrol = 0;

    int i;

    for (i = start; i < n;)
    {

        curr_petrol += (arr[i].petrol - arr[i].distance);

        // If at any point remaining petrol is less than 0,
        // it means that we cannot start our journey from
        // current start
        if (curr_petrol < 0)
        {

            // We move to the next petrol pump
            i++;

            // We try to identify the next petrol pump from
            // where we might get a full circular tour
            for (; i < n; i++)
            {
                if (arr[i].petrol >= arr[i].distance)
                {

                    start = i;

                    // Reset rem_petrol
                    curr_petrol = 0;

                    break;
                }
            }
        }

        else
        {
            // Move to the next petrolpump if curr_petrol is
            // >= 0
            i++;
        }
    }

    // If remaining petrol is less than 0 while we reach the
    // first petrol pump, it means no circular tour is
    // possible
    if (curr_petrol < 0)
    {
        return -1;
    }

    for (int j = 0; j < start; j++)
    {

        curr_petrol += (arr[j].petrol - arr[j].distance);

        // If remaining petrol is less than 0 at any point
        // before we reach initial start, it means no
        // circular tour is possibl
        if (curr_petrol < 0)
        {
            return -1;
        }
    }

    // If we have successfully reached intial_start, it
    // means can get a circular tour from final_start, hence
    // return it
    return start;
} // time complexity O(N) space complexity O(1)

// we can further improve the time complexity of O(N) by removing some redundant calculations
// NOTE: suppose we have started our tour from start and after reaching some other petrol pump let us at y
// now if at this y petrol pump we have petrol less than 0 t
// then it is sure that petrol pumps between start and y, so we start our circular tour from y+1
// now suppose starting circular tour from this start lead us to a successful circular tour,
// then after reaching the end from this start we need again traverse from 0 to the last index where we found our curent_petrol less than 0
//which is redundand and inefficient, so if we store the sum of the total petrol from 0 to the last index where we found curent_petrol less than 0
//we can optimize our code
int circular_tour_efficient(PetrolPump array[], int n)
{
    if (n == 1)
        return array[0].petrol - array[0].distance >= 0 ? 0 : -1;

    int start = 0;
    //sum is for storing the curent left petrol
    int sum = 0;
    //diff is for storing the sum of left petrols from 0 to the curent index when we have petrol less than 0 at curent index
    int diff = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + array[i].petrol - array[i].distance;
        //if we cant reach the next petrol pump
        if (sum < 0)
        {
            //we start our tour from the next pump
            start = i + 1;
            //we sore the curent sum from 0 to this start for avoiding redundant calculations
            diff += sum;
            // as we are starting a new circular tour from this curent index we make the sum=0
            sum = 0;
        }
    }
    // now here we use the previously stored diff
    // if after reaching end from any starting index we can reach index before the starting index from 0 return start
    if (sum + diff >= 0)
        return start;
    return -1;
}

int main()
{
    PetrolPump p[4];
    for (int i = 0; i < 4; i++)
        cin >> p[i].petrol >> p[i].distance;
    cout << circular_tour(p, 4) << endl;
    return 0;
}