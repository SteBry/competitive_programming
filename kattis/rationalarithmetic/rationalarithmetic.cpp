#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

#include "library.h"

using namespace std;
using namespace rationalarithmetic;
/**
 * @author Stefan Brynielsson(stebr364)
 * @date 22-04-2021
 *
 * Description:
 * Given two rational numbers and an arithmetic operation, 
 * perform the operation on the two numbers and print the 
 * result as an rational number
 *
 * The calculations ius handled by the class RationalNumber using operator overloading
 * The method reduce is used internaly inorder to simplyfy the rational number after an 
 * operation.
 * 
 * Complexity:
 * Each test case has the time complexity O(log(n)) due to the greates common denominator 
 * function used to simpify the number, based on: https://www.baeldung.com/cs/euclid-time-complexity 
 **/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nr_cases;
    cin >> nr_cases;

    RationalNumber n1, n2;
    char op;

    // Handle each test case
    for (int i = 0; i < nr_cases; i++)
    {
        // Read input for each case
        cin >> n1 >> op >> n2;

        // Perform the operation
        RationalNumber res;
        switch (op)
        {
        case '-':
            res = n1 - n2;
            break;
        case '+':
            res = n1 + n2;
            break;
        case '*':
            res = n1 * n2;
            break;
        case '/':
            res = n1 / n2;
            break;
        default:
            break;
        }

        // Write result to output
        cout << res << "\n";
    }

    return 0;
}
