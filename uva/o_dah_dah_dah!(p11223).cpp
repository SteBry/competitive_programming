#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

string ALL = "AJS1.:BKT2,;CLU3?=DMV4\'+ENW5!-FOX6/_GPY7(\"HQZ8)@IR09&";


map<string, char> ALPHABBET= {
    {".-", 'A'},
    {".---", 'J'},
    {"...", 'S'},
    {".----", '1'},
    {".-.-.-",'.'},
    {"---...",':'},
    {"-...",'B'},
    {"-.-",'K'},
    {"-",'T'},
    {"..---", '2'},
    {"--..--",','},
    {"-.-.-." , ';'},
    {"-.-.",'C'},
    {".-..",'L'},
    {"..-",'U'},
    {"...--",'3'},
    {"..--..",'?'},
    {"-...-",'='},
    {"-..", 'D'},
    {"--", 'M'},
    {"...-",'V'},
    {"....-",'4'},
    {".----.",'\''},
    {".-.-.",'+'},
    {".",'E'},
    {"-.",'N'},
    {".--",'W'},
    {".....",'5'},
    {"-.-.--",'!'},
    {"-....-",'-'},
    {"..-.", 'F'},
    {"---", 'O'},
    {"-..-", 'X'},
    {"-....", '6'},
    {"-..-.", '/'},
    {"..--.-", '_'},
    {"--.",'G'},
    {".--.", 'P'},
    {"-.--", 'Y'},
    {"--...", '7'},
    {"-.--.",'('},
    {".-..-.", '"'},
    {"....", 'H'},
    {"--.-", 'Q'},
    {"--..", 'Z'},
    {"---..", '8'},
    {"-.--.-", ')'},
    {".--.-.", '@'},
    {"..", 'I'},
    {".-.", 'R'},
    {"-----", '0'},
    {"----.", '9'},
    {".-...", '&'}
};

string morse(string line);
string strip(string word);

int main(){

    string line, l;
    int cases;
    getline(cin, l);
    cases = stoi(l);

    for(int i=0; i<cases; i++){

        getline(cin, line);

        cout<< "Message #" << i+1 << endl;
        cout << morse(line) << endl;
        if(i<cases-1){
            cout<<endl;
        }
    }
}

string morse(string line){
    string key,res;

    int space = 0;
    for(char c: line){
        if (c == ' '){
            space +=1;
        }else{
            space = 0;
        }

        if(space == 0){
            key+=c;
        }else if (space ==1){
            res.push_back(ALPHABBET[key]);
            key.clear();
        }else if(space == 2){
            res.push_back(' ');
        }
    }
    res.push_back(ALPHABBET[key]);
    return strip(res);
}

string strip(string word){
    string res;
    bool prevSpace = true;
        for (char c : word) {

            if (ALL.find(c) == std::string::npos){
                if (!prevSpace){
                    res.push_back(' ');
                }
                prevSpace = true;
            } else {
                res.push_back(c);
                prevSpace = false;
            }
        }
    return res;
}
