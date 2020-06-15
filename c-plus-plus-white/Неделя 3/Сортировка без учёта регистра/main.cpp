#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string toLow(const string& s)
{
    string result;
    for (auto i : s)
	{
        result += tolower(i);
    }
    return result;
}

bool f(string x, string y)
{
    return toLow(x) < toLow(y);
}
int main()
{
    int n;
    string a;
    vector<string> ints;
    cin >> n;
    for (int i = 0; i < n; i++)
	{
        cin >> a;
        ints.push_back(a);
    }

    sort(begin(v), end(v), f);
    for (const auto& i : ints) {
        cout << i << " ";
    }
    return 0;
}