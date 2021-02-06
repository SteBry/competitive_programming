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
 * Description:
 * Finds the longest increasing subsequence of a sequence and print it to the standard output.
 * 
 * In the main function the input is read and saved to data structures.
 * 
 * The functon "lis" then calculates the longest increasing sequence and return the indices of it
 * 
 * The length of the sequence and the indices is then output by the main function. 
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int sequence_len{};

    while (cin >> sequence_len)
    {
        // Read input
        vector<int> sequence(sequence_len);

        for (int i = 0; i < sequence_len; i++)
        {
            cin >> sequence[i];
        }

        // Solve Case
        vector<int> res = longincsubseq::lis(sequence);

        // Output result
        cout << res.size() << endl;
        copy(res.begin(),
             res.end(),
             ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
