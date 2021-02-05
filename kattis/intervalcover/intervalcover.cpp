#include <bits/stdc++.h>
#include <iostream>
#include "library.h"
#include <vector>

using namespace std;
using namespace intervalcover;

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 02-02-2021
 * 
 * Problem description: Implement a function that given a set of intervals and a target
 * interval returns the smallest number of intervals required to cover the target interval
 * and the incexes of the intervals.
 * 
 * An interval is a pair of real numbers. 
 * 
 * In the main function the input is read and saved to data structures.
 * 
 * The function "cover" the calculates the indexes if the intervals needed to cover the target interval, 
 * an empty vector is returned if it is impossible to cover the target interval
 * 
 * The result is then output. 
 * */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double start{}, end{};

    // While there are more test cases
    while (cin >> start >> end)
    {
        Interval goal{start, end, -1};
        int nr_intervals{};
        vector<Interval> intervals{};

        //Read the data for a testcase
        cin >> nr_intervals;
        for (int i = 0; i < nr_intervals; i++)
        {
            double current_start{}, current_end{};
            cin >> current_start >> current_end;

            intervals.push_back(Interval{current_start, current_end, i});
        }

        // Calculate the indexes of the intervals needed to cover the interval
        vector<int> res = cover(goal, intervals);

        // Output he result
        if (res.size() > 0)
        {
            cout << res.size() << endl;

            for (size_t i = 0; i < (res.size() - 1); i++)
            {
                cout << res[i] << " ";
            }
            cout << res[res.size() - 1] << endl;
        }
        else
        {
            cout << "impossible" << endl;
        }
    }

    return 0;
}
