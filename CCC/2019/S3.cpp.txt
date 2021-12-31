//NOTE: This solution is incomplete. Only 4/15 points were achieved.

#include <iostream>

using namespace std;

int main(){
    string sq[3][3];
    int sqF[3][3];
    bool filled[3][3];
    int rowc[3] = {0}, colc[3] = {0};
    int done = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> sq[i][j];
            if(sq[i][j] != "X") {
                sqF[i][j] = stoi(sq[i][j]);
                filled[i][j] = true;
                colc[j]++;
                rowc[i]++;
                done++;
            } else {
                filled[i][j] = false;
            }
        }
    }
    while(done < 4){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(!filled[i][j]){
                    sqF[i][j] =  rand() % 10;
                    filled[i][j] = true;
                    colc[j]++;
                    rowc[i]++;
                    done++;
                    goto stop;
                }
            }
        }
        stop:;
    }
    while(true){
        for(int i = 0; i < 3; i++){
            if(colc[i] == 2){
                if(!filled[0][i]){
                    sqF[0][i] = 2 * sqF[1][i] - sqF[2][i];
                    filled[0][i] = true;
                    rowc[0]++;
                } else if(!filled[1][i]){
                    sqF[1][i] = (sqF[0][i] + sqF[2][i]) / 2;
                    filled[1][i] = true;
                    rowc[1]++;
                } else {
                    sqF[2][i] = 2 * sqF[1][i] - sqF[0][i];
                    rowc[2]++;
                    filled[2][i] = true;
                }
                colc[i]++;
                done++;
            }
        }
        for(int i = 0; i < 3; i++){
            if(rowc[i] == 2){
                if(!filled[i][0]){
                    sqF[i][0] = 2 * sqF[i][1] - sqF[i][2];
                    filled[i][0] = true;
                    colc[0]++;
                } else if(!filled[i][1]){
                    sqF[i][1] = (sqF[i][0] + sqF[i][2]) / 2;
                    filled[i][1] = true;
                    colc[1]++;
                } else {
                    sqF[i][2] = 2 * sqF[i][1] - sqF[i][0];
                    filled[i][2] = true;
                    colc[2]++;
                }
                rowc[i]++;
                done++;
            }
        }
        if(done >= 9) break;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) cout << sqF[i][j] << " ";
        cout << endl;
    }
}