#include <iostream>

using namespace std;

int Factorial(int a)
{
    int sum = 1;
    if (a >= 0)
    {
        for(int i = 2; i <= a; i++)
        {
            sum *= i;
        }
    }
    return sum;
}

int main()
{
    int a;
    cin >> a;
    cout << Factorial(a);
	return 0;
}