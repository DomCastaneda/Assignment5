#ifndef Included_Person_H
#define Included_Person_H
#include "Member.h"
#endif
#include <vector>
#include <iterator>
using namespace std;

class Faculty: public Member
{
public:
  string toString();
  
  vector<int> studentList;

  Faculty();
  Faculty(int fID, string fName, string fDep = "No Department",  string fPos = "Unassigned Faculty");
  Faculty(vector<int> fList, int fID, string fName, string fDep = "No Department",  string fPos = "Unassigned");
  ~Faculty();
};
