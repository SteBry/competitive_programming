#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iostream>

#include "library.h"

using namespace std;

// recursive call to determine if each question should be answered or not
long double solve(long double score, int n, long double t)
{
    // Base case, answered all questions.
    if (n <= 0)
    {
        return score;
    }

    // The expected result if the question is answered correctly.
    long double next_expected = solve(score * 2, n - 1, t);

    // The proportional increase if answered correctly, when p is larger then this answering the question is worth it
    long double p_break = score / next_expected;

    // p will always be larger then p_break
    if (p_break <= t)
    {
        return next_expected * (1.0f + t) / 2.0f;
    }

    // The prob that p is over or under p_break
    long double p_over = (1.0f - p_break) / (1.0f - t);
    long double p_under = (p_break - t) / (1.0f - t);

    // The probability of answering the question correctly if p is larger then p_break
    long double p_over_expected = (1.0f + p_break) / 2.0f;

    // (do not answer the question) + (answer the question)
    return p_over * p_over_expected * next_expected + p_under * score;
}

/**
 * @author Stefan Brynielsson(stebr364)
 * @date 29-05-2021
 * */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(3);

    int n;
    long double t;

    while (cin >> n >> t && !(n == 0 && t == 0))
    {
        cout << solve(1, n, t) << '\n';
    }

    return 0;
}
