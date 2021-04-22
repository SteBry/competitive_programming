#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

#include "library.h"

using namespace std;

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 04-02-2021
 *
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;
    vector<int> prices(n);

    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end(), greater<>());

    long long res = 0;
    for (int i = 2; i < prices.size(); i += 3)
    {
        res += prices[i];
    }

    cout << res << endl;

    return 0;
}
