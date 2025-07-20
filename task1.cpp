#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeToFile(const string& filename) {
    ofstream outFile(filename); // opens in write mode (overwrites existing content)
    if (!outFile) {
        cout << "Error opening file for writing!\n";
        return;
    }

    string data;
    cout << "Enter data to write to the file: ";
    cin.ignore();
    getline(cin, data);

    outFile << data << endl;
    outFile.close();

    cout << "Data written to file successfully.\n";
}

void appendToFile(const string& filename) {
    ofstream outFile(filename, ios::app); // opens in append mode
    if (!outFile) {
        cout << "Error opening file for appending!\n";
        return;
    }

    string data;
    cout << "Enter data to append to the file: ";
    cin.ignore();
    getline(cin, data);

    outFile << data << endl;
    outFile.close();

    cout << "Data appended to file successfully.\n";
}

void readFromFile(const string& filename) {
    ifstream inFile(filename); // opens in read mode
    if (!inFile) {
        cout << "Error opening file for reading!\n";
        return;
    }

    string line;
    cout << "\n--- File Contents ---\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

int main() {
    string filename = "filedata.txt";
    int choice;

    do {
        cout << "\n--- File Management Tool ---\n";
        cout << "1. Write to File\n";
        cout << "2. Append to File\n";
        cout << "3. Read from File\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                appendToFile(filename);
                break;
            case 3:
                readFromFile(filename);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}      
