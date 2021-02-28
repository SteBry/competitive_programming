#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

#include "library.h"

using namespace std;

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 28-02-2021
 *
 * Description: Find the shortest path to each node in a graph (given starting node)
 * where edges can have negaitve costs.
 **/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nr_nodes, nr_edges, nr_queries, start_index;

    while (cin >> nr_nodes >> nr_edges >> nr_queries >> start_index && !(nr_nodes == 0 && nr_edges == 0 && nr_queries == 0 && start_index == 0))
    {
        // Read input and costruct graph based on it
        shortestpath1::Graph graph(nr_nodes);

        int from_node, to_node, weight;
        for (int i = 0; i < nr_edges; i++)
        {
            cin >> from_node >> to_node >> weight;
            graph.set_weight(from_node, to_node, weight);
        }

        // Calculate Chortest paths
        vector<pair<int, int>> res = shortestpath3::shortest_path(graph, start_index);

        // Handle Queries
        int goal_index;
        for (int i = 0; i < nr_queries; i++)
        {
            cin >> goal_index;

            // No solution found
            if (goal_index >= res.size() || res[goal_index].second == -1)
            {
                cout << "Impossible" << '\n';
            }
            else if (res[goal_index].first == INT_MIN)
            {
                cout << "-Infinity" << '\n';
            }
            //Solution found
            else
            {
                cout << res[goal_index].first << '\n';
            }
        }
    }

    // Insert code here

    return 0;
}
