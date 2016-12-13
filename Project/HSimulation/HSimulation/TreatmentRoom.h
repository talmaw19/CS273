#pragma once
#ifndef TREATMENTROOM_H
#define TREATMENTROOM_H
#include "Patient.h"
#include "caregivers.h"
#include "EmergencyRoom.h"
#include "Hospital.h"
#include "Random.h"
#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

fstream fin("residents_of_273ville.txt");
fstream flast("surname_of_273ville.txt");

class TreatmentRoom
{
private:
	int totalTreatement;
	int clock;
	int servingPatients;
	//pointers 
	EmergencyRoom* ERroom;
	/*Hospital* hospital;
	Caregiver* cgivers;*/
	priority_queue<Patient*> ERPqueue; // a queue of the patiants in the hospital 
	Patient *pequeue; // pointer to queue of the patients that are entering the emergency room

	double ifPatientsArrive = (double)rand() / double(RAND_MAX);
	if (ifPatientsArrive < arrivaltime && !pequeue->pequeue.empty())
	{
		double rangeOfIllness() = (double)rand() / double(RAND_MAX);
		int levelIll;
		if (rangeOfIllness <= .7)// Illnesses is less than or equal to 70% 
		{
			levelIll = (rand() % 10) + 1; // it occurs between 1-10 
		}
		else if (rangeOfIllness > .7 && rangeOfIllness <= .9)// Illnesses is less than or equal to 90% and greater than 70% 
		{
			levelIll = (rand() % 5) + 11;// it occurs between 10-15
		}
		else // if greater than 90 then the lvl of illness is between 15-20
		{
			levelOfIllness = (rand() % 5) + 16;
		}

		pequeue->pequeue.front()->levelIll = levelIll;
		Patient *patient = pequeue->pequeue.front();
		patient->arrivalTime = clock;
		ERPqueue.push(patient);
		pequeue->pequeue.pop_front();
		int times = histoyrecordmap.count(patient->name); // counts and then displays how many times the have been in the ER
	}
	//void welcome()
	//{

	//	cout << " Welcome to the 273-ville Emergency Room Simulator " << endl;
	//	cout << "Enter the number of nurses you would like in the ER " << endl;
	//	int numberOfNurses = patientIllness("", 1, 10);
	//	cout << "Enter the number of doctors you would like in the ER " << endl;
	//	int numberOfDoctors = patientIllness("", 1, 10);

	//	int avgPatientarrival = patientIllness("enter the amount of patients per hour", 1, 59);
	//	cgivers = new Caregivers(numberOfDoctors, numberOfNurses, ERroom, hospital);
	//}

	//int patientIllness(const std::string &prompt, int low, int high)
	//{
	//	if (low >= high) // invalid range
	//		throw std::invalid_argument("invalid range specified");

	//	std::cin.exceptions(std::ios_base::failbit);
	//	int num = 0;
	//	while (true) {
	//		try {
	//			while (true) {
	//				cout << prompt;
	//				cin >> num;
	//				if (num >= low && num <= high) { // within the specified range
	//					cout << endl;
	//					return num;
	//				}
	//			}
	//		}
	//		// catches any found errors
	//		catch (std::ios_base::failure)
	//		{
	//			cout << "invalid numeric string -- please try again\n";
	//			cin.clear();
	//			cin.ignore(std::numeric_limits<int>::max(), '\n');
	//		}
	//	}
	//}

public:
	TreatmentRoom() // no argument constructor
	{
		ERroom = new EmergencyRoom(); // creats new ER 
		totalTreatement = 10080; // time in weeeks
		hospital = new Hospital(ERroom); // hospital has an er room
	}
	TreamentRoom(int servingPatient, int clock, int totaltime)
	{
		this->servingPatient;
		this->clock = clock;
		this->totalTreatment = totaltime;
	}

	//	map <string, string> patientNames;
	vector < string> names = vector <string>(2000);//  

	void patientList()
	{
		string fullName;
		string *pointer = names.data();
		if (fin.fail() || flast.fail()) {
			cout << "fail, sorry can't open this file";
		}
		else
		{

			string firstName, lastName;
			while (getline(fin, firstName) && getline(flast, lastName))
			{
				fullName = firstName + " " + lastName;
				*pointer = fullName;
				++pointer;
			}
			//patientNames.insert(make_pair(firstName, lastName));
		}

	}

}


void update(int clock)
{
	for (auto it; names.begin()< names.end(); it++)
	{
		illnesslvl = double(rand()) / double(RAND_MAX);
		if (illnesslvl < .5)
		{
			Patient *patient = NULL;
			patient = new Patient(*it, 0, 0);
		}
	}
}


void menu()
{
	//		cout << "Patients wait time is: " << googlehospital-> getWaitTime << endl;
	int pick = 0;
	TreatmentRoom tr;

	cout << " Pick from the menu; what do you want to see? " << endl;
	cout << "1) View the Treatment Room " << endl;
	cout << "2) View the list of patients " << endl;
	cout << "3) Look up a Patient " << endl;
	cout << "4) Quit/ goodbye" << endl;
	cin >> pick;

	switch (pick)
	{

	case 1: { cout << "  " << endl;
		tr.update(); }
	case 2: {cout << "  " << endl;
		tr.patientList(); // displays the patients 
		hospital->addRecords();
	}
	case 3: {cout << " " << endl;
		tr.patientsList(); }
	case 4: {cout << "  " << endl; }
	default:
	{cout << "enter a number between 1 and 4" << endl; break; }

	}

}



};



#endif // TREATMENTROOM