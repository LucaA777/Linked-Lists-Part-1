/*
Placeholder student class so that nodes can point to this.
Will eventually be a more complete class in part 2 of the assignment.

Author: Luca Ardanaz
Last Updated: 9/24/2025
 */

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student {
 public:
  Student(const char nName[20], int nID);
  ~Student();

  char* getName();
  int getID();

 private:
  char* name;
  int ID;
};

#endif
