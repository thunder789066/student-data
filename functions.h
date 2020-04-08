#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void menu(int id[], string first[], string last[], string city[], string state[], double gpa[], int size);

void display_info(int id[], string first[], string last[], string city[], string state[], double gpa[], int size);
// - displays all student info (id, first, last, city, state, gpa)
// - func: 'Display Student Info' -> menu option 1

void display_by_city_sort(int id[], string first[], string last[], string city[], string state[], double gpa[], int size);
// - displays all student info ordered by city
// - func: 'Display Student Info sorted by City' -> menu option 2
// - func: 'Display Student Info sorted by City & Total # of student in each city' -> menu option 3

void count_city(string city[], string state[], int size);
// - displays # of students applied from each city
// - func: 'Display Student Info sorted by City & Total # of student in each city' -> menu option 3



