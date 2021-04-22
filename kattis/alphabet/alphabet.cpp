#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>

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

    string letters;

    while (cin >> letters)
    {
        vector<int> int_rep = vector<int>();
        copy(letters.begin(), letters.end(), std::back_inserter(int_rep));

        cout << max(26 - (int)longincsubseq::lis(int_rep).size(), 0) << "\n";
    }

    return 0;
}
