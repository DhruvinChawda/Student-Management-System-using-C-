#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

string arr1[20], arr2[20], arr3[20], arr4[20], arr5[20];
int total = 0;

void saveToFile() {
    ofstream file("students.txt");
    if (file.is_open()) {
        file << total << endl;
        for (int i = 0; i < total; ++i) {
            file << arr1[i] << endl;
            file << arr2[i] << endl;
            file << arr3[i] << endl;
            file << arr4[i] << endl;
            file << arr5[i] << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

void loadFromFile() {
    ifstream file("students.txt");
    if (file.is_open()) {
        file >> total;
        file.ignore();  
        for (int i = 0; i < total; ++i) {
            getline(file, arr1[i]);
            getline(file, arr2[i]);
            getline(file, arr3[i]);
            getline(file, arr4[i]);
            getline(file, arr5[i]);
        }
        file.close();
    } else {
        cout << "No previous data found." << endl;
    }
}

void enter() {
    int choice;
    cout << "How many students do you want to enter: ";
    cin >> choice;
    if (total + choice > 20) {
        cout << "Cannot enter more than 20 students in total." << endl;
        return;
    }

    cin.ignore(); 
    for (int i = total; i < total + choice; ++i) {
        cout << "\nEnter data of student: " << i + 1 << endl << endl;
        cout << "ENTER NAME: ";
        getline(cin, arr1[i]);
        cout << "ENTER ROLL NO.: ";
        getline(cin, arr2[i]);
        cout << "ENTER COURSE: ";
        getline(cin, arr3[i]);
        cout << "ENTER CLASS: ";
        getline(cin, arr4[i]);
        cout << "ENTER CONTACT: ";
        getline(cin, arr5[i]);
    }
    total += choice;
    saveToFile();
}

void show() {
    if (total == 0) {
        cout << "NO data Available 👀" << endl;
    } else {
        for (int i = 0; i < total; ++i) {
            cout << "-----------------------------------------" << endl;
            cout << "Data of student: " << i + 1 << endl << endl;
            cout << "-----------------------------------------" << endl;
            cout << "NAME: " << arr1[i] << endl;
            cout << "ROLL NO: " << arr2[i] << endl;
            cout << "COURSE: " << arr3[i] << endl;
            cout << "CLASS: " << arr4[i] << endl;
            cout << "CONTACT: " << arr5[i] << endl;
            cout << "------------------------------------------" << endl;
        }
    }
}

void search() {
    if (total == 0) {
        cout << "NO data Available 👀" << endl;
    } else {
        string rollno;
        cout << "Enter Rollno of student which you want to search: ";
        cin >> rollno;
        bool found = false;
        for (int i = 0; i < total; ++i) {
            if (rollno == arr2[i]) {
                found = true;
                cout << "-----------------------------------------" << endl;
                cout << "Data of student: " << i + 1 << endl << endl;
                cout << "-----------------------------------------" << endl;
                cout << "NAME: " << arr1[i] << endl;
                cout << "ROLL NO: " << arr2[i] << endl;
                cout << "COURSE: " << arr3[i] << endl;
                cout << "CLASS: " << arr4[i] << endl;
                cout << "CONTACT: " << arr5[i] << endl;
                cout << "-------------------------------------------" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Student with Roll No. " << rollno << " not found." << endl;
        }
    }
}

void update() {
    if (total == 0) {
        cout << "NO data Available 👀" << endl;
    } else {
        string rollno;
        cout << "Enter Rollno of student which you want to update: ";
        cin >> rollno;
        bool found = false;
        for (int i = 0; i < total; ++i) {
            if (rollno == arr2[i]) {
                found = true;
                cout << "Previous Data - " << endl;
                cout << "Data of student: " << i + 1 << endl << endl;
                cout << "NAME: " << arr1[i] << endl;
                cout << "ROLL NO: " << arr2[i] << endl;
                cout << "COURSE: " << arr3[i] << endl;
                cout << "CLASS: " << arr4[i] << endl;
                cout << "CONTACT: " << arr5[i] << endl << endl;

                cin.ignore();  
                cout << "\nEnter New Data - " << endl;
                cout << "\nENTER NAME: ";
                getline(cin, arr1[i]);
                cout << "ENTER ROLL NO.: ";
                getline(cin, arr2[i]);
                cout << "ENTER COURSE: ";
                getline(cin, arr3[i]);
                cout << "ENTER CLASS: ";
                getline(cin, arr4[i]);
                cout << "ENTER CONTACT: ";
                getline(cin, arr5[i]);
                break;
            }
        }
        if (!found) {
            cout << "Student with Roll No. " << rollno << " not found." << endl;
        } else {
            saveToFile();
        }
    }
}

void deleterecord() {
    if (total == 0) {
        cout << "NO data Available 👀" << endl;
    } else {
        int a;
        cout << "Press 1 to delete full record " << endl;
        cout << "Press 2 to delete specific record " << endl;
        cin >> a;
        if (a == 1) {
            total = 0;
            saveToFile();
            cout << "-----------------------------------------" << endl;
            cout << "All records are deleted" << endl;
            cout << "-----------------------------------------" << endl;
        } else if (a == 2) {
            string rollno;
            cout << "Enter roll no which you want to delete: ";
            cin >> rollno;
            bool found = false;
            for (int i = 0; i < total; ++i) {
                if (rollno == arr2[i]) {
                    found = true;
                    for (int j = i; j < total - 1; ++j) {
                        arr1[j] = arr1[j + 1];
                        arr2[j] = arr2[j + 1];
                        arr3[j] = arr3[j + 1];
                        arr4[j] = arr4[j + 1];
                        arr5[j] = arr5[j + 1];
                    }
                    total--;
                    saveToFile();
                    cout << "--------------------------------------------------" << endl;
                    cout << "Your required record is deleted successfully!" << endl;
                    cout << "--------------------------------------------------" << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Student with Roll No. " << rollno << " not found." << endl;
            }
        }
    }
}

int main() {
    loadFromFile();
    int value;
    while (true) {
        cout << "Press 1 to enter data" << endl;
        cout << "Press 2 to show data" << endl;
        cout << "Press 3 to search data" << endl;
        cout << "Press 4 to update data" << endl;
        cout << "Press 5 to delete data" << endl;
        cout << "Press 6 to exit program" << endl;
        cin >> value;
        switch (value) {
            case 1:
                enter();
                break;
            case 2:
                show();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                deleterecord();
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "Invalid Input: please enter correct input" << endl;
        }
    }
}
