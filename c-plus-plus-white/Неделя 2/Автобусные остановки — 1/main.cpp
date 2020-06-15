#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool BUSES_FOR_STOP(string bus_stop, map<string, vector<string>> BUSES, string ignore)
{
    bool isRealy = false;
    for (auto bus : BUSES)
    {
        for (string stop : bus.second)
        {
            if (bus_stop == stop && bus.first != ignore)
            {
                cout << bus.first << " ";
                isRealy = true;
            }
        }
    }
    if (!isRealy)
    {
        return false;
    }
    return true;
}

void STOPS_FOR_BUS(string bus_name, map<string, vector<string>> BUSES)
{
    bool isRealy = false;
    for (auto stop : BUSES[bus_name])
    {
        cout << stop << ": ";
        if (!BUSES_FOR_STOP(stop, BUSES, bus_name))
        {
            cout << "no interchange";
        }
        cout << endl;
        isRealy = true;
    }
    if (!isRealy)
    {
        cout << "No bus";
    }
}

int main()
{
    map<string, vector<string>> BUSES;
    string command, bus_name, bus_stop;
    int Q, bus_stop_count;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> command;
        if (command == "NEW_BUS")
        {
            cin >> bus_name >> bus_stop_count;
            for (int i = 0; i < bus_stop_count; i++)
            {
                cin >> bus_stop;
                BUSES[bus_name].push_back(bus_stop);
            }
        }
        else if (command == "BUSES_FOR_STOP")
        {
            cin >> bus_stop;
            if (!BUSES_FOR_STOP(bus_stop, BUSES, ""))
            {
                cout << "No stop";
            }
            cout << endl;
        }
        else if (command == "STOPS_FOR_BUS")
        {
            cin >> bus_name;
            STOPS_FOR_BUS(bus_name, BUSES);
        }
        else if (command == "ALL_BUSES")
        {
            if (BUSES.empty())
            {
                cout << "No buses" << endl;
            }
            else
            {
                for (auto bus : BUSES)
                {
                    cout << "Bus " << bus.first << ": ";
                    for (auto stop : bus.second)
                    {
                        cout << stop << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}