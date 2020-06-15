#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Person {
public:
	Person(const string& first_name, const string& last_name, int bearth_yaer)
	{
		this->first_name[bearth_yaer] = first_name;
		this->last_name[bearth_yaer] = last_name;
		this->bearth_yaer = bearth_yaer;
	}
	void ChangeFirstName(int year, const string& first_name)
	{
		if (year >= this->bearth_yaer)
		{
			this->first_name[year] = first_name;
		}
	}
	void ChangeLastName(int year, const string& last_name)
	{
		if (year >= this->bearth_yaer)
		{
			this->last_name[year] = last_name;
		}
	}
	string GetFullName(int year) const
	{
		if (year < this->bearth_yaer)
		{
			return "No person";
		}

		string first_name_now = "";

		for (auto value : this->first_name)
		{
			if (value.first <= year)
			{
				first_name_now = value.second;
			}
		}

		string last_name_now = "";

		for (auto value : this->last_name)
		{
			if (value.first <= year)
			{
				last_name_now = value.second;
			}
		}

		if (first_name_now == "" && last_name_now == "")
		{
			return "Incognito";
		}
		else if (first_name_now == "")
		{
			return last_name_now + " with unknown first name";
		}
		else if (last_name_now == "")
		{
			return first_name_now + " with unknown last name";
		}
		else
		{
			return first_name_now + " " + last_name_now;
		}
	}
	string GetFullNameWithHistory(int year) const
	{
		if (year < this->bearth_yaer)
		{
			return "No person";
		}
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
	int bearth_yaer;
};

int main() {
	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}