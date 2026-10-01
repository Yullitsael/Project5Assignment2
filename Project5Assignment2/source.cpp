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
#ifdef PRE_RELEASE
    string email;
#endif
};

int main()
{
#ifdef PRE_RELEASE
    cout << "Running PRE-RELEASE source code." << endl;

    ifstream inputFile("StudentData_Emails.txt");
#else
    cout << "Running STANDARD source code." << endl;

    ifstream inputFile("StudentData.txt");
#endif

    vector<STUDENT_DATA> students;

    string line;

    while (getline(inputFile, line))
    {
        string firstName;
        string lastName;

#ifdef PRE_RELEASE
        string email;
#endif

        stringstream ss(line);

        getline(ss, firstName, ',');
        getline(ss, lastName, ',');

#ifdef PRE_RELEASE
        getline(ss, email);
#endif

        STUDENT_DATA student;

        student.firstName = firstName;
        student.lastName = lastName;

#ifdef PRE_RELEASE
        student.email = email;
#endif

        students.push_back(student);
    }

#ifdef _DEBUG
    for (const STUDENT_DATA& student : students)
    {
        cout << student.firstName << " "
            << student.lastName;

#ifdef PRE_RELEASE
        cout << " - " << student.email;
#endif

        cout << endl;
    }
#endif

    return 0;
}