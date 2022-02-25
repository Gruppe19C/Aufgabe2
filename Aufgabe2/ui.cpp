#include <iostream>
#include "ui.h"
using namespace std;

UI::UI()
{
}

string UI::getInput()
{
    string input;
    cin >> input;
    return input;
}

string UI::getInput(string prompt)
{
    cout << prompt;
    return getInput();
}

void UI::printMenu()
{
    cout << "1. Set complex number" << endl;
    cout << "2. Print complex number" << endl;
    cout << "3. Print complex number in kartesian" << endl;
    cout << "4. Print complex number in polar" << endl;
    cout << "Q to quit" << endl;
}

void UI::printInputMenu()
{
    cout << "1. Set complex number in kartesian" << endl;
    cout << "2. Set complex number in polar" << endl;
    cout << "3. Set real part" << endl;
    cout << "4. Set imaginary part" << endl;
    cout << "5. Set radius" << endl;
    cout << "6. Set angle" << endl;
    cout << "Q to go back" << endl;
}

void UI::printComplexNumber(ComplexNumber cn)
{
    cout << "Real: " << cn.getReal() << ", Imaginary: " << cn.getImaginary();
    cout << ", Radius: " << cn.getRadius() << ", Angle: " << cn.getAngle() << endl;
}

void UI::printKartesian(ComplexNumber cn)
{
    cout << " z=" << cn.getReal() << "+" << cn.getImaginary() << "i" << endl;
}

void UI::printPolar(ComplexNumber cn)
{
    cout << " Z=" << cn.getRadius() << "(cos(" << cn.getAngle() << ")+isin(" << cn.getAngle() << "))" << endl;
}

void UI::printLine()
{
    cout << "----------------------------------------------------" << endl;
}

void UI::printError(string error)
{
    cout << error << endl;
}

void UI::start()
{
    string input = "";
    while (input != "q" && input != "Q")
    {
        cout << "Input: " << input << endl;
        UI::printMenu();
        input = UI::getInput();
        UI::printLine();
        if (input == "1")
        {
            UI::printInputMenu();
            string cnMenuInput = UI::getInput();
            if (cnMenuInput == "1")
            {
                double real = stod(UI::getInput("Real: "));
                double imaginary = stod(UI::getInput("Imaginary: "));
                cn.setKartesian(real, imaginary);
            }
            else if (cnMenuInput == "2")
            {
                double radius = stod(UI::getInput("Radius: "));
                double angle = stod(UI::getInput("Angle: "));
                cn.setPolar(radius, angle);
            }
            else if (cnMenuInput == "3")
            {
                double real = stod(UI::getInput("Real: "));
                cn.setReal(real);
            }
            else if (cnMenuInput == "4")
            {
                double imaginary = stod(UI::getInput("Imaginary: "));
                cn.setImaginary(imaginary);
            }
            else if (cnMenuInput == "5")
            {
                double radius = stod(UI::getInput("Radius: "));
                cn.setRadius(radius);
            }
            else if (cnMenuInput == "6")
            {
                double angle = stod(UI::getInput("Angle: "));
                cn.setAngle(angle);
            }
            else if (cnMenuInput == "q" || cnMenuInput == "Q")
            {
            }
        }
        else if (input == "2")
        {
            (cn.getRadius() && cn.getAngle() && cn.getReal() && cn.getImaginary())
                ? UI::printComplexNumber(cn)
                : UI::printError("No complex number set");
        }
        else if (input == "3")
        {
            (cn.getReal() && cn.getImaginary())
                ? UI::printKartesian(cn)
                : UI::printError("No Real or Imaginary Value set");
        }
        else if (input == "4")
        {
            (cn.getRadius() && cn.getAngle())
                ? UI::printPolar(cn)
                : UI::printError("No Radius or Angle set");
        }
        UI::printLine();
    }
}
