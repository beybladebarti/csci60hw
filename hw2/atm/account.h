#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <fstream>
#include <iostream>
using namespace std;

class Account {

 public:

  Account(float b);
  Account();
  float GetBalance() const;
  void Withdraw(float amount);
  void Print();
 private:
   float balance;
};

#endif
