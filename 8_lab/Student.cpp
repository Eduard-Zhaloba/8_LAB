#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <deque>
#include "Student.h"
Student::Student() : name("None"), rating(0) {}
Student::Student(std::string name, int rating) {
	this->name = name;
	this->rating = rating;

}
std::ostream& operator<<(std::ostream& out, Student& s) {
	return out << s.name << " (" << s.rating << ")";
}