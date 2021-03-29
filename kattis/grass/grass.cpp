#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

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

    int nr_sprinklers, length , width; 

    while (cin >> nr_sprinklers >> length >> width)
    {
        
        vector<intervalcover::Interval> intervals;

        for (int j = 0; j < nr_sprinklers; j++)
        {    

            int center, radius;
            cin >> center >>radius;

            long double dist= max(sqrt(max(pow(radius,2) - pow(((long double)width/2), 2), (long double ) 0)), (long double)0.00000000000001);

            intervals.push_back(intervalcover::Interval(((long double)center)-dist, ((long double)center)+dist, j));
        }

        vector<int> res= intervalcover::cover(intervalcover::Interval(0, length, -1), intervals);

        cout <<(res.size()>0? (int)res.size() : -1)<< '\n';
    }
    
    return 0;
}
