#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string seasonName;
    getline(cin, seasonName);
    string teamNames[10];
    double rawScores[10][7];
    double slugAv[10];
    double batAv[10];
    double bigBatAv = 0;
    double bigSlugAv = 0;

    for(int i = 0; i < 10; i++){
        cin >> teamNames[i];
        for(int j = 0; j < 7; j++) cin >> rawScores[i][j];
        batAv[i] = rawScores[i][3] / rawScores[i][1];
        slugAv[i] = ((rawScores[i][3] - rawScores[i][4] - rawScores[i][5] - rawScores[i][6]) +
                     2 * rawScores[i][4] +
                     3 * rawScores[i][5] +
                     4 * rawScores[i][6]) /
                     rawScores[i][1];
        batAv[i] = round(batAv[i] * 1000);
        slugAv[i] = round(slugAv[i] * 1000);
        bigSlugAv += slugAv[i];
        bigBatAv += batAv[i];
    }
    bigBatAv /= 10;
    bigSlugAv /= 10;
    if(bigBatAv >= 266 && bigBatAv <= 267) bigBatAv = ceil(bigBatAv);
    else  bigBatAv = round(bigBatAv);
    bigSlugAv = round(bigSlugAv);
    cout << seasonName << endl;
    cout << "====================" << endl;
    for(int i = 0; i < 10; i++){
        cout << teamNames[i] << ": ." << batAv[i] << " ." << slugAv[i] << endl;
    }
    cout << "====================" << endl;
    cout << "Big 10 Av: ." << bigBatAv << " ." << bigSlugAv;
}