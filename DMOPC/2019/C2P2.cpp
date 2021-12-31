#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[501][501];
int mi[501][501];
bool r[501][501] = {{0}};

int solve(int x, int y){
    if(x > n || y > m || x < 1 || y < 1) return 250000000000;
    if(r[x][y]) return mi[x][y];
    mi[x][y] = grid[x][y] + min(solve(x - 1, y), solve(x, y - 1));
    //cout << min(solve(x - 1, y), solve(x, y - 1)) << endl;
    r[x][y] = 1;
    return mi[x][y];
}

int main(){
    int l;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }
    mi[1][1] = grid[1][1];
    r[1][1] = 1;
    solve(n, m);
    cout << mi[n][m];
}
