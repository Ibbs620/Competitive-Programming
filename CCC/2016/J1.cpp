#include <iostream>

using namespace std;

int main()
{
    char player[6];
    int wins = 0;

    for(int i = 0; i < 6; i++){
        cin >> player[i];
        if(player[i] == 'W'){
            wins++;
        }
    }
    if(wins == 0){
        cout << -1;
    } else if(wins > 4){
        cout << 1;
    } else if(wins > 2){
        cout << 2;
    } else {
        cout << 3;
    }
}