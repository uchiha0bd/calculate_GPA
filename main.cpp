#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_SUBJECT_COUNT 10

class Subject
{
private:
    string name;
    string code;
    int score;

public:
    Subject();
    void setData(string n, string c, int s);
    int credit() const;
    string grade() const;
    double point() const;
    void print() const;

    string getName() const { return name; }
    int getScore() const { return score; }
};

// Default constructor
Subject::Subject() : name(""), code(""), score(0) {}

// Function to set data
void Subject::setData(string n, string c, int s)
{
    name = n;
    code = c;
    score = s;
}

// Getter for credit
int Subject::credit() const
{
    if (code.length() >= 8)
        return code[7] - '0';
    return 0; // Default to 0 if code length is invalid
}

// Getter for grade
string Subject::grade() const
{
    if (score >= 90)
        return "A+";
    if (score >= 80)
        return "A";
    if (score >= 75)
        return "A-";
    if (score >= 70)
        return "B+";
    if (score >= 65)
        return "B";
    if (score >= 60)
        return "B-";
    if (score >= 55)
        return "C+";
    if (score >= 50)
        return "C";
    if (score >= 45)
        return "C-";
    if (score >= 40)
        return "D+";
    if (score >= 35)
        return "D";
    if (score >= 30)
        return "D-";
    return "E";
}

// Function to calculate point
double Subject::point() const
{
    string g = grade();
    if (g == "A+")
        return 4.0;
    if (g == "A")
        return 4.0;
    if (g == "A-")
        return 3.7;
    if (g == "B+")
        return 3.3;
    if (g == "B")
        return 3.0;
    if (g == "B-")
        return 2.7;
    if (g == "C+")
        return 2.3;
    if (g == "C")
        return 2.0;
    if (g == "C-")
        return 1.7;
    if (g == "D+")
        return 1.3;
    if (g == "D")
        return 1.0;
    if (g == "D-")
        return 0.7;
    return 0.0;
}

// Function to print subject details
void Subject::print() const
{
    cout << left << setw(15) << code;
    cout << left << setw(30) << name;
    cout << left << setw(10) << credit();
    cout << left << setw(10) << score;
    cout << left << setw(10) << grade();
    cout << left << setw(10) << point();
    cout << left << setw(10) << point() * credit();
    cout << endl;
}

// Function to read user input
int readUserInput(Subject subjects[])
{
    int count;
    cout << "Enter the number of subjects (max " << MAX_SUBJECT_COUNT << "): ";
    cin >> count;
    if (count > MAX_SUBJECT_COUNT)
        count = MAX_SUBJECT_COUNT;

    for (int i = 0; i < count; i++)
    {
        string name, code;
        int score;
        cout << "Enter subject name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter subject code: ";
        cin >> code;
        cout << "Enter score: ";
        cin >> score;

        subjects[i].setData(name, code, score);
    }

    return count;
}

// Function to determine the subject with the lowest score
Subject lower(Subject a, Subject b)
{
    return (a.getScore() < b.getScore()) ? a : b;
}

int main()
{
    Subject subjects[MAX_SUBJECT_COUNT];
    int subjectCount = readUserInput(subjects);

    cout << endl
         << endl
         << "THE RESULT"
         << endl
         << endl;

    // Print the output table header
    cout << left << setw(15) << "Subject Code";
    cout << left << setw(30) << "Subject Name";
    cout << left << setw(10) << "Credit";
    cout << left << setw(10) << "Score";
    cout << left << setw(10) << "Grade";
    cout << left << setw(10) << "Point";
    cout << left << setw(10) << "Sub Total";
    cout << endl
         << endl;

    double totalPoints = 0;
    int totalCredits = 0;
    Subject lowestSubject = subjects[0];

    for (int i = 0; i < subjectCount; i++)
    {
        subjects[i].print();
        totalPoints += subjects[i].point() * subjects[i].credit();
        totalCredits += subjects[i].credit();
        lowestSubject = lower(lowestSubject, subjects[i]);
    }

    cout << endl;
    cout << "TOTAL POINT  : " << totalPoints << endl;
    cout << "TOTAL CREDIT : " << totalCredits << endl;
    cout << "GPA          : " << fixed << setprecision(2) << (totalCredits ? totalPoints / totalCredits : 0) << endl;

    cout << endl;
    cout << "LOWEST SUBJECT : " << lowestSubject.getName() << endl;
    cout << endl;

    system("pause");
    return 0;
}
