#pragma once
#ifndef TREATMENTROOM_H
#define TREATMENTROOM_H
#include "Patient.h"
#include "caregivers.h"
#include "EmergencyRoom.h"
#include "Hospital.h"
#include "Random.h"

class TreatmentRoom
{
private:
	int totalTreatementTime;
	int clock;
	int servingPatients;
	//pointers 
	EmergencyRoom* ERroom;
	Hospital* hospital;
	Caregivers* cgivers;

	int patientIllness(const std::string &prompt, int low, int high)
	{
		if (low >= high) // invalid range
			throw std::invalid_argument("invalid range specified");

		std::cin.exceptions(std::ios_base::failbit);
		int num = 0;
		while (true) {
			try {
				while (true) {
					cout << prompt;
					cin >> num;
					if (num >= low && num <= high) { // within the specified range
						cout << endl;
						return num;
					}
				}
			}
			// catches any found errors
			catch (std::ios_base::failure) {
				cout << "invalid numeric string -- please try again\n";
				cin.clear();
				cin.ignore(std::numeric_limits<int>::max(), '\n');
			}
		}
	}

public:
	TreatmentRoom() // no argument constructor
	{
		ERroom = new EmergencyRoom(); // creats new ER 
		totalTreatementTime = 10080; // time in weeeks
		hospital = new Hospital(ERroom); // hospital has an er room
	}
	void welcome()
	{
		
		cout << " Welcome to the 273-ville Emergency Room Simulator " << endl;
		cout << "Enter the number of nurses you would like in the ER " << endl;
		int numberOfNurses = patientIllness("", 1,10);
		cout << "Enter the number of doctors you would like in the ER " << endl;
		int numberOfDoctors = patientIllness("", 1,10);

		int avgPatientarrival = patientIllness("enter the amount of patients per hour", 1, 59);
		cgivers = new Caregivers(numberOfDoctors,numberOfNurses, ERroom, hospital);
	}

	/*	int maxPatientAVG=0; 
		if (maxPatientAVG >= 1 && maxPatientAVG <= 60)
		{
			cout << "Enter the amount of patients in the hospital";
		}*/
		/*else 
			try
			{
				throw maxPatientAVG;
			}
			catch (...)
			{
				cout << "An exception occured" << endl;
			}
		}*/
	//cgivers = new Caregivers(ERroom, hospital);

	map <string, string> patientNames;
	void patientList()
	{
		fstream fin;
		ifstream flast;

		fin.open("residents_of_273ville.txt");
		flast.open("surname_of_273ville.txt");

		if (fin.fail()) {
			cout << "fail, sorry can't open this file";
		}
		else if (flast.fail())
		{
			cout << "fail, sorry can't open this file";
		}
		else
		{
			string firstName;
			while (getline(fin, firstName))
			{
				cout << firstName << endl;
			}
			string lastName;
			while (getline(flast, lastName))
			{
				cout << lastName << endl;
			}
			patientNames.insert(make_pair(firstName, lastName));
		}
		
	}
	void time()
	{
		for (clock = 0; clock < totalTreatementTime; clock++)
		{
			cgivers->updatePa(clock);
				ERroom->update(clock);
		}
	}
	void menu()
	{
//		cout << "Patients wait time is: " << hospital-> getWaitTime << endl;
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
			tr.welcome();
			tr.time(); }
		case 2: {cout << "  " << endl;
			tr.patientList();
			hospital->display();
		}
		case 3: {cout << " " << endl;
			hospital->findPatient(); }
		case 4: {cout << "  " << endl;}
		default: 
		{cout << "enter a number between 1 and 4" << endl; break; }

		}

	}

};



#endif // TREATMENTROOM