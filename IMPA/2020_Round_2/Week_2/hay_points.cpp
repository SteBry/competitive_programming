#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int nrOfWordsInMap, nrOfJobs;

    while (cin >> nrOfWordsInMap >> nrOfJobs)
    {
        // Variables
        unordered_map<string, int> hayPointsMap;

        // Populate map
        string currentJob;
        int currentPoints;
        for (size_t i = 0; i < nrOfWordsInMap; i++)
        {
            cin >> currentJob >> currentPoints;
            hayPointsMap.insert(pair<string, int>(currentJob, currentPoints));
        }

        // Calculate points for each job
        unordered_map<string, int>::iterator hayPointsIt;
        string currentWord;
        for (size_t i = 0; i < nrOfJobs; i++)
        {
            int totalHayPoints = 0;

            while (cin >> currentWord && currentWord != ".")
            {
                // add value of currentword if it exists in map, else 0
                totalHayPoints += (hayPointsIt = hayPointsMap.find(currentWord)) != hayPointsMap.end() ? (*hayPointsIt).second : 0;
            }
            cout << totalHayPoints << endl;
        }
    }
}
