#include <iostream>

using namespace std;

int main(){
    int pos = 1;
    int roll;
    while(true){
        cin >> roll;
        if(roll == 0){
            cout << "You Quit!";
            break;
        }
        pos += roll;
        if(pos == 9) pos = 34;
        else if(pos == 40) pos = 64;
        else if(pos == 67) pos = 86;
        else if(pos == 54) pos = 19;
        else if(pos == 90) pos = 48;
        else if(pos == 99) pos = 77;
        else if(pos > 100) pos -= roll;
        else if(pos == 100){
            cout << "You are now on square " << pos << "\nYou Win!";
            break;
        }
        cout << "You are now on square " << pos << "\n";
    }
}