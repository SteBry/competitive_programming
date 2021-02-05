#include <bits/stdc++.h>
#include <sstream>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;
namespace local
{
    bool is_placeholder(string s)
    {
        return s.front() == '<' && s.back() == '>';
    }

} // namespace local

string solve_case(stringstream l1, stringstream l2)
{
    vector<string> template1{};
    vector<string> template2{};
    map<string, string> template1_assignments{};
    map<string, string> template2_assignments{};

    string current_word;

    // Read string streams into template vectors
    while (l1 >> current_word)
    {
        template1.push_back(current_word);
    }

    while (l2 >> current_word)
    {
        template2.push_back(current_word);
    }

    // Not same length on template, exit
    if (template1.size() != template2.size())
    {
        return "-";
    }

    // Run untill no template can be replaced by a string
    bool change_was_made{true};

    while (change_was_made)
    {
        change_was_made = false;

        string current_string{};

        // Loop over both templates replace placeholder with string if the other placeholder has a word
        for (size_t i = 0; i < template1.size(); i++)
        {

            if (local::is_placeholder(template1[i]) && !local::is_placeholder(template2[i]))
            {
                change_was_made = true;
                string temp = template1[i];
                for (size_t j = 0; j < template1.size(); j++)
                {
                    if (template1[j] == temp)
                    {
                        template1[j] = template2[i];

                        if (!local::is_placeholder(template2[j]) && template2[j] != template2[i])
                        {

                            return "-";
                        }
                    }
                }
            }

            if (local::is_placeholder(template2[i]) && !local::is_placeholder(template1[i]))
            {
                change_was_made = true;
                string temp = template2[i];
                for (size_t j = 0; j < template2.size(); j++)
                {
                    if (template2[j] == temp)
                    {
                        template2[j] = template1[i];

                        if (!local::is_placeholder(template1[j]) && template1[j] != template1[i])
                        {
                            return "-";
                        }
                    }
                }
            }
        }
    }

    stringstream res{};

    for (size_t i = 0; i < template1.size(); i++)
    {
        if (local::is_placeholder(template1[i]) && local::is_placeholder(template2[i]))
        {
            res << "a"
                << " ";
        }
        else if (template1[i] == template2[i])
        {

            res << template1[i] << " ";
        }
        else
        {
            return "-";
        }
    }

    return res.str();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nr_cases{};

    cin >> nr_cases;
    cin.ignore();

    string l1, l2;
    for (int i = 0; i < nr_cases; i++)
    {

        getline(std::cin, l1);
        getline(std::cin, l2);
        cout << solve_case(stringstream(l1), stringstream(l2)) << endl;
    }

    return 0;
}
