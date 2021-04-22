#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>

#include "library.h"

using namespace std;

bool cmp(intervalcover::Interval &i1, intervalcover::Interval &i2)
{
    return i1.end < i2.end;
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

    vector<string> dictionary;
    string current_message = "", current_word, word_part;

    // Handle input of dictionary
    while (cin >> current_word && current_word != "#")
    {
        dictionary.push_back(current_word);
    }

    // Solve given each message
    while (cin >> word_part && word_part != "#")
    {
        current_message += word_part;

        if (current_message.back() == '|')
        {
            current_message.pop_back();
            //cout << "mes:-" << current_message << "-" << '\n';
            vector<intervalcover::Interval> intervals;

            // Find the matches for all words
            for (size_t i = 0; i < dictionary.size(); i++)
            {

                vector<int> matches = stringmatching::find(dictionary[i], current_message);

                for (size_t j = 0; j < matches.size(); j++)
                {

                    intervals.push_back(intervalcover::Interval(matches[j], matches[j] + dictionary[i].size() - 1, 0));
                }
            }

            // Find the maximum number of words
            sort(intervals.begin(), intervals.end(), cmp);

            int last_index = -1, res = 0;
            for (int i = 0; i < intervals.size(); i++)
            {
                if (intervals[i].start > last_index)
                {
                    last_index = intervals[i].end;
                    res++;
                }
            }

            cout << res << '\n';
            current_message = "";
        }
    }

    return 0;
}
