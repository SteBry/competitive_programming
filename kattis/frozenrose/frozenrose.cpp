#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#include <unordered_set>
#include <set>

#include "library.h"

using namespace std;

int min_sum(vector<vector<pair<int, int>>> &graph, int center)
{
    int sum = 0;
    bool change = false;

    for (pair<int, int> edge : graph[center])
    {
        int branch_sum = min_sum(graph, edge.second);
        change = true;
        sum += min(branch_sum, edge.first);
    }

    return change ? sum : INT_MAX;
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

    // 1..nr_nodes
    int nr_nodes, center_index;

    while (cin >> nr_nodes >> center_index)
    {

        // Read input and create the tree
        set<pair<pair<int, int>, int>> not_added;

        unordered_set<int> added{center_index};

        vector<vector<pair<int, int>>>
            ordered_weighs(nr_nodes + 1);

        for (int i = 1; i < nr_nodes; i++)
        {
            int from, to, weight;

            cin >> from >> to >> weight;
            if (added.count(from) == 1)
            {
                ordered_weighs[from].push_back({weight, to});
                added.insert(to);
            }
            else if (added.count(to) == 1)
            {
                ordered_weighs[to].push_back({weight, from});
                added.insert(from);
            }
            else
            {
                not_added.insert({{from, to}, weight});
            }
        }

        while (not_added.size() > 0)
        {
            for (auto it = not_added.begin(); it != not_added.end();)
            {
                if (added.count(it->first.first) == 1)
                {
                    ordered_weighs[it->first.first].push_back({it->second, it->first.second});
                    added.insert(it->first.second);
                    it = not_added.erase(it);
                }
                else if (added.count(it->first.second) == 1)
                {
                    ordered_weighs[it->first.second].push_back({it->second, it->first.first});
                    added.insert(it->first.first);
                    it = not_added.erase(it);
                }
                else
                {
                    ++it;
                }
            }
        }

        // Calculate solution
        cout << min_sum(ordered_weighs, center_index) << endl;
    }

    return 0;
}
