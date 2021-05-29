#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#include <limits.h>

#include "library.h"

using namespace std;

bool Compare(pair<long double, int> a, pair<long double, int> b)
{
    return a.first < b.first;
}

struct Graph
{
    vector<vector<pair<long double, int>>> weights;
    Graph(int nr_nodes) : weights(nr_nodes, vector<pair<long double, int>>()){};
};

long double dijkstra(Graph &g, int start, int goal)
{
    int graph_size = g.weights.size();

    priority_queue<pair<long double, int>, vector<pair<long double, int>>, function<bool(pair<long double, int>, pair<long double, int>)>> pq(Compare);
    vector<long double> dist(graph_size, 0);
    dist[start] = 1;

    pq.push({1, start});

    while (!pq.empty())
    {
        long double src_cost = pq.top().first;
        int src = pq.top().second;

        // early exit, if goal already has the best possible value
        if (src == goal)
            break;

        pq.pop();

        // for all neighbours of src
        for (pair<long double, int> edge : g.weights[src])
        {
            long double edge_cost = edge.first;
            int dest = edge.second;

            //  If there is shorted path to dest through src.
            if (dist[dest] < dist[src] * edge_cost)
            {
                // Updating distance of dest
                dist[dest] = dist[src] * edge_cost;
                pq.push(make_pair(dist[dest], dest));
            }
        }
    }

    return dist[goal];
}

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 29-05-2021
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(4);

    int nr_nodes, nr_edges;

    while (cin >> nr_nodes >> nr_edges && !(nr_nodes == 0 && nr_edges == 0))
    {
        Graph g(nr_nodes);
        int from_node, to_node;
        long double factor;
        for (size_t i = 0; i < nr_edges; i++)
        {
            cin >> from_node >> to_node >> factor;
            g.weights[from_node].push_back(make_pair(factor, to_node));
            g.weights[to_node].push_back(make_pair(factor, from_node));
        }

        cout << dijkstra(g, 0, nr_nodes - 1) << '\n';
    }

    return 0;
}
