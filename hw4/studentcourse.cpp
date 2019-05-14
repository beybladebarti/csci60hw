#include <iostream>

using namespace std;

class Student {
public:
  Student() { name = "unknown"; };
  Student(string n) { name = n; };
  void Print() { cout << name << endl; };
  string GetName() { return name; };
private:
  string name;
};

class Course {
public:
  // [3 points] Given course id as input, initialize member variable id. Also initialize nstudents and capacity to zero.
  Course(int i) {
    id = i;
    nstudents = 0;
    capacity = 0;
    students = new Student[capacity];
    for (int i = 0; i<capacity; i++){
      students[i] = Student();
    }
  }
  // [10 points] Add student to the class. Update nstudents accordingly. If capacity of member variable students is not enough to contain the new student, allocate more space. New_capacity should be (2 * (old_capacity + 1)). Capacity is the length of the students array. For example, if 5 students have been added, then nstudents is 5, capacity is 6, and the length of students array is 6. However, students[5] is just a dummy object that does not represent any real Student in the Course. Make sure your program has no memory leak.
  void AddStudent(Student s) {
    int old_capacity = capacity;

    if (capacity <= nstudents){
      capacity = (2 * (old_capacity + 1));

      Student *temp = new Student[capacity];

      for (int i = 0; i<nstudents; i++){
        temp[i] = students[i];
      }

      temp[nstudents] = s;
      delete []students;
      students = temp;
      nstudents++;
    }
    else {
      students[nstudents] = s;
      nstudents++;
    }
  }
  // [15 points] Remove all students with the input name from the Course. If nstudents becomes less than 1/4 of capacity, then free memory such that new capacity is 1/2 of old capacity. Make sure your program has no memory leak.
  void DeleteStudentsWithName(string name) {
    int old_capacity = capacity;
    int index = 0;
    int capacity_restraint = old_capacity/4;
    int new_capacity = old_capacity/2;

    Student *temp = new Student[old_capacity];

    for (int i = 0; i<capacity; i++){
      if (students[i].GetName() != name){
        temp[index] = students[i];
        index++;
      }
    }
    delete []students;
    students = temp;

    nstudents = 0;
    for (int l = 0; l<capacity; l++){
      if (students[l].GetName() != "unknown"){
        nstudents++;
      }
    }
    if (nstudents < capacity_restraint){
      capacity = new_capacity;
      Student *new_students2 = new Student[capacity];
      for (int k = 0; k<capacity; k++){
        new_students2[k] = students[k];
      }
      delete []students;
      students = new_students2;
    }
  }
  // [2 points] Print the names of all the actual Student objects in the Course. Do not print dummy objects. Also print nstudents and capacity after printing names.
  void PrintStudents() {
    for (int i = 0; i<capacity; i++){
      if (students[i].GetName() != "unknown"){
        students[i].Print();
      }
    }
    cout<<"nStudents: "<<nstudents<<endl;
    cout<<"capacity: "<<capacity<<endl;
  }
private:
  int capacity;
  int nstudents;
  Student* students;
  int id;
};


int main()
{
    Course c1(15472);
    c1.AddStudent(Student("Ann"));
    c1.AddStudent(Student("Bob"));
    c1.AddStudent(Student("Crystal"));
    c1.AddStudent(Student("Diane"));
    c1.AddStudent(Student("Edward"));
    c1.AddStudent(Student("Frank"));
    c1.AddStudent(Student("George"));
    c1.AddStudent(Student("Frank"));
    c1.AddStudent(Student("Diane"));
    c1.AddStudent(Student("Diane"));
    c1.AddStudent(Student("Henry"));

    c1.PrintStudents();

    c1.DeleteStudentsWithName("Diane");
    cout << "deleted Diane" << endl;

    c1.PrintStudents();

    c1.DeleteStudentsWithName("Frank");
    cout << "deleted Frank" << endl;

    c1.PrintStudents();


    c1.AddStudent(Student("Henry"));
    c1.DeleteStudentsWithName("Ann");
    c1.DeleteStudentsWithName("Bob");
    c1.DeleteStudentsWithName("Crystal");
    c1.DeleteStudentsWithName("Edward");
    c1.DeleteStudentsWithName("Irene");

    cout << "Deleted whole bunch." << endl;

    c1.PrintStudents();

    c1.DeleteStudentsWithName("Henry");
    cout << "Deleted Henry" << endl;

    c1.PrintStudents();

    return 0;
}

/*
Sample output:
Ann
Bob
Crystal
Diane
Edward
Frank
George
Frank
Diane
Diane
Henry
nstudents: 11
capacity: 14
deleted Diane
Ann
Bob
Crystal
Edward
Frank
George
Frank
Henry
nstudents: 8
capacity: 14
deleted Frank
Ann
Bob
Crystal
Edward
George
Henry
nstudents: 6
capacity: 14
Deleted whole bunch.
George
Henry
Henry
nstudents: 3
capacity: 14
Deleted Henry
George
nstudents: 1
capacity: 7

*/
