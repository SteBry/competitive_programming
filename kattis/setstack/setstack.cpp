#include <bits/stdc++.h>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>

//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

void solve_case()
{
    int nr_operations;
    cin >> nr_operations;

    // Keep track of all already seen sets, and the stack
    stack<int> current_stack;

    map<set<int>, int> mapping{
        {set<int>(), 0},
    };

    map<int, set<int>> inverted_mapping{
        {0, set<int>()},
    };

    // Handle each operation
    for (int j = 0; j < nr_operations; j++)
    {

        string current_operation;
        cin >> current_operation;

        if ('P' == current_operation[0])
        {
            current_stack.push(0);
        }
        else if ('D' == current_operation[0])
        {

            current_stack.push(current_stack.top());
        }
        else if ('U' == current_operation[0])
        {

            set<int> first = inverted_mapping[current_stack.top()];
            current_stack.pop();
            set<int> second = inverted_mapping[current_stack.top()];
            current_stack.pop();

            second.insert(first.begin(), first.end());

            if (mapping.count(second) > 0)
            {
                current_stack.push(mapping[second]);
            }
            else
            {
                int id = mapping.size();
                mapping[second] = id;
                inverted_mapping[id] = second;
                current_stack.push(id);
            }
        }
        else if ('I' == current_operation[0])
        {

            set<int> first = inverted_mapping[current_stack.top()];
            current_stack.pop();
            set<int> second = inverted_mapping[current_stack.top()];
            current_stack.pop();

            set<int> intersection;
            set_intersection(first.begin(), first.end(), second.begin(), second.end(),
                             std::inserter(intersection, intersection.begin()));
            if (mapping.count(intersection) > 0)
            {
                current_stack.push(mapping[intersection]);
            }
            else
            {
                int id = mapping.size();
                mapping[intersection] = id;
                inverted_mapping[id] = intersection;
                current_stack.push(id);
            }
        }
        else if ('A' == current_operation[0])
        {

            int first = current_stack.top();
            current_stack.pop();
            set<int> second = inverted_mapping[current_stack.top()];
            current_stack.pop();
            second.insert(first);

            if (mapping.count(second) > 0)
            {
                current_stack.push(mapping[second]);
            }
            else
            {
                int id = mapping.size();
                mapping[second] = id;
                inverted_mapping[id] = second;
                current_stack.push(id);
            }
        }
        cout << inverted_mapping[current_stack.top()].size() << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases{};

    cin >> cases;

    // Handle one case
    for (int i = 0; i < cases; i++)
    {
        solve_case();
        cout << "***" << endl;
    }

    return 0;
}
