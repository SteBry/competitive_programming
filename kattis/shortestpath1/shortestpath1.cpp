#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

#include "library.h"

using namespace std;

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 04-02-2021
 *
 * Description: Given a graph and the starting node, answer queries about the distance to other nodes.
 * 
 * Complexity:
 * The solution has the time complexity O(n^2) due to Dijkstra's algorithm for 
 * shortest path being used.The complexity comes from the fact that for each 
 * node the algorithm loops over all order to find the node closest to start 
 * node not yet explored (n^2). 
 **/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nr_nodes, nr_edges, nr_queries, start_index;

    while (cin >> nr_nodes >> nr_edges >> nr_queries >> start_index && !(nr_nodes == 0 && nr_edges == 0 && nr_queries == 0 && start_index == 0))
    {
        shortestpath1::Graph graph(nr_nodes);

        int to, from, weight;

        // Build Graph
        for (int i = 0; i < nr_edges; i++)
        {
            cin >> from >> to >> weight;
            graph.set_weight(from, to, weight);
        }

        // Calculate distanses based on if it is a sparse graph or not
        vector<pair<int, int>> res;
        if (nr_edges > nr_nodes / 2)
        {
            res = shortestpath1::sparse_shortest_path(graph, start_index);
        }
        else
        {
            res = shortestpath1::shortest_path(graph, start_index);
        }

        // Handle queries
        int goal_index;
        for (int i = 0; i < nr_queries; i++)
        {
            cin >> goal_index;
            if (goal_index >= res.size() || res[goal_index].second == -1)
            {
                cout << "Impossible" << '\n';
            }
            else
            {
                cout << res[goal_index].first << '\n';
            }
        }
    }

    return 0;
}
