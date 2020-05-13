#include "Member.h"
using namespace std;

string Member::toString()
{
  ostringstream out;
  out << id << ',' << name << ',' << position << ',' << focus;
  return out.str();
}

bool Member::operator < (Member greater)
{
  return id < greater.id;
}

bool Member::operator > (Member less)
{
  return id > less.id;
}
