#include <set>
#include <algorithm>
#include <vector>
#include "library.h"

/**
 * @author Stefan brynielsson
 * This File contains the implementations of reusable functions and classes specified in library.h 
 **/

using namespace std;

bool intervalcover::Interval::operator<(const Interval &other) const
{
    return start < other.start;
}

intervalcover::Interval::Interval(double start, double end, int index) : start{start}, end{end}, index{index} {}

intervalcover::Interval::Interval() {}

vector<int> intervalcover::cover(Interval interval, vector<Interval> &intervals)
{
    vector<int> result{};
    double current = interval.start;
    Interval best{};

    sort(intervals.begin(), intervals.end());

    auto it = intervals.begin();
    bool updated = true;

    // Find the indexes of intervals needed
    do
    {
        // Exit if it is not possible to cover the whole interval
        // (all intervals have been processed and the goal havn't been reached)
        if (it == intervals.end() || !updated)
        {
            return vector<int>{};
        }
        updated = false;

        // Find the interval that covers the largest distance
        // (each interval in interval is only processed once since the iterator "it" is precerved between
        // each while loop)
        for (; it < intervals.end() && it->start <= current; it++)
        {
            if (it->end >= current)
            {
                if (it->end - current > best.end - current)
                {
                    updated = true;
                    best = *it;
                }
            }
        }

        result.push_back(best.index);
        current = best.end;

    } while (current < interval.end);

    // Return the indexes if a intervals was found otherwise this return is not reached
    return result;
}

vector<int> knapsack::knapsack(int capacity, vector<Item> items)
{
    // The maximum value for the items 0..i given the maximum capacity w is stored at the position [i+1][w]
    vector<vector<int>> df(items.size() + 1, vector<int>(capacity + 1));

    // Fill the vector df
    for (size_t item_index = 0; item_index <= items.size(); item_index++)
    {
        for (int weight_index = 0; weight_index <= capacity; weight_index++)
        {
            // The first coumn and row will always be 0
            if (item_index == 0 || weight_index == 0)
            {
                df[item_index][weight_index] = 0;
            }
            // If the maximum weight for the earier item not reached, choos wheather or not to include the previus item in the knapsack
            else if (items[item_index - 1].weight <= weight_index)
            {
                int last_included = items[item_index - 1].value + df[item_index - 1][weight_index - items[item_index - 1].weight];
                int last_excluded = df[item_index - 1][weight_index];
                df[item_index][weight_index] = max(last_included, last_excluded);
            }
            // If the weight is to large, do not include last item
            else
            {
                df[item_index][weight_index] = df[item_index - 1][weight_index];
            }
        }
    }

    // Backtrack and calculate the included indexes
    vector<int> res{};
    int max_w = capacity;

    for (size_t i = items.size(); i > 0; i--)
    {
        int current = df[i][max_w];
        int last = df[i - 1][max_w];
        if (current != last)
        {
            res.push_back(i - 1);
            max_w -= items[i - 1].weight;
        }
    }

    return res;
}