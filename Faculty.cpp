#include "Faculty.h"
using namespace std;

Faculty::Faculty(){}

Faculty::Faculty(int fID, string tName, string fDep,  string fPos)
{
  id = fID;
  name = tName;
  focus = fDep;
  position = fPos;

}

Faculty::Faculty(vector<int> fList, int fID, string tName, string fDep,  string fPos)
{
  id = fID;
  name = tName;
  focus = fDep;
  position = fPos;
  studentList = fList;

}

Faculty::~Faculty(){}

string Faculty::toString()
{
  string Students;
  if (!studentList.empty())
  {
    ostringstream out;
    copy(studentList.begin(), studentList.end()-1, ostream_iterator<int>(out, ","));
    out << studentList.back();
    Students = out.str();
  }
  ostringstream totS;
  totS << Member::toString() << ',' << "Total Students: " << studentList.size() << ',' << Students;
  return totS.str();
}
