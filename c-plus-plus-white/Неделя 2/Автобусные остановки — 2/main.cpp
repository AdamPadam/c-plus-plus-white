#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    map<int, vector<string>> stops;
    string bus_stop;
    int Q, bus_number, bus_stop_count;
    bus_number = 0;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> bus_stop_count;
        vector<string> new_stops(bus_stop_count);
        for (int i = 0; i < bus_stop_count; i++)
        {
            cin >> new_stops[i];
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