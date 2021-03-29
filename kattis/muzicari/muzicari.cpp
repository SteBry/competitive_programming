#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#include <unordered_set>

#include "library.h"

using namespace std;

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

    int length, nr_musicians;

    cin >> length >> nr_musicians;
    vector<knapsack::Item> breaks;

    for (int i = 0; i < nr_musicians; i++)
    {
        int break_len;

        cin >> break_len;
        breaks.push_back(knapsack::Item(break_len, break_len));
    }
    
    // Que for one of the break positions
    vector<int> indexes=knapsack::knapsack(length, breaks);

    unordered_set<int> res(indexes.begin(), indexes.end());

    int q1=0;
    int q2=0;

    for (int i = 0; i < nr_musicians; i++)
    {
        if(res.count(i)>0){
            cout <<q1;
            q1 += breaks[i].weight;
        }else{
            cout <<q2;
            q2 += breaks[i].weight;
        }
        if (i<nr_musicians-1){
            cout << " ";
        }
    }
    cout << "\n";
    



    return 0;
}
