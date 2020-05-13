#include "BSTOutput.h"
#include <iostream>
using namespace std;

class Menu
{
public:
  Menu();
  ~Menu();

  void showMenu();

  void getTree(string files);
  void writeTrees(string files);

  void addStudent();
  void showStudentBST();
  void showStudentFromID(int id);
  void removeStudent();

  void addFaculty();
  void showFacultyBST();
  void showFacultyFromID(int id);
  void removeFaculty();

  int getID(string showString);
  
  void changeAdvisor();

  BST<Student> studentBST;
  BST<Faculty> facultyBST;
};
