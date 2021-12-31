#include <iostream>

using namespace std;

bool cat[26][26] = {{0}};
int r, c;
int paths[26][26] = {{0}};

int solve(int x, int y){
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            if(!cat[i-1][j] && i-1 > 0) {
                paths[i][j] += paths[i-1][j];
            }
            if(!cat[i][j-1] && j-1 > 0) {
                paths[i][j] += paths[i][j-1];
            }
        }
    }
    return paths[x][y];
}

int main(){
    cin >> r >> c;
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        cat[x][y] = 1;
    }
    paths[1][1] = 1;
    cout << solve(r, c) << endl;

}
