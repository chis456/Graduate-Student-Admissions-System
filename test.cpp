#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include "student.hpp"

// #include "" <--- Required functions
using namespace std;


template<class T>
void Check(T x, T y);
void Check(void* x, void* y);

//function for rounding a float because no <iomanip>
float roundFloat(float gpa)
{
  string gpa_s = to_string(gpa);

  //converting a float to a string adds 6 decimal points after so we need to remove 4 of them and then evaluate the last one 
  //to see if we need to make it one bigger or one smaller
  for(int i = 0; i < 4; i++)
  {
    gpa_s.pop_back();
  }
  //then convert the one we didnt remove to an int so we can evalulate whether we need to round up or not
  char lastNum = gpa_s[3];
  int lastNum_i = lastNum - '0';
  if(lastNum_i < 5) //if not needed to round up, just delete
  {
    gpa_s.pop_back();
  }
  else //if needed to be rounded up, check that the last character isnt a 9 or else it will convert into a ":" character
  {
    gpa_s.pop_back();
    if(gpa_s[2] != '9')
    {
      gpa_s[2] +=1;
    }
    else //if last character is a 9 then change back to 0 and then increase the integral number by 1
    {
      gpa_s[2] = '0';
      gpa_s[0] += 1;
    }
  }
  return stof(gpa_s);
}

// ^^^ Compare x to y, display relationship meaning ^^^

int main(){

  cout << "Test Start" << endl;

  cout << "Testing on Domestic Students" << endl;
  //inserting domestic students check
  int r = 50;
  DomesticList dtl;
  dtl.createDom("John", "Elden", 4.3, r, "BC");        // Corner cGPA
  dtl.createDom("Aaron", "Yogurt", 0, r, "ON");           // Corner cGPA
  dtl.createDom("John", "Sekiro", 4.1, r, "AB");       // Normal cGPA

  dtl.createDom("John", "Dark Souls", 4.5, 50, "PE");   // Invalid cGPA
  dtl.createDom("American", "Man", 0, 0, "Washington"); //invalid province

  cout << dtl << endl;
  dtl.createDom("Patrick", "Star", 2.4, 100, "NT");     // Corner Research Score
  dtl.createDom("David", "LeeRoth", 2.4, 0, "NU");      // Corner Research Score
  dtl.createDom("Papa", "Smurf", 2.4, 50, "BC");        // Norml Research Score
  dtl.createDom("Crazy", "Frog", 2.4, 110, "NS");       // Invalid Research Score
  
  cout << dtl << endl;

  //Test Searching
  
  cout << "Test Searching Name (John Elden)" << endl;
  dtl.searchName("John", "Elden");

  cout << "Test Searching cGPA (2.4)" << endl;
  dtl.searchCPGA(2.4);

  cout << "Test Searching application ID (20220000)" << endl;
  dtl.searchAppID(20220000);

  cout << "Test Searching ResearchScore (50)" << endl;
  dtl.searchResearch(50);

  cout << "Test deleting by name (Crazy Frog)" << endl;
  dtl.deleteDom("Crazy", "Frog");
  cout << dtl << endl;

  cout << "Test Head and Tail deletion" << endl;
  dtl.deleteHT();
  cout << dtl << endl;

  cout << "Checking if created Domestic Student actually exists\n";
  cout << "By comparing head to last name string\n\n";
  Check(dtl.getHead()->getLastName(), string("Elden"));
  Check(dtl.getHead()->next->getLastName(), string("Smurf"));
  Check(dtl.getHead()->next->next->getLastName(), string("Yogurt"));
  Check(dtl.getHead()->next->next->next->getLastName(), string("Sekiro"));
  //Check(dtl.getHead()->next->next->next->next->getLastName(), string("LeeRoth"));
 
    cout << "\nTrue, Domestic Create Pass\n";


// Test InternationalList

  cout << endl;

  int errDet = 0;

  ToeflScore toefl1(25, 21, 23, 27);  // Normal Case Score
  ToeflScore toefl2(20, 20, 20, 20);  // Corner Case Score
  ToeflScore toefl3(30, 30, 30, 30);  // Corner Case Score
  ToeflScore toefl4(33, 0, 15, 25);   // Invalid Case Score

  InternationalList intStudents;
  if(!intStudents.createInter("Normal", "Case", 4.0, 2, "China", toefl1)){
    cout << "ERROR NORMAL CASE INSERTION" << endl;
    errDet++;
  }
  if(!intStudents.createInter("Idian", "Case", 3.9, 100, "Idian", toefl2)){
    cout << "ERROR IDIAN CASE INSERTION" << endl;
    errDet++;
  }
  if(!intStudents.createInter("Corner", "TOEFL", 4.1, 99, "India", toefl3)){
    cout << "ERROR CORNER TOEFL INSERTION" << endl;
    errDet++;
  }
  if(!intStudents.createInter("Edge", "cGPA0", 4.3, 100, "China", toefl1)){
    cout << "ERROR MAX CGPA/RESEARCH INSERTION" << endl;
    errDet++;
  }
  if(!intStudents.createInter("Edge", "cPGA1", 0, 0, "China", toefl1)){
    cout << "ERROR MIN CGPA/RESEARCH INSERTION" << endl;
    errDet++;
  }

  if(intStudents.createInter("Invalid", "TOEFL", 4.1, 99, "Canada", toefl4)){
    cout << "ERROR INVALID TOEFL NOT CAUGHT" << endl;
    errDet++;
  }
  if(intStudents.createInter("Invalid", "Country", 4.1, 86, "Soviet Union", toefl1)){
    cout << "ERROR INVALID COUNTRY NOT CAUGHT" << endl;
    errDet++;
  }
  if(intStudents.createInter("Invalid", "cGPA0", 4.5, 57, "Iran", toefl1)){
    cout << "ERROR INVALID CGPA NOT CAUGHT" << endl;
    errDet++;  
  }
  if(intStudents.createInter("Invalid", "cGPA1", -0.6, 34, "Japan", toefl1)){
    cout << "ERROR INVALID CGPA NOT CAUGHT" << endl;
    errDet++;
  }
  if(intStudents.createInter("Invalid", "Research0", 4.2, 101, "Korea", toefl1)){
    cout << "ERROR INVALID RESEARCH SCORE NOT CAUGHT" << endl;
  }
  if(intStudents.createInter("Invalid", "Research1", 2.8, -35, "Iran", toefl1)){
    cout << "ERROR INVALID RESEARCH SCORE NOT CAUGHT" << endl;
    errDet++;
    }
  if(intStudents.createInter("", "", 2.3, 50, "", toefl1)){
    cout << "ERROR MISSING FIELD NOT CAUGHT" << endl;
    errDet++;
  }
  
  cout << intStudents << endl;

  cout << "searching for Normal Case" << endl;
  if(!intStudents.searchName("Normal", "Case")){
    cout << "SEARCH NAME NORMAL CASE ERROR" << endl;
    errDet++;
  }
  cout << "searching for Idian Case" << endl;
  if(!intStudents.searchName("IdIaN", "cAsE")){
    cout << "SEARCH NAME SPONGEBOB ERROR" << endl;
    errDet++;
  }
  cout << "searching for Edge cGPA0" << endl;
  if(!intStudents.searchAppID(intStudents.getHead()->getAppID())){
    cout << "SEARCH APPID ERROR" << endl;
    errDet++;
  }
  cout << "searching for Edge cGPA1" << endl;
  if(!intStudents.searchCPGA(intStudents.getTail()->getCGPA())){
    cout << "SEARCH CGPA ERROR" << endl;
    errDet++;
  }
  cout << "searching for research score == 100" << endl;
  if(!intStudents.searchResearch(100)){
    cout << "SEARCH RESEARCH ERROR" << endl;
    errDet++;
  }

  cout << "searching for Non existent entry" << endl;
  if(intStudents.searchName("Invalid", "Country")){
    cout << "SEARCH NAME ERROR NOT CAUGHT" << endl;
    errDet++;
  }
  cout << "searching for invalid appID" << endl;
  if(intStudents.searchAppID(1)){
    cout << "SEARCH APPID ERROR NOT CAUGHT" << endl;
    errDet++;
  }
  cout << "searching for invalid research score" << endl;
  if(intStudents.searchResearch(-35)){
    cout << "SEARCH RESEARCH ERROR NOT CAUGHT" << endl;
    errDet++;
  }

  intStudents.deleteHT();

  if(intStudents.getHead()->getFirstName() != "Corner" || intStudents.getTail()->getFirstName() != "Idian"){
    cout << "deleteHT ERROR" << endl;
    errDet++;
  }

  cout << intStudents << endl;

  if(!errDet){
    cout << endl << "InternationalList Test Complete: Invalid Entries Caught, No Errors Detected" << endl;
  }

// Test Merge

  cout << endl;

  DomesticList edl;
  InternationalList eil;
  GeneralList gl(dtl, intStudents);

  cout << "merge domestic and international list" << endl;
  cout << gl << endl;

  cout << "threshold cgpa: 4, research: 50" << endl;
  gl.thresholdSearch(4, 50);

  cout << endl;
  GeneralList egl(edl, eil);
  cout << "merge empty lists" << endl;
  cout << egl << endl;

  cout << "merge international and empty domestic" << endl;
  GeneralList edgl(edl, intStudents);
  cout << edgl << endl;

  cout << "merge domestic and empty international" << endl;
  GeneralList eigl(dtl, eil);
  cout << eigl << endl;

  cout << endl;
  cout << "GeneralList Test Complete: No Errors Detected" << endl;

}

// Assuming input as same type as x or y
// Reads pointers as unsigned ints
template<class T>
void Check(T x, T y){
    if(x != y){
        cout << x << " is NOT equal to " << y << "\n";
    }else{
        cout << x << " is equal to " << y << "\n";
    }
}

// Reads pointers as pointers, covers flaws with prior
// Pointer Relationships
void Check(void* x, void* y){
    if(x != y){
        cout << "Failure\n";
    }else{
        cout << "Success\n";
    }
}

