#ifndef HOSPITALRECORDS_H_

#define HOSPITALRECORDS_H_




#include <vector>
#include <map>
#include <iostream>


struct HospitalRecords // use  maps for this 

{

	std::string name;
	int levelOfIllness;
	std::map<std::string, std::vector<int>> hospitalRec;
	HospitalRecords* hospitalRecords;
	HospitalRecords() {}

	void setHospitalRecords(HospitalRecords* hospitalRecords) {
		this->hospitalRecords = hospitalRecords;
	}

	void addRecords(std::string name, std::vector<int> illnessPerVisit, int levelOfIllness)

	{
		illnessPerVisit.push_back(levelOfIllness);
		this->name = name;
		hospitalRec.insert(std::pair <std::string, std::vector<int>>(name, illnessPerVisit));
	}

	std::string getFName() {	return name;}

	void listPatients() {

		std::map<std::string, std::vector<int>>::iterator it;

		for (it = hospitalRec.begin(); it != hospitalRec.end(); it++)
		{
			// 
		}
	}
};

#endif