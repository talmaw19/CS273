#ifndef EVERYPATIENT_H_
#define EVERYPATIENT_H_

#include <iostream>
#include<vector>
#include<string>
#include <fstream>

using namespace std;
class AllPatients {
private:
	vector<string> PatientsVector;
public:
	void addPeopleToVector() {
		ifstream fin;
		ifstream flast;
	
		fin.open("residents_of_273ville.txt");
		flast.open("surname_of_273ville.txt");
				
		if (fin.fail()) {
			cout << "fail";
		}
		else if (flast.fail())
		{
			cout << "fail";
		}
		else 
		{
			string firstName;
			while (getline(fin, firstName))
			{
				cout << firstName << endl;

				}
			string lastName;
			while (getline(flast, lastName))
			{
				cout << lastName << endl;
			}

			//PatientsVector.push_back(); complete this
		}
	}
};


#endif // !EVERYPATIENT_H_
