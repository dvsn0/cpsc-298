#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
using namespace std;

unsigned long sigma(unsigned long n){
    unsigned long sum = 0;

    try{
        //Check preconditions
        //      Raise a std::runtime_error if the precondition (n>=1) is not met

        if(n<1){
            std::string strMessage = "Precondition n>=1 voilated; invalid value for argument n: " + std::to_string(n) + " (Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")";
            throw runtime_error(strMessage);
        }

        //Function body
        //      Implement a for loop to compute sum of integers from 1 to n

        for(int i = 1; i <= n; i++){
            sum += i;
        }

        //Check postconditions
        //      Raise a std::runtime_error exception if the postcondition (sum == (n(n+1)/2) ) is not met

        if(sum != (n * (n+1) / 2)){
            std::string strMessage = "Postcondition sum == (n(n+1)/2) voilated; sum: " + std::to_string(sum) + "; n(n+1)/2: " + std::to_string((n * (n+1) / 2)) + " (Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")";
            throw runtime_error(strMessage);
        }
    }

    catch(std::runtime_error & ex){
        std::cout << "Exception: " << ex.what() << std::endl;
        std::cout << "Cannot compute sum; returning 0"  << std::endl;
        sum = 0; //  0 is returned to indicate an error occurred
    }

    return sum;
}

int main(){
    int sum = sigma(5);
    cout << "sigma(5) = " << sum << endl;
    sum = sigma(0);
    cout << "sigma(0) = " << sum << endl;

    return 0;
}
