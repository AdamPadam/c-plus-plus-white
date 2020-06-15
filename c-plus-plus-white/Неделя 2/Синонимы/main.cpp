#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set<set<string>> words;
    string command, word1, word2;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> command;
        if (command == "ADD")
        {
            cin >> word1 >> word2;
            words.insert({word1, word2});
        }
        else if (command == "COUNT")
        {
            int c = 0;
            cin >> word1;
            for (auto sinonym : words)
            {
                for (auto word : sinonym)
                {
                    if (word1 == word)
                    {
                        c++;
                    }
                }
            }
            cout << c << endl;
        }
        else if (command == "CHECK")
        {
            cin >> word1 >> word2;
            bool b = false;
            set<string> new_words = { word1, word2 };
            for (auto sinonym : words)
            {
                if (sinonym == new_words)
                {
                    cout << "YES" << endl;
                    b = true;
                }
            }
            if (!b)
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}