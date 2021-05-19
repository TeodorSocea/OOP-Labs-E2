#ifndef _AGENDA_H
#define _AGENDA_H

#include <vector>
#include "Contact.h"
#include <string>
using namespace std;

class Agenda
{
private:
  vector<Contact> contact_list;

public:
  Contact lookUp(string _name);

  Contact getFriends();

  void remove(string _name);

  void add(const Contact &_contact);
};
#endif
