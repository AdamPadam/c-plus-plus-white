#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name)
    {
        this->first_name[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name)
    {
        this->last_name[year] = last_name;
    }
    string GetFullName(int year) {

        int min = 1000000000;
        string first_name, last_name;
        for (auto a : this->first_name)
        {
            if (min > year - a.first && year >= a.first)
            {
                min = a.first;
            }
        }
        first_name = this->first_name[min];
        for (auto a : this->last_name)
        {
            if (min > year - a.first && year >= a.first)
            {
                min = a.first;
            }
        }
        last_name = this->last_name[min];

        if (first_name == "" && last_name == "")
        {
            return "Incognito";
        }
        else if (first_name == "")
        {
            return last_name + " with unknown first name";
        }
        else if (last_name == "")
        {
            return first_name + " with unknown last name";
        }
        else
        {
            return first_name + " " + last_name;
        }
    }
private:
    map<int, string> first_name;
    map<int, string> last_name;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}