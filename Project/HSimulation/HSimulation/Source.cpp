#include <iostream>
#include <string>
#include "Hospital.h"
#include <map>
#include "TreatmentRoom.h"

using namespace std;
int main()
{

	srand(time(NULL)); // seeds the time

	TreatmentRoom tr;
	//tr.welcome();
	tr.menu();
	tr.patientsList();


	return 0;
}
