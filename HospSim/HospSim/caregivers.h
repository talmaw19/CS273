#pragma once
#ifndef CAREGIVERS_H
#define CAREGIVERS_H
#include <vector>
#include <iostream>
#include <ctime>
#include "EmergencyRoom.h"
#include "TreatmentRoom.h"
#include "Hospital.h"
#include "Patient.h"
#include "Random.h"

using namespace std;
Random my_rand;

class Caregivers
{
public:
	bool servingPatients; 
	int treatmentTime = 0;// treatment time starts at 0 
	int numberOfCareGivers; 
	Hospital *hospital;
	EmergencyRoom *ERroom;
	Patient *patient;

	//virtual int getNumOfCareGivers() = 0; // keep track of the cargivers
	//virtual void setNumOfCG(int numOfCareGiver) = 0;
	//virtual int getTreatmentTime() = 0; // applies random value inorder to treat patients
	//virtual int setTreatmentTime() = 0; // will return a random integer between 1-10 for a nurse or 1-20 for a doctor


	Caregivers(int treatmentTime, int servingPatients, EmergencyRoom* r, Hospital* r1) : treatmentTime(0), servingPatients(false), hospital(), ERroom() 
	{}
	void updatePa(int clock)
	{
		if (servingPatients == false)
		{
			if(ERroom -> getIllestpatient() != 0)
			{
//				patient = ERroom->highPriority();
				patient->setTTT(clock + treatmentTime); //sets the treatment time to the current time + the total time of the treatment
				servingPatients = true;
				treatmentTime = my_rand.next_int(20) + 1;
				//ERroom -> // patient that has been treated
			}
			else if (ERroom->getLowestIll() != 0)
			{
			//	patient = ERroom->lowPriority();
				patient->setTTT(clock + treatmentTime); // sets the treatment time to the current time + the total time of the treatment
				servingPatients = true;
				treatmentTime = my_rand.next_int(20) + 1;
				//ERroom -> // patient that has been treated
			}
			else if (patient->getDischarge() < clock)
			{
				patient->setDischargeTime(clock);
				hospital->setTreatedPatients(patient);
				servingPatients = false;
			}
		}
	}
};



#endif 