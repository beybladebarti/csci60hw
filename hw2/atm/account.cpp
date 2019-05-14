#include "account.h"
#include <fstream>
#include <iostream>
using namespace std;

Account::Account(float b) {
  balance = b;
 }

Account::Account(){
  balance = 0.0;
 }

float Account::GetBalance() const {
   return balance;
 }

void Account::Withdraw(float amount) {
   balance -= amount;
 }

void Account::Print() {
   cout << "balance: " << balance << endl;
 }
