#ifndef PATIENT_H
#define PATIENT_H
#include <vector>
#include "Random.h"

Random my_random; // Global variable 

struct Patient
{ // 
	Patient(std::string name, int arrivalTime, int levelOfIllness)
		: name(name), arrivalTime(arrivalTime), levelOfIllness(levelOfIllness) {}

	std::string name;
	int levelOfIllness;
	int arrivalTime;
	int dischargeTime;

	/*	 compares a patient with another patient and checks if it is true:
	if level of illness is greater than another object/patient
	name is greater than the other patient
	arrival time is greate than other patient
	dischargetime is greater than other patient
	return true

	otherwise return false

	*/
	bool operator> (const Patient &otherPatient) cosnt {
		if (levelOfIllness > otherPatient.levelOfIllness)
			return true;
		else if (name > otherPatient.name)
			return true;
		else if (arrivalTime > otherPatient.arrivalTime)
			return true;
		else if (dischargeTime > otherPatient.dischargeTime)
			return true;
		else
			return false;

	}

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
};




#endif PATIENT_H