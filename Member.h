#include <iostream>
#include <sstream>
using namespace std;

class Member
{
public:
  virtual string toString();

  bool operator < (Member greater);
  bool operator > (Member less);
  bool operator == (Member equal);
  
  int id;

  string name;
  string focus;
  string position;
};
