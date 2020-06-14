#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<bool> Queue;
    int Q;
    int WORRY_COUNT = 0;
    cin >> Q;
    string command;
    int number;
    for (int i = 0; i < Q; i++)
    {
        cin >> command;
        if (command == "WORRY")
        {
            cin >> number;
            Queue[number] = true;
            WORRY_COUNT++;
        }
        else if (command == "QUIET")
        {
            cin >> number;
            Queue[number] = false;
            WORRY_COUNT--;
        }
        else if (command == "COME")
        {
            cin >> number;
            if (number > 0)
            {
                for (int i = 0; i < number; i++) {
                    Queue.push_back(false);
                }
            }
            else
            {
             for (int i = 0; i < (-1)*number; i++) {
                    Queue.pop_back();
                }   
            }
        }
        else if (command == "WORRY_COUNT")
        {
            cout << WORRY_COUNT << endl;
        }
    }
	return 0;
}