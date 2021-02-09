#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>

#include "library.h"

using namespace std;

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 06-02-2021
 *
 * Description: Given the sets 0...N-1, perform operations on the sets as specified by the input.
 * The available operations are find (check if the two values belong to the same set) and 
 * merge (merge the sets that the two values belong to) 
 * 
 * First the number of elements(the initial amount of sets) and the number of operations on the 
 * sets are read from the input
 * 
 * Then the specifivation for each operation is read and applied to the sets and 
 * the ouput (if applicable) is printed
 * 
 * The operations are applied on and handled by the struct "DSU" (Disjoint Set Union)
 * 
 **/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Read input
    int nr_elements, nr_operations;
    cin >> nr_elements >> nr_operations;

    unionfind::DSU dsu{nr_elements};

    // Handle a operation
    for (int i = 0; i < nr_operations; i++)
    {
        // Read input for operation
        char operation;
        int elem1, elem2;

        cin >> operation >> elem1 >> elem2;

        //Calculate result of operation
        if (operation == '=')
        {
            dsu.union_set(elem1, elem2);
        }
        else if (operation == '?')
        {
            cout << (dsu.find_set(elem1) == dsu.find_set(elem2) ? "yes" : "no") << "\n";
        }
    }

    return 0;
}
