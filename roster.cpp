#include "roster.h"

void Roster::parse(string items) 
{
    DegreeProgram degreeProgram = DegreeProgram::SECURITY;
    if (items.back() == 'K') degreeProgram = DegreeProgram::NETWORK;
    else if (items.back() == 'E') degreeProgram = DegreeProgram::SOFTWARE;
    string parsed[9];
    int leftSide = 0;
    int rightSide = 0;
    for (int i = 0; i < 8; i++) {
        rightSide = items.find(",", leftSide);
        parsed[i] = items.substr(leftSide, rightSide - leftSide);
        leftSide = rightSide + 1;
    }
    add(parsed[0], parsed[1], parsed[2], parsed[3], stoi(parsed[4]), stoi(parsed[5]), 
        stoi(parsed[6]), stoi(parsed[7]), degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, 
            int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
    int rosterArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[++lastIdx] = new Student(studentID, firstName, lastName, emailAddress, age,
        rosterArray, degreeprogram);
    cout << "Student added to class roster at row" << lastIdx + 1 << endl;
}

void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIdx; i++) Roster::classRosterArray[i]->print();
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIdx; i++)
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
}

void Roster::printInvalidEmails()
{
    for (int i = 0; i <= Roster::lastIdx; i++) {
        string email = Roster::classRosterArray[i]->getEmail();
        if (email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos)
            cout << email << " is invalid." << endl;
    }
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastIdx; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            cout << studentID << ":";
            cout << (classRosterArray[i]->getDaysToComplete()[0] + 
                classRosterArray[i]->getDaysToComplete()[1] + 
                classRosterArray[i]->getDaysToComplete()[2]) / 3.0 << endl;
        }
    }
}

//removes row, but does not delete. decrements the counter to give appearance of deletion
void Roster::remove(string studentID)
{
    bool isPresent = false;
    for (int i = 0; i <= Roster::lastIdx; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            isPresent = true;
            Student* temp = classRosterArray[i];
            classRosterArray[i] = classRosterArray[rosterArraySize-1];
            classRosterArray[rosterArraySize - 1] = temp;
            Roster::lastIdx--;
        }
    }
    if (isPresent) {
        cout << "Student " << studentID << " removed." << endl;
        printAll();
    } else {
        cout << "Student " << studentID << " not found." << endl;
    }
}

Roster::~Roster()
{
    for (int i = 0; i < rosterArraySize; i++) {
        cout << "Destructor called for " << classRosterArray[i]->getStudentID() << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}