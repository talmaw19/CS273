#pragma once
#ifndef EMERGENCYROOM_H
#define EMERGENCYROOM_H
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <ctime>
#include "Hospital.h"
#include "Patient.h"


using namespace std;

class EmergencyRoom
{
private:
	int totalTreatementTime;
	int numberOfPatients;
	int maximumTime;
	int waitTime;
	int arrivalTime;
	int dischargeTime;
public:
	priority_queue<Patient *> highPriority;
	priority_queue<Patient *> lowPriority;

	string name;
	
	int patientInc;
	EmergencyRoom() {}
	void update(int clock)
	{
		// update the emergency room clock and add a new patient that comes in 
		//if () a new 
		Patient *patient = new Patient(name, clock);
	}

	int getPatientsTreated(int treated)
	{
		numberOfPatients = treated;
		return numberOfPatients;
	}
	int getLowestIll()
	{
		return lowPriority.size(); //returns the lowest ill in the priotiy queue
	}
	Patient *getLowestIll(int treated)
	{
		return lowPriority.top(); // returns the lowest ill 
	}
	int getIllestPatient()
	{
		return highPriority.size(); // returns the illest in the priotiy queue
	}

	Patient *getIllestpatient()
	{
		return highPriority.top();// returns the illest  
	}
	void treatedIllestP()
	{
		highPriority.pop();// removes this elemet after it has been treated
	}
	void treatedLowestP()
	{
		lowPriority.pop(); // removes this element after it has been treated
	}
	
	int getTTT(int vist) // get total treatment time for this visit 
	{
		waitTime = vist;
		return waitTime;
	}
	friend class Patient;
};




#endif
