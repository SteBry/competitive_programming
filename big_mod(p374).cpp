#include <iostream>
#include <string>

using namespace std;

// Solution using pseudocode from:
// https://en.wikibooks.org/wiki/Algorithm_Implementation/Mathematics/Modular_Exponentiation

int main()
{
    long long base, power, mod;

    while(cin >> base >> power >> mod){
        long res = 1;

        while(power != 0){
            if (power%2 == 1){
                res = (res*base) % mod;
            }
            power = power/2;
            base = (base * base) % mod;
        }
        cout<< res << endl;
    }

}
