#ifndef PATIENTS_H
#define PATIENTS_H
#include <vector>
#include "RandomVal.h"

struct Patient
{
	int arrivalTime;
	int startTimeOfTreatment;
	int totalTimeOfTreatment;
	int dischargeTime;
	int levelOfIllness;

	std::string firstName;
	std::string surName;

	Patient() {}
	Patient(std::string firstName, std::string surName, int clock, int levelOfIllness)
	{	
		this->arrivalTime = clock;
		this->dischargeTime = -1;
		this->startTimeOfTreatment = -1;
		this->firstName = firstName;
		this->surName = surName;
		this->levelOfIllness = levelOfIllness;
				
	}
	int getLevelOfIllness()
	{
		return 0;//levelOfIllnes; }
	} 
	int setLevelOfIllness()
	{
		int rangeOfIllness = rand() % 10 + 1;

		if (rangeOfIllness > 9)
		{
			levelOfIllness = rand() % 5 + 16; 
		}
		else if (rangeOfIllness > 7)
		{
			levelOfIllness = rand() % 5 + 11; 
		}
		else
		{
			levelOfIllness = rand() % 10 + 1;
		}

	}

	int getTotalTimeOfTreatment() { return totalTimeOfTreatment;}
	void setTotalTimeTreatment(int startTimeOfTreatment)
	{
		this->startTimeOfTreatment;
	}
};




#endif PATIENTS_H