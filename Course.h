#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Course {
private:
    int id;
    string name;
    string description;
    vector<int> enrolledStudentIds;

public:
    Course() = default;
    Course(int s_id, const string& s_name, const string& s_description) : id(s_id), name(s_name), description(s_description) {}

 
    Course(const Course& other) {
        id = other.id;
        name = other.id;
        description = other.description;
        enrolledStudentIds = other.enrolledStudentIds;
    }

    Course& operator=(const Course& other) {
        if (this == &other) {
            return *this;
        }
        id = other.id;
        name = other.id;
        description = other.description;
        enrolledStudentIds = other.enrolledStudentIds;

        return *this;

    }
    ~Course() {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getDescription() const { return description; }
    vector<int> getEnrolledStudentIds() const { return enrolledStudentIds; }

    void setName(const string& newName) { name = newName; }
    void setDescription(const string& newDescription) { description = newDescription; }
    void enrollStudent(int studentId) {
        if (std::find(enrolledStudentIds.begin(), enrolledStudentIds.end(), studentId) == enrolledStudentIds.end()) {
            enrolledStudentIds.push_back(studentId);
        }
    }

    void removeStudent(int studentId) {
        enrolledStudentIds.erase(std::remove(enrolledStudentIds.begin(), enrolledStudentIds.end(), studentId), enrolledStudentIds.end());
    }

    bool operator==(const Course& other) const { return id == other.id; }

    friend ostream& operator<<(ostream& os, const Course& course) {
        os << course.id << '\n'
            << course.name << '\n'
            << course.description << '\n';

        os << course.enrolledStudentIds.size() << '\n';
        for (int studentId : course.enrolledStudentIds) {
            os << studentId << '\n';
        }
        return os;
    }

    friend istream& operator>>(istream& is, Course& course) {
        if (!(is >> course.id)) return is;
        is.ignore(); 

        if (getline(is, course.name)) return is;
        if (getline(is, course.description)) return is;

        size_t count;
        if (!(is >> count)) return is;
        is.ignore();

        course.enrolledStudentIds.clear();
        for (size_t i = 0; i < count; ++i) {
            int studentId;
            if (!(is >> studentId)) return is;
            is.ignore();
            course.enrolledStudentIds.push_back(studentId);
        }

        return is;
    }

};

