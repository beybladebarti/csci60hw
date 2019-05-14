#ifndef RATIONAL_H
#define RATIONAL_H
#include <fstream>
#include <iostream>
using namespace std;

class Rational{
public:
  Rational();
  Rational(double a, double b);
  double getNum();
  double getDenom();
  void operator+= (Rational rhs);
private:
  double num, denom;
};

Rational operator* (Rational lhs, Rational rhs);
Rational operator+ (Rational lhs, Rational rhs);
bool operator== (Rational lhs, Rational rhs);

#endif
