#include <iostream>
#include <complex>
#include <cmath>
using namespace std;

void arithmetic()
{
    int op = 0;
    float A = 0;
    float B = 0;

    cout << "Select Operation: \n";
    cout << "[1] Addition\n";
    cout << "[2] Substraction\n";
    cout << "[3] Multiplication\n";
    cout << "[4] Division\n";
    cout << "Enter A Number Based on Selection: ";
    cin >> op;
    cout << "Enter First Number: ";
    cin >> A;
    cout << "Enter Second Number: ";
    cin >> B;
    cout << "Result: ";

    switch (op)
    {
    case 1:
        cout << (A + B);
        break;
    case 2:
        cout << (A - B);
        break;
    case 3:
        cout << (A * B);
        break;
    case 4:
        cout << (A / B);
        break;
    default:
        cout << "Invalid Operation - - -";
        break;
    }
    cout << endl;
}

void exponential()
{
    float base = 0.0;
    float power = 0.0;

    cout << "Enter Base: ";
    cin >> base;
    cout << "Enter The Number Of Power: ";
    cin >> power;
    cout << base << " To The Power Of " << power << " is: " << pow(base, power) << endl;
}

void trigonometric()
{
    int op2 = 0;
    float val = 0.0;

    cout << "Select\n";
    cout << "[1]Cosine\n";
    cout << "[2]Sine\n";
    cout << "[3]Tan\n";
    cout << "Your Option is: ";
    cin >> op2;
    cout << "Enter Value: ";
    cin >> val;
    cout << "Result: ";

    switch (op2)
    {
    case 1:
        cout << cos(val);
        break;

    case 2:
        cout << sin(val);
        break;

    case 3:
        cout << tan(val);
        break;

    default:
        cout << "Invalid Operation";
        break;
    }
}

void logarithmic()
{
    float value = 0.0;
    cout << "Enter Value For Calculate The log(e): ";
    cin >> value;
    cout << "The Log Of " << value << " is: " << log(value);
}

int main()
{
    int sel = 0;

    cout << "ADVANCED CALCULATOR\n";
    cout << "ENTER THE TYPE OF OPERATION YOU WANT TO CALCULATE \n";

    cout << "[1] Arithmetic \n";
    cout << "[2] Trigonometric \n";
    cout << "[3] Exponential\n";
    cout << "[4] Logarithmic \n";
    cout << "Your Choice is: ";
    cin >> sel;

    switch (sel)
    {
    case 1:
        arithmetic();
        break;

    case 2:
        trigonometric();
        break;

    case 3:
        exponential();
        break;

    case 4:
        logarithmic();
        break;

    default:
        cout << "Invalid Operation";
        break;
    }
    return 0;
}