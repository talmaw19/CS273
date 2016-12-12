#pragma once
#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include <ctime>
#include <queue>

using namespace std;
class Patient
{
public:
	string firstName;
	string lastName;
	int levelOfIllness;
	int arrivalTime;
	int treatmentTime;
	int discharge;


	Patient() //no argument constructor 
	{
		levelOfIllness = 0;
	}
	Patient(string name, int clock): arrivalTime(clock), treatmentTime(-1), firstName(name), lastName(name)
	{
		setIllness();
	}

	void setIllness()                
	{
		srand(time(NULL));

		int rangeOfIllness = rand() % 100 + 1;

		if (rangeOfIllness > 1 && rangeOfIllness <= 70 )// Illnesses is less than or equal to 70 and greater than 10 it occurs between 1-10 
		{
			levelOfIllness = rand() % 10 + 1;  
		}
		else if (rangeOfIllness > 70 && rangeOfIllness <= 90)// Illnesses is less than or equal to 90 and greater than 70 it occurs between 10-15
		{
			levelOfIllness = 10;
			levelOfIllness + rand() % 5 + 1; 
		}
		else // if greater than 90 then the lvl of illness is between 15-20
		{
			levelOfIllness = 15;
			levelOfIllness + rand() % 5 + 1;
		}
	}
	int getArrivalTime() { return arrivalTime; }
	int getDischarge() { return discharge; }
	int getlvlIllness() { return levelOfIllness; }
	
	void setDischargeTime(int time)
	{
		discharge = time;
	}
	void setTTT(int clock)
	{
		treatmentTime = clock;
	}

	
	
	
};

#endif
