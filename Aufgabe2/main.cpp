#include <iostream>
#include "ComplexNumber.h"
using namespace std;

int main()
{
    // UI ui;
    // ui.start();
    ComplexNumber cn1(1, 2);
    ComplexNumber cn2(3, 4);
    ComplexNumber cn3 = cn1 * cn2;
    cout << cn1.getReal() << endl;
    cout << cn1.getImaginary() << endl;
    cout << cn3.getImaginary() << endl;
    cout << cn3.getCount() << endl;
    return 0;
}