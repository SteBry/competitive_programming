#include <iostream>
#include <string>

using namespace std;

int main(){
    int res, friends, A, B, C;

    cin>>friends>>A>>B>>C;

    int in_a_row =0;
    int last = 0;
    res =0;

    while(A>0 || B>0 || C>0 ){

        if (A>=B && A>=C && A>0){
                if (last != 1){
                    res ++;
                    A--;
                    last=1;
                    continue;
                }

        }else if (B>=C && B>=A && B>0){
            if (last != 3){
                    res ++;
                    B--;
                    last=2;
                    continue;
                }
        }else if(C>=B && C>=A && C>0){
            if (last != 3){
                    res ++;
                    C--;
                    last=3;
                    continue;
                }
        }

        if ((A>=B || A>=C)&& A>0){
            if (last != 1){
                    res ++;
                    A--;
                    last=1;
                    continue;
                }
        }else if ((B>=C || B>=A)&& B>0){
            if (last != 2){
                    res ++;
                    B--;
                    last=2;
                    continue;
                }

        }else if((C>=B || C>=A)&& C>0){
            if (last != 3){
                    res ++;
                    C--;
                    last=3;
                    continue;
                }
        }

        if (A<B && A<C && A>0){
                if (last != 1){
                    res ++;
                    A--;
                    last=1;
                    continue;
                }

        }else if (B<C && B<A && B>0){
            if (last != 2){
                    res ++;
                    B--;
                    last=2;
                    continue;
                }

        }else if(C<B && C<A && C>0){
            if (last != 3){
                    res ++;
                    C--;
                    last=3;
                    continue;
                }

        }
        break;
    }

    if (last = 1 && A>0){
        res += min(friends-1, A);
    }else if (last = 2 && B>0){
        res += min(friends-1, B);
    }else if(last = 3 && C>0){
        res += min(friends-1, C)
    }else{
        res += min(A+B+C, friends);
    }
    cout << res <<endl;



    return 0;
}
