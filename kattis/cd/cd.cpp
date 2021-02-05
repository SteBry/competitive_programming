#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    while (cin >> N >> M && N != 0 && M != 0)
    {

        unordered_set<int> jack_owns{};

        int current;
        for (int n = 0; n < N; n++)
        {
            cin >> current;
            jack_owns.insert(current);
        }

        int res = 0;

        for (int m = 0; m < M; m++)
        {
            cin >> current;
            if (jack_owns.count(current) > 0)
            {
                res += 1;
            }
            /* code */
        }
        cout << res << endl;
    }

    return 0;
}
