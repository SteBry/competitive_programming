#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#include <unordered_set>

#include "library.h"

using namespace std;

bool is_prime(int const m)
{
    if (m % 2 == 0 || m == 1)
    {
        return false;
    }

    // Check all odd numbers
    for (int i = 3; i <= sqrt(m); i += 2)
    {
        if (m % i == 0)
        {
            return false;
        }
    }

    return true;
}

string is_happy_prime(int const candidate)
{
    // Check that first number is a prime
    if (!is_prime(candidate))
    {
        return "NO";
    }

    // The numbers that hgave been evaluated, prevents cycles
    unordered_set<int> found{candidate};
    int cur_num = candidate;

    // continue until happy prime confirmed or cycle detected
    while (true)
    {
        // Square and sum all digits in the number
        int sum = 0;
        while (cur_num > 0)
        {
            int digit = cur_num % 10;
            cur_num /= 10;
            sum += digit * digit;
        }

        // Happy prime found
        if (sum == 1)
        {
            return "YES";
        }

        // check if cycle found
        if (found.count(sum) != 0)
        {
            return "NO";
        }

        cur_num = sum;
        found.insert(cur_num);
    }
}

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 04-02-2021
 *
 * "Description"
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nr_cases, curret_case = 0, candidate;
    cin >> nr_cases;

    // While cases left
    while (curret_case != nr_cases && cin >> curret_case >> candidate)
    {
        cout << curret_case << " " << candidate << " "
             << is_happy_prime(candidate) << endl;
    }

    return 0;
}
