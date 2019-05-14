#include <fstream>
#include <iostream>
#include "rational.h"
using namespace std;

int main(){
  Rational test1;
  Rational test2(2, 4);
  Rational test3(5, 10);
  Rational test4(4, 7);
  Rational test5(8, 4);
  Rational test6(8, 4);

  test2 += test5;
  test3 += test5;

  Rational testAdd = test5 + test6;
  Rational testAdd2 = test4 + test5;

  cout<<"Expected Value: 16, 4. "<<"Real Value: "<<testAdd.getNum()<<", "<<testAdd.getDenom()<<endl;
  cout<<"Expected Value: 72, 28. "<<"Real Value: "<<testAdd2.getNum()<<", "<<testAdd2.getDenom()<<endl;

  cout<<"Expected Value: 10, 4. "<<"Real Value: "<<test2.getNum()<<", "<<test2.getDenom()<<endl;
  cout<<"Expected Value: 100, 40. "<<"Real Value: "<<test3.getNum()<<", "<<test3.getDenom()<<endl;

  Rational testMult1(3, 5);
  Rational testMult2(7, 8);

  Rational testMult3 = testMult1 * testMult2;

  cout<<"Expected Value: 21, 40. "<<"Real Value: "<<testMult3.getNum()<<", "<<testMult3.getDenom()<<endl;

  if (test5 == test6){
    cout<<"Expected Response has worked. Test5 == Test6 "<<endl;
  }
  else {
    cout<<"Expected Response has not worked. Test5 != Test6 "<<endl;
  }

  if (test4 == test5){
    cout<<"Expected Response has not worked. Test4 == Test5 "<<endl;
  }
  else{
    cout<<"Expected Response has worked. Test4 != Test5 "<<endl;
  }


}
