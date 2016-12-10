#pragma once
#ifndef WRQUEUE_H
#define WRQUEUE_H

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include "RandomVal.h"
#include "HospitalRecords.h"
#include "Patients.h"



class WaitingRoom
{
private:
	int totalWaitTime;
	int levelOfIllness; // level of illness
	int visitTime; 
	int numberOfDoctors;
	int numberOfNurses;
	int totalTreatmentDoc; // total treatment time for a doctor 
	int totalTreatmentNur; // total treatment time for a nurse 
	int patientsTreated; 
	double frequency;

	Patient patient;
	HospitalRecords hospitalRec;
	std::vector <std::string> firstNamesofEP; // a vector of first names of every patients
	std::vector <std::string> surNamesofEP; // a vector of sur names of every patients

public:
	WaitingRoom()
	{
		visitTime = 0; // waiting time starts at 0
		patientsTreated = 0; // at the beinging 0 for the number of patients treated
	}
	/*void cast()
	//{
	
	} */
	double randomNum() { return double(rand()) / RAND_MAX; }  

	void newTime(int clock)
	{
		//if() complete 
		if (randomNum() < frequency)
		{
			if (numberOfDoctors > 0 || numberOfNurses > 0)
			{
				if (levelOfIllness > 10)
				{
					
				}
			}
		}
	}
};



#endif // !WRQUEUE_H
