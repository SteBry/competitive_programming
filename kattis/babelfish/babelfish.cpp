#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string line, key, word;
    unordered_map<string, string> dict = unordered_map<string, string>();

    while (getline(cin, line) && line != "")
    {
        stringstream(line) >> word >> key;
        dict.insert(pair<string, string>(key, word));
    }

    while (cin >> key)
    {
        string res = "eh";

        if (dict.find(key) != dict.end())
        {
            res = dict[key];
        }

        cout << res << endl;
    }

    return 0;
}
