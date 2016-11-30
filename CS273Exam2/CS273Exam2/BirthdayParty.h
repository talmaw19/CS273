
#ifndef _BIRTHDAY_PARTY_H_
#define _BIRTHDAY_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "BirthdayPartyTicket.h"

// FIXME 2: Create BirthdayParty and BirthdayPartyTicket to host birthday parties!
// FIXME 3: Update PartyFactory::factory() to allow it to be the ONLY method for creating a BirthdayParty
/**
* BirthdayParty is derived from Party
*/
class BirthdayParty : public Party
{
private:
	std::list<std::string> room;
public:
	PartyTicket * add(std::string name)
	{ 
	// a person is added to the front of the line 
		room.push_front(name); 
		// get iterator to the front of the room (this points to the recently added party goer)
		std::list<std::string> ::iterator it = room.begin();
		 // create a new BIRTHDAY party ticket (BIRTHDAY PartyTicket) with its constructor
		//            Pass to the constructor "this" party, and the iterator from step 2
		PartyTicket * bPartyTicket = new BirthdayPartyTicket(this, it);
		//return this new party ticket
		return bPartyTicket;
	}
	void list()
	{
		std::list<std::string>::iterator it = room.begin();
		for (it; it != room.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	void remove(std::list<std::string>::iterator it) {
		// removes a person fromt the party 
		room.erase(it);
	}
};

#endif
