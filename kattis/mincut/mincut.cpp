#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

#include "library.h"

using namespace std;

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 03-03-2021
 *
 * Given a flow graph, find the minimum cut and output it
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nr_nodes, nr_edges, source_index, target_index;

    cin >> nr_nodes >> nr_edges >> source_index >> target_index;

    // Construct graph of capacities
    // graph[i][j] is the capacity on the edge between node i and j
    vector<vector<int>>
        graph(nr_nodes, vector<int>(nr_nodes, 0));

    // Store the nodes every node connects to, this is done to avoid looping over the whole graph
    vector<vector<int>> adj(nr_nodes, vector<int>());

    int from_node, to_node, capacity;
    for (int i = 0; i < nr_edges; i++)
    {
        cin >> from_node >> to_node >> capacity;

        if (from_node != to_node)
        {
            graph[from_node][to_node] = graph[from_node][to_node] + capacity;
            adj[from_node].push_back(to_node);
            adj[to_node].push_back(from_node);
        }
    }

    // Calculate the result
    vector<int> res = mincut::min_cut(graph, adj, source_index, target_index);

    // Output result
    cout << res.size() << '\n';

    // Output largest to smallest index
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << '\n';
    }

    return 0;
}
