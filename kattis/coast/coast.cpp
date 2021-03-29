#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

#include "library.h"

using namespace std;


void floodFill(vector<vector<int>> &map, int x, int y)
{
    if (x < 0 || x >= map.size() || y < 0 || y >= map[0].size())
        return;
    if (map[x][y] != 0)
        return;
    if (map[x][y] == -1)
        return;
 
    map[x][y] =-1;

    floodFill(map, x+1, y);
    floodFill(map, x-1, y);
    floodFill(map, x, y+1);
    floodFill(map, x, y-1);
}
 



/**
 * @author Stefan Brynielsson(stebr364)
 * @date 29-03-2021
 *
 * 
 **/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    cin >> n >> m;

    vector<vector<int>> sea(n+2, vector<int>(m+2, 0));
            // Add a layer of sea around the whole map
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j  <= m; j++)
        {
            char c;
            cin >>c;

            sea[i][j]=(c- '0');
        }
    }

    floodFill(sea, 0,0);

    int sum=0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j  <= m; j++)
        {
            if (sea[i][j]== -1) continue;
            if(sea[i+1][j]==-1) sum++;
            if(sea[i-1][j]==-1) sum++;
            if(sea[i][j+1]==-1) sum++;
            if(sea[i][j-1]==-1) sum++;
        }
    }

    cout  << sum<<endl;

    return 0;
}
