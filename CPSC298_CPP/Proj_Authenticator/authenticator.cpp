//part 1 prompts the user to enter 3 letter message code and dispaly the message and authenticator codes.
//part 2 perform a character by character comparison of the codes
//part 3 compare the codes using string comparison
//part 4 characterize the received message code and display information helpful in defeating spoofing attempts

#include <iostream>
#include <string>
using namespace std;

int main(){
    string authStr;
    const char authChar1 = 'E';
    const char authChar2 = 'C';
    const char authChar3 = 'A';

    authStr += authChar1;
    authStr += authChar2;
    authStr += authChar3;

    string inputStr;
    char inputChar1;
    char inputChar2;
    char inputChar3;

    cout << "Enter the first character of the message code: " << endl;
    cin >> inputChar1;
    cout << "Enter the second character of the message code: " << endl;
    cin >> inputChar2;
    cout << "Enter the third character of the message code: " << endl;
    cin >> inputChar3;

    inputStr += inputChar1;
    inputStr += inputChar2;
    inputStr += inputChar3;

    cout << "Authenticator Code: " << authStr << endl;
    cout << "Message Code: " << inputStr << endl;

    if(authChar1 == inputChar1 && authChar2 == inputChar2 && authChar3 == inputChar3){
        cout << "Message is authentic." << endl;
    }
    else{
        cout << "Message is invalid." << endl;
    }

    if(authStr == inputStr){
        cout << "Concurrence: message is authentic." << endl;
    }
    else{
        cout << "Conccurence: message is invalid." << endl;
    }

    cout << "Characterization of Message Code" << endl;
    cout << "--------------------------------" << endl;

    int checksum = 0;
    const int k_iValidCodeChecksum = 5;
    checksum = (int(inputChar1) + int(inputChar2) + int(inputChar3)) % 7;

    if(k_iValidCodeChecksum == checksum){
        cout << "Message Code Checksum is valid: 5" << endl;
    }
    else{
        cout << "Message Code Checksum is invalid: " << checksum << "; expected: 5" << endl;
    }

    cout << "ASCII Values of Message Code Characters: " << int(inputChar1) << ", " << int(inputChar2) << ", " << int(inputChar3) << endl;
    cout << "Sum of ASCII values for Message Code Characters: " << int(inputChar1) + int(inputChar2) + int(inputChar3) << endl;

    if(int(authChar1)!= int(inputChar1)){
        cout << "First characters do not match: Message: " << inputChar1 << "; Authenticator: " << authChar1 << endl;
    }
    if(int(authChar2)!= int(inputChar2)){
        cout << "First characters do not match: Message: " << inputChar2 << "; Authenticator: " << authChar2 << endl;
    }
    if(int(authChar3)!= int(inputChar3)){
        cout << "First characters do not match: Message: " << inputChar3 << "; Authenticator: " << authChar3 << endl;
    }

    int inputSum = int(inputChar1) + int(inputChar2) + int(inputChar3);
    int authSum = int(authChar1) + int(authChar2) + int(authChar3);

    if(inputSum < authSum){
        cout << "Message code (" << inputStr << ") is lexicographically less than Authenticator code (" << authStr << ")" << endl;
    }
    else if(inputSum > authSum){
        cout << "Message code (" << inputStr << ") is lexicographically greater than Authenticator code (" << authStr << ")" << endl;
    }
}