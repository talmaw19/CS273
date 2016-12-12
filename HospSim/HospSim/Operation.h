#pragma once
#ifndef OPERATION_H
#define OPERATION_H

#include "Patient.h"
#include "caregivers.h"
#include "EmergencyRoom.h"
#include "Hospital.h"
#include "Random.h"

class Operation
{
private:
	int totalTreatementTime;
	int clock;

	//pointers 
	EmergencyRoom* ERroom;
	Hospital* hospital;

	int patientIllness(const std::string &prompt, int low, int high)
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

public:
	Operation() // no argument constructor
	{
		ERroom = new EmergencyRoom(); // creats new ER 
		totalTreatementTime = 10080; // time in weeeks
		hospital = new Hospital(ERroom); // hospital has an er room
	}

public:

};



#endif // !WAITINGROOM_H

