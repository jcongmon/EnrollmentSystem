#include "roster.h"

int main() 
{
    cout << "--------------------------------------------" << endl;
    cout << "Scripting and Programming Applications, C867" << endl;
    cout << "          C++, StudentID: 010318775         " << endl;
    cout << "              Jonathan Congmon              " << endl;
    cout << "--------------------------------------------" << endl;

    const string studentData[] = 
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
        "A5,Jonathan,Congmon,jcongmo@wgu.edu,33,1,2,3,SOFTWARE"
        };
    
    const int dataSize = 5;

    Roster roster;
    for (string str : studentData) roster.parse(str);

    cout << "Displaying all students:" << endl;
    roster.printAll();

    cout << "Displaying students with invalid emails:" << endl;
    roster.printInvalidEmails();

    cout << "Average days in course:" << endl;
    for (int i = 0; i < dataSize; i++) roster.printAverageDaysInCourse(roster.classRosterArray[i]->getStudentID());

    for (int i = 0; i < 3; i++) {
        cout << "Displaying by degree program:" << degreeProgramStrings[i] << endl;
        roster.printByDegreeProgram((DegreeProgram)i);
    }
    
    cout << "Removing StudentID A3:" << endl;
    roster.remove("A3");

    cout << "Removing StudentID A3:" << endl;
    roster.remove("A3");

    cout << "End of program. Destructors will be called upon exit." << endl;

    return 0;
}