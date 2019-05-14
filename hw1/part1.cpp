#include <fstream>
#include <iostream>
using namespace std;

/*The following code uses a nested for loop. For each element of the array,
we iterate through the rest of the elements to find the new minimum value,
setting the next element of the array to the next minimum value. This continues
until all of the array elements have been processed. There will be a problem if
the list has different case type names, ie. upper case and lower case names. This
is because the code uses ASCII to compare the values and sort alphabetically, with uppercase
letters having lower values than lower case letters. This causes a problem in the loops.*/

void PrintNamesInOrder(string names[], int nNames){
  string minVal;
  int minIndex, startScan;

  for (startScan = 0; startScan<(nNames-1); startScan++){//for loop to iterate through the array, setting the next minimum value
    minIndex = startScan;
    minVal = names[startScan];

    for (int j = startScan + 1; j<nNames; j++){//for loop to compare minimum value to the rest of the array values.
      if (names[j] < minVal){
        minVal = names[j];
        minIndex = j;
      }
    }
    names[minIndex] = names[startScan];
    names[startScan] = minVal;
  }
  for (int j = 0; j<nNames; j++){
    cout<<names[j]<<", ";
  }
  cout<<endl;

int main() {
  string nameList[6] = {"Tim", "Jill", "June", "Tony", "Tina", "Bob"};

  PrintNamesInOrder(nameList, 6);
}
