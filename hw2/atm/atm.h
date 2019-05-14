#ifndef ATM_H
#define ATM_H
#include <fstream>
#include <iostream>
#include "account.h"
using namespace std;

class Atm {
public:
  Atm();
  Atm(int a, int b);
  int getTens();
  int getTwenties();
  void emptyAtm();
  void get_cash(int amount, Account& b);
  void operator+= (Atm& rhs);
  void restock(int new20s, int new10s);
private:
  int tens, twenties;
};


bool operator== (Atm lhs, Atm rhs);
std::ostream& operator<< (std::ostream& out, Atm a);

#endif
