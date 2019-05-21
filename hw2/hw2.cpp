#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
#include <algorithm>
#include <iomanip>

using namespace std;

class student {
  string  id;
  string first, last, DOB;
  double GPA;
 
  public:
  student(string id, string first, string last, string DOB, double GPA) {
    this->id = id;
    this->first = first;
    this->last = last;
    this->DOB = DOB;
    this->GPA = GPA;
  }

  string getId() {
    return id;
  }
  string getFirstname() {
    return first;
  }
  string getLastname() {
    return last;
  }
  string getDOB() {
    return DOB;
  }
  double getGPA() {
    return GPA;
  }
};

student* parse(string rawArguments, char delimiter) {
  stringstream currentArgumentName;
  stringstream currentArgumentValue;
  bool argumentNameFinished = false;

  string params[5];
  int paramIdx = 0;
  
  for (unsigned int i=1; i<=rawArguments.length()-1; i++) {
    if (i == rawArguments.length()-1 || rawArguments[i] == delimiter) {
      if (currentArgumentName.str() != "") {
          params[paramIdx++] = currentArgumentValue.str();
      }
      // reset
      currentArgumentName.str("");
      currentArgumentValue.str("");
      argumentNameFinished = false;
    }
    else if (rawArguments[i] == ':') {
      argumentNameFinished = true;
    }
    else {
      if (argumentNameFinished) {
        currentArgumentValue << rawArguments[i];
      }
      else {
        // ignore any spaces in argument names. 
        if (rawArguments[i] == ' ')
            continue;
        currentArgumentName << rawArguments[i];
      }
    }
  }

  // cout<<params[0]<<params[1]<<params[2]<<params[3]<<params[4];
  return new student(params[0], params[1], params[2], params[3], stod(params[4]));
}

int check(student *records[], int recordSize, string id) {

  for(int i=0;i<recordSize;i++){
    if(records[i]->getId() == id)
      return i;
  }

  return -1;
}

bool deleteRecord(student *records[], int recordSize, string id) {

   for(int i=0;i<recordSize;i++){
    if(records[i]->getId() == id)  {

      delete records[i];
      while(i<=recordSize-2) {
        records[i] = records[i+1];
        i++;
      }
      return true;
    }
  }
  return false;
}

bool compareWithId(student* stu1, student* stu2) {
  return stu1->getId() < stu2->getId();
}

bool compareWithfirstname(student* stu1, student* stu2) {
  return stu1->getFirstname() < stu2->getFirstname();
}

bool compareWithlastname(student* stu1, student* stu2) {
  return stu1->getLastname() < stu2->getLastname();
}

bool compareWithGPA(student* stu1, student* stu2) {
  return stu1->getGPA() < stu2->getGPA();
}

bool compareWithDOB(student* stu1, student* stu2) {
  return stu1->getDOB() < stu2->getDOB();
} 


int main(int argc, char *argv[]) {

  // Incorrect Usage
  if (argc < 2) {
    cout << "Usage: densemultiple \"A=<file>;B=<file>;C=<file>\"" << endl;
    return -1;
  }

  ArgumentManager am(argc, argv);

  string input1 = am.get("input");
  string input2 = am.get("sort");
  string output = am.get("output");
  
  //cout<<"Filenames are "<<input1<<" "<<input2<<" "<<output<<endl;
  

  ifstream file1(input1.c_str()), file2(input2.c_str());
  ofstream file3(output.c_str());

  if (!file1 || !file2 || !file3) {
      cout << "error";
      return -1;
  }

  string record;
  student* (records[2000]);
  int recordSize = 0;
  while(getline(file1, record)) {
    if(record[record.size()-1] == '\r'){
      record = record.substr(0,record.size() - 1);
    }
//    cout<<"Record: "<<record[0]<<endl;
    if(record[0] == '{') {
      student *temp = parse(record, ',');
      int pos = check(records, recordSize, temp->getId());
      if(pos >= 0) {
        delete records[pos];
        records[pos] = temp;
      } else {
        records[recordSize++] = temp;
      }
    } else if(record[0] == 'd') {
      // delete
      
//      cout<<"del";
      istringstream iss(record);  

      string deleteString, idString;
      string idToDelete;

      getline(iss, deleteString, ' ');
      getline(iss, idString, ' ');
      idString = idString.substr(0,7);
//      cout<<idString;

      idToDelete = idString;

      if(deleteRecord(records, recordSize, idToDelete))
        recordSize--;
    }
  }

//  for(int i=0;i<recordSize;i++) {
//    cout<<"{id:"<<records[i]->getId()<<",first:"<<records[i]->getFirstname()<<",last:"<<records[i]->getLastname()<<",DOB:"<<records[i]->getDOB()<<",GPA:"<<records[i]->getGPA()<<"}"<<endl;
//  }
  
  
  string sortBase;
  bool hasData = false;
  sort(records, records + recordSize, compareWithId);
  while(getline(file2, sortBase)) {
//    cout<<"sortBase:" << sortBase<<endl;
    if(sortBase[sortBase.size()-1] == '\r'){
      sortBase = sortBase.substr(0,sortBase.size() - 1);
    }
    if(!sortBase.compare("id")) {
      stable_sort(records, records + recordSize, compareWithId);
    } else if(!sortBase.compare("first")) {
      stable_sort(records, records + recordSize, compareWithfirstname);
    } else if(!sortBase.compare("last")) {
      stable_sort(records, records + recordSize, compareWithlastname);
    } else if(!sortBase.compare("DOB")) {
      stable_sort(records, records + recordSize, compareWithDOB);
    } else if(!sortBase.compare("GPA")) {
      stable_sort(records, records + recordSize, compareWithGPA);
    } else {
      stable_sort(records, records + recordSize, compareWithId);
    }
//    cout<<endl;
//    for(int i=0;i<recordSize;i++) {
//      cout<<"{id:"<<records[i]->getId()<<",first:"<<records[i]->getFirstname()<<",last:"<<records[i]->getLastname()<<",DOB:"<<records[i]->getDOB()<<",GPA:"<<records[i]->getGPA()<<"}"<<endl;
//    }
//    cout<<endl;
  }

  for(int i=0;i<recordSize;i++) {
    file3<<"{id:"<<records[i]->getId()<<",first:"<<records[i]->getFirstname()<<",last:"<<records[i]->getLastname()<<",DOB:"<<records[i]->getDOB()<<",GPA:"<<fixed<<setprecision(1)<<records[i]->getGPA()<<"}\n";
  }
  
}

  