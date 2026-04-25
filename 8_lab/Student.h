#pragma once
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <deque>
class Student {
public:
	std::string name;
	int rating;
	Student();
	Student(std::string name, int rating);
	bool operator>(Student& other){
		return this->rating > other.rating;
	}
	friend std::ostream& operator<<(std::ostream& os, Student& s);
		
};