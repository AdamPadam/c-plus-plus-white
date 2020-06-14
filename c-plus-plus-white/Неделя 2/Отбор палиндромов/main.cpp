#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength)
{
    vector<string> new_words;
    for (auto word : words) {
        if (IsPalindrom(word) && word.size() >= minLength)
        {
            new_words.push_back(word);
        }
    }
    return new_words;
}

int main()
{
    vector<string> words = PalindromFilter({"abacaba", "aba"}, 5);
    for (auto word : words) {
        cout << word << " ";
    }
    cout << endl;
    words = PalindromFilter({"abacaba", "aba"}, 2);
    for (auto word : words) {
        cout << word << " ";
    }
    cout << endl;
    words = PalindromFilter({"weew", "bro", "code"}, 4);
    for (auto word : words) {
        cout << word << " ";
    }
    cout << endl;
	return 0;
}