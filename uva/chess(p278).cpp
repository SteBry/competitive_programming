#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

int max_amount(char type, int r, int c);

int main()
{;
    int cases, rows, columns;
    char type;

    cin >> cases;

    for(int i=0; i<cases; i++){
        cin >> type >> rows >> columns;
        cout << max_amount(type, rows, columns) << endl;
    }
}

int max_amount(char type, int r, int c){
    switch(type){
        case 'r': return min(r, c);
        case 'k': return (r*c)/2 + (r*c)%2;
        case 'Q': return min(r,c);
        case 'K': return (((c + 1)/2) * ((r + 1)/2));
    }
}
