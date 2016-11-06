#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>

/**
The Bank has Customers.  Each Customer has a name, address, age, and telephone number.
Additionally, there are specialized types of Customers: Adult, Senior, and Student.
Each type of Customer has its own checking and savings interest rates,
as well as its own checking and overdraft fees.

@author: Ed Walker
*/
class Customer // FIXME: Complete the implementation!
{
protected:
	int age;
	std::string name;
	std::string address;
	std::string telephone_number;
	int customer_number;
	double savings_interest;
	double check_interest;
	double check_charge;
	double overdraft_penalty;

public:
	Customer(int a, std::string n, int custNum, std::string add, std::string teleNum)
	{
		age = a;
		name = n;
		customer_number = custNum;
		address = address;
		telephone_number = teleNum;
	}
	int getAge()
	{
		return age;
	}
	std::string getName()
	{
		return name;
	}
	int getCustomersNum()
	{
		return customer_number;
	}
	std::string getAdress()
	{
		return address;
	}
	std::string getTelephoneNum()
	{
		return telephone_number;
	}
	double getCheckIntrest()
	{
		return check_interest;
	}
	double getSavingInterest()
	{
		return savings_interest;
	}
	double getCheckCharge()
	{
		return check_charge;
	}
	double getOverdraftPenatly()
	{
		return overdraft_penalty;
	}

	void setAge(int cusAge)
	{
		age = cusAge;
	}
	void setName(std::string cusName)
	{
		name = cusName;
	}
	void setAddress(std::string cusAddress)
	{
		address = cusAddress;
	}
	void setTelephone(std::string tnum)
	{
		telephone_number = tnum;
	}
	void setCustomers_Number(int customersNumber)
	{
		customer_number = customersNumber;
	}




};

class Senior : public Customer
{
public:
	Senior(int a, std::string n, int custNum, std::string add, std::string teleNum) : Customer(a, n, custNum, add, teleNum)
	{
		check_charge = 12.00;
		check_interest = 2.5;
		savings_interest = 4.50;
		overdraft_penalty = 25;
	}

};

class Adult : public Customer
{
public:
	Adult(int a, std::string n, int custNum, std::string add, std::string teleNum) : Customer(a, n, custNum, add, teleNum)
	{
		check_charge = 15.00;
		check_interest = 5.5;
		savings_interest = 7.50;
		overdraft_penalty = 30;
	}

};

class Student : public Customer
{
public:
	Student(int a, std::string n, int custNum, std::string add, std::string teleNum) : Customer(a, n, custNum, add, teleNum)
	{
		check_charge = 3.00;
		check_interest = 1.5;
		savings_interest = 1.50;
		overdraft_penalty = 20;
	}

};
#endif