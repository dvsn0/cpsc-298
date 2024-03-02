#include <cmath>
#include <iostream>
#include <iomanip>
#include <cfloat>
using namespace std;

int main(){
    int n;
    cout << "Input a value for n: " << endl;
    cin >> n;
    double piOver4 = 0.0;

    for(int k = 0; k <= n; k++){
        piOver4 += pow(-1.0, k)/(2.0*k + 1);
    }
    piOver4 *= 4.0;

    //cout << "PI: "<< setprecision(DBL_DIG) << piOver4 << endl;

    std::cout << std::fixed;
    cout << "PI (approx): " <<  setprecision(DBL_DIG) << piOver4 << "; n: " << setw(7) << n << endl;
    cout << "PI (actual): " << "3.141592653589793" << endl;

    cout << "Decimal digits of precision: " << DBL_DIG << endl;
    cout << "Number of base 2 mantissa digits of double precision floating point value: " << DBL_MANT_DIG << endl;
    cout << "Next representable number from 3.141592653589793: " << nextafter(3.141592653589793, 3.14) << endl;
}