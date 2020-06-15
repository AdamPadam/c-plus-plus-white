#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    vector<int> ints;
    cin >> n;
    for (int i = 0; i < n; i++)
	{
        int a;
		cin >> a;
        ints.push_back(a);
    }
    sort(begin(ints), end(ints), [](const int& x, const int& y)
	{
        return abs(x) < abs(y);
    });
    for (const auto& i : ints)
	{
        cout << i << " ";
    }
    return 0;
}