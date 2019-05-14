#include <fstream>
#include <iostream>
#include "account.h"
#include "atm.h"
using namespace std;

int main(){
  Account account1(100);
  Account account2(260);
  Account account3;

  Atm atm1(20, 40);
  Atm atm2(50, 80);


  cout<<"Expected value: 3 twenties. Real value: "<<endl;
  atm1.get_cash(60, account1);
  cout<<"Expected value: 2 twenties and 1 ten. Real value: "<<endl;
  atm2.get_cash(50, account2);


  cout<<"Expected value (ATM1): 37 twenties and 20 tens. Actual value: "<<endl;
  cout<<atm1<<endl;
  cout<<"Expected value (ATM2): 78 twenties and 49 tens. Actual value: "<<endl;
  cout<<atm2<<endl;

  Atm atm3(10, 10);
  Atm atm4(10, 10);

  if (atm3 == atm4){
    cout<<"The test has worked, atm3 == atm4. "<<endl;
  }
  else
    cout<<"The test has not worked, atm3 != atm4. "<<endl;

  if (atm1 == atm3)
    cout<<"The test has not worked, atm1 == atm3. "<<endl;
  else
    cout<<"The test has worked, atm1 != atm3. "<<endl;

  atm3+=atm4;
  cout<<"Expected value (ATM3): 20 twenties and 20 tens. Actual value: "<<endl;
  cout<<atm3<<endl;
  cout<<"Expected value (ATM4): 0 twenties and 0 tens. Actual value: "<<endl;
  cout<<atm4<<endl;
}
