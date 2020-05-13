#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

class BSTOutput
{
public:
  BSTOutput();
  ~BSTOutput();

  BST<Student> readTreeStudent(string filePath);
  void writeTreeStudent(string filePath, BST<Student>);
  Student studentFromString(string studentString);

  BST<Faculty> readTreeFaculty(string filePath);
  void writeTreeFaculty(string filePath, BST<Faculty>);
  Faculty facultyFromString(string facultyString);

  vector<string> splitString(string input, char *delimiter);

};
