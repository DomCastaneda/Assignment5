#include "Menu.h"
using namespace std;

Menu::Menu()
{
  getTree("table");
}

Menu::~Menu()
{
  writeTrees("table");
}

void Menu::showMenu()
{
  string input;
  int option = 0;
  while(option < 1 || option > 14)
  {

  cout << " 1. Print all students and their information (sorted by ascending id #)" << endl;
  cout << " 2. Print all faculty and their information (sorted by ascending id #)" << endl;
  cout << " 3. Find and display student information given the students id" << endl;
  cout << " 4. Find and display faculty information given the faculty id" << endl;
  cout << " 5. Given a student’s id, print the name and info of their faculty advisor" << endl;
  cout << " 6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
  cout << " 7. Add a new student" << endl;
  cout << " 8. Delete a student given the id" << endl;
  cout << " 9. Add a new faculty member" << endl;
  cout << "10. Delete a faculty member given the id." << endl;
  cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
  cout << "12. Remove an advisee from a faculty member given the ids" << endl;
  cout << "13. Rollback" << endl;
  cout << "14. Save and Exit" << endl;
  cout << "Pick an Option: ";
  cin >> input;
  cout << endl;

  try
  {
    option = stoi(input);
  }
  catch(...)
  {
    cout << "enter an option 1-14" << endl << endl;
  }

}

switch (option)
{
  case 1:
    showStudentBST();
  break;

  case 2:
    showFacultyBST();
  break;

  case 3:
    try
    {
    option = getID("Student ID: ");
    showStudentFromID(option);
    }
    catch(const char* error)
    {
      cout << error << endl;
      showMenu();
    }
  break;

  case 4:
    try
    {
    option = getID("Faculty ID: ");
    showFacultyFromID(option);
    }
    catch(char* error)
    {
      cout << error << endl;
      showMenu();
    }
  break;

  case 5:
    try
    {
      option = getID("Student ID: ");
      int adv = studentBST.getNode(option)->advisor;
      cout << facultyBST.getNode(adv)->toString() << endl;
      showMenu();
    }
    catch(const char* error)
    {
      cout << error << endl;
      showMenu();
    }
  break;

  case 6:
    try
    {
      option = getID("Faculty ID: ");
      vector<int> slist = facultyBST.getNode(option)->studentList;
      for(unsigned int i=0; i<slist.size(); i++)
      {
        cout << studentBST.getNode(slist[i])->toString() << endl;
      }
      showMenu();
    }
    catch(const char* error)
    {
      cout << error << endl;
      showMenu();
  }
  break;

  case 7:
    try
    {
      addStudent();
      showMenu();
    }
    catch(const char* error)
    {
      cout << error << endl;
      showMenu();
    }
  break;

  case 8:
    try
    {
      removeStudent();
      showMenu();
    }
    catch(const char* error)
    {
      cout << error;
      showMenu();
    }
  break;

  case 9:
    try
    {
      addFaculty();
      showMenu();
    }
    catch(const char* error)
    {
      cout << error << endl;
      showMenu();
    }
  break;

  case 10:
    try
    {
      removeFaculty();
      showMenu();
    }
    catch(const char* error)
    {
      cout << error;
      showMenu();
    }
  break;

  case 11:
    try
    {
      changeAdvisor();
      showMenu();
    }
    catch(const char* error)
    {
      cout << error;
      showMenu();
    }
  break;

  case 12:
    try
    {
      changeAdvisor();
      showMenu();
    }
    catch(const char* error)
    {
      cout << error;
      showMenu();
    }
  break;

  case 13:
    showMenu();
  break;
  
  case 14:
  break;


  }
}

void Menu::getTree(string files)
{
  BSTOutput readWrite = BSTOutput();

  string fileStudent;
  string fileFaculty;

  string student = "Student.txt";
  string faculty = "Faculty.txt";

  fileStudent.append(files);
  fileFaculty.append(files);

  fileStudent.append(student);
  fileFaculty.append(faculty);
  ifstream stFile(fileStudent);
  ifstream faFile(fileFaculty);

  if(stFile.good() && faFile.good())
  {
    cout << "Files Found." << endl;
    studentBST = readWrite.readTreeStudent(fileStudent);
    cout << "Student File Ready" << endl;
    facultyBST = readWrite.readTreeFaculty(fileFaculty);
    cout << "Faculty File Ready" << endl;
  }
  else
  {
    cout << "No files found. Fresh start by adding a faculty member(9)." << endl;
    studentBST = BST<Student>();
    facultyBST = BST<Faculty>();
    cout << "Database Ready" << endl;
  }

}

void Menu::writeTrees(string files)
{
  BSTOutput readWrite = BSTOutput();

  string fileStudent;
  string fileFaculty;

  string student = "Student.txt";
  string faculty = "Faculty.txt";

  fileStudent.append(files);
  fileFaculty.append(files);

  fileStudent.append(student);
  fileFaculty.append(faculty);

  readWrite.writeTreeStudent(fileStudent, studentBST);
  readWrite.writeTreeFaculty(fileFaculty, facultyBST);
}


void Menu::addStudent()
{
  int id;
  string name;
  int advisor;
  string gpaTest;
  double gpa;
  string focus;
  string position;
try
{
  cin.clear();
  id = getID("Student ID: ");
  if(studentBST.contains(id))
  {
    throw "Student ID already in use";
  }

  cin.clear();
  advisor = getID("Advisor ID: ");
  if(!facultyBST.contains(advisor))
  {
    throw "Faculty ID does not exist";
  }

  cin.clear();
  cout << "------Information------" << endl;
  getline(cin,name);

  cin.clear();
  cout << "Name: ";
  getline(cin,name);
  cout << endl;

  cin.clear();
  cout << "Major: ";
  getline(cin,focus);
  cout << endl;

  cin.clear();
  cout << "Year: ";
  getline(cin,position);
  cout << endl;

  cin.clear();
  cout << "GPA: ";
  cin >> gpaTest;
  cout << endl;
  try
  {
    gpa = stod(gpaTest);
  }
  catch(...)
  {
    throw "Invalid GPA";
  }
  studentBST.insert(id, Student(id,name,advisor,gpa,focus,position));
  cout << name << " added successfully with ID " << id << endl;
  facultyBST.getNode(advisor)->studentList.push_back(id);
  cout << "Added student to faculty list" << endl;
}
catch(const char* error)
{
  throw error;
}
}

void Menu::showStudentBST()
{
  cout << "Students: " << endl;
  cout << studentBST.toString();
  showMenu();
}

void Menu::showStudentFromID(int id)
{
  cout << "Student Info: " << endl;
  try
  {
  cout << studentBST.getNode(id)->toString() << endl;
  }
  catch(const char* error)
  {
    throw error;
  }
  showMenu();
}

void Menu::removeStudent()
{
  try
  {
  int id = getID("Student ID: ");
  if(!studentBST.contains(id))
  {
    throw "No student with that ID";
  }
  vector<int>* includedList = &facultyBST.getNode(studentBST.getNode(id)->advisor)->studentList;
  vector<int>::iterator position = find(includedList->begin(), includedList->end(), id);
  if (position != includedList->end())
  {
    includedList->erase(position);
  }
  else
  {
    throw "Student Advisor and Faculty Advisees have a discrepency.";
  }

  studentBST.deleteNode(id);
  cout << "Student Deleted" << endl;
  }
  catch(const char* error)
  {
    throw error;
  }
  catch(...)
  {
    throw "unknown error in removing student";
  }
}

void Menu::addFaculty()
{
  int id;
  string name;
  string focus;
  string position;

  try
  {
    cin.clear();
    id = getID("Faculty ID: ");

    cin.clear();
    cout << "____Personal Information____" << endl;
    getline(cin,name);

    cin.clear();
    cout << "Name: ";
    getline(cin,name);
    cout << endl;

    cin.clear();
    cout << "Department: ";
    getline(cin,focus);
    cout << endl;

    cin.clear();
    cout << "Level: ";
    getline(cin,position);
    cout << endl;

    facultyBST.insert(id, Faculty(id,name,focus,position));
    cout << name << " with ID " << id << " added to system" << endl;

  }
  catch(const char* error)
  {
    throw error;
  }
}

void Menu::showFacultyBST()
{
  cout << "Faculty: " << endl;
  cout << facultyBST.toString();
  showMenu();
}

void Menu::showFacultyFromID(int id)
{
  cout << "Faculty Info: " << endl;
  try
  {
  cout << facultyBST.getNode(id)->toString() << endl;
  }
  catch(char* error)
  {
    cout << error << endl;
  }
  showMenu();
}

int Menu::getID(string showString)
{
  cout << showString;
  int option;
  string input;
  cin >> input;
  cout << endl;
  try
  {
    option = stoi(input);
    return option;
  }
  catch(...)
  {
    throw "enter a valid number";

  }

}

void Menu::removeFaculty()
{
  try
  {
    int id = getID("Faculty ID: ");
    int tid = getID("Transfer ID: ");

    if(!facultyBST.contains(id) || !facultyBST.contains(tid))
    {
      throw "One or more faculty do not exist";
    }

    vector<int>* transferFacultyList = &facultyBST.getNode(tid)->studentList;
    vector<int>* deleteFacultyList = &facultyBST.getNode(id)->studentList;

    transferFacultyList->insert(transferFacultyList->end(), deleteFacultyList->begin(), deleteFacultyList->end());

    for(unsigned int i = 0; i<deleteFacultyList->size(); i++)
    {
      try
      {
        studentBST.getNode(deleteFacultyList->at(i))->advisor = tid;
      }
      catch(const char* error)
      {
        throw error;
      }
    }
    facultyBST.deleteNode(id);
  }
  catch(const char* error)
  {
    throw error;
  }
}

void Menu::changeAdvisor()
{
  int stID = getID("Student to Change: ");
  int faID = getID("Faculty Destination: ");

  if(!studentBST.contains(stID) || !facultyBST.contains(faID))
  {
    throw "Faculty and/or student does not exist";
  }

  try
  {
    vector<int>* includedList = &facultyBST.getNode(studentBST.getNode(stID)->advisor)->studentList;
    vector<int>::iterator position = find(includedList->begin(), includedList->end(), stID);
    if (position != includedList->end())
    {
      includedList->erase(position);
    }
    else
    {
      throw "Student Advisor and Faculty Advisees have a discrepency.";
    }
    facultyBST.getNode(faID)->studentList.push_back(stID);
    studentBST.getNode(stID)->advisor = faID;
  }
  catch(const char* error)
  {
    throw error;
  }
}
