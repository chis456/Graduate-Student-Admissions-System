#include <string> //you will have to use string in C++
#include <vector>
#include "student.hpp"

#ifndef STU_SORT_H
#define STU_SORT_H

using namespace std;

// SORTING BY EACH FIELD

// Used Functions
// The six functions used in main to sort the student by whatever type
vector<DomesticStudent> sortResearch(vector<DomesticStudent> stu); //to be overloaded
vector<DomesticStudent> sortCgpa(vector<DomesticStudent> stu);
vector<DomesticStudent> sortFirstName(vector<DomesticStudent> stu);
vector<DomesticStudent> sortLastName(vector<DomesticStudent> stu);

vector<InternationalStudent> sortResearch(vector<InternationalStudent> stu); //to be overloaded
vector<InternationalStudent> sortCgpa(vector<InternationalStudent> stu);
vector<InternationalStudent> sortFirstName(vector<InternationalStudent> stu);
vector<InternationalStudent> sortLastName(vector<InternationalStudent> stu);

vector<DomesticStudent> sortProvince(vector<DomesticStudent> stu);
vector<InternationalStudent> sortCountry(vector<InternationalStudent> stu);

// Partitions and sorting
// Each of the four fields have individual partition functions, and recursive quicksort functions
// Research
vector<DomesticStudent>::iterator researchPart(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right);
void quickSortResearch(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right);

vector<InternationalStudent>::iterator researchPart(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right);
void quickSortResearch(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right);

// CGPA
vector<DomesticStudent>::iterator cgpaPart(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right);
void quickSortCgpa(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right);

vector<InternationalStudent>::iterator cgpaPart(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right);
void quickSortCgpa(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right);

// First Name
vector<DomesticStudent>::iterator firstNamePart(vector<DomesticStudent>::iterator left, vector<Student>::iterator right);
void quickSortFirstName(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right);

vector<InternationalStudent>::iterator firstNamePart(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right);
void quickSortFirstName(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right);

// Last Name
vector<DomesticStudent>::iterator lastNamePart(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right);
void quickSortLastName(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right);

vector<InternationalStudent>::iterator lastNamePart(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right);
void quickSortLastName(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right);

// Province/Country
vector<DomesticStudent>::iterator provincePart(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right);
void quickSortProvince(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right);

vector<InternationalStudent>::iterator countryPart(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right);
void quickSortCountry(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right);

// OVERALL SORT

// sort domestic students
vector<DomesticStudent> overallSort(vector<DomesticStudent> stu);
// quicksort function for overallSortDom
void overallQuickSort(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right);
// partition for overallQuickSortDom
vector<DomesticStudent>::iterator partition(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right);

// sort international students
vector<InternationalStudent> overallSort(vector<InternationalStudent> stu);
// quicksort function for overallSortInt
void overallQuickSort(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right);
// partition for overallQuickSortInt
vector<InternationalStudent>::iterator partition(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right);

#endif