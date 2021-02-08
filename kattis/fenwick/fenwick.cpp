#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>

#include "library.h"

using namespace std;

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 08-02-2021
 *
 * "Description"
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Read input
    long long nr_elements, nr_operations;
    cin >> nr_elements >> nr_operations;

    fenwick::FenwickTree tree = fenwick::FenwickTree(nr_elements);

    char op;
    long long indice, delta;

    for (long long i = 0; i < nr_operations; i++)
    {
        // Read and handle one operation
        cin >> op;

        // Handle incrementation
        if (op == '+')
        {
            cin >> indice >> delta;
            tree.add(indice, delta);
        }
        // Handle query
        else if (op == '?')
        {
            cin >> indice;

            cout << (indice == 0 ? 0 : tree.sum(indice - 1)) << endl;
        }
    }

    return 0;
}
