#include <iostream>
#include <string>

using namespace std;

void EnsureEqual(const string& s, const string& t) {
    if (s != t) {
        throw runtime_error(s + " != " + t);
    }
}

int main()
{
	return 0;
}