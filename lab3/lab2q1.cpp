#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct COURSE{
    string code;
    float grade;
};

int main(){
    vector <COURSE> courses;
    int courseCount = -1;
    char wantNewCourse = 'y';
    string inpCode;
    float inpGrade;
    float totalGrade = 0;
    while(wantNewCourse == 'y'){
        courseCount++;
        courses.push_back(COURSE());
        cout << "Enter course code and grade: ";
        cin >> courses[courseCount].code;
        cin >> courses[courseCount].grade;
        totalGrade += courses[courseCount].grade;
        cout << "Add new course? ";
        cin >> wantNewCourse;
    }
    cout << "List of entered " << (courseCount+1) << " courses:" << endl; 
    for(int i = 0; i <= courseCount ; ++i){
        cout << "- " << courses[i].code << ", Grade: " << courses[i].grade << endl; 
    }
    cout << "CGPA: " << totalGrade / (courseCount + 1) << endl;   
    return 0;
}