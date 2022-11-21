#include "student.h"

Student::Student() 
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < daysArraySize; i++) this->daysComplete[i] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, 
            string emailAddress, int age, int daysComplete[], DegreeProgram degreeProgram) 
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysArraySize; i++) this->daysComplete[i] = daysComplete[i];
    this->degreeProgram = degreeProgram;
}

Student::~Student() {}

//setters
void Student::setStudentID(string id) {this->studentID = id;}
void Student::setFirstName(string first) {this->firstName = first;}
void Student::setLastName(string last) {this->lastName = last;}
void Student::setEmail(string email) {this->emailAddress = email;}
void Student::setAge(int age) {this->age = age;}
void Student::setDaysToComplete(const int daysComplete[]){
    for (int i = 0; i < daysArraySize; i++) this->daysComplete[i] = daysComplete[i];
}
void Student::setDegreeProgram(DegreeProgram program) {this->degreeProgram = program;}

//getters
string Student::getStudentID() {return this->studentID;}
string Student::getFirstName() {return this->firstName;}
string Student::getLastName() {return this->lastName;}
string Student::getEmail() {return this->emailAddress;}
int Student::getAge() {return this->age;}
const int* Student::getDaysToComplete() {return this->daysComplete;}
DegreeProgram Student::getDegreeProgram() {return this->degreeProgram;}

void Student::printHeader() 
{
    cout << "ID\t";
    cout << "First\t";
    cout << "Last\t\t";
    cout << "Email\t\t";
    cout << "Age\t";
    cout << "DaysInCourse\t\t";
    cout << "DegreeProgram\t";
    cout << endl;
}

void Student::print()
{
    cout << this->studentID << "\t";
    cout << this->firstName << "\t";
    cout << this->lastName << "\t";
    cout << this->emailAddress << "\t";
    cout << this->age << '\t';
    cout << this->daysComplete[0] << '\t';
    cout << this->daysComplete[1] << '\t';
    cout << this->daysComplete[2] << '\t';
    cout << degreeProgramStrings[(int)this->degreeProgram] << '\t';
    cout << endl;
}