#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;

class Student 
{
    public:
        const static int daysArraySize = 3;
    private:
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int daysComplete[daysArraySize];
        DegreeProgram degreeProgram;
    public:
        //setters
        void setStudentID(string id);
        void setFirstName(string first);
        void setLastName(string last);
        void setEmail(string email);
        void setAge(int age);
        void setDaysToComplete(const int daysComplete[]);
        void setDegreeProgram(DegreeProgram program);
        
        //getters
        string getStudentID();
        string getFirstName();
        string getLastName();
        string getEmail();
        int getAge();
        const int* getDaysToComplete();
        DegreeProgram getDegreeProgram();

        //constructors and destructor
        Student();
        Student(string studentID, string firstName, string lastName, 
            string emailAddress, int age, int daysComplete[], DegreeProgram degreeProgram);
        ~Student();
        
        static void printHeader();
        void print();
};