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
	int totalTreatment;
	int numberOfPatients;
	int maximumTime;
	int waitTime;
	int arrivalTime; // avg arrival time
	int dischargeTime;
	int numDoctors, numNurses;
	priority_queue<Patient *> ERPriority; //queue of patiants in hospital
	vector <Caregiver> cqueue; // queue of caregivers of both doctors and nurses that are avaliable
	Doctor *doctor;
	Nurse *nurse;
public:
	EmergencyRoom() : totalTreatment(0), numberOfPatients(0) {}
	multimap <string, Hospital> hospitalRecMap;
	string name;

	int patientInc;

	void update(int clock)
	{
		int patients;

		// update the emergency room clock and add a new patient that comes in 
		//if () a new 
		//Patient *patient = new Patient(name, clock);
	}
	
	void Set_arrival_rate(double arrivalTime) {
		this->arrivalTime = arrivalTime;
	}
	double getAVG() {
		if (numberOfPatients == 0) // if patients havent been treated then return 0
		{
			return 0;
		}
		else
		{
			return ((totalTreatment / numberOfPatients)); // if there is patients that has been treated then divided that from the total treatement time
		}
	}

	void  Setcg(int numDoctors, int numNurses) // sets the care givers 
	{ // points a pointer to its own address 
		this->numNurses = numNurses;
		this->numDoctors = numDoctors;
		
		for (int i = 0; i < numDoctors; i++)// when i = 0 and less than the current doctor and and i increments 
		{
			Doctor *doctor = new Doctor(true);
			cqueue.push_back(doctor);// adds a doctor at the end of the current element
		}
		for (int j = 0; j < numNurses; j++)
		{
			Nurse *nurse = new Nurse(true);
			cqueue.push_back(nurse);
		}
	}

	void updateNew(int clock)
	{};


#endif
