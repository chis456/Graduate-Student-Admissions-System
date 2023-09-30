#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <vector>
#include "student.hpp"
#include "stu_sort.hpp"


void printVector(vector<DomesticStudent> stu){
  cout << "\nAppID" << "\t\t" << "First Name" << "\t\t" << "Last Name" << "\t\t" << "Province" << "\t" << "cGPA" << "\t\t" << "Research Score\n" << endl;
  for(auto i=stu.begin(); i<stu.end(); i++){
    cout << (*i) << endl;
  }
}

void printVector(vector<InternationalStudent> stu){
  cout << "\nAppID" << "\t\t" << "First Name" << "\t\t" << "Last Name" << "\t\t" << "Country" << "\t\t" << "cGPA" << "\t\t" << "Research" << "\t" << "Reading" << "\t\t" << "Listening" << "\t" << "Speaking" << "\t" << "Writing" << "\t\t" << "TOEFL Score\n" << endl;
  for(auto i=stu.begin(); i<stu.end(); i++){
    cout << (*i) << endl;
  }
}

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

string addSpaces(string name)
{
  string newName = name;
  int maxLength = 11;
  int lengthNeeded = maxLength - name.size();
  for(int i = 0; i < lengthNeeded; i++)
  {
    newName.append(" ");
  }
  return newName;
}

int main(){
  int stu_count = 1;
  vector<DomesticStudent> domesticStudents;
  
  //Read the domestic-stu.txt file and exit if failed
  string line;
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }

  //Read the first line of domestic-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(domesticFile, line);
  cout << "File format: " << line << endl;
  
  while( getline(domesticFile, line) ) {

    istringstream ss(line);

    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    //get firstName separated by comma
    getline(ss, firstName, ',');

    //get lastName separated by comma
    getline(ss, lastName, ',');

    //get province separated by comma
    getline(ss, province, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

  //set up Domestic Student
    
    //need to add a certain amount of spaces to the end or else the formatting will get messed up, also we cant use <iomanip>
    string firstNameExtended = addSpaces(firstName);
    string lastNameExtended = addSpaces(lastName);
    float roundedCGPA = roundFloat(cgpa);
    
    DomesticStudent DStudent; 
    DStudent.setFirstName(firstNameExtended);
    DStudent.setLastName(lastNameExtended);
    DStudent.setcGPA(roundedCGPA);
    DStudent.setProvince(province);
    DStudent.setResearchScore(researchScore);

    if(DStudent.validCGPA() && DStudent.validID() && DStudent.validResearchScore()){

      domesticStudents.push_back(DStudent);
      stu_count++;
      
    }
  }

  //close your file
  domesticFile.close();



  //International Student vector setup
  vector<InternationalStudent> internationalStudents;

  ifstream internationalFile("international-stu.txt");
  if(!internationalFile.is_open()) {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }

  getline(internationalFile, line);
  cout << "File format: " << line << endl;

  while( getline(internationalFile, line) ) {

    istringstream ss(line);

    string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
    float cgpa;
    int researchScore;
    int readingScore;
    int listeningScore;
    int speakingScore;
    int writingScore;

    //get firstName separated by comma
    getline(ss, firstName, ',');

    //get lastName separated by comma
    getline(ss, lastName, ',');

    //get country separated by comma
    getline(ss, country, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    //get reading score seperated by comma, then convert to int
    getline(ss, s_reading, ',');
    readingScore = atoi(s_reading.c_str());

    //get listening score seperated by comma, then convert to int
    getline(ss, s_listening, ',');
    listeningScore = atoi(s_listening.c_str());

    //get speaking score seperated by comma, then convert to int
    getline(ss, s_speaking, ',');
    speakingScore = atoi(s_speaking.c_str());

    //get writing score seperated by comma, then convert to int
    getline(ss, s_writing, ',');
    writingScore = atoi(s_writing.c_str());

    //set up toefl score
    ToeflScore toefl;
    toefl.setReading(readingScore);
    toefl.setListening(listeningScore);
    toefl.setSpeaking(speakingScore);
    toefl.setWriting(writingScore);

    //need to add a certain amount of spaces to the end or else the formatting will get messed up, also we cant use <iomanip>
    string firstNameExtended = addSpaces(firstName);
    string lastNameExtended = addSpaces(lastName);
    float roundedCGPA = roundFloat(cgpa);

  //set up International Student
    InternationalStudent IStudent; 
    IStudent.setFirstName(firstNameExtended);
    IStudent.setLastName(lastNameExtended);
    IStudent.setcGPA(roundedCGPA);
    IStudent.setCountry(country);
    IStudent.setToeflScore(toefl);
    IStudent.setResearchScore(researchScore);

    if(IStudent.validCGPA() && IStudent.validID() && IStudent.validResearchScore() && IStudent.getToeflScore().validToeflIndividual() && IStudent.getToeflScore().validToeflTotal()){
      
      internationalStudents.push_back(IStudent);
      stu_count++;

    }
  }
  internationalFile.close();

  // Sorted vectors set up beforehand
  
  //Sorted international student vectors

  vector<InternationalStudent> intSortedbyOverall = overallSort(internationalStudents);
  vector<InternationalStudent> intSortedbyCGPA = sortCgpa(internationalStudents);
  vector<InternationalStudent> intSortedbyResearch = sortResearch(internationalStudents);
  vector<InternationalStudent> intSortedbyFName = sortFirstName(internationalStudents);
  vector<InternationalStudent> intSortedbyLName = sortLastName(internationalStudents);
  vector<InternationalStudent> intSortedbyCountry = sortCountry(internationalStudents);

  //Sorted Domestic student vectors
  vector<DomesticStudent> domSortedbyOverall = overallSort(domesticStudents);
  vector<DomesticStudent> domSortedbyCGPA = sortCgpa(domesticStudents);
  vector<DomesticStudent> domSortedbyResearch = sortResearch(domesticStudents);
  vector<DomesticStudent> domSortedbyFName = sortFirstName(domesticStudents);
  vector<DomesticStudent> domSortedbyLName = sortLastName(domesticStudents);
  vector<DomesticStudent> domSortedbyProvince = sortProvince(domesticStudents);

  string studentTypeInput;
  string domFieldSelect;
  string intFieldSelect;


  for(;;)
  {
    cout << "\n\nWelcome, which type would you like to sort by? \n \
              (1) Domestic Students \n \
              (2) International Students \n \
              (3) Exit Program \n" << endl;
    // Add stats prompt here^
    
    cin >> studentTypeInput;

    
    if(studentTypeInput == "1")
    {
      for(;;)
      {
        cout << "Which field would you like to sort by?\n \
                (1) Overall \n \
                (2) cGPA \n \
                (3) Research Score \n \
                (4) First Name \n \
                (5) Last Name \n \
                (6) Province \n \
                (7) Return to main menu" << endl;
        cin >> domFieldSelect;
        if(domFieldSelect == "1")
        {
          printVector(domSortedbyOverall);
        }
        else if(domFieldSelect == "2")
        {
          printVector(domSortedbyCGPA);
        }
        else if(domFieldSelect == "3")
        {
          printVector(domSortedbyResearch);
        }
        else if(domFieldSelect == "4")
        {
          printVector(domSortedbyFName);
        }
        else if(domFieldSelect == "5")
        {
          printVector(domSortedbyLName);
        }
        else if(domFieldSelect == "6")
        {
          printVector(domSortedbyProvince);
        }
        else if(domFieldSelect == "7")
        {
          break;
        }
        else
        {
          cout << "Invalid input, try again" << endl;
        }
      }
    }
    else if(studentTypeInput == "2")
    {
      for(;;)
      {
        cout << "Which field would you like to sort by?\n \
                (1) Overall \n \
                (2) cGPA \n \
                (3) Research Score \n \
                (4) First Name \n \
                (5) Last Name \n \
                (6) Country \n \
                (7) Return to main menu" << endl;
        cin >> intFieldSelect;
        if(intFieldSelect == "1")
        {
          printVector(intSortedbyOverall);
        }
        else if(intFieldSelect == "2")
        {
          printVector(intSortedbyCGPA);
        }
        else if(intFieldSelect == "3")
        {
          printVector(intSortedbyResearch);
        }
        else if(intFieldSelect == "4")
        {
          printVector(intSortedbyFName);
        }
        else if(intFieldSelect == "5")
        {
          printVector(intSortedbyLName);
        }
        else if(intFieldSelect == "6")
        {
          printVector(intSortedbyCountry);
        }
        else if(intFieldSelect == "7")
        {
          break;
        }
        else
        {
          cout << "Invalid input, try again" << endl;
        }
      }
    }
    else if(studentTypeInput == "3")
    {
      cout << "\nGoodbye" << endl;
      return 0;
    }/*
     else if (studentTypeInput == 4){
    
      cout << "\nDisplaying Applicant Data\n" << endl;
       DomesticList::Domestic_Average_Score()
    }
    */
    else
    {
      cout << "Invalid input, try again" << endl;
    }
  }
}
