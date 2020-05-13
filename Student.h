#ifndef Included_Person_H
#define Included_Person_H
#include "Member.h"
#endif
using namespace std;

class Student: public Member
{
public:
  Student();
  Student(int sID, string sName, int sAdvisor, double sGPA = -1, string sMajor = "Undeclared",  string sYear = "Unassigned Year");
  ~Student();

  string toString();

  int advisor;

  double gpa;
};
