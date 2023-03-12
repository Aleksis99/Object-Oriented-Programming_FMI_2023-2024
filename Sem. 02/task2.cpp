#include <iostream>
#include <fstream>

#pragma warning (disable : 4996)

const int FIELD_SIZE = 32;
const int MAX_SIZE = 1000;;

struct Student
{
    char name[FIELD_SIZE];
    char lastName[FIELD_SIZE];
    char email[FIELD_SIZE];
    char FN[FIELD_SIZE];
};

void getLinesCount(std::ifstream& file, int& n)
{
    char buff[MAX_SIZE];
    int count = 0;

    while (!file.eof())
    {
        file.getline(buff, MAX_SIZE);
        count++;
    }

    n = count;

    file.seekg(0, std::ios::beg);
}

void parseField(char* dest, char*& source)
{
    while (*source != '\0' && *source != ',')
    {
        *dest = *source;

        dest++;
        source++;
    }

    source++;
    *dest = '\0';
}

void parseStudent(Student& s, char* line)
{
    parseField(s.name, line);
    parseField(s.lastName, line);
    parseField(s.email, line);
    parseField(s.FN, line);
}

void readStudents(Student*& students, std::ifstream& file, int& studentsCount)
{
    getLinesCount(file, studentsCount);

    students = new Student[studentsCount];

    char line[MAX_SIZE];

    for (size_t i = 0; i < studentsCount; i++)
    {
        file.getline(line, MAX_SIZE);

        parseStudent(students[i], line);
    }
}

void printStudent(Student s)
{
    std::cout << s.name << std::endl
        << s.lastName << std::endl
        << s.email << std::endl
        << s.FN << std::endl;
}

void printByFN(const Student* students, int n, const char* FN)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(students[i].FN, FN) == 0)
        {
            printStudent(students[i]);
            return;
        }
    }
}

void changeEmail(Student* students, int n, const char* FN, const char* newEmail)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(students[i].FN, FN) == 0)
        {
            strcpy(students[i].email, newEmail);
            return;
        }
    }
}

void writeStudentToFile(const Student s, std::ofstream& file)
{
    file << s.name << ',' << s.lastName << ','
        << s.email << s.FN << ',' << std::endl;
}

void saveToFile(const Student* students, int n, const char* fileName)
{
    std::ofstream file(fileName);

    if (!file.is_open())
    {
        std::cout << "Error";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        writeStudentToFile(students[i], file);
    }

    file.close();
}

int main()
{
    Student* students;
    int countStudents;

    std::ifstream file("students.csv");

    readStudents(students, file, countStudents);

    printByFN(students, countStudents, "89999");
    changeEmail(students, countStudents, "89999", "asd@asd");
    saveToFile(students, countStudents, "students2.csv");

    return 0;
}
