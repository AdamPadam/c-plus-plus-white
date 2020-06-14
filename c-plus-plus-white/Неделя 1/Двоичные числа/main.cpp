#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N == 0)
    {
        cout << 0;
    }
    else
    {
        vector<int> bin;
        while (N > 0)
        {
            bin.push_back(N % 2);
            N /= 2;
        }
        for (int i = bin.size() - 1; i >= 0; i--)
        {
            cout << bin[i];
        }
    }
    return 0;
}
