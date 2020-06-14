#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, D;
    cin >> a >> b >> c;
    double x1, x2;
    
    if (a == 0)
    {
        x1 = (-1*c)/b;
        cout << x1;
    }
    else
    {
        D = b*b - 4*a*c;
        if (D >= 0)
        {
            x1 = (-1*b + sqrt(D))/(2*c);
            x2 = (-1*b - sqrt(D))/(2*c);
            if (x1 == x2)
            {
                cout << x1;
            }
            else
            {
                cout << x1 << " " << x2;
            }
        }
    }
    return 0;
}
