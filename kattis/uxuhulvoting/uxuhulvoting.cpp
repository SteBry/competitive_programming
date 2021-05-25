#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>

#include "library.h"

using namespace std;

#define NR_STATES 8

void solve(vector<vector<int>> preferences, vector<vector<int>> states, int x)
{
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

    int nr_cases;
    cin >> nr_cases;
    string results[NR_STATES] = {"NNN", "NNY", "NYN", "NYY", "YNN", "YNY", "YYN", "YYY"};
    int neighbours[NR_STATES][3] = {
        {1, 2, 4}, // NNN -> NNY, NYN, YNN
        {0, 3, 5}, // NNY -> NNN, NYY, YNY
        {0, 3, 6}, // NYN -> NNN, NYY, YYN
        {1, 2, 7}, // NYY -> NNY, NYN, YYY
        {0, 5, 6}, // YNN -> NNN, YNY, YYN
        {1, 4, 7}, // YNY -> NNY, YNN, YYY
        {2, 4, 7}, // YYN -> NYN, YNN, YYY
        {3, 5, 6}  // YYY -> NYY, YNY, YYN
    };

    for (int i = 0; i < nr_cases; i++)
    {
        int nr_votes;
        cin >> nr_votes;

        vector<vector<int>> preferences(nr_votes, vector<int>(NR_STATES, 0));
        vector<vector<int>> state(nr_votes + 1, vector<int>(NR_STATES, 0));

        state[nr_votes] = {0, 1, 2, 3, 4, 5, 6, 7};

        // Read all preferences
        for (int j = 0; j < nr_votes; j++)
        {
            for (int k = 0; k < NR_STATES; k++)
            {
                cin >> preferences[j][k];
            }
        }

        for (int j = nr_votes - 1; j >= 0; j--)
        {
            for (int k = 0; k < NR_STATES; k++)
            {
                int best_i = 0;
                int best_priority = 9;

                // For all possible neightbours, which one results in the best result
                for (int l = 0; l < 3; l++)
                {
                    int end_state = state[j + 1][neighbours[k][l]];

                    if (preferences[j][end_state] < best_priority)
                    {
                        best_priority = preferences[j][end_state];
                        best_i = end_state;
                    }
                }

                state[j][k] = best_i;
            }
        }

        cout << results[state[0][0]] << "\n";
    }

    return 0;
}
