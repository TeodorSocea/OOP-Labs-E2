#ifndef _PRIETEN_H
#define _PRIETEN_H


#include <string>
using namespace std;
#include "Cunoscut.h"
#include "type.h"
#include "Contact.h"

class Prieten : public Cunoscut, public Contact {
  private:
    string birthday;

    string address;


  public:
    virtual string getName();

    virtual type getType();

    string getNumber();

    string getBirthday();

    string getAddress();

    Prieten(string _name, type _type, string _number, string _birthday, string _adress);


  private:
    string number;

};
#endif
