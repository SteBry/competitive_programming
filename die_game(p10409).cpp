#include <iostream>
#include <string>

using namespace std;

int main()
{
	size_t faces;
	while (cin >> faces) {
		if (faces == 0) {
			return 0;
		}
		int top = 1;
		int north = 2;
		int west = 3;
		int temp;

		string direction;
		for (int i = 0; i < faces; i++) {
			cin >> direction;

			if (direction == "north") {
				temp = north;
				north = top;
				top = 7 - temp;

			}
			else if (direction == "west") {
				temp = west;
				west = top;
				top = 7 - temp;
			}
			else if (direction == "south") {
				temp = north;
				north = 7 - top;
				top = temp;
			}
			else if (direction == "east") {
				temp = west;
				west = 7 - top;
				top = temp;
			}
		}
		cout << top << endl;
	}
}