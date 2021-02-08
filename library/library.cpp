#include <set>
#include <algorithm>
#include <vector>
#include "library.h"
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>

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

// Based on pseudo code from, contains some modifications: https://en.wikipedia.org/wiki/Longest_increasing_subsequence
vector<int> longincsubseq::lis(vector<int> sequence)
{
    // predecessor_index[i] Stores the index of the predecessor
    // of sequence[i] in the longest increasing index ending at sequence[i]
    vector<int> predecessor_index(sequence.size());

    // Stores the value index_of_sseq_with_len[i]=j such that sequence[k] is the smallest value where there is a increasing
    // subsequence of length j ending at sequence[k]. This means that the last index of the longest
    // increasing subsequence when the algorithm has finished will be index_of_sseq_with_len[longest].
    vector<int> index_of_sseq_with_len(sequence.size() + 1);

    // The length of the longest subseq found
    int longest = 0;

    // Process each value in the sequence and store the best subsequence found so far.
    for (size_t i = 0; i < sequence.size(); i++)
    {
        int low = 1;
        int high = longest;

        // Binary search for the largest positive low ≤ longest
        // such that sequence[index_of_sseq_with_len[low]] <= sequence[i]
        while (low <= high)
        {
            int mid = ceil((low + high) / 2);
            if (sequence[index_of_sseq_with_len[mid]] < sequence[i])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        // update values
        predecessor_index[i] = index_of_sseq_with_len[low - 1];
        index_of_sseq_with_len[low] = i;

        if (low > longest)
        {
            longest = low;
        }
    }

    // Backtrack and calculate result
    vector<int> res(longest);
    int k = index_of_sseq_with_len[longest];

    for (int i = longest - 1; i >= 0; i--)
    {
        res[i] = k;
        k = predecessor_index[k];
    }

    return res;
}

unionfind::DSU::DSU(int nr_elements)
{
    parent = vector<int>(nr_elements);
    rank = vector<int>(nr_elements);
    iota(parent.begin(), parent.end(), 0);
}

int unionfind::DSU::find_set(int v)
{
    // Base case, root found
    if (v == parent[v])
    {
        return v;
    }

    // Otherwise recursively search for representation, and compress path
    parent[v] = find_set(parent[v]);
    return parent[v];
}

void unionfind::DSU::union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    // if a and b belongs to different trees, merge the trees
    if (a != b)
    {
        if (rank[a] < rank[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

fenwick::FenwickTree::FenwickTree(long long n)
{
    tree = vector<long long>(n + 1);
    MaxIdx = n;
}

fenwick::FenwickTree::FenwickTree(vector<long long> arr) : FenwickTree(arr.size())
{
    for (long long i = 0; i < arr.size(); i++)
        add(i, arr[i]);
}

long long fenwick::FenwickTree::sum(long long idx)
{
    idx += 1;
    long long res = 0;
    while (idx > 0)
    {
        res += tree[idx];
        idx -= (idx & (-idx));
    }
    return res;
}

void fenwick::FenwickTree::add(long long idx, long long val)
{
    idx += 1;
    while (idx <= MaxIdx)
    {
        tree[idx] += val;
        idx += (idx & (-idx));
    }
}
