#ifndef EMERGENCYROOM_H_
#define EMERGENCYROOM_H_


#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <ios>
#include "WRQueue.h"// a queue for waiting room
//#include "TreatmentRoomQueue.h"
//#include "DischargeRoomQueue.h"
//#include "Citizens.h"
#include "RandomVal.h"
#include "CareGiver.h"
#include "HospitalRecords.h"


using std::cout;
using std::cin;
using std::string;

class EmergencyRoom : HospitalRecords
{
private:
	unsigned int numberOfDoctors;
	unsigned int numberOfNurses;
public:

	EmergencyRoom() {}
	EmergencyRoom(unsigned int numberOfDoctors, unsigned int numberOfNurses)
	{
		// creats doctors 
		// creats nurses 	
	}
	void listTreatedPatients() {}	//listPatients();}
	void findPatientrecords() {}
	void endOfProgram() {
		std::cout << "End Of Program...";
		exit(0);
	}
	void invalidOption() {
		std::cout << "invalidO";
	}
	int readInt(const std::string &prompt, int low, int high)
	{
		if (low >= high) // invalid range
			throw std::invalid_argument("invalid range specified");

		std::cin.exceptions(std::ios_base::failbit);
		int num = 0;
		while (true) {
			try {
				while (true) {
					std::cout << prompt;
					std::cin >> num;
					if (num >= low && num <= high) { // within the specified range
						std::cout << std::endl;
						return num;
					}
				}
			}
			catch (std::ios_base::failure) {
				std::cout << "Bad numeric string -- try again\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			}
		}
	}

	void statsMenu() {
		int choice = 0;
		std::cout << "1,2,3\n";
		choice = readInt("Pick one of the above options: ", 1, 2);
		switch (choice)
		{
		case 1: listTreatedPatients();
			statsMenu();
			break;
		case 2: findPatientrecords();
			statsMenu();
		case 3: endOfProgram();
			break;
		default:  invalidOption();
			statsMenu();
			break;
		}
	}
	void showStats() {
		std::cout << "Dr.T:  Everything went very well, these are the results if you are interested...\n\n";
		//	std::cout << "The Patients Treated: " << dischargeRoomQueue->getPatientsTreated();//->getPatientsTreted();
			//	std::cout << "Average visit time: " << dischargeRoomQueue->getVisitTime() / dischargeRoomQueue->getPatientsTreated();
		std::cout << "\n\nPlease Select from the menu below...\n\n";
		statsMenu();
	}
};

#endif