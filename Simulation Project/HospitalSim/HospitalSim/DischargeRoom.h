#ifndef DISCHARGEROOM_H
#define DISCHARGEROOM_H

#include <queue>
#include "Patients.h"
#include "WaitingRoom.h"
#include "caregiver.h"


class DischargeRoom
{
private: 
	std::queue<Patient *> the_pqueue; // the queue of patients in the discharge 
	int dischargeTime;
	int totalTreatmentTime;
	int servedPatients;
public:
	DischargeRoom(): totalTreatmentTime(0), servedPatients(0) {}
	void setDischargeTime(int dischargeTime) {
		this->setDischargeTime = dischargeTime;
	}
	int getDischargedTime() { return dischargeTime; }
	int getTotalTreatmentTime() { return totalTreatmentTime; }
	int getServedPatients() {return servedPatients;	}

};
#endif // !DISCHARGEROOM_H

