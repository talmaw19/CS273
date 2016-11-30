#ifndef _BIRTHDAY_PARTY_TICKET_H_
#define _BIRTHDAY_PARTY_TICKET_H_

#include <list>
#include <string>
#include "Party.h"
#include "PartyTicket.h"

class BirthdayPartyTicket : public PartyTicket
{
private:
	Party * the_party; // points to this_party
	std::list<std::string>::iterator me; // creats an itrator to the person that has the ticket 
public:

	BirthdayPartyTicket(Party* the_party, std::list<std::string>::iterator me) : the_party(the_party), me(me) {}

	void leave();
};

#endif