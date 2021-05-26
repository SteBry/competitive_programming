#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>
#

#include "library.h"

using namespace std;

bool danger(vector<vector<char>> &map, int x, int y)
{
    return map[x - 1][y] == 'T' || map[x + 1][y] == 'T' || map[x][y - 1] == 'T' || map[x][y + 1] == 'T';
}

int dfs(vector<vector<char>> &map, vector<vector<bool>> &explored, int x, int y)
{
    if (explored[x][y])
        return 0;

    int sum = map[x][y] == 'G';

    explored[x][y] = true;

    if (map[x][y] == '#' || danger(map, x, y))
    {
        return sum;
    }

    sum += dfs(map, explored, x - 1, y);
    sum += dfs(map, explored, x + 1, y);
    sum += dfs(map, explored, x, y - 1);
    sum += dfs(map, explored, x, y + 1);
    return sum;
}

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 26-05-2021
 *
 * "Description"
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int width, height, x, y;

    cin >> width >> height;

    vector<vector<char>> map(width, vector<char>(height, 0));
    vector<vector<bool>> explored(width, vector<bool>(height, false));

    // Read map and save start position
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            cin >> map[w][h];
            if (map[w][h] == 'P')
            {
                x = w;
                y = h;
            }
        }
    }

    int res = dfs(map, explored, x, y);

    cout << res << '\n';

    return 0;
}
