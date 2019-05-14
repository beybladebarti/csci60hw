#include <fstream>
#include <iostream>
#include "rational.h"
using namespace std;

Rational::Rational(){
    num = 1;
    denom = 1;
  }
Rational::Rational(double a, double b){
    num = a;
    denom = b;
  }
double Rational::getNum(){
    return num;
  }
double Rational::getDenom(){
    return denom;
  }
void Rational::operator+= (Rational rhs){
    if(denom == rhs.getDenom()){
      num = num + rhs.getNum();
      denom = rhs.getDenom();
    }
    else{
      num = (denom*rhs.getNum()) + (rhs.getDenom()*num);
      denom = denom * rhs.getDenom();
    }
  }

bool operator== (Rational lhs, Rational rhs){
  double div1 = (lhs.getNum()) / (lhs.getDenom());
  double div2 = (rhs.getNum()) / (rhs.getDenom());

  if (div1 == div2){
    return true;
  }
  else{
    return false;
  }
}

Rational operator* (Rational lhs, Rational rhs){
  double num1, denom1;

  num1 = lhs.getNum()*rhs.getNum();
  denom1 = lhs.getDenom()*rhs.getDenom();

  Rational multiplication(num1, denom1);
  return multiplication;
}

Rational operator+ (Rational lhs, Rational rhs){
  double num1, denom1;

  if (lhs.getDenom() == rhs.getDenom()){
    denom1 = lhs.getDenom();
    num1 = lhs.getNum()+rhs.getNum();
  }
  else{
    num1 = (lhs.getNum() * rhs.getDenom())+(lhs.getDenom() * rhs.getNum());
    denom1 = lhs.getDenom() * rhs.getDenom();
  }

  Rational addition(num1, denom1);
  return addition;
}
