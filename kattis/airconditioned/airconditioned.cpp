#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

#include "library.h"

using namespace std;

bool comparePair(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.second)
    {
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
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

    int n;
    cin >> n;

    vector<pair<int, int>> minions(n);

    for (int i = 0; i < n; i++)
    {
        cin >> minions[i].first >> minions[i].second;
    }

    sort(minions.begin(), minions.end(), comparePair);

    int res = 1;
    int max = minions[0].second;

    for (int i = 0; i < minions.size(); i++)
    {
        //Find the smallest temp that fit within already created room
        if (minions[i].first <= max)
        {
            if (minions[i].second < max)
            {
                max = minions[i].second;
            }
        }
        else
        {
            res += 1;
            max = minions[i].second;
        }
    }

    cout << res << endl;

    return 0;
}
