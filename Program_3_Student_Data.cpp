// Christina Gerstner
// clgdtf@mail.umkc.edu
// 9/24/2019
// CS201R Program 3 - Student Data

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "functions.h"
using namespace std;

void menu(int id[], string first[], string last[], string city[], string state[], double gpa[], int size) {
	bool check = true;
	char option = ' ';

	cout << "Welcome to Student Center" << endl;
	cout << "(1) Display Student Info" << endl;
	cout << "(2) Display Student Info sorted by City" << endl;
	cout << "(3) Display Student Info sorted by City & total # of students in each city" << endl;
	cout << "(4) Exit" << endl;

	while (check) {
		cout << "\nEnter selection >>> ";
		cin >> option;

		switch (option) {
		case '1':
			// display all student info
			display_info(id, first, last, city, state, gpa, size);
			break;
		case '2':
			// display all student info sorted by city
			display_by_city_sort(id, first, last, city, state, gpa, size);
			break;
		case '3':
			// display all student info sorted by city & ttl # of student in each city
			display_by_city_sort(id, first, last, city, state, gpa, size);
			count_city(city, state, size);
			break;
		case '4':
			break;
		default:
			cout << "\nInvalid Input. " << option << " isn't available." << endl;
			break;
		}
		if (option == '4') {
			check = false;
		}
	}
}

void display_info(int id[], string first[], string last[], string city[], string state[], double gpa[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << setw(10) << id[i] << setw(15) << first[i] << setw(15) << last[i] << setw(20) << city[i] << setw(10) << state[i] << setw(10) << gpa[i] << "\n";
	}
}

void display_by_city_sort(int id[], string first[], string last[], string city[], string state[], double gpa[], int size) {
	int min;
	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (city[j] < city[min]) {
				min = j;
			}
		}
		//swap id
		int id_temp = id[min];
		id[min] = id[i];
		id[i] = id_temp;

		//swap first
		string first_temp = first[min];
		first[min] = first[i];
		first[i] = first_temp;

		//swap last
		string last_temp = last[min];
		last[min] = last[i];
		last[i] = last_temp;

		//swap city
		string city_temp = city[min];
		city[min] = city[i];
		city[i] = city_temp;

		//swap state
		string state_temp = state[min];
		state[min] = state[i];
		state[i] = state_temp;

		//swap gpa
		double gpa_temp = gpa[min];
		gpa[min] = gpa[i];
		gpa[i] = gpa_temp;
	}
	display_info(id, first, last, city, state, gpa, size);
}

void count_city(string city[], string state[], int size) {
	cout << endl;

	//get list of cities
	string uniqueCities[100];
	int uniqueCitiesSize = 0;
	for (int i = 0; i < size; i++)
	{
		string currentCity = city[i];
		bool found = false;
		for (int j = 0; j < uniqueCitiesSize; j++)
		{
			if (currentCity == uniqueCities[j])
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			uniqueCitiesSize++;
			uniqueCities[uniqueCitiesSize - 1] = currentCity;
		}
	}

	//get count of each city
	for (int i = 0; i < uniqueCitiesSize; i++)
	{
		int count = 0;
		string currentUniqueCity = uniqueCities[i];
		for (int i = 0; i < size; i++)
		{
			if (currentUniqueCity == city[i]) {
				count++;
			}
		}
		cout << "\t***** We have " << count << " students from " << currentUniqueCity << " this year *****" << endl;
	}
}

int main() {
	fstream fin("student_data.txt");
	if (!fin) exit(1);
	int const maxsize = 100;

	int size = 0;
	int id[maxsize];
	double gpa[maxsize];
	string first[maxsize], last[maxsize], city[maxsize], state[maxsize];

	int id_temp = 0;
	double gpa_temp = 0.0;
	string first_temp = " ", last_temp = " ", city_temp = " ", state_temp = " ";

	while (fin >> id_temp >> first_temp >> last_temp >> city_temp >> state_temp >> gpa_temp) {
		size++;
		id[size - 1] = id_temp;
		first[size - 1] = first_temp;
		last[size - 1] = last_temp;
		city[size - 1] = city_temp;
		state[size - 1] = state_temp;
		gpa[size - 1] = gpa_temp;
	}

	menu(id, first, last, city, state, gpa, size);
}
