#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    std::string line;

    while (cin >> line && line != "0")
    {
        string aString, lString, nString;
        int tempPos;
        sort(line.begin(), line.end());

        /*
        The string is split into 3 strings 
        one contains all characters of type "qprst",
        one contains all characters of type "KACE",
        one contains all characters of type "N"
        */

        // Create string of all "qprst"
        tempPos = line.find_first_of("qprst");
        if (tempPos != string::npos)
        {
            aString = line.substr(tempPos);
        }

        //create string of all "KACE"
        tempPos = line.find_first_of("KACE");
        if (tempPos != string::npos)
        {
            lString = line.substr(tempPos, line.find_last_of("KACE") - tempPos + 1);
        }

        // Create string of all "N"
        tempPos = line.find_first_of("N");
        if (tempPos != string::npos)
        {
            nString = line.substr(tempPos, line.find_last_of("N") - tempPos + 1);
        }

        if (aString == "")
        {
            // if there are no string of "qprst" there can be no WFF
            cout << "no WFF possible" << endl;
        }
        else
        {
            /*
            Add all characters of type "N" to the WFF since they always create a WFF if the rest of the formula is a WFF
            Add one more character of type "KACE" then of type "qprst"
            */
            cout << nString << lString.substr(0, aString.length() - 1) << aString.substr(0, lString.length() + 1) << endl;
        }
    }
}
