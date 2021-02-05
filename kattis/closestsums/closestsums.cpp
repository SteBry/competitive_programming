#include <bits/stdc++.h>
//#define REP(var, k) for (long var = 0; var < (long) k; ++var)
using namespace std;

//using vi=vector<long>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long n;
    long cas{1};

    while (cin >> n && n != 0)
    {
        cout << "Case " << cas << ":" << endl;
        cas++;
        set<long> numbers{};

        long current;
        for (long i = 0; i < n; i++)
        {
            cin >> current;
            numbers.insert(current);
        }

        long m;

        cin >> m;

        for (long i = 0; i < m; i++)
        {

            cin >> current;

            bool has_been_set = false;
            long res = 0;

            for (long a : numbers)
            {
                for (long b : numbers)
                {
                    //cout << "a: " << a << " b: " << b << " has set: " << has_been_set << endl;
                    long s = a + b;
                    if (a != b && (abs(s - current) < abs(res - current) || !has_been_set))
                    {
                        has_been_set = true;
                        res = s;
                    }
                }
            }

            cout << "Closest sum to " << current << " is " << res << "." << endl;
        }
    }

    // Insert code here

    return 0;
}
