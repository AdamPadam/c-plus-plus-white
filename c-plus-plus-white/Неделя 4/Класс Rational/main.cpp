#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Rational
{
public:
    Rational()
    {
        this->numerator = 0;
        this->denominator = 1;
    }
    Rational(int numerator, int denominator)
    {
        if (numerator == 0)
        {
            this->numerator = 0;
            this->denominator = 1;
        }
        else
        {
            int NOD;
            int a = abs(numerator);
            int b = abs(denominator);
            while(a > 0 && b > 0)
            {
                if (a > b)
                {
                    a %= b;
                }
                else
                {
                    b %= a;
                }
            }
            this->numerator = numerator/(a + b);
            this->denominator = denominator/(a + b);
            if (this->denominator < 0)
            {
                this->numerator *= -1;
                this->denominator *= -1;
            }
        }
    }
    int Numerator() const
    {
        return this->numerator;
    }
    int Denominator() const
    {
        return this->denominator;
    }
    bool operator==(const Rational& rh)
    {
        return this->Numerator() == rh.Numerator() && this->Denominator() == rh.Denominator();
    }
private:
    int numerator;
    int denominator;
};

    Rational operator+(const Rational& lh, const Rational& rh)
    {
        return Rational(lh.Numerator()*rh.Denominator()+lh.Denominator()*rh.Numerator(),lh.Denominator()*rh.Denominator());
    }
    
    Rational operator-(const Rational& lh, const Rational& rh)
    {
        return Rational(lh.Numerator()*rh.Denominator()-lh.Denominator()*rh.Numerator(),lh.Denominator()*rh.Denominator());
    }
    
    Rational operator*(const Rational& lh, const Rational& rh)
    {
        return Rational(lh.Numerator()*rh.Numerator(),lh.Denominator()*rh.Denominator());
    }
    Rational operator/(const Rational& lh, const Rational& rh)
    {
        return Rational(lh.Numerator()*rh.Denominator(),lh.Denominator()*rh.Numerator());
    }
    istream& operator>>(istream& stream, Rational& rh)
    {
        int p, q;
        if (stream >> p && stream.ignore(1) && stream >> q)
        {
            rh = Rational(p, q);
        }
        return stream;
    }
 
    ostream& operator<<(ostream& stream, const Rational& rh)
    {
        stream << rh.Numerator() << "/" << rh.Denominator();
        return stream;
    }
    bool operator>(const Rational& lh, const Rational& rh)
    {
        return (lh.Numerator() / (double)lh.Denominator()) > double(rh.Numerator() / (double)rh.Denominator());
    }
    bool operator<(const Rational& lh, const Rational& rh)
    {
        return (lh.Numerator() / (double)lh.Denominator()) < (rh.Numerator() / (double)rh.Denominator());
    }
    bool operator==(const Rational& lh, const Rational& rh)
    {
    if ((lh.Numerator() == rh.Numerator()) && (lh.Denominator() == rh.Denominator()))
    {
        return true;
    }
    return false;
}

int main() {
    const Rational r1(3, 10);
    if (r1.Numerator() != 3 || r1.Denominator() != 10)
    {
        cout << "Rational(3, 10) != 3/10" << endl;
        return 1;
    }

    const Rational r2(8, 12);
    if (r2.Numerator() != 2 || r2.Denominator() != 3)
    {
        cout << "Rational(8, 12) != 2/3" << endl;
        return 2;
    }

    const Rational r3(-4, 6);
    if (r3.Numerator() != -2 || r3.Denominator() != 3)
    {
        cout << "Rational(-4, 6) != -2/3" << endl;
        return 3;
    }

    const Rational r4(4, -6);
    if (r4.Numerator() != -2 || r4.Denominator() != 3)
    {
        cout << "Rational(4, -6) != -2/3" << endl;
        return 3;
    }

    const Rational r5(0, 15);
    if (r5.Numerator() != 0 || r5.Denominator() != 1)
    {
        cout << "Rational(0, 15) != 0/1" << endl;
        return 4;
    }

    const Rational defaultConstructed;
    if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1)
    {
        cout << "Rational() != 0/1" << endl;
        return 5;
    }
    
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

        {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }
    
{
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }
    
        {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}