#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string word;
    cin >> word;
    int location = -2;
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == 'f')
        {
            if (location == -2)
            {
                location = -1;
            }
            else if (location == -1)
            {
                location = i;
            }
        }
    }
    cout << location;
    return 0;
}
