#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

#include "library.h"

using namespace std;

// Calculates how many swaps needed to create a palindrome of the word, -1 if impossible
int swaps_palindrome(string word)
{

    // Base case, is palindrome
    if (word.empty() || word.length() == 1)
    {
        return 0;
    }

    // Search from back for the fist character
    int pos = word.find_last_of(word[0]);
    if (pos != 0)
    {
        // Remove the two matching characters and call recursively
        word.erase(pos, 1);
        int res = swaps_palindrome(word.substr(1));

        return res != -1 ? word.length() - pos + res : res;
    }

    // Search from front for last character
    pos = word.find_first_of(word[word.length() - 1]);
    if (pos != word.length() - 1)
    {
        // Remove the two matching characters and call recursively
        word.erase(pos, 1);
        int res = swaps_palindrome(word.substr(0, word.length() - 1));

        return res != -1 ? pos + res : res;
    }

    // Impossible to create palindrome
    return -1;
}

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 08-04-2021
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    string word;
    int res;

    for (int i = 0; i < cases; i++)
    {
        cin >> word;
        res = swaps_palindrome(word);
        cout << (res != -1 ? to_string(res) : "Impossible") << endl;
    }

    return 0;
}
