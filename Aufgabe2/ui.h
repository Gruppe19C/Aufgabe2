#ifndef ui_h
#define ui_h
#include <string>
#include "ComplexNumber.h"
using namespace std;

class UI
{
private:
    ComplexNumber cn;

public:
    UI();

    void start();

    void printMenu();

    void printInputMenu();

    string getInput();

    string getInput(string prompt);

    void printComplexNumber(ComplexNumber cn);

    void printKartesian(ComplexNumber cn);

    void printPolar(ComplexNumber cn);

    void printLine();

    void printError(string error);

    void printError(string error, string input);
};

#endif