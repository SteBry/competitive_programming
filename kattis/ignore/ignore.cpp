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
 * "Description"
 * */
int main()
{

    int base[7] = {0, 1, 2, 5, 9, 8, 6};
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    while (cin >> k)
    {
        string res = "";

        while (k > 0)
        {
            res += to_string(base[k % 7]);
            k /= 7;
        }
        cout << res << endl;
    }

    return 0;
}
