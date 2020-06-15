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
            if (denominator == 0)
            {
                throw invalid_argument("invalid_argument");
            }
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
        if (rh.Numerator() == 0)
        {
            throw domain_error("domain_error");
        }
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
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}