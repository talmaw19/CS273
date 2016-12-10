#ifndef WAITINGROOM_H
#define WAITINGROOM_H

#include <queue>
#include <iostream>
#include <string>
//#include "Citizens.h" 
#include "Patients.h"
#include "RandomVal.h"
//#include "HospitalRecords"

class WaitingRoomQueue
{
private: 
	int totalWaitTime;
	int numberOfDoctors;
	int numberOfNurses;
	int visitTime;
	int patientsTreated;
	
public: 
	WaitingRoomQueue() :totalWaitTime(0), patientsTreated(0) {}
	
	int getTotalWaitTime()
	{
		return totalWaitTime;
	}
	int getPatientsTreated()
	{
		return patientsTreated;
	}
	int getVisitTime()
	{
		return visitTime;
	}

	
};



#endif WAITINGROOM_H


