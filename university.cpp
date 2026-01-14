#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
public:
    void setData(string n, int i) {
        name = n;
        id = i;
    }
    void showData() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
private:
    string course;
public:
    void setStudent(string n, int i, string c) {
        setData(n, i);
        course = c;
    }

    void showStudent() {
        showData();
        cout << "Course: " << course << endl;
    }
};

class Teacher : public Person {
private:
    string subject;
public:
    void setTeacher(string n, int i, string s) {
        setData(n, i);
        subject = s;
    }

    void showTeacher() {
        showData();
        cout << "Subject: " << subject << endl;
    }
};

class Course {
private:
    int courseId;
    string courseName;
public:
    void setCourse(int id, string name) {
        courseId = id;
        courseName = name;
    }

    void showCourse() {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
    }
};

int main() {
    Student s;
    Teacher t;
    Course c;
    int choice;

    do {
        cout << "\n--- University Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Add Teacher\n";
        cout << "3. Add Course\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if(choice == 1) {
            string name, course;
            int id;
            cout << "Enter Student Name: ";
            cin >> name;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Course: ";
            cin >> course;

            s.setStudent(name, id, course);
            s.showStudent();
        }
        else if(choice == 2) {
            string name, subject;
            int id;
            cout << "Enter Teacher Name: ";
            cin >> name;
            cout << "Enter Teacher ID: ";
            cin >> id;
            cout << "Enter Subject: ";
            cin >> subject;

            t.setTeacher(name, id, subject);
            t.showTeacher();
        }
        else if(choice == 3) {
            int cid;
            string cname;
            cout << "Enter Course ID: ";
            cin >> cid;
            cout << "Enter Course Name: ";
            cin >> cname;

            c.setCourse(cid, cname);
            c.showCourse();
        }
        else if(choice != 4) {
            cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 4);

    cout << "Program exited successfully.\n";
    return 0;
}
