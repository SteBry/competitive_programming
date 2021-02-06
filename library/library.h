#include <set>
#include <algorithm>
#include <vector>
#include <iostream>

#ifndef MY_LIBRARY
#define MY_LIBRARY

/**
 * @author Stefan brynielsson
 * This File contains the defenitions of reusable functions and classes, they are impelented i library.cpp
 **/

namespace intervalcover
{
    /**
     * Struct that represents an interval with a start and end value
     **/
    struct Interval
    {
        double start{};
        double end{};
        int index{};

        // Counstruct a interval
        Interval(double start, double end, int index);
        Interval();

        // Comparator, compares the start of Intervals
        bool operator<(const Interval &other) const;
    };

    /**
     * Given a target interval and a set of intervals
     *  returns the indexes of the intervals that results in the smallest number of intervals 
     *  required to cover the target interval. 
     *  An interval is a pair of real numbers.
     * 
     *  It is assumed that intervals has a size larger then 0.
     * 
     * @param interval the target interval
     * @param intervals the available intervals, must be larger then 0
     * @return the indexes of the minimal number of intervals in intervals that together covers the target interval, 
     * the length of the vector is 0 if not no such exists
     **/
    std::vector<int> cover(Interval interval, std::vector<Interval> &intervals);

} // namespace intervalcover

namespace knapsack
{
    /**
     *  Struct that represents an Item that can be packed into the "Knapsack"
     *  Has a Value and a weight
     **/
    struct Item
    {
        int weight{};
        int value{};
        Item(int weight, int value) : weight{weight}, value{value} {}
        Item() {}
    };

    /**
     *  Given that the knapsack can contain a maximum capacity return the indices of the items 
     *  in items that result in the highest value and fit into the knapsak
     * 
     * @param capacity the maximum weight the knapsack can contain
     * @param items the items that can be packed into the knapsack
     * @return the indices of the items in items that should be packed int the knapsack
     **/
    std::vector<int> knapsack(int capacity, std::vector<Item> items);
} // namespace knapsack

namespace longincsubseq
{

    /**
     * Given a sequence return the indices of the longest increasing sequence
     * in the sequence
     * 
     * Time complexity: O(nlog(n))
     * 
     * @param sequence the maximum weight the knapsack can contain
     * @return the indices of values that is part of the longest increasing sequence
     **/
    std::vector<int> lis(std::vector<int> sequence);
} // namespace longincsubseq

#endif /* MY_LIBRARY*/