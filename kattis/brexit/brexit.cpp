#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

#include "library.h"

using namespace std;

void brexit(vector<int> &orig, unordered_set<int> &to_leave, vector<unordered_set<int>> &partners, int leave)
{

    for (auto it = partners[leave].begin(); it != partners[leave].end();)
    {
        partners[*it].erase(leave);

        if (partners[*it].size() <= orig[*it] / 2)
        {
            int val = *it;
            to_leave.insert(val);
        }

        it = partners[leave].erase(it);
    }

    while (to_leave.size() > 0)
    {
        auto it = to_leave.begin();
        int val = *it;
        to_leave.erase(it);

        brexit(orig, to_leave, partners, val);
    }
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

    int nr_countries, nr_partners, home, left;

    cin >> nr_countries >> nr_partners >> home >> left;

    vector<unordered_set<int>> partners(nr_countries + 1);

    for (int i = 0; i < nr_partners; i++)
    {
        int fst_partner, scd_partner;

        cin >> fst_partner >> scd_partner;

        partners[fst_partner].insert(scd_partner);
        partners[scd_partner].insert(fst_partner);
    }

    vector<int> orig(nr_countries + 1);

    for (int i = 0; i <= nr_countries; i++)
    {
        orig[i] = partners[i].size();
    }

    unordered_set<int> to_leave;

    brexit(orig, to_leave, partners, left);

    cout << ((orig[home] / 2 < partners[home].size()) ? "stay" : "leave") << endl;

    return 0;
}
