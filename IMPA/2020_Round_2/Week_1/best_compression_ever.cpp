#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    long long N, b;
    while (cin >> N >> b)
    {
        cout << (pow(2, b + 1) - 1 < N ? "no" : "yes") << endl;
    }
}