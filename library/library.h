#include <set>
#include <algorithm>
#include <vector>
#include <iostream>
#include <complex>

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

namespace shortestpath1
{

    /**
     * A graph represented as a adjacency matrix
     **/
    struct Graph
    {
        std::vector<std::vector<std::pair<int, int>>> edges;

        Graph(int nr_nodes) : edges(nr_nodes, std::vector<std::pair<int, int>>()){};

        /**
         * Add a directed edge between from -> to with the weight cost 
         * 
         * @param from The index of the node where the edge start
         * @param to The index of the node where the edge end
         * @param cost The cost of traversing the edge
         **/
        void set_weight(int from, int to, int cost);
    };

    /**
     * Find the parrent of the shortest path to node i from start node using dijkstras algorithm.
     * based on https://cp-algorithms.com/graph/dijkstra.html
     * 
     * @param graph the graph
     * @param start_node the index the search start at
     * @return a vector of pairs with the cost and parent to each node 
     **/
    std::vector<std::pair<int, int>> shortest_path(Graph &graph, int start_node);

    /**
     * Find the parrent of the shortest path to node i from start node using dijkstras algorithm for sparse graphs.
     * based on https://cp-algorithms.com/graph/dijkstra_sparse.html
     * 
     * @param graph the graph
     * @param start_node the index the search start at
     * @return a vector of pairs with the cost and parent to each node 
     **/
    std::vector<std::pair<int, int>> sparse_shortest_path(Graph &graph, int start_node);
}

namespace shortestpath2
{
    struct PeriodicEdge
    {
        // Note , cost==-1 means that the edge is not traversable
        int start_time{0}, period{0}, cost{-1};

        /**
         * Given a timepoint return the next timepoint the edge is usable (-1 if none exists)
         * @param time the timepoint
         **/
        int next_period_time(int time);
    };

    /**
     * A graph represented as a adjacency matrix, the edges are only usable during certain time intervals
     **/
    struct Graph
    {
        std::vector<std::vector<std::pair<int, PeriodicEdge>>> edges;

        Graph(int nr_nodes) : edges(nr_nodes, std::vector<std::pair<int, PeriodicEdge>>()){};

        /**
         * Add a directed edge between "from" -> "to" with a cost, a time is start being usable and the periods it is usable 
         * 
         * @param from The index of the node where the edge start
         * @param to The index of the node where the edge end
         * @param cost The cost of traversing the edge
         * @param start_time The first timepoint the edge is usable
         * @param period The interval between each useable timepoint
         **/
        void set_weight(int from, int to, int cost, int start_time, int period);
    };

    /**
     * Find the parrent of the shortest path to node i from start node using dijkstras algorithm.
     * based on https://cp-algorithms.com/graph/dijkstra.html
     * 
     * @param graph the graph
     * @param start_node the index the search start at
     * @return a vector of pairs with the cost and parent to each node 
     **/
    std::vector<std::pair<int, int>> shortest_path(Graph &graph, int start_node);
}

namespace shortestpath3
{ /**
     * Find the parrent of the shortest path to node i from start node, handles negative edges
     *  Based on: 
     * https://cp-algorithms.com/graph/bellman_ford.html
     * https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
     * 
     * 
     * @param graph the graph
     * @return a 2d vector[i][j] with the distance between node i, j
     **/
    std::vector<std::pair<int, int>> shortest_path(shortestpath1::Graph &graph, int start_node);
}

namespace allpairspath

{
    /**
     * Find the shortest distance between all pairs of nodes in agraph
     * Based on:
     * https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
     * https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/ 
     * 
     * 
     * @param graph the graph
     * @param start_node the index the search start at
     * @return a vector of pairs with the cost and parent to each node 
     **/
    std::vector<std::vector<long long>> shortest_path(shortestpath1::Graph &graph);
}

namespace minspantree
{
    struct Edge
    {
        int u, v, weight;
        bool operator<(Edge const &other)
        {
            return weight < other.weight;
        }
    };

    /**
     * Find the minimum spanning tree of a graph given as a list of edges
     * Based on:
     * https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html 
     * 
     * @param edges the edges in the graph
     * @param nr_nodes the number of nodes in the graph
     * @return the edges that is part of the mst, will have size=nr_nodes-1 if there was a mst found.
     **/
    std::vector<Edge> mst(std::vector<Edge> &edges, int nr_node);
}

#endif /* MY_LIBRARY*/