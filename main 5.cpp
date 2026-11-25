#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char name[20];
    int id;
    float grade;
    char delim = '$';
    char choice;

    // فتح الملف في وضع الإضافة (append) للحفاظ على السجلات السابقة
    ofstream outFile("students.txt", ios::app);

    if (!outFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    do {
        cin.ignore();

        cout << "Enter student name: ";
        cin.getline(name, 20);

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter student grade: ";
        cin >> grade;


        outFile << name << ", " << id << ", " << grade << " " << delim << endl;

        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    outFile.close();
    cout << "Records saved successfully to students.txt" << endl;

    return 0;
}
