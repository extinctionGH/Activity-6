#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string firstName;
    string lastName;
    string course;
    float GPA = 0.00;
};

int main() {
    Student p[1000];
    int studentCount = 0;

    while (true) {
        int opt;
        int idFinder;
        cout << "\nMenu\n";
        cout << "1] Add Student\n";
        cout << "2] Edit Student\n";
        cout << "3] Delete Student\n";
        cout << "4] View Student\n";
        cout << "5] Exit\n";
        cout << "Enter your option: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                system("cls");
                int studentId;
                cout << "Enter Student ID: ";
                cin >> studentId;

                while (true) {
                    bool isDuplicate = false;
                    for (int i = 0; i < studentCount; ++i) {
                        if (p[i].id == studentId) {
                            isDuplicate = true;
                            break;
                        }
                    }
                    if (isDuplicate) {
                        cout << "Student ID already exists! Please enter a new ID: ";
                        cin >> studentId;
                    } else {
                        break;
                    }
                }

                p[studentCount].id = studentId;
                cout << "Enter First Name: ";
                cin >> p[studentCount].firstName;
                cout << "Enter Last Name: ";
                cin >> p[studentCount].lastName;
                cout << "Enter Course: ";
                cin >> p[studentCount].course;
                cout << "Enter GPA: ";
                cin >> p[studentCount].GPA;

                cout << "Student Added Successfully!\n";
                cout << "ID: " << p[studentCount].id << "\nFirst Name: " << p[studentCount].firstName
                     << "\nLast Name: " << p[studentCount].lastName << "\nCourse: " << p[studentCount].course
                     << "\nGPA: " << p[studentCount].GPA << endl;
                studentCount++;
                break;
            }

            case 2: {
                system("cls");
                if (studentCount == 0) {
                    cout << "No Student record found\n";
                    break;
                }

                cout << "Enter Student ID to Edit: ";
                cin >> idFinder;
                bool studentFound = false;
                for (int i = 0; i < studentCount; ++i) {
                    if (p[i].id == idFinder) {
                        cout << "Current details: \nID: " << p[i].id << "\nFirst Name: " << p[i].firstName
                             << "\nLast Name: " << p[i].lastName << "\nCourse: " << p[i].course << "\nGPA: " << p[i].GPA << endl;
                        cout << "\nEditing student details...\n";
                        cout << "Enter new First Name: ";
                        cin >> p[i].firstName;
                        cout << "Enter new Last Name: ";
                        cin >> p[i].lastName;
                        cout << "Enter new Course: ";
                        cin >> p[i].course;
                        cout << "Enter new GPA: ";
                        cin >> p[i].GPA;

                        bool idExists = false;
                        for (int j = 0; j < studentCount; ++j) {
                            if (p[i].id == p[j].id && i != j) {
                                idExists = true;
                                break;
                            }
                        }

                        if (idExists) {
                            cout << "\nStudent ID already exists, please try again\n";
                            cout << "Enter Student ID: ";
                            cin >> p[i].id;
                        } else {
                            cout << "\nSuccessfully Edited\n";
                            cout << "ID: " << p[i].id << "\nFirst Name: " << p[i].firstName
                                 << "\nLast Name: " << p[i].lastName << "\nCourse: " << p[i].course
                                 << "\nGPA: " << p[i].GPA << endl;
                        }
                        studentFound = true;
                        break;
                    }
                }
                if (!studentFound) {
                    cout << "Student with ID " << idFinder << " not found.\n";
                }
                break;
            }

            case 3: {
                system("cls");
                if (studentCount == 0) {
                    cout << "No Student record found\n";
                    break;
                }

                int toDelete;
                cout << "Enter Student ID to delete: ";
                cin >> toDelete;
                bool find = false;
                for (int i = 0; i < studentCount; ++i) {
                    if (toDelete == p[i].id) {
                        find = true;
                        cout << "Student record found:\n";
                        cout << "ID: " << p[i].id << "\nFirst Name: " << p[i].firstName
                             << "\nLast Name: " << p[i].lastName << "\nCourse: " << p[i].course << "\nGPA: " << p[i].GPA << endl;
                        for (int j = i; j < studentCount - 1; ++j) {
                            p[j] = p[j + 1];
                        }
                        studentCount--;
                        cout << "Student record deleted successfully.\n";
                        break;
                    }
                }
                if (!find) {
                    cout << "Student with ID " << toDelete << " not found.\n";
                }
                break;
            }

            case 4: {
                system("cls");
                if (studentCount == 0) {
                    cout << "No Student records available.\n";
                    break;
                }

                int viewOption;
                cout << "Select viewing option:\n";
                cout << "1] Alphabetically by Last Name\n";
                cout << "2] By GPA (Ascending)\n";
                cout << "Enter option: ";
                cin >> viewOption;

                if (viewOption == 1) {
                    for (int i = 0; i < studentCount; i++) {
                        for (int j = i + 1; j < studentCount; j++) {
                            if (p[i].lastName > p[j].lastName) {
                                Student temp = p[i];
                                p[i] = p[j];
                                p[j] = temp;
                            }
                        }
                    }
                    cout << "Student Records:\n";
                    cout << "ID | First Name | Last Name | Course | GPA\n";
                    for (int i = 0; i < studentCount; i++) {
                        cout << p[i].id << " | " << p[i].firstName << " | " << p[i].lastName << " | " << p[i].course << " | " << p[i].GPA << endl;
                    }
                } else if (viewOption == 2) {
                    for (int i = 0; i < studentCount; i++) {
                        for (int j = i + 1; j < studentCount; j++) {
                            if (p[i].GPA > p[j].GPA) {
                                Student temp = p[i];
                                p[i] = p[j];
                                p[j] = temp;
                            }
                        }
                    }
                    cout << "Student Records:\n";
                    cout << "ID | First Name | Last Name | Course | GPA\n";
                    for (int i = 0; i < studentCount; i++) {
                        cout << p[i].id << " | " << p[i].firstName << " | " << p[i].lastName << " | " << p[i].course << " | " << p[i].GPA << endl;
                    }
                } else {
                    cout << "Invalid option.\n";
                }
                break;
            }

            case 5: {
                system("cls");
                cout << "Thank you for using the program! :)\n";
                return 0;
            }

            default: {
                system("cls");
                cout << "Invalid option. Please try again.\n";
                break;
            }
        }
    }

    return 0;
}
