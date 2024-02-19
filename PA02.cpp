/// @file PA02.cpp
/// @brief Program calculating musical note frequencies. Used a separate function outside of main
/// @author David Sohn


#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double calculation(double v, double k){
    double root = 1.059463094359;
    double output = (16.35 * pow(2, v) * pow(root, k));
    return output;
}

int main(){
    double RefFreq = 16.35;
    double  speedOfSound = 345;
    
    cout << "Reference Frequency: " << RefFreq << "Hz" << endl;
    cout << "Speed of Sound: " << speedOfSound << "m/s" << endl; 

    cout << "Note: C0; nu: 0; k: 0; frequency: " << calculation(0, 0) << "Hz; wavelength: " << speedOfSound / calculation(0,0) * 100 << " cm" << endl;

    cout << "Note: C#0; nu: 0; k: 1; frequency: " << calculation(0, 1) << "Hz; wavelength: " << speedOfSound / calculation(0,1) * 100 << " cm" << endl;

    cout << "Note: D0; nu: 0; k: 2; frequency: " << calculation(0, 2) << "Hz; wavelength: " << speedOfSound / calculation(0,2) * 100 << " cm" << endl;

    cout << "Note: D3; nu: 3; k: 2; frequency: " << calculation(3, 2) << "Hz; wavelength: " << speedOfSound / calculation(3,2) * 100 << " cm" << endl;

    cout << "Note: C4; nu: 4; k: 0; frequency: " << calculation(4, 0) << "Hz; wavelength: " << speedOfSound / calculation(4,0) * 100 << " cm" << endl;

    cout << "Note: D#7; nu: 7; k: 3; frequency: " << calculation(7, 3) << "Hz; wavelength: " << speedOfSound / calculation(7,3) * 100 << " cm" << endl;

    cout << "Note: C8; nu: 8; k: 0; frequency: " << calculation(8, 0) << "Hz; wavelength: " << speedOfSound / calculation(8,0) * 100 << " cm" << endl;
}