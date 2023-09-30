#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <vector>
#include "student.hpp"

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

int main(){

    string line;

//domestic-stu.txt
    DomesticList dl;

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
        cgpa = roundFloat(cgpa);

        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());

        dl.createDom(firstName, lastName, cgpa, researchScore, province);
        
    }
    //close your file
    domesticFile.close();
    cout << dl << endl;

//international-stu.txt
    InternationalList il;

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
        int researchScore, readingScore, listeningScore, speakingScore, writingScore;

        //get firstName separated by comma
        getline(ss, firstName, ',');

        //get lastName separated by comma
        getline(ss, lastName, ',');

        //get country separated by comma
        getline(ss, country, ',');

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        cgpa = atof(s_cgpa.c_str());
        cgpa = roundFloat(cgpa);
        
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

        il.createInter(firstName, lastName, cgpa, researchScore, country, toefl);

    }
    internationalFile.close();
    cout << il << endl;

    // USER INTERFACE
    string input, input1, input2, input3;
    for(;;){
      cout << "Please enter the number of the following you would like to test, or type '0' for exit: " << endl
          << "1) Domestic Student List" << endl
          << "2) International Student List" << endl
          << "3) Compare two Domestic Students" << endl
          << "4) Compare two International Students" << endl
          << "5) Merged List" << endl;
      cin >> input;
      if(input == "0"){
        cout << "Exiting program" << endl;
        break;
      }else if(input == "1"){
        for(;;){
          cout << "Please select what you would like to do with the domestic student list:" << endl
              << "1) Search by application ID" << endl
              << "2) Search for CGPA" << endl
              << "3) Search for research score" << endl
              << "4) Search for first and last name" << endl
              << "5) Create a new student" << endl
              << "6) Delete a student from first and last name" << endl
              << "7) Delete the first and last students" << endl
              << "8) Print out the list" << endl
              << "9) Go back to main menu" << endl;
          cin >> input1;
          if(input1 == "1"){
            string appid;
            int appid_i;
            for(;;){
              cout << "Please enter an application ID: ";
              cin >> appid;
              try
              {
                appid_i = stoi(appid);
              }
              catch(...)
              {
                cout << "Invalid input, please try again." << endl;
                continue;
              }
              
              if(appid_i < 20220000 || appid_i > 20229999){
                cout << "Invalid input, please try again." << endl;
              }else{
                dl.searchAppID(appid_i);
                break;
              }
            }
          }else if(input1 == "2"){
            string cgpa;
            float cgpa_f;
            for(;;){
              cout << "Please enter a CGPA: ";
              cin >> cgpa;
              try
              {
                cgpa_f = stof(cgpa);
              }
              catch(...)
              {
                cout << "Invalid input, please try again." << endl;
                continue;
              }
              
              if(cgpa_f < 0 || cgpa_f > 4.31){
                cout << "Invalid input, please try again." << endl;
              }else{
                dl.searchCPGA(cgpa_f);
                break;
              }
            }
          }else if(input1 == "3"){
            string rscore;
            int rscore_i;
            for(;;){
              cout << "Please enter a research score: ";
              cin >> rscore;
              try
              {
                rscore_i = stoi(rscore);
              }
              catch(...)
              {
                cout << "Invalid input, please try again." << endl;
                continue;
              }
              
              if(rscore_i < 0 || rscore_i > 100){
                cout << "Invalid input, please try again." << endl;
              }else{
                dl.searchResearch(rscore_i);
                break;
              }
            }            
          }else if(input1 == "4"){
            string first, last;
            cout << "Please enter a first name: ";
            cin >> first;
            cout << "Please enter a last name: ";
            cin >> last;
            dl.searchName(first, last);
          }else if(input1 == "5"){
            string first, last, province, cgpa, rscore;
            for(;;){
              cout << "Please enter a first name: ";
              cin >> first;
              cout << "Please enter a last name: ";
              cin >> last;
              cout << "Please enter a cgpa: ";
              cin >> cgpa;
              cout << "Please enter a research score: ";
              cin >> rscore;
              cout << "Please enter a province: ";
              cin >> province;
              if(stof(cgpa) < 0 || stof(cgpa) > 4.31 || stoi(rscore) < 0 || stoi(rscore) > 100 || (province != "NL" && province != "PE" && province != "NS" && province != "NB" && province != "QC" && province != "ON" && province != "MB" && province != "SK" && province != "AB" && province != "BC" && province != "YT" && province != "NT" && province != "NU")){
                cout << "Invalid input, please try again." << endl;
              }else{
                if(dl.createDom(first, last, stof(cgpa), stoi(rscore), province)){
                  cout << "Student made correctly." << endl;
                  break;
                }else{
                  cout << "Student made incorrectly, please try again." << endl;
                }
              }
            }
          }else if(input1 == "6"){
            string first, last;
            cout << "Please enter a first name: ";
            cin >> first;
            cout << "Please enter a last name: ";
            cin >> last;
            dl.deleteDom(first, last);
          }else if(input1 == "7"){
            dl.deleteHT();
          }else if(input1 == "8"){
            cout << dl << endl;
          }else if(input1 == "9"){
            break;
          }else{
            cout << "Invalid input, please try again." << endl;
          }
        }
      }else if(input =="2"){
        for(;;){
          cout << "Please select what you would like to do with the international student list:" << endl
              << "1) Search by application ID" << endl
              << "2) Search for CGPA" << endl
              << "3) Search for research score" << endl
              << "4) Search for first and last name" << endl
              << "5) Create a new student" << endl
              << "6) Delete a student from first and last name" << endl
              << "7) Delete the first and last students" << endl
              << "8) Print out the list" << endl
              << "9) Go back to main menu" << endl;
          cin >> input2;
          if(input2 == "1"){
            string appid;
            int appid_i;
            for(;;){
              cout << "Please enter an application ID: ";
              cin >> appid;
              try
              {
                appid_i = stoi(appid);
              }
              catch(...)
              {
                cout << "Invalid input please try again." << endl;
                continue;
              }
              
              if(appid_i < 20220000 || appid_i > 20229999){
                cout << "Invalid input, please try again." << endl;
              }else{
                il.searchAppID(appid_i);
                break;
              }
            }
          }else if(input2 == "2"){
            string cgpa;
            float cgpa_f;
            for(;;){
              cout << "Please enter a CGPA: ";
              cin >> cgpa;
              try
              {
                cgpa_f = stof(cgpa);
              }
              catch(...)
              {
                cout << "Invalid input, please try again." << endl;
                continue;
              }
              
              if(cgpa_f < 0 || cgpa_f > 4.31){
                cout << "Invalid input, please try again." << endl;
              }else{
                il.searchCPGA(cgpa_f);
                break;
              }
            }
          }else if(input2 == "3"){
            string rscore;
            int rscore_i;
            for(;;){
              cout << "Please enter a research score: ";
              cin >> rscore;
              try
              {
                rscore_i = stoi(rscore);
              }
              catch(...)
              {
                cout << "Invalid input, please try again." << endl;
                continue;
              }
              
              if(rscore_i < 0 || rscore_i > 100){
                cout << "Invalid input, please try again." << endl;
              }else{
                il.searchResearch(rscore_i);
                break;
              }
            }            
          }else if(input2 == "4"){
            string first, last;
            cout << "Please enter a first name: ";
            cin >> first;
            cout << "Please enter a last name: ";
            cin >> last;
            il.searchName(first, last);
          }else if(input2 == "5"){
            string first, last, country, cgpa, rscore, r, w, s, l;
            float cgpa_f;
            int rscore_i;
            int reading, writing, speaking, listening;
            for(;;){
              cout << "Please enter a first name: ";
              cin >> first;
              cout << "Please enter a last name: ";
              cin >> last;
              cout << "Please enter a cgpa: ";
              cin >> cgpa;
              try
              {
                cgpa_f = stof(cgpa);
                if(cgpa_f < 0 || cgpa_f > 4.31)
                {
                  cout << "Invalid cgpa input, please try again." << endl;
                  continue;
                }
              }
              catch(...)
              {
                cout << "Invalid cgpa input, please try again." << endl;
                continue;
              }
              cout << "Please enter a research score: ";
              cin >> rscore;
              try
              {
                rscore_i = stoi(rscore);
                if(rscore_i < 0 || rscore_i > 100)
                {
                  cout << "Invalid research score input, please try again" << endl;
                  continue;
                }
              }
              catch(...)
              {
                cout << "Invalid research score input, please try again." << endl;
                continue;
              }
              cout << "Please enter a country: ";
              cin >> country;
              if(country != "China" && country != "Korea" && country != "India" && country != "Iran")
              {
                cout << "Invalid country input, please try again." << endl;
                continue;
              }
              cout << "Please enter a reading score: ";
              cin >> r;
              try
              {
                reading = stoi(r);
                if(reading < 0 || reading > 30)
                {
                  cout << "Invalid reading score input, please try again" << endl;
                  continue;
                }
              }
              catch(...)
              {
                cout << "Invalid reading score input, please try again." << endl;
                continue;
              }
              
              cout << "Please enter a writing score: ";
              cin >> w;
              try
              {
                writing = stoi(w);
                if(writing < 0 || writing > 30)
                {
                  cout << "Invalid writing score input, please try again" << endl;
                  continue;
                }
              }
              catch(...)
              {
                cout << "Invalid writing score input, please try again." << endl;
                continue;
              }

              cout << "Please enter a speaking score: ";
              cin >> s;
              try
              {
                speaking = stoi(s);
                if(speaking < 0 || speaking > 30)
                {
                  cout << "Invalid speaking score input, please try again" << endl;
                  continue;
                }
              }
              catch(...)
              {
                cout << "Invalid speaking score input, please try again." << endl;
                continue;
              }

              cout << "Please enter a listening score: ";
              cin >> l;
              try
              {
                listening = stoi(l);
                if(listening < 0 || listening > 30)
                {
                  cout << "Invalid listening score input, please try again" << endl;
                  continue;
                }
              }
              catch(...)
              {
                cout << "Invalid listening score input, please try again." << endl;
                continue;
              }
              ToeflScore toefl(reading, listening, speaking, writing);

              if(il.createInter(first, last, stof(cgpa), stoi(rscore), country, toefl)){
                cout << "Student made correctly." << endl;
                break;
              }else{
                cout << "Student made incorrectly, please try again." << endl;
                continue;
                }
              }
            
          }else if(input2 == "6"){
            string first, last;
            cout << "Please enter a first name: ";
            cin >> first;
            cout << "Please enter a last name: ";
            cin >> last;
            il.deleteInter(first, last);
          }else if(input2 == "7"){
            dl.deleteHT();
          }else if(input2 == "8"){
            cout << il << endl;
          }else if(input2 == "9"){
            break;
          }else{
            cout << "Invalid input, please try again." << endl;
          }
        }
      } else if (input == "3") //coimpoaring diosmentsic ustnedt
      {
        cout << "Enter the first and last name of the first student to compare: " << endl;
        string first, last;
        cout << "First Name: ";
        cin >> first;
        cout << "Last Name: ";
        cin >> last;
        vector<DomPtr> matchingStudents = dl.searchNameCompare(first, last);
        if(matchingStudents.size() == 0){
          continue;
        }
        for(int i = 0; i < matchingStudents.size(); i++)
        {
          cout << (i + 1) << ". " << matchingStudents.at(i)->getFirstName() << " " << matchingStudents.at(i)->getLastName() << " cGPA: " << matchingStudents.at(i)->getCGPA() << " Research Score: " << matchingStudents.at(i)->getResearchScore() << " Province: " << matchingStudents.at(i)->getProvince() << endl;
        }
        cout << "Please type the corresponding number of the student you want to compare" << endl;
        int studentSelection;
        cin >> studentSelection;
        DomPtr selectedStudent1 = matchingStudents.at(studentSelection - 1);

        cout << "Enter the first and last name of the second student to compare: " << endl;
        cout << "First Name: ";
        cin >> first;
        cout << "Last Name: ";
        cin >> last;
        vector<DomPtr> matchingStudents2 = dl.searchNameCompare(first, last);
        if(matchingStudents2.size() == 0){
          continue;
        }
        for(int i = 0; i < matchingStudents2.size(); i++)
        {
          cout << (i + 1) << ". " << matchingStudents2.at(i)->getFirstName() << " " << matchingStudents2.at(i)->getLastName() << " cGPA: " << matchingStudents2.at(i)->getCGPA() << " Research Score: " << matchingStudents2.at(i)->getResearchScore() << " Province: " << matchingStudents2.at(i)->getProvince() << endl;
        }
      
        cout << "Please type the corresponding number of the student you want to compare" << endl;
        cin >> studentSelection;
        DomPtr selectedStudent2 = matchingStudents2.at(studentSelection - 1);

        dl.compareDL(selectedStudent1, selectedStudent2);

      } else if (input == "4") //focmapring sinterational students
      {
        cout << "Enter the first and last name of the first student to compare: " << endl;
        string first, last;
        cout << "First Name: ";
        cin >> first;
        cout << "Last Name: ";
        cin >> last;
        vector<IntPtr> matchingStudents = il.searchNameCompare(first, last);
        if(matchingStudents.size() == 0){
          continue;
        }
        for(int i = 0; i < matchingStudents.size(); i++)
        {
          cout << (i + 1) << ". " << matchingStudents.at(i)->getFirstName() << " " << matchingStudents.at(i)->getLastName() << " cGPA: " << matchingStudents.at(i)->getCGPA() << " Research Score: " << matchingStudents.at(i)->getResearchScore() << " Province: " << matchingStudents.at(i)->getCountry() << endl;
        }
        cout << "Please type the corresponding number of the student you want to compare" << endl;
        int studentSelection;
        cin >> studentSelection;
        IntPtr selectedStudent1 = matchingStudents.at(studentSelection - 1);

        cout << "Enter the first and last name of the second student to compare: " << endl;
        cout << "First Name: ";
        cin >> first;
        cout << "Last Name: ";
        cin >> last;
        vector<IntPtr> matchingStudents2 = il.searchNameCompare(first, last);
        if(matchingStudents2.size() == 0){
          continue;
        }
        for(int i = 0; i < matchingStudents2.size(); i++)
        {
          cout << (i + 1) << ". " << matchingStudents2.at(i)->getFirstName() << " " << matchingStudents2.at(i)->getLastName() << " cGPA: " << matchingStudents2.at(i)->getCGPA() << " Research Score: " << matchingStudents2.at(i)->getResearchScore() << " Province: " << matchingStudents2.at(i)->getCountry() << endl;
        }
        cout << "Please type the corresponding number of the student you want to compare" << endl;
        cin >> studentSelection;
        IntPtr selectedStudent2 = matchingStudents2.at(studentSelection - 1);

        il.compareIL(selectedStudent1, selectedStudent2);

        
      }
      else if(input == "5"){
        GeneralList gl = GeneralList(dl, il);
        string minCGPA, minResearchScore;
        for(;;){
          cout << "Please enter a minimum CGPA: ";
          cin >> minCGPA;
          cout << "Please enter a minimum research score: ";
          cin >> minResearchScore;
          if(stof(minCGPA) < 0 || stof(minCGPA) > 4.31 || stoi(minResearchScore) < 0 || stoi(minResearchScore) > 100){
            cout << "Invalid input, please try again." << endl;
          }else{
            gl.thresholdSearch(stof(minCGPA), stoi(minResearchScore));
            break;
          }
        }
      }else{
        cout << "Invalid input, please try again." << endl;
      }
    }
    return 0;
}