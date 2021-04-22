#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

#include "library.h"

using namespace std;

struct Edge
{
    int u, v;

    long double weight;

    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};

vector<Edge> mst(vector<Edge> &edges, int nr_nodes)
{

    unionfind::DSU dsu(nr_nodes);
    vector<Edge> result;

    sort(edges.begin(), edges.end());

    for (Edge e : edges)
    {
        if (dsu.find_set(e.u) != dsu.find_set(e.v))
        {
            result.push_back(e);
            dsu.union_set(e.u, e.v);
        }
    }

    return result;
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

    for (int i = 0; i < nr_cases; i++)
    {
        int nr_freckles;
        cin >> nr_freckles;
        //cout << "f" << nr_freckles;
        vector<pair<long double, long double>> freckles(nr_freckles);
        vector<Edge> edges;

        for (int j = 0; j < nr_freckles; j++)
        {
            cin >> freckles[j].first >> freckles[j].second;

            for (int k = 0; k < j; k++)
            {
                //    cout << freckles[j].first << freckles[j].second << freckles[k].first << freckles[k].second << endl;
                //      cout << "edge" << j << ":" << k << ":" << sqrt(pow(freckles[j].first - freckles[k].first, 2) + pow(freckles[j].second - freckles[k].second, 2)) << endl;
                edges.push_back({j, k, sqrt(pow(freckles[j].first - freckles[k].first, 2) + pow(freckles[j].second - freckles[k].second, 2))});
            }
        }

        vector<Edge> res = mst(edges, nr_freckles);
        //cout << "si:" << res.size() << endl;

        cout << fixed << setprecision(2) << accumulate(res.begin(), res.end(), (long double)0, [](long double a, Edge b) {
            return a + b.weight;
        }) << '\n';
    }

    return 0;
}
