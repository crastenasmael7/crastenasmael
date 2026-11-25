
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name;
    int id;
    float grade;

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter student ID: ";
    cin >> id;

    cout << "Enter student grade: ";
    cin >> grade;

    ofstream file("Student.txt");

    file << name << endl;
    file << id << endl;
    file << grade << endl;

    file.close();

    cout << "Data saved successfully";

    return 0;
}
