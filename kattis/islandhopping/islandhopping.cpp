#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#include <math.h>

#include "library.h"

using namespace std;

typedef long double ld;

// Calculate the cost of the Mst using Prims algorithm
ld primMST(vector<vector<ld>> &graph)
{
    // Array to store constructed MST
    vector<int> parent(graph.size());

    // costs values used to pick minimum weight edge
    vector<ld> costs(graph.size(), INT_MAX);

    // To represent set of vertices included in MST
    vector<bool> mstSet(graph.size(), false);

    // Always include first 1st vertex in MST.
    costs[0] = 0;
    parent[0] = 0;

    for (int count = 0; count < graph.size() - 1; count++)
    {
        // Pick the minimum cost vertex not yet included
        int u;
        ld min = INT_MAX;

        for (int v = 0; v < graph.size(); v++)
            if (mstSet[v] == false && costs[v] < min)
                min = costs[v], u = v;

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        for (int v = 1; v < graph.size(); v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < costs[v])

                parent[v] = u, costs[v] = graph[u][v];
    }

    // calculate sum
    ld sum = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        sum += graph[i][parent[i]];
    }

    return sum;
}

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 04-02-2021
 *
 * "Description"
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int nr_tests;

    cin >> nr_tests;

    for (int i = 0; i < nr_tests; i++)
    {

        // Read input and construct graph
        int nr_islands;

        cin >> nr_islands;
        vector<vector<ld>> graph(nr_islands, vector<ld>(nr_islands, 0));
        vector<pair<ld, ld>> islands(nr_islands);

        for (int j = 0; j < nr_islands; j++)
        {
            ld x, y;
            cin >> x >> y;

            for (int k = 0; k < j; k++)
            {
                ld dist = sqrt(pow(x - islands[k].first, 2) + pow(y - islands[k].second, 2));
                graph[k][j] = dist;
                graph[j][k] = dist;
            }

            islands[j].first = x;
            islands[j].second = y;
        }

        cout << primMST(graph) << endl;
    }
    return 0;
}
