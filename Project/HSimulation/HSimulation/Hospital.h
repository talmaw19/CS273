#pragma once
#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <queue>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <ctime>
#include "EmergencyRoom.h"
#include "Patient.h"
#include "Random.h"


//Random my_rand;
struct Hospital
{// this records the number of patients 
int vNumber; 
	int patIllness; // patients that will ill that got treated 
	Hospital(int vNumber, int patIllness) : vNumber(vNumber), patIllness(patIllness) {}

	/*queue<Patient*> treatedPatients;
	double pAVGarrival;
	int number_Patients;
	int waitTime;
	std::map<std::string, std::vector<int>> hospitalRec;
	Hospital *hospitalRecords;
	std::string pname;
	
	
	
	void setHospitalRecords(Hospital* hospitalRecords) {
		this->hospitalRecords = hospitalRecords;
	}
	void addRecords(std::string name, std::vector<int> illnessPerVisit, int levelOfIllness)
	{
		illnessPerVisit.push_back(levelOfIllness);
		this->pname = name;
		hospitalRec.insert(std::pair <std::string, std::vector<int>>(name, illnessPerVisit));
	}
*/
	/*void setpArrival(double avg)
	{
		this->pAVGarrival = avg;
		waitTime += waitTime;

	}*/
	
};
#endif
