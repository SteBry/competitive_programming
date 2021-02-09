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

namespace unionfind
{
    /**
     * Represents a Disjoint set union
     * implementation is based on: https://cp-algorithms.com/data_structures/disjoint_set_union.html
     **/
    struct DSU
    {

        /**
         * Construct an Disjoint set union with the elements 0,...,nr_elements-1
         * 
         * @param nr_elements the amount of elements the DSU will contain
         **/
        DSU(int nr_elements);

        /**
         * Find the representative value of the set that contains v
         * 
         * @param v the value we want to find the representation of
         * @return the value that represents the set that contains v 
         **/
        int find_set(int v);

        /**
         * Merge the set in which a and b is located
         * 
         * @param a a value in one of the sets to be merged
         * @param b a value in one of the sets to be merged
         **/
        void union_set(int a, int b);

    private:
        std::vector<int> parent;
        std::vector<int> rank;
    };
} // namespace unionfind

namespace fenwick
{

    class FenwickTree
    {
    private:
        std::vector<long long> tree;
        long long MaxIdx;

    public:
        /**
         * Construct a Fenwick tree of length n with every value initialized to 0
         * 
         * @param n The size of the tree
         **/
        FenwickTree(long long n);

        /**
         * Construct a Fenwick tree of length n with values initialized to arr. 
         * 
         * It is assumed that n is the length of arr
         * 
         * @param arr array of inital values for eah element in the tree
         * @param n The size of the tree
         **/
        FenwickTree(std::vector<long long> arr);

        /**
         * Calculates the cumulative sum of index 0...idx-1. 
         *  
         * Time complexity: O(nlog(n))
         * 
         * @param n The size of the tree
         **/
        long long sum(long long idx);

        /**
         * Add the value delta to the value at index idx. 
         *  
         * Time complexity: O(nlog(n))
         * 
         * @param idx The index to update
         * @param delta the amount to chenge tthe value at index idx
         **/
        void add(long long idx, long long delta);
    };

} // namespace fenwick

#endif /* MY_LIBRARY*/