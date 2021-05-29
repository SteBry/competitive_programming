#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>

#include "library.h"

using namespace std;

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 29-05-2021
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    shortestpath1::Graph board(64);

    //The available moves relative to a tile
    vector<pair<int, int>> neighbours{
        {-2, 1},
        {-2, -1},
        {2, 1},
        {2, -1},
        {1, -2},
        {-1, -2},
        {1, 2},
        {-1, 2},
    };

    // Setup graph for all positions
    for (int i = 0; i < 64; i++)
    {
        int from_x = i % 8;
        int from_y = i / 8;

        for (int j = 0; j < 8; j++)
        {
            int to_x = from_x + neighbours[j].first;
            int to_y = from_y + neighbours[j].second;

            if (to_x >= 0 && to_y >= 0 && to_x < 8 && to_y < 8)
            {
                int to_i = 8 * to_y + to_x;
                board.set_weight(i, to_i, 1);
            }
        }
    }

    int nr_cases;
    cin >> nr_cases;

    for (int i = 0; i < nr_cases; i++)
    {
        string pos;
        int x, y;
        cin >> pos;

        // Normalize position to [0, 7] for both axis
        x = pos[0] - 'a';
        y = pos[1] - '1';

        // Transform to index of tile
        int start_square = y * 8 + x;

        // Find distances to each node
        std::vector<std::pair<int, int>> res = shortestpath1::shortest_path(board, start_square);

        // find the index with the highest cost and save all teh indexes with that cost
        int best_tile;
        int best_cost = 0;
        vector<int> best;

        for (int j = 0; j < 64; j++)
        {
            // new best found, clear list
            if (res[j].first > best_cost)
            {
                best_tile = j;
                best.clear();
                best.push_back(j);
                best_cost = res[j].first;
            }
            //another index witht he same cost found
            else if (res[j].first == best_cost)
            {
                best.push_back(j);
            }
        }

        // sort the tiles in the order a8, b8 ,..., g1, h1
        sort(best.begin(), best.end(),
             [](const int &lhs, const int &rhs)
             {
                 if (lhs / 8 == rhs / 8)
                 {
                     return lhs % 8 < rhs % 8;
                 }
                 return lhs > rhs;
             });

        // output result
        cout << best_cost << " ";
        for (int j = 0; j < best.size(); j++)
        {
            // transform index to tile
            string out = "a1";
            out[0] += (char)(best[j] % 8);
            out[1] += (char)(best[j] / 8);

            cout << out << " ";
        }
        cout << '\n';
    }

    return 0;
}
