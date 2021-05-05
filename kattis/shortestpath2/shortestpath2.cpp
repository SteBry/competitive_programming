#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>

#include "library.h"

using namespace std;

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 27-02-2021
 *
 * Gives a graph with edges that only can be used during specified time intervals, calculate 
 * the cost from starting node to each one and aswer queries about it 
 * 
 * Complexity:
 * The solution has the time complexity O(n^2) due to Dijkstra's algorithm for 
 * shortest path being used.The complexity comes from the fact that for each 
 * node the algorithm loops over all order to find the node closest to start 
 * node not yet explored (n^2). 
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nr_nodes, nr_edges, nr_queries, start_index;

    while (cin >> nr_nodes >> nr_edges >> nr_queries >> start_index && !(nr_nodes == 0 && nr_edges == 0 && nr_queries == 0 && start_index == 0))
    {
        shortestpath2::Graph graph(nr_nodes);

        // Read edges and construct graph
        int from_node, to_node, time, period, cost;

        for (int i = 0; i < nr_edges; i++)
        {
            cin >> from_node >> to_node >> time >> period >> cost;
            graph.set_weight(from_node, to_node, cost, time, period);
        }

        // Calculate distance and parent for each node
        vector<std::pair<int, int>> res = shortestpath2::shortest_path(graph, start_index);

        // Handle queries
        int goal_index;
        for (int i = 0; i < nr_queries; i++)
        {
            cin >> goal_index;

            // No solution found
            if (goal_index >= res.size() || res[goal_index].second == -1)
            {
                cout << "Impossible" << '\n';
            }

            //Solution found
            else
            {
                cout << res[goal_index].first << '\n';
            }
        }
    }

    return 0;
}
