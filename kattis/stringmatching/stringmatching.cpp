#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>

#include "library.h"

using namespace std;

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 5-4-2021
 *
 * Description: 
 * Given a pattern and a text find the position of all occurances of pattern in text. 
 * 
 * Solved using Knuth-Morris-Pratt-algorithm implemented in the function find.
 * 
 * Complexity:
 * The Knuth-Morris-Pratt-algorithm has the time-complexity: O(length(text) + length(pattern)) 
 * and therefore this implementation also do.
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Input variables
    string pattern, text;

    // While there are more testcases
    while (getline(cin, pattern) && !pattern.empty() && getline(cin, text) && !text.empty())
    {
        // Find all positions
        vector<int> res = stringmatching::find(pattern, text);

        // Output the positions
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }

        cout << "\n";
    }

    return 0;
}
