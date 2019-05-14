#include <fstream>
#include <iostream>
#include "atm.h"
using namespace std;


Atm::Atm (){
  tens = 0;
  twenties = 0;
}

Atm::Atm(int a, int b){
  tens = a;
  twenties = b;
}

int Atm::getTens(){
  return tens;
}
int Atm::getTwenties(){
  return twenties;
}
/* The get_cash function first checks to see if the amount requested is a valid amount

*/
void Atm::get_cash(int amount, Account& b){
  int numTens, numTwenties;

  if (amount%10 != 0){
    cout<<"Invalid Amount. Please try again. "<<endl;
    return;
  }
  else if(amount>((tens*10)+(twenties*20))){
    cout<<"ATM has insufficient funds. Please try again. "<<endl;
    return;
  }
  else if(amount>b.GetBalance()){
    cout<<"Your account has insufficient funds. Please try again. "<<endl;
    return;
  }
  else if(amount%20==0){
    numTwenties = amount/20;
    twenties -= numTwenties;
    b.Withdraw(amount);
    cout<<"You have withdrawn "<<numTwenties<<" twenties. "<<endl;
  }
  else {
    numTens = 1;
    numTwenties = amount/20;
    tens -= numTens;
    twenties -= numTwenties;
    b.Withdraw(amount);
    cout<<"You have withdrawn "<<numTwenties<<" twenties and "<<numTens<<" ten. "<<endl;
  }
}
void Atm::emptyAtm(){
  twenties = 0;
  tens = 0;
}
void Atm::operator+= (Atm& rhs){
  twenties = twenties + rhs.getTwenties();
  tens = tens + rhs.getTens();
  rhs.emptyAtm();
}
void Atm::restock(int new10s, int new20s){
  twenties += new20s;
  tens += new10s;
}
bool operator== (Atm lhs, Atm rhs){
  if ((lhs.getTwenties() == rhs.getTwenties()) && (lhs.getTens() == rhs.getTens())){
    return true;
  }
  else
    return false;
}
std::ostream& operator<< (std::ostream& out, Atm a){
  out<<"Tens in ATM: "<<a.getTens()<<endl;
  out<<"Twenties in ATM: "<<a.getTwenties()<<endl;
  return out;
}
