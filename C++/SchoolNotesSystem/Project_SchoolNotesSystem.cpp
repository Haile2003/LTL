#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

void AddStudent()
{
    string temp;
    vector<string> Data;

    cout << "Enter Student First Name: ";
    cin >> temp;
    Data.push_back(temp);

    cout << "Enter Student Last Name: ";
    cin >> temp;
    Data.push_back(temp);

    cout << "Enter Phone Number: ";
    cin >> temp;
    Data.push_back(temp);

    cout << "Enter Student ID: ";
    cin >> temp;
    Data.push_back(temp);

    string makeFile;
    makeFile = Data[3] + ".dat";

    ofstream file;
    file.open(makeFile.c_str());

    file << Data[0] << endl;
    file << Data[1] << endl;
    file << Data[2] << endl;
    file << Data[3] << endl;

    file.close();
}

void AddNote()
{
    vector<string> Subject;
    vector<string> Note;

    string fileName;
    string temp;
    string student;
    int z = 0;
    cout << "Enter The Student ID to add notes: ";
    cin >> student;
    while (true)
    {
        cout << "\nEnter Subject: ";
        cin >> temp;
        Subject.push_back(temp);

        cout << "Enter Note: ";
        cin >> temp;
        Note.push_back(temp);

        cout << "Do You want to continue? [0] YES [1] No >";
        cin >> z;

        if (z != 0)
        {
            break;
        }
    }

    fileName = student + ".cal";
    ofstream file;
    file.open(fileName.c_str());

    for (int i = 0; i != Subject.size(); i++)
    {
        file << Subject[i] << ": ";
        file << Note[i] << endl;
    }

    file.close();
}

void SearchStudent()
{
    string number;

    cout << "Insert Student ID: ";
    cin >> number;

    string fileName;
    fileName = number + ".dat";

    ifstream file;
    file.open(fileName.c_str());

    vector<string> data;

    if (file.is_open())
    {
        string in;

        while (!file.eof())
        {
            file >> in;
            data.push_back(in);
        }

        cout << "First name: " << data[0] << endl;
        cout << "Last Name: " << data[1] << endl;
        cout << "Phone: " << data[2] << endl;
        cout << "Student number: " << data[3] << endl;

        file.close();
    }
    else
    {
        cout << " Student not found";
    }
}

void ReadKardex()
{
    string number;
    cout << "Insert Student ID: ";
    cin >> number;

    string fileName;
    fileName = number + ".dat";

    ifstream file;
    file.open(fileName.c_str());

    vector<string> data;
    if (file.is_open())
    {
        string in;
        while (!file.eof())
        {
            file >> in;
            data.push_back(in);
        }
        file.close();

        for (int i = 0; i != (data.size() / 2); i += 2)
        {
            cout << data[i] << "\t" << data[i + 1] << endl;
        }
    }

    else
    {
        cout << "Student not found\n";
    }
}

void PrintKardex()
{
    string number;

    cout << "Insert Student ID: ";
    cin >> number;

    vector<string> data;
    vector<string> notes;

    string fileName1, fileName2;
    fileName1 = number + ".dat";
    fileName2 = number + ".cal";

    ifstream dataFile, noteFile;
    dataFile.open(fileName1.c_str());
    noteFile.open(fileName2.c_str());

    string temp;
    if (dataFile.is_open())
    {
        while (!dataFile.eof())
        {
            dataFile >> temp;
            data.push_back(temp);
        }
    }
    else
    {
        cout << "Student not found\n";
        return;
    }

    if (noteFile.is_open())
    {
        while (!noteFile.eof())
        {
            noteFile >> temp;
            notes.push_back(temp);
        }
    }
    else
    {
        cout << "Kardex Not Found\n";
    }
    dataFile.close();
    noteFile.close();

    ofstream kardex;
    string fileName3;

    fileName3 = "Kardex" + number + ".dat";
    kardex.open(fileName3.c_str());

    kardex << "STUDENT KARDEX\n\n";
    kardex << "NAME: " << data[1] << "," << data[0] << endl;
    kardex << "PHONE: " << data[2] << endl;
    kardex << "NOTES" << endl;
    kardex << "---------------------------------" << endl;

    for (int i = 0; i <= (notes.size()) / 2; i += 2)
    {
        kardex << notes[0] << "\t" << notes[1] << endl;
    }

    kardex.close();
    cout << "\n\nKardex Generated\n";
}

int main()
{
    int sel = 0;
    while (true)
    {
        cout << "\n\nSchool Control\n\n";
        cout << "[1] Add Student\n";
        cout << "[2] Add Notes\n";
        cout << "[3] Search Student\n";
        cout << "[4] Read Kardex\n";
        cout << "[5] Print Kardex\n";
        cout << "[6] Exit\n";
        cout << "Choice >";
        cin >> sel;

        switch (sel)
        {
        case 1:
            AddStudent();
            break;
        case 2:
            AddNote();
            break;
        case 3:
            SearchStudent();
            break;
        case 4:
            ReadKardex();
            break;
        case 5:
            PrintKardex();
            break;
        case 6:
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}
