#include <set>
#include <algorithm>
#include <vector>
#include "library.h"
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <limits.h>
#include <queue>

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

intervalcover::Interval::Interval() : Interval{0, 0, -1} {}

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
                if (it->end - current > best.end - current || !updated)
                {
                    updated = true;
                    best = *it;
                }
            }
        }

        if (updated)
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
            // If the maximum weight for the earier item not reached, choose wheather or not to include the previus item in the knapsack
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

void shortestpath1::Graph::set_weight(int from, int to, int cost)
{
    edges[from].push_back(make_pair(to, cost));
}

vector<pair<int, int>> shortestpath1::shortest_path(Graph &graph, int start_node)
{
    int graph_size = graph.edges.size();

    // The output array, each index will contain the distance to it and the parent node on the shortest path
    // A node that do not have any path will have the parent -1, the start node will have itself as parent
    vector<pair<int, int>> dist_parent = vector<pair<int, int>>(graph_size, make_pair(INT_MAX, -1));

    // explored[i] will be true if node i has been explored
    vector<bool> explored(graph_size, false);

    // Distance of source vertex from itself is always 0 and the parrent is itself
    dist_parent[start_node].first = 0;
    dist_parent[start_node].second = start_node;

    // Find shortest path for all nodes
    for (int count = 0; count < graph_size - 1; count++)
    {
        // Find the node closest to start_node not yet explored
        int min{INT_MAX}, min_index;
        int u;

        for (int v = 0; v < graph_size; v++)
        {
            if (explored[v] == false && dist_parent[v].first <= min)
            {
                min = dist_parent[v].first,
                u = v;
            }
        }

        // Exit if an unreachable node is being processed
        if (dist_parent[u].first == INT_MAX)
            break;

        // Mark the found node as explored
        explored[u] = true;

        // Update distance and parrent of the neighbours of the picked node if a new shortest path is found.
        for (pair<int, int> edge : graph.edges[u])
        {
            if (dist_parent[u].first + edge.second < dist_parent[edge.first].first)
            {
                dist_parent[edge.first].first = dist_parent[u].first + edge.second;
                dist_parent[edge.first].second = u;
            }
        }
    }

    return dist_parent;
}

std::vector<std::pair<int, int>> shortestpath1::sparse_shortest_path(Graph &graph, int start_node)
{
    int graph_size = graph.edges.size();

    // The output array, each index will contain the distance to it and the parent node on the shortest path
    // A node that do not have any path will have the parent -1, the start node will have itself as parent
    vector<pair<int, int>> dist_parent = vector<pair<int, int>>(graph_size, make_pair(INT_MAX, -1));

    // Distance of source vertex from itself is always 0 and the parrent is itself
    dist_parent[start_node].first = 0;
    dist_parent[start_node].second = start_node;

    using pii = pair<int, int>;

    // unexplored edges
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, start_node});

    // While there are more unexplored nodes that is reachable from the start node
    while (!q.empty())
    {

        // Retrieve the best node
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();

        if (d_v != dist_parent[v].first)
            continue;

        // Explore neighbouring edges
        for (pair<int, int> edge : graph.edges[v])
        {
            int to = edge.first;
            int len = edge.second;

            if (dist_parent[v].first + len < dist_parent[to].first)
            {
                dist_parent[to].first = dist_parent[v].first + len;
                dist_parent[to].second = v;
                q.push({dist_parent[to].first, to});
            }
        }
    }
    return dist_parent;
}

void shortestpath2::Graph::set_weight(int from, int to, int cost, int start_time, int period)
{
    PeriodicEdge p;
    p.cost = cost;
    p.start_time = start_time;
    p.period = period;
    edges[from].push_back(make_pair(to, p));
}

vector<pair<int, int>> shortestpath2::shortest_path(Graph &graph, int start_node)
{
    int graph_size = graph.edges.size();

    // The output array, each index will contain the distance to it and the parent node on the shortest path
    // A node that do not have any path will have the parent -1, the start node will have itself as parent
    vector<pair<int, int>> dist_parent = vector<pair<int, int>>(graph_size, make_pair(INT_MAX, -1));

    // explored[i] will be true if node i has been explored
    vector<bool> explored(graph_size, false);

    // Distance of source vertex from itself is always 0 and the parrent is itself
    dist_parent[start_node].first = 0;
    dist_parent[start_node].second = start_node;

    // Find shortest path for all nodes
    for (int count = 0; count < graph_size - 1; count++)
    {
        // Find the node closest to start_node not yet explored
        int min{INT_MAX}, min_index;
        int u;

        for (int v = 0; v < graph_size; v++)
        {
            if (explored[v] == false && dist_parent[v].first <= min)
            {
                min = dist_parent[v].first,
                u = v;
            }
        }

        // Exit if an unreachable node is being processed
        if (dist_parent[u].first == INT_MAX)
            break;

        // Mark the found node as explored
        explored[u] = true;

        // Update distance and parrent of the neighbours of the picked node if a new shortest path is found.
        for (pair<int, PeriodicEdge> parent_edge : graph.edges[u])
        {
            int current_cost = dist_parent[u].first;

            // If edge is not traversable;
            if (parent_edge.second.cost == -1 || parent_edge.second.next_period_time(current_cost) == -1)
                continue;

            if (parent_edge.second.next_period_time(current_cost) + parent_edge.second.cost < dist_parent[parent_edge.first].first)
            {
                dist_parent[parent_edge.first].first = parent_edge.second.next_period_time(current_cost) + parent_edge.second.cost;
                dist_parent[parent_edge.first].second = u;
            }
        }
    }

    return dist_parent;
}

int shortestpath2::PeriodicEdge::next_period_time(int time)
{
    if (time <= start_time)
    {
        return start_time;
    }

    if (period == 0)
    {
        return -1;
    }
    return start_time + ceil(((double)(time - start_time) / period)) * period;
}

vector<pair<int, int>> shortestpath3::shortest_path(shortestpath1::Graph &graph, int start_node)
{
    int graph_size = graph.edges.size();

    // The output array, each index will contain the distance to it and the parent node on the shortest path
    // A node that do not have any path will have the parent -1, the start node will have itself as parent
    vector<pair<int, int>> dist_parent = vector<pair<int, int>>(graph_size, make_pair(INT_MAX, -1));

    // Distance of source vertex from itself is always 0 and the parrent is itself
    dist_parent[start_node].first = 0;
    dist_parent[start_node].second = start_node;

    int x;

    // Find shortest distance to each node
    for (int i = 0; i < graph_size; ++i)
    {
        //Loop over all edges
        for (int j = 0; j < graph_size; j++)
        {
            for (pair<int, int> edge : graph.edges[j])
            {
                int src = j;
                int dest = edge.first;
                int weight = edge.second;

                if (dist_parent[j].first < INT_MAX && dist_parent[dest].first > dist_parent[src].first + weight)
                {
                    dist_parent[edge.first].first = max(INT_MIN, dist_parent[j].first + edge.second);
                    dist_parent[edge.first].second = j;
                }
            }
        }
    }

    //Loop over all edges graph_size times inorder to calculate all infinite costs
    for (int a = 0; a < graph_size; a++)
    {
        // Loop over edges
        for (int j = 0; j < graph_size; j++)
        {
            for (pair<int, int> edge : graph.edges[j])
            {
                int src = j;
                int dest = edge.first;
                int weight = edge.second;

                // All neightbours also have a infinite negative cost if src have it
                if (dist_parent[src].first == INT_MIN)
                {
                    dist_parent[dest].first = INT_MIN;
                }

                // If a lower cost is found, there is a negative loop
                else if (dist_parent[src].first != INT_MAX && dist_parent[src].first + weight < dist_parent[dest].first)
                {
                    dist_parent[dest].first = INT_MIN;
                }
            }
        }
    }

    return dist_parent;
}

vector<vector<long long>> allpairspath::shortest_path(shortestpath1::Graph &graph)
{

    vector<vector<long long>> distances(graph.edges.size(), vector<long long>(graph.edges.size(), LONG_LONG_MAX));

    // Init distances based on graph
    for (int i = 0; i < graph.edges.size(); i++)
    {
        for (pair<int, int> edge : graph.edges[i])
        {
            distances[i][edge.first] = min((long long)edge.second, distances[i][edge.first]);
        }
        distances[i][i] = min((long long)0, distances[i][i]);
    }

    // update distances
    for (int k = 0; k < distances.size(); ++k)
    {
        for (int i = 0; i < distances.size(); ++i)
        {
            for (int j = 0; j < distances.size(); ++j)
            {
                if (distances[i][k] < LONG_LONG_MAX && distances[k][j] < LONG_LONG_MAX)
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }

    // Find negative cycles
    for (int i = 0; i < distances.size(); ++i)
    {
        for (int j = 0; j < distances.size(); ++j)
        {
            for (int t = 0; t < distances.size(); ++t)
            {
                if (distances[i][t] < LONG_LONG_MAX && distances[t][t] < 0 && distances[t][j] < LONG_LONG_MAX)
                    distances[i][j] = LONG_LONG_MIN;
            }
        }
    }

    return distances;
}

vector<minspantree::Edge> minspantree::mst(vector<minspantree::Edge> &edges, int nr_nodes)
{

    unionfind::DSU dsu(nr_nodes);
    vector<Edge> result;

    sort(edges.begin(), edges.end());

    for (Edge e : edges)
    {
        if (dsu.find_set(e.u) != dsu.find_set(e.v))
        {
            result.push_back(e);
            dsu.union_set(e.u, e.v);
        }
    }

    // Sort result in lexicographically order
    sort(result.begin(), result.end(), [](minspantree::Edge lhs, minspantree::Edge rhs) {
        if (lhs.u == rhs.u)
        {
            return lhs.v < rhs.v;
        }
        return lhs.u < rhs.u;
    });

    return result;
}

std::vector<int> maxflow::bfs(vector<vector<int>> &r_graph, vector<vector<int>> &adj, int start, int goal)
{
    vector<bool> visited(r_graph.size(), false);
    vector<int> parent(r_graph.size(), -1);

    // Create a queue, enqueue source vertex and mark start vertex as visited
    queue<int> q;
    q.push(start);
    visited[start] = true;

    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v] == false && r_graph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // If we reached goal in BFS starting from source, then return parent else return a empty vector
    return (visited[goal] == true) ? parent : vector<int>();
}

vector<vector<int>> maxflow::max_flow(vector<vector<int>> graph, vector<vector<int>> &adj, int s, int t)
{

    int u, v;
    int nr_nodes = graph.size();

    // While thera are a path with available capacity
    vector<int> parent = bfs(graph, adj, s, t);

    while (parent.size() != 0)
    {
        // Find the most restricive part of the found path
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, graph[u][v]);
        }

        // Update residual graph based on the most restrictive part
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
        }

        parent = bfs(graph, adj, s, t);
    }

    // Return the overall flow
    return graph;
}

void mincut::dfs(vector<vector<int>> &r_graph, int s, vector<bool> &visited)
{
    visited[s] = true;
    for (int i = 0; i < r_graph.size(); i++)
        if (r_graph[s][i] && !visited[i])
            dfs(r_graph, i, visited);
}

vector<int> mincut::min_cut(vector<vector<int>> &graph, vector<vector<int>> &adj, int s, int t)
{

    vector<vector<int>> r_graph = maxflow::max_flow(graph, adj, s, t);

    vector<bool> visited(graph.size(), false);

    dfs(r_graph, s, visited);

    vector<int> res;
    for (size_t i = 0; i < graph.size(); i++)
    {
        if (visited[i])
        {
            res.push_back(i);
        }
    }

    return res;
}