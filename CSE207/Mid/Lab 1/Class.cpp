#include <iostream>
using namespace std;

class course{
    string courseCode, courseTitle;
    float totalCr, labCr;
public:
    course(string code, string title, float credit, float lab){
        courseCode = code;
        courseTitle = title;
        totalCr = credit;
        labCr = lab;
    }

    void printCourse(){
        cout << "The course title is: " << courseTitle;
    }
};

int main(){
    course c1 = course("CSE207", "Data Structures", 4, 1);
    c1.printCourse();
    return 0;
}