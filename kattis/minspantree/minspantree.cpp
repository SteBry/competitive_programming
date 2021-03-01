#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

#include "library.h"

using namespace std;

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 01-03-2021
 *
 * Description: Given a graph, find the minimum spanning tree
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nr_nodes, nr_edges;

    while (cin >> nr_nodes >> nr_edges && !(nr_nodes == 0 && nr_edges == 0))
    {
        // Construct the graph
        int first_node, second_node, weight;

        vector<minspantree::Edge> edges(nr_nodes);

        for (int i = 0; i < nr_edges; i++)
        {
            cin >> first_node >> second_node >> weight;
            edges.push_back(minspantree::Edge{min(first_node, second_node), max(first_node, second_node), weight});
        }

        // Construct minimum spanning tree
        vector<minspantree::Edge> res = minspantree::mst(edges, nr_nodes);

        //output result

        //no mst found
        if (res.size() != nr_nodes - 1)
        {
            cout << "Impossible" << '\n';
        }

        // mst found
        else
        {
            // Caclulate total cost and output it
            cout << accumulate(res.begin(), res.end(), 0, [](int sum, minspantree::Edge edge) { return sum + edge.weight; }) << '\n';

            //Output all edges
            for (int i = 0; i < res.size(); i++)
            {
                cout << res[i].u << " " << res[i].v << '\n';
            }
        }
    }

    return 0;
}
