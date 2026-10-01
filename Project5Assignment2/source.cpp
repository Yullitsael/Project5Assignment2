#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct STUDENT_DATA
{
    string firstName;
    string lastName;
};

int main()
{
    std::ifstream inputFile("Resource Files/StudentData.txt");
    if (!inputFile.is_open())
    {
        cout << "Failed to open StudentData.txt" << endl;
        return 1;
    }

    vector<STUDENT_DATA> students;

    string line;

    while (getline(inputFile, line))
    {
        string firstName;
        string lastName;

        stringstream ss(line);

        getline(ss, firstName, ',');
        getline(ss, lastName);

        STUDENT_DATA student;

        student.firstName = firstName;
        student.lastName = lastName;

        students.push_back(student);
    }

    return 1;
}