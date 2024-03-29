#include <iostream>
#include <string>
using namespace std;

class CUltimateMachine{
    private:
        bool m_bState; // true (on) false (off)
    public:
        CUltimateMachine(): m_bState(false){
            cout << "CUltimateMachine constructor (ctor) called" << endl;
        }

        ~CUltimateMachine(){
            cout << "CUltimateMachine destructor (dtor) called" << endl;
        }

        void displayState(){
            if(m_bState){
                cout << "Ult Machine is ON" << endl;
            }
            else{
                cout << "Ult Machine is OFF" << endl;
            }
        }

        void turnOn(){
            m_bState = true;
            displayState();
            if(m_bState == true){
                m_bState = false;
            }
            displayState();
        }



};

int main(){
    cout << "The Ultimate Machine simulation" << endl;

    CUltimateMachine ultmach;
    ultmach.displayState();
    ultmach.turnOn();
}