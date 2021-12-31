#include <iostream>

using namespace std;

int main(){
    int grid[4][4];
    int sumI[4] = {0};
    int sumJ[4] = {0};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> grid[i][j];
            sumI[i] += grid[i][j];
            sumJ[j] += grid[i][j];
        }
    }
    if(sumI[0] == sumI[1] && sumI[1] == sumI[2] && sumI[2] == sumI[3] && sumJ[0] == sumJ[1] && sumJ[1] == sumJ[2] && sumJ[2] == sumJ[3] && sumI[0] == sumJ[0]){
        cout << "magic\n";
    } else {
        cout << "not magic\n";
    }
}