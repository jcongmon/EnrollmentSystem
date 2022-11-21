#pragma once
#include "student.h"

class Roster
{
    private:
        int lastIdx = -1;
        const static int rosterArraySize = 5;
    public:
        Student* classRosterArray[rosterArraySize] = {nullptr, nullptr, nullptr, nullptr, nullptr};
        void parse(string items);
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, 
            int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
        void remove(string studentID);
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
        ~Roster();
};