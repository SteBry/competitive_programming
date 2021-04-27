#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

#include "library.h"

using namespace std;

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 26-04-2021
 *
 * Description:
 * Given two numbers an operation and an mod, perform the modular arithmetic 
 * operation, print -1 if the operation is impossible The operations is performed
 * By operator overloading in the class modulararithmetic::ModularNumber, 
 * the function simplify() is used to modulu parts of the calculations.
 * gcd() is used to determine if division is possible. The division is calculated 
 * using the modular inverse of x, this is calculated using the Extended Euclidean algorithm 
 * (based on: https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/). 
 * 
 * Compexity:
 * Each opeartion have the time complexity O(Log(max(mod, y))) due to the gcd function. 
 **/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long mod, nr_tests;

    //While there are more sets of tests
    while (cin >> mod >> nr_tests && !(mod == 0 && nr_tests == 0))
    {
        //for each test set
        for (int i = 0; i < nr_tests; i++)
        {
            // Read numbers and operation
            long long x, y;
            char op;
            cin >> x >> op >> y;
            long long res;
            modulararithmetic::ModularNumber mod_num(x, mod);

            // Perform operation
            switch (op)
            {
            case '-':
                res = (mod_num - y).x;
                break;
            case '+':
                res = (mod_num + y).x;
                break;
            case '*':
                res = (mod_num * y).x;
                break;
            case '/':
                res = (rationalarithmetic::gcd(y, mod) == 1 ? (mod_num / y).x : -1); // Division only possible if gcd(y, mod)==1
                break;
            default:
                break;
            }

            // Print output
            cout << res << '\n';
        }
    }

    return 0;
}
