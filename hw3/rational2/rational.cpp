#include <fstream>
#include <iostream>
#include <math.h>
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
void Rational::reduce(){
  for (int i = denom * num; i > 1; i--){
    if ((fmod(denom, i) == 0) && (fmod(num, i) == 0)) {
      denom = denom/i;
      num = num/i;
    }
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
  multiplication.reduce();
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
  addition.reduce();
  return addition;
}
