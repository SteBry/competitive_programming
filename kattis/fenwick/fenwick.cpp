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
 * Problem description: Implement the data structure "Fenwick Tree" and
 * perform operations on it based on the input, The operations are 
 * incrementation of the value at index i and query for the sum of the 
 * values at indexes 0...i-1  
 * 
 * In the main function the input is read and the data structure 
 * FenwickTree is constructed.
 * 
 * The class "FenwickTree" stores the data and contains methods that 
 * handle the two operations. these methods are called from the main 
 * function based on the input
 * 
 * The result is then output buy the main function. 
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Read input
    long long nr_elements, nr_operations;
    cin >> nr_elements >> nr_operations;

    fenwick::FenwickTree tree = fenwick::FenwickTree(nr_elements);

    // Read and handle All operations then output the result
    char op;
    long long indice, delta;

    for (long long i = 0; i < nr_operations; i++)
    {

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

            cout << (indice == 0 ? 0 : tree.sum(indice - 1)) << "\n";
        }
    }

    return 0;
}
