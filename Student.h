#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Student {
private :
	int id;
	string name;
	string email;
	vector<int> enrolledCourseIds;

public :
	
	Student() = default;
	Student(int s_id, string& s_name, string& s_email, vector<int> s_enrolledCourseIds) : id(s_id), name(s_name), email(s_email), enrolledCourseIds(s_enrolledCourseIds) {}

	~Student() = default;
	Student(const Student& other) : id(other.id), name(other.name), email(other.email), enrolledCourseIds(other.enrolledCourseIds) {}
	Student& operator=(const Student& other) {
		if (this == &other) {
			return *this;
		}

		id = other.id;
		name = other.name;
		email = other.email;
		enrolledCourseIds = other.enrolledCourseIds;
		return *this;
	}

	int getId() const { return id; }
	string getName() const { return name; }
	string getEmail() const { return email; }
	vector <int> getEnrolledCourseIds() const { return enrolledCourseIds; }

	void setName(string* newName) { name = newName; }
	void setEmail(string* newEmail) { email = newEmail; }
	
	void enrollCourse(int courseId) {
		if (std::find(enrolledCourseIds.begin(), enrolledCourseIds.end(), courseId) == enrolledCourseIds.end()) {
			enrolledCourseIds.push_back(courseId);
		}
	}

	void removeCourse(int courseId) {
		enrolledCourseIds.erase(std::remove(enrolledCourseIds.begin(), enrolledCourseIds.end(), courseId), enrolledCourseIds.end());
	}

	bool operator==(const Student& other) const {
		return id == other.id;
	}
	
};