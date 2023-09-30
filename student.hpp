using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>
#include <vector>

#ifndef STUDENT_H
#define STUDENT_H

typedef struct DomesticStudent* DomPtr;
typedef struct InternationalStudent* IntPtr;
typedef struct GeneralStudent* GenPtr;

string tolower(string s);

class Student
{
    private:
        string firstName;
        string lastName;
        float cGPA;
        int researchScore;
        int appID;
        static int stuCount;
    
    public:
    // Constructors
        Student();
        Student(string f, string l, float gpa, int rscore);
    
    //get functions
        string getFirstName() const;
        string getLastName() const;
        float getCGPA() const;
        int getResearchScore() const; 
        int getAppID() const;

    //set functions
        void setFirstName(string name);
        void setLastName(string name);
        void setcGPA(float c);
        void setResearchScore(int score);
    
    //Compare functions
        //returns 1 if s1's cGPA is greater than s2, 0 if equal, -1 if s1's cGPA is smaller than s2
        friend int compareCGPA(const Student& s1, const Student& s2); 
        //returns 1 if s1's research score is greater than s2, 0 if equal, -1 if s1's research score is smaller than s2
        friend int compareResearchScore(const Student& s1, const Student& s2);

        friend int compareFirstName(const Student& s1, const Student& s2);

        friend int compareLastName(const Student& s1, const Student& s2);
        
        friend ostream &operator<<(ostream &os, Student &stu);
    
    // check functions
        bool validID () const;
        bool validResearchScore () const;
        bool validCGPA () const;
};

class ToeflScore {
    private:
    // Only accesible by member functions within the class
        int reading;
        int listening;
        int speaking;
        int writing;
    public:
     // Accesible from any function
        ToeflScore();
        ToeflScore(int r, int l, int s, int w);

    //get functions
        int getReading();
        int getListening();
        int getSpeaking();
        int getWriting();
        int getTotal();

    //set functions
        void setReading(int r);
        void setListening(int l);
        void setSpeaking(int s);
        void setWriting(int w);
    
    // check functions
        bool validToeflTotal () const;
        bool validToeflIndividual () const;
    
};

class DomesticStudent: public Student {
    
    private:
    // Only accesible by member functions within the class
        string province;
        
    public:
        DomPtr prev;
        DomPtr next;
    // Constructor
        DomesticStudent();

    // gets
        DomPtr getNext();
        DomPtr getPrev();
        string getProvince() const;

    // sets
        bool setProvince(string p);

    // friend functions
        // compare
        friend int compareProvince(const DomesticStudent& s1, const DomesticStudent& s2);        

        // output
        friend ostream &operator<<(ostream &os, DomesticStudent &domStu);

        // linked list
        friend class DomesticList;
};

class DomesticList{
    private:
        DomPtr head;
        DomPtr tail;

        // helper for createDom
        void domInsert(DomesticStudent *stu);

    public:
    // Constructors
        DomesticList();
        ~DomesticList();

    //Gets
        DomPtr getHead() const;
        DomPtr getTail() const;

    // functions
        void deleteDom(string first, string last);  // delete all students with first and last name
        bool createDom(string first, string last, float cgpa, int rscore, string province);  // create student with specified parameters and insert into list
        void deleteHT(); // delete the head and tail

        float Domestic_Average_Score();
        void compareDL(DomesticStudent *stu1, DomesticStudent *stu2);

        // Search and print functions
        bool searchAppID(int appid);                // appid search and print, return true if found at least 1 matching student
        bool searchCPGA(float cgpa);                // cpga search and print, return true if found at least 1 matching student
        bool searchResearch(int rscore);            // reasearch score search and print, return true if found at least 1 matching student
        bool searchName(string first, string last); // first name last name, return true if found at least 1 matching student
        vector<DomPtr> searchNameCompare(string first, string last);

        // output
        friend ostream &operator<<(ostream &os, DomesticList &stu);
};

class InternationalStudent: public Student {
    
    private:
        string country;
        ToeflScore toefl;
        //IntPtr next;      Need access for test!
        IntPtr prev;

    public: 
        IntPtr getNext();
        IntPtr getPrev();
    
        IntPtr next;
    // Accesible from any function
        InternationalStudent();
        string getCountry() const;
        ToeflScore getToeflScore() const;
        
    // Miscellaneous Functions
        bool setCountry(string c);
        void setToeflScore(ToeflScore score);
        friend int compareCountry(const InternationalStudent& s1, const InternationalStudent& s2);
        friend ostream &operator<<(ostream &os, InternationalStudent &intStu);
        

        friend class InternationalList;
};

class InternationalList{
    private:
        IntPtr head;
        IntPtr tail;

        // helper for createInter
        void interInsert(IntPtr stu);

    public:
    // Constructors
        InternationalList();
        ~InternationalList();
        
    // gets
        IntPtr getHead() const;
        IntPtr getTail() const;
        
    // functions
        void deleteInter(string first, string last);    // delete all students with first and last name
        bool createInter(string first, string last, float cgpa, int rscore, string country, ToeflScore toefl);      // create student with specified parameters and insert into list
        void deleteHT(); // delete head and tail
        float International_Average_Score();
        void compareIL(InternationalStudent *stu1, InternationalStudent *stu2);
        vector<IntPtr> searchNameCompare(string first, string last);

        
    
    // Search and print functions
        bool searchAppID(int appid);                // appid search and print, return true if found at least 1 matching student
        bool searchCPGA(float cgpa);                // cpga search and print, return true if found at least 1 matching student
        bool searchResearch(int rscore);            // reasearch score search and print, return true if found at least 1 matching student
        bool searchName(string first, string last); // first name last name, return true if found at least 1 matching student

        // output
        friend ostream &operator<<(ostream &os, InternationalList &stu);
};

class GeneralStudent
{
    private:
        string firstName;
        string lastName;
        float cGPA;
        int researchScore;
        int appID;
        string province;
        string country;
        ToeflScore TOEFL;

    public:
    // Constructors
        GeneralStudent();
        GeneralStudent(string first, string last, float cgpa, int rscore, int appid, string prov, string count, ToeflScore toefl);

    // gets and sets
        string getFirstName();
        void setFirstName(string n);

        string getLastName();
        void setLastName(string n);

        float getcGPA();
        void setcGPA(float c);

        int getResearchScore();
        void setResearchScore(int r);

        int getAppID();
        void setAppID(int id);

        string getProvince();
        void setProvince(string p);

        string getCountry();
        void setCountry(string c);
        
        ToeflScore getTOEFL();
        void setTOEFL(ToeflScore t);

        GenPtr getNext();
        GenPtr getPrev();

        GenPtr next;
        GenPtr prev;

        // output
        friend ostream &operator<<(ostream &os, GeneralStudent &stu);

        // linked list
        friend class GeneralList;
};

class GeneralList //for part 3
{
    private:
        
        
    public:
        GenPtr head;
        GenPtr tail;

    // Constructors
        GeneralList();
        GeneralList(const DomesticList &DomesticStudents,const InternationalList &InternationalStudents);
        ~GeneralList();

    // functions
        void thresholdSearch(float minCGPA, int minResearchScore);
        GenPtr getHead();
        GenPtr getTail();

       

        // output
        friend ostream &operator<<(ostream &os, GeneralList &stu);
};

#endif
