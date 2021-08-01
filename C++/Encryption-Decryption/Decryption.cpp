#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int main()
{
    char fileName[30], ch;
    fstream fps, fpt;
    cout << "Enter the Name of File: ";
    gets(fileName);
    fps.open(fileName, fstream::out);
    if (!fps.is_open())
    {
        cout << "\nError Occurred while Opening the Source File!";
        return 0;
    }
    fpt.open("tmp.txt", fstream::in);
    if (!fpt.is_open())
    {
        cout << "\nError Occurred while Opening tmp File!";
        return 0;
    }
    while (fpt >> noskipws >> ch)
    {
        ch = ch - 100;
        fps << ch;
    }
    fps.close();
    fpt.close();
    cout << "\nFile '" << fileName << "' Decrypted Successfully!";
    cout << endl;
    return 0;
}