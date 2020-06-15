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
    string GetFullName(int year)
    {

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
    string GetFullNameWithHistory(int year)
    {
        string first_name_now = "";
        vector<string> first_name_old = {};
        
        for (auto value : this->first_name)
        {
            if (value.first <= year)
            {
                if (value.second != first_name_now)
                {
                    first_name_old.push_back(value.second);
                }
                first_name_now = value.second;
            }
        }
        if (first_name_old.size() != 0)
        {
            first_name_old.pop_back();
            reverse(first_name_old.begin(), first_name_old.end());
        }

        string last_name_now = "";
        vector<string> last_name_old = {};

        for (auto value : this->last_name)
        {
            if (value.first <= year)
            {
                if (value.second != last_name_now)
                {
                    last_name_old.push_back(value.second);
                }
                last_name_now = value.second;
            }
        }
        if (last_name_old.size() != 0)
        {
            last_name_old.pop_back();
            reverse(last_name_old.begin(), last_name_old.end());
        }

        if (first_name_now == "" && last_name_now == "")
        {
            return "Incognito";
        }
        else if (first_name_now == "")
        {
            string s = "";
            if (last_name_old.size() != 0)
            {
                s =+ " (";
                for (int i = 0; i < last_name_old.size(); i++)
                {
                    s += last_name_old[i];
                    if (i != last_name_old.size() - 1)
                    {
                        s += ", ";
                    }
                }
                s += ")";
            }
            return last_name_now + s + " with unknown first name";
        }
        else if (last_name_now == "")
        {
            string s = "";
            if (first_name_old.size() != 0)
            {
                s = +" (";
                for (int i = 0; i < first_name_old.size(); i++)
                {
                    s += first_name_old[i];
                    if (i != first_name_old.size() - 1)
                    {
                        s += ", ";
                    }
                }
                s += ")";
            }
            return first_name_now + s + " with unknown last name";
        }
        else
        {
            string s1 = "";
            if (last_name_old.size() != 0)
            {
                s1 = +" (";
                for (int i = 0; i < last_name_old.size(); i++)
                {
                    s1 += last_name_old[i];
                    if (i != last_name_old.size() - 1)
                    {
                        s1 += ", ";
                    }
                }
                s1 += ")";
            }
            string s2 = "";
            if (first_name_old.size() != 0)
            {
                s2 = +" (";
                for (int i = 0; i < first_name_old.size(); i++)
                {
                    s2 += first_name_old[i];
                    if (i != first_name_old.size() - 1)
                    {
                        s2 += ", ";
                    }
                }
                s2 += ")";
            }
            return first_name_now + s2 + " " + last_name_now + s1;
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
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}