#include <iostream>
#include <string>

using namespace std;


int cuts(int width, int height);

int main()
{
    int w,l;
    while (cin>> w >> l){
        cout << cuts(w, l) << endl;
    }
}


int cuts(int width, int height){
    return max(width, height)-1 + max(width,height) * (min(width, height)-1);
}
