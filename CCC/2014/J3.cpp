#include <iostream>

using namespace std;

int main()
{
    int n, aRoll, dRoll;
    cin >> n;
    int aPoints = 100;
    int dPoints = 100;
    for(int i = 0; i < n; i++){
        cin >> aRoll >> dRoll;
        if(aRoll < dRoll){
            aPoints -= dRoll;
        } else if(aRoll > dRoll){
            dPoints -= aRoll;
        }
    }
    cout << aPoints << endl << dPoints;
}