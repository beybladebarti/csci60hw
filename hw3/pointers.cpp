#include <fstream>
#include <iostream>
using namespace std;

int* Greater(int* a, int* b){
  if (*a > *b){
    return a;
  }
  else
    return b;
}

void IncrBy(int *a, int b){
  *a += b;
}

int* CreateNewArray(int start, int len){
  int* iptr;
  iptr = new int[len];
  for (int i = 0; i<len; i++){
    iptr[i]=start+i;
  }
  return iptr;
}

int main(){
  int x = 15;
  IncrBy(&x, 2);
  cout << x << endl;

  int a = 10;
  int y = 15;
  int* iptr = Greater(&a, &y);

  cout << *iptr << " ";
  y = 2;
  cout << *iptr << endl;

  int* m = CreateNewArray(7, 4);
  for (int i = 0; i < 4; i++) {
    cout << m[i] << " ";
  }

  cout<<endl;

  return 0;
}
