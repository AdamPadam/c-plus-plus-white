#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int Q;
    cin >> Q;
    int month_now = 0;
    vector<int> month_day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    vector<vector<string>> TODO(31);
    
    string command, name;
    int day_number;
    
    for (int i = 0; i < Q; i++)
    {
        cin >> command;
        if (command == "ADD")
        {
            cin >> day_number >> name;
            TODO[day_number - 1].push_back(name);
        }
        else if (command == "DUMP")
        {
            cin >> day_number;
            cout << TODO[day_number - 1].size();
            for (int i = 0; i < TODO[day_number - 1].size(); i++) {
                cout << " " << TODO[day_number - 1][i] << " ";
            }
            cout << endl;
        }
        else if (command == "NEXT")
        {
            month_now++;
            for (int i = month_day[month_now % 12]; i < month_day[(month_now - 1) % 12]; i++)
            {
                TODO[month_day[month_now % 12] - 1].insert(end(TODO[month_day[month_now % 12] - 1]), begin(TODO[i]), end(TODO[i]));
                TODO[i].clear();
            }
        }
    }
	return 0;
}