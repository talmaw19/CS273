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
using namespace std;

//Random my_rand;
class Hospital
{
public:
	queue<Patient*> treatedPatients;
	double pAVGarrival;
	int number_Patients;
	int waitTime;

	EmergencyRoom *patient; // points to a user 
	Hospital() // no argument constructor
	{
		pAVGarrival = 0;
		waitTime = 0;
	}
	Hospital(EmergencyRoom* erPat)
	{
		patient = erPat;
		pAVGarrival = 0;
		number_Patients = 0;
	}

	void setpArrival(double avg) 
	{
		this->pAVGarrival = avg;
		waitTime += waitTime;

	}
	int getWaitTime()
	{
		return waitTime;
	}
	int getTreatedPatients()
	{
		return number_Patients; // returns the number of patients that have been treated 
	}
	void setTreatedPatients(Patient* tPatients)
	{
		treatedPatients.push(tPatients);
	}
	map <string, string> name;
	map <string, string>::iterator it;
	string find;
	void findPatient()
	{
		int lookUP;
		lookUP = 0; 
		
		cout << " who are you looking for? " << endl;
		cin >> find;
		for (it = name.begin(); it != name.end(); it++)
		{
			if (it->first != find)
			{
				cout << "sorry :/ we are not able to locate this patient in the hospital 273ville";
			}
			else if (it->first == find)
			{
				lookUP++;
				cout << "the patient we're looking for is: " << it->first << endl;
				cout << "thier past illness level was: " << endl;
			}
			
	}
		
	}
	void display()
	{

		for (it = name.begin(); it != name.end(); it++)
		{
			cout << "The patient First Name: " << it->first << '\n' << endl;
			cout << "the patient Last Name" << it->second << endl;
		}
	}
};
#endif
