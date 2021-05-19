#ifndef _CONTACT_H
#define _CONTACT_H

#include <string>
using namespace std;
#include "type.h"

class Contact
{
protected:
  string name;

  type contact_type;

public:
  virtual string getName() = 0;

  virtual type getType() = 0;

  Contact(string _name, type _type);
};
#endif
