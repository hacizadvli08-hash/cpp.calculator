#include <iostream>
#include <limits>
using namespace std;

// Əsas riyazi əməliyyat funksiyaları
double add(double a, double b) { 
    return a + b; 
}

double subtract(double a, double b) { 
    return a - b; 
}

double multiply(double a, double b) { 
    return a * b; 
}

double divide(double a, double b) {
    if (b == 0) {
        return numeric_limits<double>::quiet_NaN();
    }
    return a / b;
}

// Əməliyyat: 1 = +, 2 = -, 3 = *, 4 = /
// WebAssembly (Emscripten) və ya C interfeysi üçün 'extern "C"' istifadə olunur
extern "C" double calculate(double a, double b, int operation) {
    if (operation == 1) return add(a, b);
    if (operation == 2) return subtract(a, b);
    if (operation == 3) return multiply(a, b);
    if (operation == 4) return divide(a, b);
    
    return numeric_limits<double>::quiet_NaN();
}

#ifndef __EMSCRIPTEN__
int main() {
    double a, b;
    int operation;

    cout << "Birinci eded: ";
    cin >> a;
    cout << "Ikinci eded: ";
    cin >> b;
    cout << "Emeliyyat (1=+, 2=-, 3=*, 4=/): ";
    cin >> operation;

    cout << "Netice: " << calculate(a, b, operation) << endl;

    return 0;
}
#endif