#include <iostream>
#include <vector>

using namespace std;

struct Student {
    int id;
    int semestersCompleted;
    int creditsCompleted;
    double cgpa;
};

int main() {
    vector<Student> students;

    // Input student records
    for (int i = 1; i <= 15; i++) {
        Student s;
        s.id = i;
        cout << "Enter the number of semesters completed for Student " << i << ": ";
        cin >> s.semestersCompleted;
        cout << "Enter the number of credits completed for Student " << i << ": ";
        cin >> s.creditsCompleted;
        cout << "Enter the CGPA for Student " << i << ": ";
        cin >> s.cgpa;
        students.push_back(s);
    }

    // a. Print students with CGPA > 3.50
    cout << "Students with CGPA > 3.50:" << endl;
    for (const Student& s : students) {
        if (s.cgpa > 3.50) {
            cout << "Student ID: " << s.id << endl;
        }
    }

    // b. Print students with more than 50 credits
    cout << "Students with more than 50 credits:" << endl;
    for (const Student& s : students) {
        if (s.creditsCompleted > 50) {
            cout << "Student ID: " << s.id << endl;
        }
    }

    // c. Print students with at least 2 semesters and 28 credits
    cout << "Students with at least 2 semesters and 28 credits:" << endl;
    for (const Student& s : students) {
        if (s.semestersCompleted >= 2 && s.creditsCompleted >= 28) {
            cout << "Student ID: " << s.id << endl;
        }
    }

    return 0;
}
