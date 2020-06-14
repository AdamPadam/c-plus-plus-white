#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination)
{
    for (int i = 0; i < destination.size(); i++) {
        source.push_back(destination[i]);
    }
    destination.clear();
}

int main()
{
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    
    for (auto word : source) {
        cout << word << " ";
    }
    cout << endl;
    for (auto word : destination) {
        cout << word << " ";
    }
	return 0;
}