#include <iostream>
#include <fstream>
#include <vector>

struct Student {
    std::string name;
    int rollNumber;
    std::vector<int> marks;
    char grade;
};

// Function to calculate the grade based on average marks
char calculateGrade(const std::vector<int>& marks) {
    int totalMarks = 0;
    for (int mark : marks) {
        totalMarks += mark;
    }
    int averageMarks = totalMarks / marks.size();

    if (averageMarks >= 90) {
        return 'A';
    } else if (averageMarks >= 80) {
        return 'B';
    } else if (averageMarks >= 70) {
        return 'C';
    } else if (averageMarks >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

// Function to add a new student record
void addStudent(std::vector<Student>& students) {
    Student student;
    std::cout << "Enter student name: ";
    std::cin.ignore();
    std::getline(std::cin, student.name);
    std::cout << "Enter roll number: ";
    std::cin >> student.rollNumber;

    int numSubjects;
    std::cout << "Enter the number of subjects: ";
    std::cin >> numSubjects;
    std::cout << "Enter marks for each subject: ";
    for (int i = 0; i < numSubjects; ++i) {
        int mark;
        std::cin >> mark;
        student.marks.push_back(mark);
    }

    student.grade = calculateGrade(student.marks);
    students.push_back(student);
}

// Function to display student details
void displayStudents(const std::vector<Student>& students) {
    std::cout << "\nStudent Details:\n";
    for (const Student& student : students) {
        std::cout << "Name: " << student.name << "\n";
        std::cout << "Roll Number: " << student.rollNumber << "\n";
        std::cout << "Marks: ";
        for (int mark : student.marks) {
            std::cout << mark << " ";
        }
        std::cout << "\n";
        std::cout << "Grade: " << student.grade << "\n";
        std::cout << "-------------------------------------\n";
    }
}

// Function to save student records to a file
void saveStudentsToFile(const std::vector<Student>& students, const std::string& fileName) {
    std::ofstream outFile(fileName);

    if (outFile.is_open()) {
        for (const Student& student : students) {
            outFile << student.name << " " << student.rollNumber << " ";
            for (int mark : student.marks) {
                outFile << mark << " ";
            }
            outFile << student.grade << "\n";
        }
        outFile.close();
        std::cout << "Student records saved to " << fileName << "\n";
    } else {
        std::cout << "Unable to open the file for writing.\n";
    }
}

int main() {
    std::vector<Student> students;
    int choice;

    while (true) {
        std::cout << "\nStudent Management System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display Students\n";
        std::cout << "3. Save Students to File\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                saveStudentsToFile(students, "student_records.txt");
                break;
            case 4:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
