#include <bits/stdc++.h>
#include <vector>

#include "library.h"

using namespace std;

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 04-02-2021
 * 
 * Problem description: Solve the classical knapsack problem
 * 
 * 
 * In the main function the input is read and saved to data structures.
 * 
 * The function "knapsack" calculates the indexes of the items that will be packed int the sack
 * 
 * The result is then output by the main function. 
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    size_t capacity{}, nr_objects{};

    // While there are mor test cases
    while (cin >> capacity >> nr_objects)
    {

        // Read all objects and save them into the vector objects
        vector<knapsack::Item> objects{nr_objects};

        for (size_t i = 0; i < nr_objects; i++)
        {
            int weight, value;

            cin >> value >> weight;

            knapsack::Item current(weight, value);
            objects[i] = current;
        }

        // Calculate the needed indexes
        vector<int> res = knapsack::knapsack(capacity, objects);

        // Output the result
        cout << res.size() << endl;
        for (size_t i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
