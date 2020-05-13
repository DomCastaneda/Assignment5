#include "Student.h"
using namespace std;

Student::Student(){}

Student::Student(int sID, string sName, int sAdvisor, double sGPA, string sMajor,  string sYear)
{
  id = sID;
  name = sName;
  advisor = sAdvisor;
  gpa = sGPA;
  focus = sMajor;
  position = sYear;
}

Student::~Student(){}

string Student::toString()
{
  ostringstream out;
  out << Member::toString() << ',' << gpa << ',' << advisor;
  return out.str();
}
