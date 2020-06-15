#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    map<int, set<string>> stops;
    string bus_stop;
    int Q, bus_number, bus_stop_count;
    bus_number = 0;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> bus_stop_count;
        set<string> new_stops;
        for (int i = 0; i < bus_stop_count; i++)
        {
            string s;
            cin >> s;
            new_stops.insert(s);
        }
        bool isNew = true;
        for (auto stop : stops)
        {
            if (stop.second == new_stops)
            {
                cout << "Already exists for " << stop.first << endl;
                isNew = false;
            }
        }
        if (isNew)
        {
            bus_number++;
            stops[bus_number] = new_stops;
            cout << "New bus " << bus_number << endl;
        }
    }
    return 0;
}