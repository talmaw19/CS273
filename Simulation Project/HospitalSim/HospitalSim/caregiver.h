#ifndef CAREGIVER_H
#define CAREGIVER_H

#include<string>

#include<ctime>

#include<cstdlib>

class CareGiver {

private:
	int numberOfCareGivers; // user input 
	int treatmentTime; // random num

public:

	CareGiver() {}
	virtual int getNumOfCareGivers() = 0; // keep track of the cargivers
	virtual void setNumOfCG(int numOfCareGiver) = 0; 
	virtual int getTreatmentTime() = 0; // applies random value inorder to treat patients
	virtual int setTreatmentTime() = 0; // will return a random integer between 1-10 for a nurse or 1-20 for a doctor

};

class Doctor : public CareGiver {
private:
	int numOfCareGivers;
	int treatmentTime;

public:

	Doctor(): CareGiver() {}
	int getNumOfCareGiver() {
		return numOfCareGivers;
	}

	void setNumOfCareGiver(int numOfCareGivers) {
		this->numOfCareGivers = numOfCareGivers;
	}

	int getTreatmentTime() {
		return treatmentTime;
	}

	int setTreatmentTime() {
		return rand() % 20 + 1; // range 1-20 for  a doctor 
	}

};

class Nurse : public CareGiver {

private:
	int numOfCareGiver;
	int treatmentTime;
public:
	Nurse() : CareGiver() {}
		
	int getNumOfCareGiver() {
		return numOfCareGiver;
	}
	void setNumOfCareGiver(int numOfCareGivers) {
		this->numOfCareGiver = numOfCareGiver;
	}
	int getTreatmentTime() {
		return treatmentTime;
	}

	int setTreatmentTimeNur() {
		return  rand() % 10 + 1; //1-10 minutes to treat a patient 
	}
};

#endif // !CAREGIVER_H

