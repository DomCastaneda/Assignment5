#include "BSTOutput.h"
using namespace std;

BSTOutput::BSTOutput(){}

BSTOutput::~BSTOutput(){}

BST<Student> BSTOutput::readTreeStudent(string filePath)
{
  BST<Student> output = BST<Student>();
  vector<Student> temp;
  ifstream infile(filePath);
  string line;
  while (getline(infile, line))
  {
    temp.push_back(studentFromString(line));
  }

  int vectorAmount = temp.size();
  int halfAmount = round(vectorAmount / 2.0);

  vector<int> exploredNumbers;

  while(halfAmount > 1)
  {
    for(int i = halfAmount; i<vectorAmount; i+=halfAmount)
    {
      if (find(exploredNumbers.begin(), exploredNumbers.end(), i) != exploredNumbers.end())
      {

      }
      else
      {
        exploredNumbers.push_back(i);
        output.insert(temp[i].id, temp[i]);
      }

    }
    halfAmount = round(halfAmount / 2.0);

  }

  for(int i=0; i<vectorAmount; i++)
  {
    if (find(exploredNumbers.begin(), exploredNumbers.end(), i) != exploredNumbers.end()){}
    else
    {
      output.insert(temp[i].id, temp[i]);
    }
  }

  return output;
}

void BSTOutput::writeTreeStudent(string filePath, BST<Student> gbst)
{
  ofstream myfile(filePath);
  if(myfile.is_open())
  {
    myfile << gbst.toString();
    myfile.close();
  }

}

Student BSTOutput::studentFromString(string studentString)
{

  char d = ',';
  vector<string> splitLine = splitString(studentString, &d);

  cout << "Student Added: " << studentString << endl;
  int id = stoi(splitLine[0]);
  int advisor = stoi(splitLine[5]);
  double gpa = stod(splitLine[4]);

  return Student(id, splitLine[1], advisor, gpa, splitLine[3], splitLine[2]);


}

BST<Faculty> BSTOutput::readTreeFaculty(string filePath)
{
  BST<Faculty> output = BST<Faculty>();
  vector<Faculty> temp;
  ifstream infile(filePath);
  string line;
  while (getline(infile, line))
  {
    temp.push_back(facultyFromString(line));
  }
  vector<int> exploredNumbers;

  int vectorAmount = temp.size();
  int halfAmount = round(vectorAmount / 2.0);

  while(halfAmount > 1)
  {
    for(int i = halfAmount; i<vectorAmount; i+=halfAmount)
    {
      if (find(exploredNumbers.begin(), exploredNumbers.end(), i) != exploredNumbers.end()){}
      else
      {
        exploredNumbers.push_back(i);
        output.insert(temp[i].id, temp[i]);
      }

    }
    halfAmount = round(halfAmount / 2.0);
  }
  for(int i=0; i<vectorAmount; i++)
  {
    if (find(exploredNumbers.begin(), exploredNumbers.end(), i) != exploredNumbers.end())
    {
    }
    else
    {
      output.insert(temp[i].id, temp[i]);
    }
  }


  return output;
}
void BSTOutput::writeTreeFaculty(string filePath, BST<Faculty> gbst)
{
  ofstream myfile(filePath);
  if(myfile.is_open())
  {
    myfile << gbst.toString();
    myfile.close();
  }
}

Faculty BSTOutput::facultyFromString(string facultyString)
{
  cout << "Faculty Added: " << facultyString << endl;
  char d = ',';
  vector<string> splitLine = splitString(facultyString, &d);

  int id = stoi(splitLine[0]);
  if(splitLine.size() == 6)
  {
    return Faculty(id, splitLine[1], splitLine[3], splitLine[2]);
  }
  vector<string> strlist(splitLine.begin() + 5, splitLine.end());

  vector<int> tslist;

  for(unsigned int i = 0; i<strlist.size(); i++)
  {
    int num = stoi(strlist[i]);
    tslist.push_back(num);
  }
  return Faculty(tslist, id, splitLine[1], splitLine[3], splitLine[2]);
}

vector<string> BSTOutput::splitString(string input, char *delimiter)
{
  vector<string> output;

  char p[input.length()];
  for (unsigned int i = 0; i < sizeof(p); i++)
  {
        p[i] = input[i];
  }

  char *token = strtok(p, delimiter);

  while (token != NULL)
      {
        string splitToken = "";
        splitToken = token;
        output.push_back(splitToken);
        token = strtok(NULL, delimiter);
      }

      return output;

}
