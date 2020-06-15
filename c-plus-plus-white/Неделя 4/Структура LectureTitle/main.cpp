#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Specialization {
    string value;
    explicit Specialization(string value)
    {
        this->value = value;
    }
};

struct Course {
    string value;
    explicit Course(string value)
    {
        this->value = value;
    }
};

struct Week {
    string value;
    explicit Week(string value)
    {
        this->value = value;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(Specialization specialization, Course course, Week week)
    {
        this->specialization = specialization.value;
        this->course = course.value;
        this->week = week.value;
    }
};

int main() {
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );
    return 0;
}