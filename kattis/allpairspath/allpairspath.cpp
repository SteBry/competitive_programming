#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>

#include "library.h"

using namespace std;

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 28-02-2021
 *
 * Description: Find the shortest path between each pair of nodes in a graph
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nr_nodes, nr_edges, nr_queries;

    while (cin >> nr_nodes >> nr_edges >> nr_queries && !(nr_nodes == 0 && nr_edges == 0 && nr_queries == 0))
    {
        // Read input and construct graph
        shortestpath1::Graph graph(nr_nodes);
        int from_node, to_node, weight;
        for (int i = 0; i < nr_edges; i++)
        {
            cin >> from_node >> to_node >> weight;
            graph.set_weight(from_node, to_node, weight);
        }

        // Find the shortest paths for each pair of nodes
        vector<vector<long long>> res = allpairspath::shortest_path(graph);

        // Handle Queries
        int start_index, goal_index;
        for (int i = 0; i < nr_queries; i++)
        {
            cin >> start_index >> goal_index;

            // No solution found
            if (res[start_index][goal_index] == LONG_LONG_MAX)
            {
                cout << "Impossible" << '\n';
            }

            // Path part of an infinite cycle
            else if (res[start_index][goal_index] == LONG_LONG_MIN)
            {
                cout << "-Infinity" << '\n';
            }

            //Solution found
            else
            {
                cout << res[start_index][goal_index] << '\n';
            }
        }
        cout << '\n';
    }

    return 0;
}
