#include "stu_sort.hpp"
#include "student.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ****comments only on the first of the four sorting algorithms, as the other three are similar, just changing variable types and comparative operators for ascending or descending

//                  RESEARCH/INT SCORE SORT DOMESTIC

vector<DomesticStudent>::iterator researchPart(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right){
    int pivot = (*right).getResearchScore(); // chooses the far right value as the 'halfway value', as to sort all other values larger to the left, and smaller to the right relative to this value.
    vector<DomesticStudent>::iterator i = left;

    for(vector<DomesticStudent>::iterator j=left; j<right; j++){ // for loop to use two different iterators and sort all items relative to pivot, larger to the left, smaller to the right
        if((*j).getResearchScore() >= pivot){ // descending
            swap(*i,*j);
            i++;
        }
    }
    swap(*right, *(i)); // put the iterator in the middle of the 2 larger and smaller sections
    return(i); // return the index of the iterator
}

void quickSortResearch(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right){ //recursive function
    if(left<right){ // error check, to see if there needs to be more recursive iterations executed
        vector<DomesticStudent>::iterator pivot = researchPart(left, right); // create new pivot

        quickSortResearch(left, pivot-1); // left half of the above pivot
        quickSortResearch(pivot+1, right); // right half of the above pivot
    }
}

vector<DomesticStudent> sortResearch(vector<DomesticStudent> stu){
    vector<DomesticStudent>::iterator left = stu.begin();
    vector<DomesticStudent>::iterator right = stu.end()-1;
    quickSortResearch(left, right);
    
    return stu;
}

//                  RESEARCH/INT SCORE SORT INTERNATIONAL

vector<InternationalStudent>::iterator researchPart(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right){
    int pivot = (*right).getResearchScore(); 
    vector<InternationalStudent>::iterator i = left;

    for(vector<InternationalStudent>::iterator j=left; j<right; j++){ 
        if((*j).getResearchScore() >= pivot){ 
            swap(*i,*j);
            i++;
        }
    }
    swap(*right, *(i)); 
    return(i); 
}

void quickSortResearch(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right){ 
    if(left<right){ 
        vector<InternationalStudent>::iterator pivot = researchPart(left, right);

        quickSortResearch(left, pivot-1); 
        quickSortResearch(pivot+1, right); 
    }
}

vector<InternationalStudent> sortResearch(vector<InternationalStudent> stu){
    vector<InternationalStudent>::iterator left = stu.begin();
    vector<InternationalStudent>::iterator right = stu.end()-1;
    quickSortResearch(left, right);
    
    return stu;
}

//                  CGPA/FLOAT SORT DOMESTIC

vector<DomesticStudent>::iterator cgpaPart(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right){
    float pivot = (*right).getCGPA();
    vector<DomesticStudent>::iterator i = left;

    for(vector<DomesticStudent>::iterator j=left; j<right; j++){
        if((*j).getCGPA() >= pivot){ // descending
            swap(*i,*j);
            i++;
        }
    }
    swap(*right, *(i));
    return(i);
}

void quickSortCgpa(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right){
    if(left<right){
        vector<DomesticStudent>::iterator pivot = cgpaPart(left, right);

        quickSortCgpa(left, pivot-1);
        quickSortCgpa(pivot+1, right);
    }
}

vector<DomesticStudent> sortCgpa(vector<DomesticStudent> stu){
    vector<DomesticStudent>::iterator left = stu.begin();
    vector<DomesticStudent>::iterator right = stu.end()-1;
    quickSortCgpa(left, right);

    return stu;
}

//                  CGPA/FLOAT SORT INTERNATIONAL

vector<InternationalStudent>::iterator cgpaPart(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right){
    float pivot = (*right).getCGPA();
    vector<InternationalStudent>::iterator i = left;

    for(vector<InternationalStudent>::iterator j=left; j<right; j++){
        if((*j).getCGPA() >= pivot){ // descending
            swap(*i,*j);
            i++;
        }
    }
    swap(*right, *(i));
    return(i);
}

void quickSortCgpa(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right){
    if(left<right){
        vector<InternationalStudent>::iterator pivot = cgpaPart(left, right);

        quickSortCgpa(left, pivot-1);
        quickSortCgpa(pivot+1, right);
    }
}

vector<InternationalStudent> sortCgpa(vector<InternationalStudent> stu){
    vector<InternationalStudent>::iterator left = stu.begin();
    vector<InternationalStudent>::iterator right = stu.end()-1;
    quickSortCgpa(left, right);

    return stu;
}

//                  NAME/PROVINCE/COUNTRY/CHARACTER SORT

//                      FIRST NAME DOMESTIC

vector<DomesticStudent>::iterator firstNamePart(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right){
    auto pivot = right;

    for(vector<DomesticStudent>::iterator j=left; j<right; j++){
        if(compareFirstName(*j, *pivot) < 0){ // ascending (alphabetical)
            swap(*j,*left);
            left++;
        }
    }
    swap(*left, *pivot);
    return left;
}

void quickSortFirstName(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right){
    if(left<right){
        vector<DomesticStudent>::iterator pivot = firstNamePart(left, right);

        quickSortFirstName(left, pivot-1);
        quickSortFirstName(pivot+1, right);
    }
}

vector<DomesticStudent> sortFirstName(vector<DomesticStudent> stu){
    vector<DomesticStudent>::iterator left = stu.begin();
    vector<DomesticStudent>::iterator right = stu.end()-1;
    quickSortFirstName(left, right);

    return stu;
}

//                      FIRST NAME INTERNATIONAL

vector<InternationalStudent>::iterator firstNamePart(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right){
    auto pivot = right;

    for(vector<InternationalStudent>::iterator j=left; j<right; j++){
        if(compareFirstName(*j, *pivot) < 0){ // ascending (alphabetical)
            swap(*j,*left);
            left++;
        }
    }
    swap(*left, *pivot);
    return left;
}

void quickSortFirstName(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right){
    if(left<right){
        vector<InternationalStudent>::iterator pivot = firstNamePart(left, right);

        quickSortFirstName(left, pivot-1);
        quickSortFirstName(pivot+1, right);
    }
}

vector<InternationalStudent> sortFirstName(vector<InternationalStudent> stu){
    vector<InternationalStudent>::iterator left = stu.begin();
    vector<InternationalStudent>::iterator right = stu.end()-1;
    quickSortFirstName(left, right);

    return stu;
}

//                      LAST NAME DOMESTIC

vector<DomesticStudent>::iterator lastNamePart(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right){
    auto pivot = right;

    for(vector<DomesticStudent>::iterator j=left; j<right; j++){
        if(compareLastName(*j, *pivot) < 0){ // ascending (alphabetical)
            swap(*j,*left);
            left++;
        }
    }
    swap(*left, *pivot);
    return left;
}

void quickSortLastName(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right){
    if(left<right){
        vector<DomesticStudent>::iterator pivot = lastNamePart(left, right);

        quickSortLastName(left, pivot-1);
        quickSortLastName(pivot+1, right);
    }
}

vector<DomesticStudent> sortLastName(vector<DomesticStudent> stu){
    vector<DomesticStudent>::iterator left = stu.begin();
    vector<DomesticStudent>::iterator right = stu.end()-1;
    quickSortLastName(left, right);

    return stu;
}

//                      LAST NAME INTERNATIONAL

vector<InternationalStudent>::iterator lastNamePart(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right){
    auto pivot = right;

    for(vector<InternationalStudent>::iterator j=left; j<right; j++){
        if(compareLastName(*j, *pivot) < 0){ // ascending (alphabetical)
            swap(*j,*left);
            left++;
        }
    }
    swap(*left, *pivot);
    return left;
}

void quickSortLastName(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right){
    if(left<right){
        vector<InternationalStudent>::iterator pivot = lastNamePart(left, right);

        quickSortLastName(left, pivot-1);
        quickSortLastName(pivot+1, right);
    }
}

vector<InternationalStudent> sortLastName(vector<InternationalStudent> stu){
    vector<InternationalStudent>::iterator left = stu.begin();
    vector<InternationalStudent>::iterator right = stu.end()-1;
    quickSortLastName(left, right);

    return stu;
}

//                      PROVINCE DOMESTIC

vector<DomesticStudent>::iterator provincePart(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right){
    string pivot = (*right).getProvince();
    vector<DomesticStudent>::iterator i = left;

    for(vector<DomesticStudent>::iterator j=left; j<right; j++){
        if((*j).getProvince().compare(pivot) < 0){ // ascending (alphabetical)
            swap(*i,*j);
            i++;
        }
    }
    swap(*right, *(i));
    return(i);
}

void quickSortProvince(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right){
    if(left<right){
        vector<DomesticStudent>::iterator pivot = provincePart(left, right);

        quickSortProvince(left, pivot-1);
        quickSortProvince(pivot+1, right);
    }
}

vector<DomesticStudent> sortProvince(vector<DomesticStudent> stu){
    vector<DomesticStudent>::iterator left = stu.begin();
    vector<DomesticStudent>::iterator right = stu.end()-1;
    quickSortProvince(left, right);

    return stu;
}

//                      COUNTRY INTERNATIONAL

vector<InternationalStudent>::iterator countryPart(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right){
    string pivot = (*right).getCountry();
    vector<InternationalStudent>::iterator i = left;

    for(vector<InternationalStudent>::iterator j=left; j<right; j++){
        if((*j).getCountry().compare(pivot) < 0){ // ascending (alphabetical)
            swap(*i,*j);
            i++;
        }
    }
    swap(*right, *(i));
    return(i);
}

void quickSortCountry(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right){
    if(left<right){
        vector<InternationalStudent>::iterator pivot = countryPart(left, right);

        quickSortCountry(left, pivot-1);
        quickSortCountry(pivot+1, right);
    }
}

vector<InternationalStudent> sortCountry(vector<InternationalStudent> stu){
    vector<InternationalStudent>::iterator left = stu.begin();
    vector<InternationalStudent>::iterator right = stu.end()-1;
    quickSortCountry(left, right);

    return stu;
}



//                  OVERALL SORT

// Domestic

// create iterators for recursive quicksort
vector<DomesticStudent> overallSort(vector<DomesticStudent> stu){
    auto left = stu.begin();
    auto right = (stu.end() - 1);
    overallQuickSort(left, right);
    
    return stu;
}

// quicksort
void overallQuickSort(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right){

    if(left < right){
        vector<DomesticStudent>::iterator pIt = partition(left, right);
        // left of pivot
        overallQuickSort(left, pIt - 1);
        // right of pivot
        overallQuickSort(pIt + 1, right);
    }
    return;
}

// partition
vector<DomesticStudent>::iterator partition(vector<DomesticStudent>::iterator left, vector<DomesticStudent>::iterator right){

    // vector<DomesticStudent>::iterator pivot = right;

    /*  swap to left of pivot if research score is higher
        if research score is same compare cGPA
        if cGPA is same compare province
    */  
    for(auto i = left; i < right; ++i){
        switch(compareResearchScore(*i, *right)){
            case 0:
                switch(compareCGPA(*i, *right)){
                    case 0:
                        if(compareProvince(*i, *right) < 0){
                            swap(*i, *left);
                            ++left;
                        }
                        break;
                    case 1:
                        swap(*i, *left);
                        ++left;
                        break;
                    case -1:
                        break;
                    default:
                        cout << "DomesticStudent partition Error compareCGPA" << endl;
                }
                break;
            case 1:
                swap(*i, *left);
                ++left;
                break;
            case -1:
                break;
            default:
                cout << "DomesticStudent partition Error compareResearchScore" << endl;
        }
    }

    swap(*left, *right);
    return left;
}

// International

// create iterators for recursive quicksort
vector<InternationalStudent> overallSort(vector<InternationalStudent> stu){

    // remove toefl individual score < 20 or total score < 93
    for(auto i = stu.begin(); i < stu.end(); ++i){

        if( (*i).getToeflScore().getTotal() < 93 || 
            (*i).getToeflScore().getReading() < 20 ||
            (*i).getToeflScore().getListening() < 20 ||
            (*i).getToeflScore().getSpeaking() < 20 ||
            (*i).getToeflScore().getWriting() < 20 ){
            
            stu.erase(i);
            --i;

        }

    }

    auto left = stu.begin();
    auto right = (stu.end() - 1);
    overallQuickSort(left, right);

    return stu;
}

// quicksort
void overallQuickSort(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right){
    
    if(left < right){
        vector<InternationalStudent>::iterator pIt = partition(left, right);
        // left of pivot
        overallQuickSort(left, pIt - 1);
        // right of pivot
        overallQuickSort(pIt + 1, right);
    }
    return;
}

// partition
vector<InternationalStudent>::iterator partition(vector<InternationalStudent>::iterator left, vector<InternationalStudent>::iterator right){
    
    vector<InternationalStudent>::iterator pivot = right;


    /*  swap to left of pivot if research score is higher
        if research score is same compare cGPA
        if cGPA is same compare country
    */  
    for(auto i = left; i < right; ++i){
        switch(compareResearchScore(*i, *pivot)){
            case 0:
                switch(compareCGPA(*i, *pivot)){
                    case 0:
                        if(compareCountry(*i, *pivot) < 0){
                            swap(*i, *left);
                            ++left;
                        }
                        break;
                    case 1:
                        swap(*i, *left);
                        ++left;
                        break;
                    case -1:
                        break;
                    default:
                        cout << "InternationalStudent partition Error compareCGPA" << endl;
                }
                break;
            case 1:
                swap(*i, *left);
                ++left;
                break;
            case -1:
                break;
            default:
                cout << "InternationalStudent partition Error compareResearchScore" << endl;
        }
    }

    swap(*left, *pivot);
    return left;
}