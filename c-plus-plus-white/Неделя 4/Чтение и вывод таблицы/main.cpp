#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    ifstream input("input.txt");
    string lines;
    int n, m;
    input >> n >> m;
    input.ignore(1);
    for (int i = n; i > 0;i--)
	{
        for (int z = m; z > 1; z--)
		{
            getline(input, lines, ',');
            cout << setw(10) << lines << " ";
        }
        getline(input, lines);
        cout << setw(10) << lines << endl;
    }
    return 0;
}