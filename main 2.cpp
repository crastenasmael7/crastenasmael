#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    ifstream inFile("fruit.txt");
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }


    ofstream outFile("fruit.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "\nFresh Fruits";
        outFile.close();
    }

    return 0;
}
