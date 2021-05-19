#ifndef _CUNOSCUT_H
#define _CUNOSCUT_H


#include "Contact.h"
#include <string>
using namespace std;
#include "type.h"

class Cunoscut : public Contact {
  private:
    string number;


  public:
    virtual string getName();

    virtual type getType();

    string getNumber();

    Cunoscut(string _name, type _type, string _number);

};
#endif
