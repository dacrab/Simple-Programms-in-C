#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    vector<int> grades;
};

map<string, Student> students;

void addStudent(string name) {
    students[name] = {name, {}};
    cout << "Student added: " << name << endl;
}

void addGrade(string name, int grade) {
    if (students.find(name) != students.end()) {
        students[name].grades.push_back(grade);
        cout << "Grade added for " << name << ": " << grade << endl;
    } else {
        cout << "Error: Student " << name << " not found!" << endl;
    }
}

void displayStudentInfo(string name) {
    if (students.find(name) != students.end()) {
        cout << "Student: " << students[name].name << endl;
        cout << "Grades:";
        for (int grade : students[name].grades) {
            cout << " " << grade;
        }
        cout << endl;
        double average = 0;
        for (int grade : students[name].grades) {
            average += grade;
        }
        average /= students[name].grades.size();
        cout << "Average grade: " << fixed << setprecision(2) << average << endl;
    } else {
        cout << "Error: Student " << name << " not found!" << endl;
    }
}

int main() {
    addStudent("Alice");
    addStudent("Bob");
    addStudent("Charlie");

    addGrade("Alice", 85);
    addGrade("Alice", 90);
    addGrade("Bob", 75);
    addGrade("Bob", 80);
    addGrade("Charlie", 95);
    addGrade("Charlie", 88);

    displayStudentInfo("Alice");
    displayStudentInfo("Bob");
    displayStudentInfo("Charlie");

    return 0;
}
