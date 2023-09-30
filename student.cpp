#include <string>
#include <iostream>
#include <iomanip>

#include "student.hpp"

using namespace std;

int Student::stuCount = 0;
// Constant values use in check functions
    const unsigned int minID = 20220000;
    const unsigned int maxID = 20230000;
    const unsigned int minResScore = 0;
    const unsigned int maxResScore = 100;
    const float gpaMAX = 4.33;

// Student Class Creation
Student::Student(){
    firstName = "NULL";
    lastName = "NULL";
    cGPA = 0;
    researchScore = 0;
    appID = stuCount+20220000;
    stuCount++;
    
    // next = NULL;
    // prev = NULL;
}
Student::Student(string f, string l, float gpa, int rscore)
{
    firstName = f;
    lastName = l;
    cGPA = gpa;
    researchScore = rscore;
    appID = stuCount+20220000;
	stuCount++;

    // next = NULL;
    // prev = NULL;
}

// Sub-class creation
DomesticStudent::DomesticStudent() {
    province = "NULL";
    next = NULL;
    prev = NULL;
}
InternationalStudent::InternationalStudent() {
    country = "NULL";
    next = NULL;
    prev = NULL;
}

//Getter Functions General (Domestic and/or International Student Usage)
string Student::getFirstName() const
{
    return firstName;		//Applicable for both types of students
}
string Student::getLastName() const
{
    return lastName;		//Applicable for both types of students
}

float Student::getCGPA() const
{
    return cGPA;		//Applicable for both types of students
}

int Student::getResearchScore() const
{
    return researchScore;	//Applicable for both types of students
}

int Student::getAppID() const
{
    return appID;		//Applicable for both types of students
}

 //Setters Functions General (Domestic and/or International Student Usage)
void Student::setFirstName(string name)
{
    firstName = name;		//Applicable for both types of students
}
void Student::setLastName(string name)
{
    lastName = name;		//Applicable for both types of students
}

void Student::setcGPA(float c)
{
    cGPA = c;			//Applicable for both types of students
    // validCGPA();
}

void Student::setResearchScore(int score)
{
    researchScore = score;	//Applicable for both types of students
    // validResearchScore();
}

string DomesticStudent::getProvince() const      // Obtains Province Information for Domestic Students
{
    return province;		//Applicable for domestic students only
}

bool DomesticStudent::setProvince(string p)
{
    // for(int i = 0; i < p.length(); ++i){
    //     p[i] = toupper(p[i]);
    // }
    // if(p == "NL" || p == "PE" || p == "NS" || p == "NB" || p == "QC" || p == "ON" || p == "MB" || p == "SK" || p == "AB" || p == "BC" || p == "YT" || p == "NT" || p == "NU"){
    //     province = p;		//Applicable for domestic students only
    //     return true;
    // }else{
    //     cout << "ERROR: Invalid province" << endl;
    //     return false;
    // }
    province = p;
    return true;
}

string InternationalStudent::getCountry() const	 // Obtains Country of Origin for International Students
{
	return country;		//Applicable for international students only
}

bool InternationalStudent::setCountry(string c)
{
    // for(int i = 0; i < c.length(); ++i){
    //     c[i] = tolower(c[i]);
    // }
    // c[0] = toupper(c[0]);
    // if(c == "Canada" || c == "China" || c == "India" || c == "Iran" || c == "Korea"){
    //     country = c;		//Applicable for international students only
    //     return true;
    // }else if(c == "Idian"){
    //     country = "Indian";
    //     return true;
    // }else{
    //     cout << "ERROR: Invalid country" << endl;
    //     return false;
    // }
    country = c;
    return true;
}

ToeflScore InternationalStudent::getToeflScore() const
{
    return toefl;		//Applicable for international students only
}

void InternationalStudent::setToeflScore(ToeflScore score)
{
    toefl = score;		//Applicable for international students only
}

// ToeflScore

// Default Constructor
ToeflScore::ToeflScore(){}

// Constructor with parameters
ToeflScore::ToeflScore(int r, int l, int s, int w){
    reading = r;
    listening = l;
    speaking = s;
    writing = w;
	
//   validToeflIndividual();
}

// get reading score
int ToeflScore::getReading(){
    return reading;		//Applicable for both types of students
}

// set reading score
void ToeflScore::setReading(int r){
    reading = r;		//Applicable for both types of students
}

// get listening score
int ToeflScore::getListening(){
    return listening;		//Applicable for both types of students
}

// set listening score
void ToeflScore::setListening(int l){
    listening = l;		//Applicable for both types of students
}

// get speaking score
int ToeflScore::getSpeaking(){
    return speaking;		//Applicable for both types of students
}

// set speaking score
void ToeflScore::setSpeaking(int s){
    speaking = s;		//Applicable for both types of students
}

// get writing score
int ToeflScore::getWriting(){
    return writing;		//Applicable for both types of students
}

// set writing score
void ToeflScore::setWriting(int w){
    writing = w;		//Applicable for both types of students
}

// get total score
int ToeflScore::getTotal(){
    return reading+listening+speaking+writing;		//Applicable for both types of students
}


// CGPA Compariosson between 2 applicants at a time:
int compareCGPA(const Student& s1, const Student& s2)
{
    if(s1.getCGPA() > s2.getCGPA())
    {
        return 1;
    }

    else if(s1.getCGPA() < s2.getCGPA())
    {
        return -1;
    }
    else
    {
        return 0;
    }
//returns 1 if s1's cGPA is greater than s2, 0 if equal, -1 if s1's cGPA is smaller than s2
}


// Toefl Comparison between 2 applicants at a time:
int compareResearchScore(const Student& s1, const Student& s2)
{
    if(s1.getResearchScore() > s2.getResearchScore())
    {
        return 1;
    }

    else if(s1.getResearchScore() < s2.getResearchScore())
    {
        return -1;
    }
    else
    {
        return 0;
    }
//returns 1 if s1's research score is greater than s2, 0 if equal, -1 if s1's research score is smaller than s2
}


//  Name comparison between between names of two applicants at a time:
int compareFirstName(const Student& s1, const Student& s2) //under construction return 1 if s1 is greater than s2, -1 if opposite and 0 if same
{
    string name1 = s1.getFirstName();
    string name2 = s2.getFirstName();

    //turning all to lower case
    for(int i = 0; i < name1.size(); i++)
    {
        name1[i] = tolower(name1[i]);
    }
    for(int i = 0; i < name2.size(); i++)
    {
        name2[i] = tolower(name2[i]);
    }
    if(name1.compare(name2) > 0)
    {
        return 1;
    }
    else if(name1.compare(name2) < 0)
    {
        return -1;
    }
    return 0;
}

//  Surname comparison between between names of two applicants at a time:
int compareLastName(const Student& s1, const Student& s2) //under construction return 1 if s1 is greater than s2, -1 if opposite and 0 if same
{
    string name1 = s1.getLastName();
    string name2 = s2.getLastName();

    //turning all to lower case
    for(int i = 0; i < name1.size(); i++)
    {
        name1[i] = tolower(name1[i]);
    }
    for(int i = 0; i < name2.size(); i++)
    {
        name2[i] = tolower(name2[i]);
    }
    if(name1.compare(name2) > 0)
    {
        return 1;
    }
    else if(name1.compare(name2) < 0)
    {
        return -1;
    }
    return 0;
}

// compare province
int compareProvince(const DomesticStudent& s1, const DomesticStudent& s2) //return 1 if s1 is greater than s2, -1 if opposite and 0 if same
{
    string name1 = s1.getProvince();
    string name2 = s2.getProvince();

    //turning all to lower case
    for(int i = 0; i < name1.size(); i++)
    {
        name1[i] = tolower(name1[i]);
    }
    for(int i = 0; i < name2.size(); i++)
    {
        name2[i] = tolower(name2[i]);
    }
    if(name1.compare(name2) > 0)
    {
        return 1;
    }
    else if(name1.compare(name2) < 0)
    {
        return -1;
    }
    return 0;
}

// compare country
int compareCountry(const InternationalStudent& s1, const InternationalStudent& s2) //return 1 if s1 is greater than s2, -1 if opposite and 0 if same
{
    string name1 = s1.getCountry();
    string name2 = s2.getCountry();

    //turning all to lower case
    for(int i = 0; i < name1.size(); i++)
    {
        name1[i] = tolower(name1[i]);
    }
    for(int i = 0; i < name2.size(); i++)
    {
        name2[i] = tolower(name2[i]);
    }
    if(name1.compare(name2) > 0)
    {
        return 1;
    }
    else if(name1.compare(name2) < 0)
    {
        return -1;
    }
    return 0;
}

// Check Functions (Ensure valid input)
//
//1)
// Available for future implementaion
//
// Check ID #  (Not used but may need in future)
bool Student::validID() const {
  if (minID > appID || appID > maxID) { 	// Ensures inputted applicant ID is within the range 20220000 & 20230000

    // cout << "\nInvalid applicant ID, must be within the values 20220000 & ""20230000\nwhen sorting by ID\n" 
    //      << endl;
    return false;

    // returns error message if not within the range
	
  }

  return true;

}

// 2)
// Currently Implemented
//
// Check Research Score value
bool Student::validResearchScore() const {
    if (researchScore < minResScore ||
      researchScore > maxResScore) { 		// Ensures inputted research score is within the range 0% & 100%

        // cout
        //     << "\n***WARNING***\nInvalid Research Score Value Entered for a student.\nThe score must be within the values 0 & 100.\nplease correct any issue and try again.***\n"
        //     << endl;

        // returns error  if not within the range

        return false;
    }

    return true;

}

// 3)
//Currently Implemented
// 
// Check cGPA number
bool Student::validCGPA () const{
    if (cGPA < 0 || cGPA > gpaMAX){		// Ensures inputed cGPA is within the range 0 & 4.3 Since cgpa min scores == 0 ==  min reserach scores,...
						// can reuse the const variables
    
        // cout<<"\n***WARNING***\nCGPA, must be within the values 0 & 4.3\nwhen sorting by cGPA\n"<<
        //   "Value Causing Issues:"<<cGPA<<"\n\n"<<endl;
        //   // returns false message if not within the range
        return false;
    }

    return true;

}

// 4)
// Available for future implementaion
//
// Check total Toefl score

bool ToeflScore::validToeflTotal () const{
    if (reading+listening+speaking+writing < 0 || reading+listening+speaking+writing > 120){
		
// Ensures inputted Toefl score is within the range 0 & 120 points
// Since Toefl min scores are equal to min reserach scores, can reuse the const variables

        // cout<<"\n***WARNING***\nInvalid Toefl Total Score Value, must be within the values 0 & 120\nwhen sorting by Total\n"<<endl;
        //         // returns false message if not within the range
		
		return false;
    }

    return true;
      
}

// 5)
// Currently Implemented but no way of sorting in this way.
//
// Check toefl individual scores

bool ToeflScore::validToeflIndividual () const{

        if ((reading < 0 || reading > 30) || (listening < 0 || listening > 30) || (speaking < 0 ||speaking > 30) || ( writing < 0 || writing > 30))
           {
              // Ensures each of the parts of the toefl score are within the correct range
              // Since all min == 0 == min reserach scores, can reuse the const variables


    //   cout<<"\n***WARNING**\nInvalid Toefl Score Value for one of the 4 parts, must be within the values 0 & 30.2\nwhen sorting by: Reading, Listening, Speaking, Writting\n"<<endl;
                // returns false message if not within the range
		
		    return false;
        }

        return true;
       
}

// Overloaded displayable output

// Grabbed set student overloaded output
ostream &operator<<(ostream &os, Student &stu){
    
    os << setw(15) << stu.getAppID() << setw(15) << stu.getFirstName() << setw(15) << stu.getLastName() << setw(15) << stu.getCGPA() << setw(15) << stu.getResearchScore() << endl;
    return os;
}

// Domestic student overloaded output
ostream &operator<<(ostream &os, DomesticStudent &domStu){

    os << setw(15) << domStu.getAppID() << setw(15) << domStu.getFirstName() << setw(15) << domStu.getLastName() << setw(15) << domStu.getCGPA() << setw(15) << domStu.getResearchScore() << setw(15) << domStu.getProvince() << endl;
    return os;
}

// International student overloaded output
ostream &operator<<(ostream &os, InternationalStudent &intStu){

    os << setw(15) << intStu.getAppID() << setw(15) << intStu.getFirstName() << setw(15) << intStu.getLastName() << setw(15) << intStu.getCGPA() << setw(15) << intStu.getResearchScore() << setw(15) << intStu.getCountry() << setw(15) << intStu.getToeflScore().getTotal() << setw(15) << intStu.getToeflScore().getReading() << setw(15) << intStu.getToeflScore().getListening() << setw(15) << intStu.getToeflScore().getSpeaking() << setw(15) << intStu.getToeflScore().getWriting() << endl;
    return os;
}









//              PART 2 FUNCTIONS

string tolower(string s){
    for(int i = 0; i < s.length(); ++i){
        s[i] = tolower(s[i]);
    }
    return s;
}

//              DOMESTIC STUDENT FUNCTIONS

DomPtr DomesticStudent::getNext(){
    return next;
}

DomPtr DomesticStudent::getPrev(){
    return prev;
}

// DomesticList

DomesticList::DomesticList(){
    head = NULL;
    tail = NULL;
}

DomesticList::~DomesticList(){
    DomPtr temp;
    while(head){
        temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
    tail = NULL;
}

DomPtr DomesticList::getHead() const
{
    return head;
}

DomPtr DomesticList::getTail() const{
    return tail;
}

void DomesticList::domInsert(DomPtr stu){ //domesticStudent object will be created in the main and then passed into this function
    //overall sort - Research Score > CGPA > Province 
    
    // if empty list
    if(!head){
        head = tail = stu;
        head->prev = NULL;
        tail->next = NULL;
        return;
    }

    // find place for stu
    DomPtr current = head;
    while(current)
    {
        if(stu->getResearchScore() > current->getResearchScore())
        {
            if(current == head)
            {
                stu->next = head;
                head->prev = stu;
                head = stu;
                return;
            }
            current->prev->next = stu;
            stu->prev = current->prev;
            stu->next = current;
            current->prev = stu;
            return;
        }
        else if(stu->getResearchScore() == current->getResearchScore())
        {   
            if(stu->getCGPA() > current->getCGPA())
            {   
                
                if(current == head)
                {
                    stu->next = head;
                    head->prev = stu;
                    head = stu;
                    return;
                }
                current->prev->next = stu;
                stu->prev = current->prev;
                stu->next = current;
                current->prev = stu;
                return;
            }
            else if(stu->getCGPA() == current->getCGPA())
            {   
                if(compareProvince(*stu, *current) == -1) //if stu's province is alphabetically larger than the current iterating item
                {   
                    if(current == head)
                    {
                        stu->next = head;
                        head->prev = stu;
                        head = stu;
                        return;
                    }
                    current->prev->next = stu;
                    stu->prev = current->prev;
                    stu->next = current;
                    current->prev = stu;
                    return;
                } 
            }
        }
        if(!current->next)break;
        current = current->next;
    }

    // put at tail
    current->next = stu;
    stu->prev = current;
    tail = stu;
}

// bool for if all inputs are valid, and student gets created and inserted
bool DomesticList::createDom(string first, string last, float cgpa, int rscore, string province){
    if(cgpa > 4.31 || cgpa < 0){
        cout << "Invalid cGPA" << endl;
        return false;
    }else if(rscore > 100 || rscore < 0){
        cout << "Invalid Research Score" << endl;
        return false;
    }else if(province != "NL" && province != "PE" && province != "NS" && province != "NB" && province != "QC" && province != "ON" && province != "MB" && province != "SK" && province != "AB" && province != "BC" && province != "YT" && province != "NT" && province != "NU"){
        cout << "Invalid Province" << endl;
        return false;
    }else if(first == "" || last == ""){
        cout << "Missing Field" << endl;
        return false;
    }

    DomPtr newDom;
    try{
        newDom = new DomesticStudent;
    }catch(bad_alloc &newDom){
        cerr << "bad_alloc caught: createDom" << newDom.what();
    }
    newDom->setcGPA(cgpa);
    newDom->setFirstName(first);
    newDom->setLastName(last);
    newDom->setProvince(province);
    newDom->setResearchScore(rscore);
    domInsert(newDom);
    return true;
}

void DomesticList::deleteDom(string first, string last){
    DomPtr temp = head;
    while(temp){
        if(temp->getFirstName() == first && temp->getLastName() == last){
            if(temp == head){
                temp->next->prev = NULL;
                head = temp->next;
                delete temp;
            }else if(temp == tail){
                temp->prev->next = NULL;
                tail = temp->prev;
                delete temp;
            }else{
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
            }
        }
        temp = temp->next;
    }
}

void DomesticList::deleteHT(){
    // DomesticStudent *temp = head;
    if(head == NULL || tail == NULL){               // zero elements
        return;
    }else if(head == tail){                         // one element
        delete head;
        head = NULL;
        tail = NULL;
    }else if(head->getNext()->getNext() == NULL){   // two elements
        tail->prev = NULL;
        delete tail;
        head->next = NULL;
        delete head;
        head = NULL;
        tail = NULL;
    }else if(head->getNext()->getNext() != NULL){   // three plus elements
        DomPtr temp = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        delete temp;

        temp = head;
        head->next->prev = NULL;
        head = head->next;
        delete temp;
    }
    return;
}

float DomesticList::Domestic_Average_Score(){

  // Variables used locally
  DomPtr temp = head;
  float average = 0;
  float overall = 0;
  float increment = 0;

  // Check validity
  if (head == NULL){

    cout << "Error: List is empty. Cannot perform operation" << endl;
    return 0;

  }
  // Condition for loop
  do{

    overall += temp->getCGPA();

    increment++;
    temp = temp->next;

  }while(temp);

  average = overall/increment;
  //cout << increment << "Domestic Students have applied to SFU. The average CGPA for this 
   // group is:" << average << "\n"<< endl;

  return average;
}

float InternationalList::International_Average_Score(){

  // Variables used locally
  IntPtr temp = head;
  float average = 0;
  float overall = 0;
  float increment = 0;

  // Check validity
  if (head == NULL){

    cout << "Error: List is empty. Cannot perform operation" << endl;
    return 0;

  }
  // Condition for loop
  do{

    overall += temp->getCGPA();

    increment++;
    temp = temp->next;

  }while(temp);

  average = overall/increment;
  //cout << increment << "International Students have applied to SFU. The average CGPA for this 
   // group is:" << average << "\n"<< endl;

  return average;
}

// lower 3 functions are search, should have error checking
bool DomesticList::searchAppID(int appID){
    DomPtr temp = head;
    int count = 0;
        while(temp != NULL){
            if(temp->getAppID() == appID){
                cout << *temp << endl;
                count++;
            }
            temp = temp->getNext();
        }
        if(count == 0){
            cout << "No matching student(s)." << endl;
            return false;
        }
    return true;
}    
           
bool DomesticList::searchCPGA(float cgpa){
    DomPtr temp = head;
    int count = 0;
        while(temp != NULL){
            if(temp->getCGPA() == cgpa){
                cout << *temp << endl;
                count++;
            }
            temp = temp->getNext();
        }
        if(count == 0){
            cout << "No matching student(s)." << endl;
            return false;
        }     
    return true;
}

bool DomesticList::searchResearch(int rscore){
    DomPtr temp = head;
    int count = 0;
        while(temp != NULL){
            if(temp->getResearchScore() == rscore){
                count++;
                cout << *temp << endl;
            }
        temp = temp->getNext();
        }
        if(count == 0){
            cout << "No matching student(s)." << endl;
            return false;
        }
    return true;
}

bool DomesticList::searchName(string first, string last){
    first = tolower(first);
    last = tolower(last);
    int count = 0;
    DomPtr temp = head;
    while(temp!=NULL){
        if(tolower(temp->getFirstName()) == first && tolower(temp->getLastName()) == last){
            count++;
            cout << *temp << endl; 
        }
        temp = temp->getNext();
    }
    if(count == 0){
        cout << "No matching student(s)." << endl;
        return false;
    }
    return true;
}

vector<DomPtr> DomesticList::searchNameCompare(string first, string last)
{
    vector<DomPtr> matchingStudents;
    first = tolower(first);
    last = tolower(last);
    int count = 0;
    DomPtr temp = head;
    while(temp!=NULL){
        if(tolower(temp->getFirstName()) == first && tolower(temp->getLastName()) == last){
            count++;
            matchingStudents.push_back(temp); 
        }
        temp = temp->getNext();
    }
    if(count == 0){
        cout << "No matching student(s)." << endl;
        return matchingStudents;
    }
    return matchingStudents;
}

vector<IntPtr> InternationalList::searchNameCompare(string first, string last)
{
    vector<IntPtr> matchingStudents;
    first = tolower(first);
    last = tolower(last);
    int count = 0;
    IntPtr temp = head;
    while(temp!=NULL){
        if(tolower(temp->getFirstName()) == first && tolower(temp->getLastName()) == last){
            count++;
            matchingStudents.push_back(temp); 
        }
        temp = temp->getNext();
    }
    if(count == 0){
        cout << "No matching student(s)." << endl;
        return matchingStudents;
    }
    return matchingStudents;
}

ostream &operator<<(ostream &os, DomesticList &stu){
    os << setw(15) << "AppID" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(15) << "cGPA" << setw(15) << "Research" << setw(15) << setw(15) << "Province" << endl;
    DomPtr temp = stu.head;
    while(temp){
        os << setw(15) << temp->getAppID() << setw(15) << temp->getFirstName() << setw(15) << temp->getLastName() << setw(15) << temp->getCGPA() << setw(15) << temp->getResearchScore() << setw(15) << temp->getProvince() << endl;
        temp = temp->getNext();
    }
    return os;
}



//                              INTERNATIONAL STUDENT FUNCTIONS

IntPtr InternationalStudent::getNext(){
    return next;
}

IntPtr InternationalStudent::getPrev(){
    return prev;
}

// InternationalList

InternationalList::InternationalList(){
    head = NULL;
    tail = NULL;
}

InternationalList::~InternationalList(){
    IntPtr temp;
    while(head){
        temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
    tail = NULL;
}

IntPtr InternationalList::getHead() const
{
    return head;
}

IntPtr InternationalList::getTail() const{
    return tail;
}

void InternationalList::interInsert(IntPtr stu){ 
    //overall sort - Research Score > CGPA > Country

    // if empty list
    if(!head){
        head = tail = stu;
        head->prev = NULL;
        tail->next = NULL;
        return;
    }

    // find place for stu
    IntPtr current = head;
    while(current)
    {
        if(stu->getResearchScore() > current->getResearchScore())
        {
            if(current->prev == NULL)
            {
                stu->next = head;
                head->prev = stu;
                head = stu;
                return;
            }
            current->prev->next = stu;
            stu->prev = current->prev;
            stu->next = current;
            current->prev = stu;
            return;
        }
        else if(stu->getResearchScore() == current->getResearchScore())
        {
            if(stu->getCGPA() > current->getCGPA())
            {   
                if(current->prev == NULL)
                {
                    stu->next = head;
                    head->prev = stu;
                    head = stu;
                    return;
                }
                current->prev->next = stu;
                stu->prev = current->prev;
                stu->next = current;
                current->prev = stu;
                return;
            }
            else if(stu->getCGPA() == current->getCGPA())
            {
                if(compareCountry(*stu, *current) == -1) //if stu's Country is alphabetically larger than the current iterating item
                {   
                    if(current->prev == NULL)
                    {
                        stu->next = head;
                        head->prev = stu;
                        head = stu;
                        return;
                    }
                    current->prev->next = stu;
                    stu->prev = current->prev;
                    stu->next = current;
                    current->prev = stu;
                    return;
                } 
            }
        }
        if(!current->next)break;
        current = current->next;
    }

    // put at tail;
    current->next = stu;
    stu->prev = current;
    tail = stu;
}

bool InternationalList::createInter(string first, string last, float cgpa, int rscore, string country, ToeflScore toefl)
{   
    if(country == "Idian"){
        country = "India";
    }
    if(cgpa > 4.31 || cgpa < 0){
        cout << "Invalid CGPA" << endl;
        return false;
    }else if(rscore > 100 || rscore < 0){
        cout << "Invalid Research Score" << endl;
        return false;
    }else if(country != "Canada" && country != "China" && country != "India" && country != "Iran" && country != "Korea"){
        cout << "Invalid Country" << endl;
        return false;
    }else if(!toefl.validToeflIndividual()){
        cout << "Invalid TOEFL" << endl;
        return false;
    }else if(toefl.getReading() < 20 || toefl.getListening() < 20 || toefl.getSpeaking() < 20 || toefl.getWriting() < 20){
        cout << first << " " << last << " " << "TOEFL too low, removing from list" << endl;
        return false;
    }else if(first == "" || last == ""){
        cout << "Missing Field" << endl;
        return false;
    }

    IntPtr newInt;
    try{
        newInt = new InternationalStudent;
    }catch(bad_alloc &newInt){
        cerr << "bad_alloc caught: createInter" << newInt.what();
    }
    newInt->setcGPA(cgpa);
    newInt->setFirstName(first);
    newInt->setLastName(last);
    newInt->setCountry(country);
    newInt->setResearchScore(rscore);
    newInt->setToeflScore(toefl);
    interInsert(newInt);
    return true;
}

void InternationalList::deleteInter(string first, string last){
    IntPtr temp = head;
    while(temp){
        if(temp->getFirstName() == first && temp->getLastName() == last){
            if(temp == head){
                temp->next->prev = NULL;
                head = temp->next;
                delete temp;
            }else if(temp == tail){
                temp->prev->next = NULL;
                tail = temp->prev;
                delete temp;
            }else{
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
            }
        }
        temp = temp->next;
    }
}

void InternationalList::deleteHT(){
    if(head == NULL || tail == NULL){               // zero elements
        return;
    }else if(head == tail){                         // one element
        delete head;
        head = NULL;
        tail = NULL;
    }else if(head->getNext()->getNext() == NULL){   // two elements
        tail->prev = NULL;
        delete tail;
        head->next = NULL;
        delete head;
        head = NULL;
        tail = NULL;
    }else if(head->getNext()->getNext() != NULL){   // three plus elements
        IntPtr temp = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        delete temp;

        temp = head;
        head->next->prev = NULL;
        head = head->next;
        delete temp;
    }
    return;
}

bool InternationalList::searchAppID(int appid){
    IntPtr temp = head;
    int count = 0;
        while(temp != NULL){
            if(temp->getAppID() == appid){
                cout << *temp << endl;
                count++;
            }
            temp = temp->getNext();
        }
        if(count == 0){
            cout << "No matching student(s)." << endl;
            return false;
        }
    return true;
}

bool InternationalList::searchCPGA(float cgpa){
    IntPtr temp = head;
    int count = 0;
        while(temp != NULL){
            if(temp->getCGPA() == cgpa){
                cout << *temp << endl;
                count++;
            }
            temp = temp->getNext();
        }
        if(count == 0){
            cout << "No matching student(s)." << endl;
            return false;
        }     
    return true;
}

bool InternationalList::searchResearch(int rscore){
    IntPtr temp = head;
    int count = 0;
        while(temp != NULL){
            if(temp->getResearchScore() == rscore){
                count++;
                cout << *temp << endl;
            }
        temp = temp->getNext();
        }
        if(count == 0){
            cout << "No matching student(s)." << endl;
            return false;
        }
    return true;
}

bool InternationalList::searchName(string first, string last){
    first = tolower(first);
    last = tolower(last);
    int count = 0;
    IntPtr temp = head;
    while(temp!=NULL){
        if(tolower(temp->getFirstName()) == first && tolower(temp->getLastName()) == last){
            count++;
            cout << *temp << endl; 
        }
        temp = temp->getNext();
    }
    if(count == 0){
        cout << "No matching student(s)." << endl;
        return false;
    }
    return true;
}

ostream &operator<<(ostream &os, InternationalList &stu){
    os << setw(15) << "AppID" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(15) << "cGPA" << setw(15) << "Research" << setw(15) << setw(15) << "Country" << setw(15) << "TOEFL" << setw(15) << "Reading" << setw(15) << "Writing" << setw(15) << "Speaking" << setw(15) << "Listening" << endl;
    IntPtr temp = stu.head;
    while(temp){
        os << setw(15) << temp->getAppID() << setw(15) << temp->getFirstName() << setw(15) << temp->getLastName() << setw(15) << temp->getCGPA() << setw(15) << temp->getResearchScore() << setw(15) << temp->getCountry() << setw(15) << temp->getToeflScore().getTotal() << setw(15) << temp->getToeflScore().getReading() << setw(15) << temp->getToeflScore().getWriting() << setw(15) << temp->getToeflScore().getSpeaking() << setw(15) << temp->getToeflScore().getListening() << endl;
        temp = temp->getNext();
    }
    return os;
}

//  GeneralStudent

GeneralStudent::GeneralStudent()
{
    firstName = "";
    lastName = "";
    cGPA = 0;
    researchScore = 0;
    appID = 0;
    province = "";
    country = "";
    TOEFL = ToeflScore(0, 0, 0, 0);

    next = NULL;
    prev = NULL;
}

GeneralStudent::GeneralStudent(string first, string last, float cgpa, int rscore, int appid, string prov, string count, ToeflScore toefl)
{
    firstName = first;
    lastName = last;
    cGPA = cgpa;
    researchScore = rscore;
    appID = appid;
    province = prov;
    country = count;
    TOEFL = toefl;

    next = NULL;
    prev = NULL;
}

string GeneralStudent::getFirstName()
{
    return firstName;
}
void GeneralStudent::setFirstName(string n){
    firstName = n;
}

string GeneralStudent::getLastName()
{
    return lastName;
}
void GeneralStudent::setLastName(string n){
    lastName = n;
}

float GeneralStudent::getcGPA()
{
    return cGPA;
}
void GeneralStudent::setcGPA(float c){
    cGPA = c;
}

int GeneralStudent::getAppID()
{
    return appID;
}
void GeneralStudent::setAppID(int id){
    appID = id;
}

int GeneralStudent::getResearchScore()
{
    return researchScore;
}
void GeneralStudent::setResearchScore(int r){
    researchScore = r;
}

string GeneralStudent::getProvince()
{
    return province;
}
void GeneralStudent::setProvince(string p){
    province = p;
}

string GeneralStudent::getCountry()
{
    return country;
}
void GeneralStudent::setCountry(string c){
    country = c;
}

ToeflScore GeneralStudent::getTOEFL()
{
    return TOEFL;
}
void GeneralStudent::setTOEFL(ToeflScore t){
    TOEFL = t;
}

GenPtr GeneralStudent::getNext(){
    return next;
}

ostream &operator<<(ostream &os, GeneralStudent &stu){

     os << setw(15) << stu.getAppID() << setw(15) << stu.getFirstName() << setw(15) << stu.getLastName() << setw(15) << stu.getcGPA() << setw(15) << stu.getResearchScore() << setw(15) << stu.getProvince() << setw(15) << stu.getCountry() << endl;
    return os;
}

//  GeneralList

GeneralList::GeneralList()
{
    head = NULL;
    tail = NULL;
}

GeneralList::GeneralList(const DomesticList &DomesticStudents, const InternationalList &InternationalStudents)
{
    head = NULL;
    tail = NULL;
    // convert all international students to general student first
    
    IntPtr intIterator = InternationalStudents.getHead();

    while(intIterator)
    {
        // GenPtr newGenI = new GeneralStudent(intIterator->getFirstName(), intIterator->getLastName(), intIterator->getCGPA(), intIterator->getResearchScore(), intIterator->getAppID(), "", intIterator->getCountry(), intIterator->getToeflScore());
        
        GenPtr newGenI;
        try{
            newGenI = new GeneralStudent;
        }catch(bad_alloc &newGen){
            cerr << "bad_alloc caught: GeneralList constructor international conversion" << newGen.what();
        }
        newGenI->setFirstName(intIterator->getFirstName());
        newGenI->setLastName(intIterator->getLastName());
        newGenI->setcGPA(intIterator->getCGPA());
        newGenI->setResearchScore(intIterator->getResearchScore());
        newGenI->setAppID(intIterator->getAppID());
        newGenI->setProvince("");
        newGenI->setCountry(intIterator->getCountry());
        newGenI->setTOEFL(intIterator->getToeflScore());

        if(head == NULL)
        {
            head = tail = newGenI;
            head->prev = NULL;
            tail->next = NULL;
        }
        else
        {   
            tail->next = newGenI;
            newGenI->prev = tail;
            tail = newGenI;
        }
        intIterator = intIterator->getNext();
        if(!intIterator)break;
    }
    ToeflScore domScore(-1, -1, -1, -1);
    bool isTail;
    DomPtr domIterator = DomesticStudents.getHead();
    while(domIterator)
    {
        // if(!domIterator){
        //     return;
        // }

        // GenPtr newGen = new GeneralStudent(domIterator->getFirstName(), domIterator->getLastName(), domIterator->getCGPA(), domIterator->getResearchScore(), domIterator->getAppID(), domIterator->getProvince(), "", domScore);
        
        GenPtr newGen;
        try{
            newGen = new GeneralStudent;
        }catch(bad_alloc &newGen){
            cerr << "bad_alloc caught: GeneralList constructor domestic conversion" << newGen.what();
        }
        newGen->setFirstName(domIterator->getFirstName());
        newGen->setLastName(domIterator->getLastName());
        newGen->setcGPA(domIterator->getCGPA());
        newGen->setResearchScore(domIterator->getResearchScore());
        newGen->setAppID(domIterator->getAppID());
        newGen->setProvince(domIterator->getProvince());
        newGen->setCountry("Canada");
        newGen->setTOEFL(domScore);

        if(!head){
            head = tail = newGen;
            head->prev = NULL;
            tail->next = NULL;

            domIterator = domIterator->next;
            continue;
        }
        isTail = true;
        GenPtr current = head;
        while(current)
        {
            if(newGen->getResearchScore() > current->getResearchScore())
            {
                if(current->prev == NULL)
                {
                    newGen->next = head;
                    head->prev = newGen;
                    head = newGen;

                    isTail = false;
                    break;
                }
                current->prev->next = newGen;
                newGen->prev = current->prev;
                newGen->next = current;
                current->prev = newGen;

                isTail = false;
                break;
            }
            else if(newGen->getResearchScore() == current->getResearchScore())
            {
                if(newGen->getcGPA() > current->getcGPA())
                {
                    if(current->prev == NULL)
                    {
                        newGen->next = head;
                        head->prev = newGen;
                        head = newGen;

                        isTail = false;
                        break;
                    }
                    current->prev->next = newGen;
                    newGen->prev = current->prev;
                    newGen->next = current;
                    current->prev = newGen;

                    isTail = false;
                    break;
                }
                else if(newGen->getcGPA() == current->getcGPA())
                {
                    if(current->getProvince() == "") 
                    //if current is international, put in front
                    {
                        if(current->prev == NULL){
                            newGen->next = head;
                            head->prev = newGen;
                            head = newGen;

                            isTail = false;
                            break;
                        }

                        current->prev->next = newGen;
                        newGen->prev = current->prev;
                        newGen->next = current;
                        current->prev = newGen;

                        isTail = false;
                        break;
                    }

                    if(current->getCountry() == "Canada") 
                    //if both domestic, put new one behind current to maintain order
                    {
                        if(current->prev == NULL){
                            newGen->next = head->next;
                            head->next = newGen;
                            newGen->prev = head;

                            isTail = false;
                            break;
                        }
                        newGen->next = current->next;
                        newGen->prev = current;
                        current->next->prev = newGen;
                        current->next = newGen;

                        isTail = false;
                        break;
                    }
                }
            }
            if(!current->next)break;
            current = current->next;
        }
        if(isTail){
        current->next = newGen;
        newGen->prev = current;
        tail = newGen;
        }
        domIterator = domIterator->getNext();
    }
    
}

GeneralList::~GeneralList(){
    GenPtr temp;
    while(head){
        temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
    tail = NULL;
}

GenPtr GeneralList::getHead(){
    return head;
}

GenPtr GeneralList::getTail(){
    return tail;
}

ostream &operator<<(ostream &os, GeneralList &stu){
    os << setw(15) << "AppID" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(15) << "cGPA" << setw(15) << "Research" << setw(15) << "Province" << setw(15) << "Country" << setw(15) << "TOEFL" << setw(15) << "Reading" << setw(15) << "Writing" << setw(15) << "Speaking" << setw(15) << "Listening" << endl;
    GenPtr current = stu.head;
    while(current){
        if(current->getCountry() == "Canada") //Domestic Student
        {
            os << setw(15) << current->getAppID() << setw(15) << current->getFirstName() << setw(15) << current->getLastName() << setw(15) << current->getcGPA() << setw(15) << current->getResearchScore() << setw(15)  << current->getProvince() << setw(15) << "Canada" << endl;
        }
        else //International Student
        {
            os << setw(15) << current->getAppID() << setw(15) << current->getFirstName() << setw(15) << current->getLastName() << setw(15) << current->getcGPA() << setw(15) << current->getResearchScore() << setw(15) << "" << setw(15) << current->getCountry() << setw(15) << current->getTOEFL().getTotal() << setw(15) << current->getTOEFL().getReading() << setw(15) << current->getTOEFL().getWriting() << setw(15) << current->getTOEFL().getSpeaking() << setw(15) << current->getTOEFL().getListening() << endl;
        }
        current = current->getNext();
    }
    return os;
}

void GeneralList::thresholdSearch(float minCGPA, int minResearchScore)
{   
    cout << setw(15) << "AppID" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(15) << "cGPA" << setw(15) << "Research" << setw(15) << "Province" << setw(15) << "Country" << setw(15) << "TOEFL" << setw(15) << "Reading" << setw(15) << "Writing" << setw(15) << "Speaking" << setw(15) << "Listening" << endl;
    int counter = 0;
    GenPtr current = head;
    while(current)
    {
        if(current->getcGPA() >= minCGPA && current->getResearchScore() >= minResearchScore)
        {
            if(current->getCountry() == "Canada") //Domestic Student
            {
                cout << setw(15) << current->getAppID() << setw(15) << current->getFirstName() << setw(15) << current->getLastName() << setw(15) << current->getcGPA() << setw(15) << current->getResearchScore() << setw(15)  << current->getProvince() << setw(15) << "Canada" << endl;
            }
            else //International Student
            {
                cout << setw(15) << current->getAppID() << setw(15) << current->getFirstName() << setw(15) << current->getLastName() << setw(15) << current->getcGPA() << setw(15) << current->getResearchScore() << setw(15) << "" << setw(15) << current->getCountry() << setw(15) << current->getTOEFL().getTotal() << setw(15) << current->getTOEFL().getReading() << setw(15) << current->getTOEFL().getWriting() << setw(15) << current->getTOEFL().getSpeaking() << setw(15) << current->getTOEFL().getListening() << endl;
            }
        }
        current = current->next;
    }

    if(counter = 0)
    {
        cout << "No matching students found..." << endl;
    }
}

void DomesticList::compareDL(DomesticStudent *stu1, DomesticStudent *stu2){
    if(stu1->getCGPA() > stu2->getCGPA()){
        float diff = stu1->getCGPA() - stu2->getCGPA();
        cout << stu1->getFirstName() << " has a larger CGPA than " << stu2->getFirstName() << endl
            << "(" << stu1->getCGPA() << " - " << stu2->getCGPA() << " = " << diff << " )" << endl;
    }else if(stu1->getCGPA() < stu2->getCGPA()){
        float diff = stu2->getCGPA() - stu1->getCGPA();
        cout << stu2->getFirstName() << " has a larger CGPA than " << stu1->getFirstName() << endl
            << "( " << stu2->getCGPA() << " - " << stu1->getCGPA() << " = " << diff << " )" << endl;
    }else{
        cout << stu1->getFirstName() << " and " << stu2->getFirstName() << " have the same CGPA." << endl
            << "( " << stu1->getCGPA() << " )" << endl;
    }

    if(stu1->getResearchScore() > stu2->getResearchScore()){
        int diff = stu1->getResearchScore() - stu2->getResearchScore();
        cout << stu1->getFirstName() << " has a larger research score than " << stu2->getFirstName() << endl
            << "(" << stu1->getResearchScore() << " - " << stu2->getResearchScore() << " = " << diff << " )" << endl;
    }else if(stu1->getCGPA() < stu2->getCGPA()){
        int diff = stu2->getResearchScore() - stu1->getResearchScore();
        cout << stu2->getFirstName() << " has a larger research score than " << stu1->getFirstName() << endl
            << "( " << stu2->getResearchScore() << " - " << stu1->getResearchScore() << " = " << diff << " )" << endl;
    }else{
        cout << stu1->getFirstName() << " and " << stu2->getFirstName() << " have the same research score." << endl
            << "( " << stu1->getResearchScore() << " )" << endl;
    }
    return;
}

void InternationalList::compareIL(InternationalStudent *stu1, InternationalStudent *stu2){
    
    if(stu1->getCGPA() > stu2->getCGPA()){
        float diff = stu1->getCGPA() - stu2->getCGPA();
        cout << stu1->getFirstName() << " has a larger CGPA than " << stu2->getFirstName() << endl
            << "(" << stu1->getCGPA() << " - " << stu2->getCGPA() << " = " << diff << " )" << endl;
    }else if(stu1->getCGPA() < stu2->getCGPA()){
        float diff = stu2->getCGPA() - stu1->getCGPA();
        cout << stu2->getFirstName() << " has a larger CGPA than " << stu1->getFirstName() << endl
            << "( " << stu2->getCGPA() << " - " << stu1->getCGPA() << " = " << diff << " )" << endl;
    }else{
        cout << stu1->getFirstName() << " and " << stu2->getFirstName() << " have the same CGPA." << endl
            << "( " << stu1->getCGPA() << " )" << endl;
    }

    if(stu1->getResearchScore() > stu2->getResearchScore()){
        int diff = stu1->getResearchScore() - stu2->getResearchScore();
        cout << stu1->getFirstName() << " has a larger research score than " << stu2->getFirstName() << endl
            << "(" << stu1->getResearchScore() << " - " << stu2->getResearchScore() << " = " << diff << " )" << endl;
    }else if(stu1->getCGPA() < stu2->getCGPA()){
        int diff = stu2->getResearchScore() - stu1->getResearchScore();
        cout << stu2->getFirstName() << " has a larger research score than " << stu1->getFirstName() << endl
            << "( " << stu2->getResearchScore() << " - " << stu1->getResearchScore() << " = " << diff << " )" << endl;
    }else{
        cout << stu1->getFirstName() << " and " << stu2->getFirstName() << " have the same research score." << endl
            << "( " << stu1->getResearchScore() << " )" << endl;
    }

    if(stu1->getToeflScore().getTotal() > stu2->getToeflScore().getTotal()){
        int diff = stu1->getToeflScore().getTotal() - stu2->getToeflScore().getTotal();
        cout << stu1->getFirstName() << " has a larger TOEFL score than " << stu2->getFirstName() << endl
            << "(" << stu1->getToeflScore().getTotal() << " - " << stu2->getToeflScore().getTotal() << " = " << diff << " )" << endl;
    }else if(stu1->getToeflScore().getTotal() < stu2->getToeflScore().getTotal()){
        int diff = stu2->getToeflScore().getTotal() - stu1->getToeflScore().getTotal();
        cout << stu2->getFirstName() << " has a larger TOEFL score than " << stu1->getFirstName() << endl
            << "( " << stu2->getToeflScore().getTotal() << " - " << stu1->getToeflScore().getTotal() << " = " << diff << " )" << endl;
    }else{
        cout << stu1->getFirstName() << " and " << stu2->getFirstName() << " have the same TOEFL score." << endl
            << "( " << stu1->getToeflScore().getTotal() << " )" << endl;
    }
    return;
    
}

