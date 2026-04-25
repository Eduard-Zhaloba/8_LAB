#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <deque>
#include "Student.h"
///////////////////////////////////////////////////////////////////////////Перше завдання
template <typename T, int N>
void sort_array(std::array<T, N>& arr) {
    for (auto i = arr.begin(); i != arr.end(); i++) {
        for (auto j = arr.begin(); j < arr.end() - 1; j++) {
            if (*j > *(j + 1)) {
                T temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;
            }
        }
    }
}
template <typename T, int N, int M>
void results(std::array<T, N>& a, std::array<T, M>& b) {
    sort_array(a);
    sort_array(b);
    std::cout << "Array a: ";
    for (auto it = a.begin(); it != a.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Array b: ";
    for (auto it = b.begin(); it != b.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::array<T, N + M> c;
    auto it_с = c.begin();

    for (auto it = a.begin(); it != a.end(); it++) {
        *it_с = *it;
        it_с++;
    }

    for (auto it = b.begin(); it != b.end(); it++) {
        *it_с = *it;
        it_с++;
    }
	sort_array(c);
    std::cout << "Results: ";
    for (auto it = c.begin(); it != c.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
}
////////////////////////////////////////////////////////////////////////////Кінець першого завдання
template <typename T>
void split(std::vector<T>& num, std::vector<T>& evens, std::vector<T>& odds) {
    for (auto it = num.begin(); it != num.end(); ++it) {
     
        if (*it % 2 == 0) evens.push_back(*it);
        else odds.push_back(*it);
    }
    std::cout << "/////////////////////////////////////////" << std::endl;
    std::cout << "Numbers: " << std::endl;
    for (auto it = num.begin(); it != num.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Even numbers: " << std::endl;
    for (auto it = evens.begin(); it != evens.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Odd numbers: " << std::endl;
    for (auto it = odds.begin(); it != odds.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
void split(std::vector<Student>& students, std::vector<Student>& evens, std::vector<Student>& odds) {
    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->rating % 2 == 0) {
            evens.push_back(*it);
        }
        else {
            odds.push_back(*it);
        }
    }
    std::cout << "Students: " << std::endl;
    for (auto it = students.begin(); it != students.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Even ratings: " << std::endl;
    for (auto it = evens.begin(); it != evens.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Odd ratings: " << std::endl;
    for (auto it = odds.begin(); it != odds.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
}
////////////////////////////////////////////////////////////////////////////////Кінець другого завдання

template <typename T>
bool palindrome(std::deque<T>& deq) {
    if (deq.empty()) return true;
    auto left = deq.begin();
    auto right = deq.end() - 1;
    while (left < right) {
        if (*left != *right){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
//////////////////////////////////////////////////////////////////////////Кінець третього завдання




int main() {
    std::array<int, 10> a = { 3, 1, 5, 12, 34, 45, 67, 12, 14, 4};
    std::array<int, 12> b = { 4, 2, 0, 6, 14, 10, 9, 27, 54, 19, 0, 24};
	results(a, b);
    std::array<std::string, 10> a2 = {"ad", "ab", "qax", "dffv", "sdd", "fddf", "rger", "gfhfgh", "wer", "gha"};
    std::array<std::string, 12> b2 = {"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj", "kk", "ll"};
    results(a2, b2);
    std::array<Student, 4> a3 = { Student("Alice", 68), Student("Bob", 51), Student("Volodymyr", 80), Student("David", 95) };
	std::array<Student, 5> b3 = { Student("Oleksandr", 72), Student("Demyan", 99), Student("Yaroslaw", 85), Student("Vladislav", 49), Student("Ivan", 55) };
    results(a3, b3);
    ////////////////////////////////////////////////////////////////////////////

    std::vector<int> numbers = { 12, 34, 56, 78, 90, 34, 12, 45, 1578, 2344, 0, 33, 27, 111, 39, 52, 7, 9, 11, 138, 15 };
    std::vector<int>even;
	std::vector<int>odd;
	split(numbers, even, odd);

    std::vector<long long> numbers2 = {123234445543, 987654321012, 456789012345, 234353454112};
    std::vector<long long>even2;
    std::vector<long long>odd2;
    split(numbers2, even2, odd2);
    
	std::vector<Student> students = { Student("Alice", 68), Student("Bob", 51), Student("Volodymyr", 80), Student("David", 95), Student("Oleksandr", 72), Student("Demyan", 99), Student("Yaroslaw", 85), Student("Vladislav", 49), Student("Ivan", 55) };
    std::vector<Student> even_students;
	std::vector<Student> odd_students;
	split(students, even_students, odd_students);
	/////////////////////////////////////////////////////////////////////////
	std::deque<int> deq1 = { 1,2,3,3,2,1};
	palindrome(deq1);
    if (palindrome(deq1)) {
        std::cout << "/////////////////////////////////////////" << std::endl;
        std::cout << "The deque is a palindrome" << std::endl;
    }
    else {
        std::cout << "/////////////////////////////////////////" << std::endl;
        std::cout << "The deque is not a palindrome" << std::endl;
	}   
    return 0;
}