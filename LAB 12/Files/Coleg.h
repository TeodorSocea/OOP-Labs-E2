#ifndef _COLEG_H
#define _COLEG_H

#include <string>
using namespace std;
#include "Prieten.h"
#include "type.h"
#include "Contact.h"

class Coleg : public Prieten, public Contact
{
private:
  string workplace;

public:
  virtual string getName();

  virtual type getType();

  string getNumber();

  string getBirthday();

  string getAddress();

  Coleg(string _name, type _type, string _number, string _address, string _workplace);

private:
  string number;

  string address;
};
#endif
