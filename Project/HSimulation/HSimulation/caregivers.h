#pragma once
#ifndef CAREGIVERS_H
#define CAREGIVERS_H

#include "Patient.h"

class Caregiver 
{
public: 
	Caregiver(bool noPatient) : noPatient(noPatient) {}
	int isnotfreewhen = 0;
	bool noPatient;
	int servePatient(Patient*) = 0; // overrides the derived class
	void avaliblity(int recent)
	{
		if (isnotfreewhen < recent)
		{
			noPatient = true;
		}
		else
		{
			noPatient = false;
		}
	}
};
class Doctor : public Caregiver
{
public:
	
	Doctor(bool noPatient) :Caregiver(noPatient) {}
	int serveParient(Patient*) 
	{
		int docWaitTime = (rand() % 20) + 1;
		this->noPatient = false;
		return docWaitTime;
	}
};

class Nurse : public Caregiver
{
	Nurse(bool noPatient) :Caregiver(noPatient) {}
	int serveParient(Patient*)
	{
		int nurWaitTime = (rand() % 10) + 1;
		this->noPatient;
		return nurWaitTime;
	}
};

#endif