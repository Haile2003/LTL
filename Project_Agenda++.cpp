#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

vector<string> Names;
vector<string> Phones;

void SBN()
{
    bool found = false;
    string name;
    int i = 0;

    cout << "\n\nEnter The Name To Search: ";
    cin >> name;

    for (int i = 0; i != Names.size(); i += 1)
    {
        if (Names[i] == name)
        {
            cout << "Name: " << Names[i] << "\n";
            cout << "Phone: " << Phones[i] << "\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No contact was found with this name!\n\n";
    }
}

void SearchByID()
{
    int value;

    cout << "\n\nEnter The ID Of Your Contact: ";
    cin >> value;
    if (value >= Names.size())
    {
        cout << "Invalid ID\n\n";
        return;
    }
    cout << "Information For Contact " << value << "\n";
    cout << "Name: " << Names[value] << "\n";
    cout << "Phone: " << Phones[value] << "\n";
}

void NewContact()
{
    string name;
    string phone;

    cout << "\n\nAdd A New Contact \n\n";
    cout << "Name/Company Name: ";
    cin >> name;
    cout << "Phone Number: ";
    cin >> phone;
    cout << "This ID for this contact will be: " << Names.size() << "\n\n";

    Names.push_back(name);
    Phones.push_back(phone);
}

void recall()
{
    int sel = 0;
    bool condition = true;

    while (condition)
    {
        cout << "\n\nMy Agenda++ \n\n";
        cout << "Choose a number to execute an option\n\n";
        cout << "[1] New Contact\n";
        cout << "[2] Search By ID\n";
        cout << "[3] Search By Name\n";
        cout << "[4] Exit\n";
        cout << "Your Choice: ";
        cin >> sel;

        switch (sel)
        {
        case 1:
            NewContact();
            break;

        case 2:
            SearchByID();
            break;

        case 3:
            SBN();
            break;

        case 4:
            condition = false;
            cout << "Exiting . . . ";
            break;
        default:
            cout << "\n\nInvalid Input!";
            exit(0);
        }
    }
}

int main()
{
    int sel = 0;
    bool condition = true;

    while (condition)
    {
        cout << "My Agenda++ \n\n";
        cout << "Choose a number to execute an option\n\n";
        cout << "[1] New Contact\n";
        cout << "[2] Search By ID\n";
        cout << "[3] Search By Name\n";
        cout << "[4] Exit\n";
        cout << "Your Choice: ";
        cin >> sel;

        switch (sel)
        {
        case 1:
            NewContact();
            recall();
            break;

        case 2:
            SearchByID();
            recall();
            break;

        case 3:
            SBN();
            recall();
            break;

        case 4:
            condition = false;
            cout << "\nExiting . . . ";
            break;

        default:
            cout << "\n\nInvalid Input!";
            break;
        }

        return 0;
    }
}
