#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string original, desired;

    cin >> n >> original >> desired;

    std::function<int(string)> partitions = [](string current) -> int {
        int res = current.front() == current.back() ? 0 : 1;
        for (size_t i = 1; i < current.size(); i++)
        {
            if (current.at(i) != current.at(i - 1))
                res += 1;
        }
        return res;
    };

    int p_o = partitions(original);
    int p_d = partitions(desired);

    // Check if original and desired both only consists of either R or B
    bool c = p_o == 0 && p_d == 0 && original.begin() != original.end();

    cout << (p_d <= p_o && p_d != n && !c ? "yes" : "no") << endl;
    return 0;
}
