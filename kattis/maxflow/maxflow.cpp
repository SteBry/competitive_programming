#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

#include "library.h"

using namespace std;

struct FlowEdge
{
    int from, to, amount;
};

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 03-03-2021
 *
 * Description: Given a graph find the maxflow and the edges used in it and output them
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nr_nodes, nr_edges, source_index, target_index;

    while (cin >> nr_nodes >> nr_edges >> source_index >> target_index)
    {
        // Construct graph of capacities
        // graph[i][j] is the capacity on the edge between node i and j
        vector<vector<int>> graph(nr_nodes, vector<int>(nr_nodes, 0));

        // Sre the nodes every node connects to, this is done to avoid looping over the whole graph
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

        vector<vector<int>> res = maxflow::max_flow(graph, adj, source_index, target_index);

        // Calculate output
        vector<FlowEdge> used_edges;
        int flow = 0;

        for (int i = 0; i < nr_nodes; i++)
        {
            for (int j = 0; j < nr_nodes; j++)
            {
                // Check if edge is used in maxflow
                if (graph[i][j] != 0 && res[i][j] != graph[i][j] && graph[i][j] - res[i][j] > 0)
                {
                    used_edges.push_back(FlowEdge{i, j, graph[i][j] - res[i][j]});

                    // Calculate the maxflow by checking the edges connected to the target node
                    if (j == target_index) //
                    {
                        flow += graph[i][j] - res[i][j];
                    }
                }
            }
        }

        // Output result
        cout << nr_nodes << " " << flow << " " << used_edges.size() << '\n';

        for (int i = 0; i < used_edges.size(); i++)
        {
            cout << used_edges[i].from << " " << used_edges[i].to << " " << used_edges[i].amount << '\n';
        }
    }

    return 0;
}
