#include <fstream>
#include <iostream>
using namespace std;

struct Animal{
string name, gender, type;
float age, price;
};

/* the cheapest functions iterates through the animal array A, setting the minimum
value to the next minimum value in the array until the iteration is complete and recording
the index of that value. Then, the function returns the animal at that index.
*/

Animal Cheapest(string type, Animal a[], int size){
  float min = a[0].price;
  int minIndex = 0;

  for (int i = 0; i<size; i++){//finds the minimum price in the array
    if (a[i].type == type){
      if (a[i].price < min){
        min = a[i].price;
        minIndex = i;
      }
    }
  }

  return a[minIndex];
}

bool SameSpecies(Animal a, Animal b){
  if (a.type == b.type){
    return true;
  }
  return false;
}

int main() {
  Animal shelter[5];

  shelter[0].name = "Bob";
  shelter[0].gender = "M";
  shelter[0].type = "Dog";
  shelter[0].age = 12;
  shelter[0].price = 30;

  shelter[1].name = "George";
  shelter[1].gender = "M";
  shelter[1].type = "Cat";
  shelter[1].age = 13;
  shelter[1].price = 20;

  shelter[2].name = "Zach";
  shelter[2].gender = "M";
  shelter[2].type = "Cat";
  shelter[2].age = 14;
  shelter[2].price = 10;

  shelter[3].name = "Lana";
  shelter[3].gender = "F";
  shelter[3].type = "Dog";
  shelter[3].age = 15;
  shelter[3].price = 15;

  shelter[4].name = "Ben";
  shelter[4].gender = "M";
  shelter[4].type = "Dog";
  shelter[4].age = 16;
  shelter[4].price = 5;

  Animal test = Cheapest("Dog", shelter, 5);
  Animal test2 = Cheapest("Cat", shelter, 5);

  bool test3 = SameSpecies(shelter[0], shelter[1]);
  bool test4 = SameSpecies(shelter[2], shelter[1]);

  cout<<"Cheapest dog is: "<<test.name<<endl;
  cout<<"Cheapest cat is: "<<test2.name<<endl;

  if (test3){
    cout<<"Test 3 is true. "<<endl;
  }
  if(test4){
    cout<<"Test 4 is true. "<<endl;
  }


}
