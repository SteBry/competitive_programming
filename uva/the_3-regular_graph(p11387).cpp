#include <iostream>
#include <string>

bool graph(int n);

using namespace std;
int main() {
    int n;

    while (cin >> n) {
        if(!graph(n)){
            break;
        }
    }
    return 0;
}

bool graph(int n){
    if (n == 0){
        return false;
    }
    if (n%2 == 1 || n == 2) {
        cout << "Impossible" << endl;
        return true;
    }
    cout << n+n/2<<endl;
        int i,j;
    for (i = 1, j = 2; i <= n; ++i, j = j%n+1){
        cout << i <<" "<< j<<endl;
    }
    for (i = 1, j = n/2+1; i <= n/2; ++i, j = j%n+1){
        cout << i <<" " << j << endl;
    }
    return true;
}
