#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>
using namespace std;

int main(){

    double piOver4 = 0.0;
    for(int n = 2; n <= 1048576; n *= 2){
        for(int k = 0; k <= n; k++){
            piOver4 += pow(-1.0, k)/(2.0*k + 1);
        }
        
        std::cout << std::fixed;
        cout << "PI: " << setprecision(DBL_DIG) << piOver4 * 4.0 << "; n: " << setw(7) << n << endl;
        piOver4 = 0.0;
    }
}