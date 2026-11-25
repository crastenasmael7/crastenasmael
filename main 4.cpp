
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    int n;

    // Step 1: Enter number of persons
    cout << "Enter number of persons: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of persons!" << endl;
        return 1;
    }

    // Save persons in file
    ofstream outFile("persons.txt");

    if (!outFile)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        Person p;

        cout << "Enter person " << i + 1 << " name: ";
        cin >> ws;
        getline(cin, p.name);

        cout << "Enter person " << i + 1 << " age: ";
        cin >> p.age;

        outFile << p.name << endl;
        outFile << p.age << endl;
    }

    outFile.close();

    // Step 2: Read persons from file
    vector<Person> persons;

    ifstream inFile("persons.txt");

    if (!inFile)
    {
        cout << "Error reading file!" << endl;
        return 1;
    }

    Person p;

    while (getline(inFile, p.name))
    {
        if (!(inFile >> p.age))
            break;

        inFile.ignore(numeric_limits<streamsize>::max(), '\n');

        persons.push_back(p);
    }

    inFile.close();

    // Find youngest and oldest persons
    int minAge = persons[0].age;
    int maxAge = persons[0].age;

    for (int i = 1; i < persons.size(); i++)
    {
        if (persons[i].age < minAge)
            minAge = persons[i].age;

        if (persons[i].age > maxAge)
            maxAge = persons[i].age;
    }

    // Save results in results file
    ofstream resultFile("results.txt");

    if (!resultFile)
    {
        cout << "Error opening results file!" << endl;
        return 1;
    }

    resultFile << "Youngest Persons:" << endl;

    for (int i = 0; i < persons.size(); i++)
    {
        if (persons[i].age == minAge)
        {
            resultFile << persons[i].name
                       << " " << persons[i].age << endl;
        }
    }

    resultFile << "Oldest Persons:" << endl;

    for (int i = 0; i < persons.size(); i++)
    {
        if (persons[i].age == maxAge)
        {
            resultFile << persons[i].name
                       << " " << persons[i].age << endl;
        }
    }

    resultFile.close();

    cout << "Data saved successfully!" << endl;

    return 0;
}
