#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, m, sx, sy, x, y;
    cin >> n >> m;
    char grid[n][m];
    bool visited[n][m];
    bool yes = false;
    int direct[4] = {1,-1,0,0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            visited[i][j] = false;
            if(grid[i][j] == 's'){
                sx = i;
                sy = j;
            }
        }
    }
    queue<int> qx;
    queue<int> qy;
    qx.push(sx);
    qy.push(sy);
    visited[sx][sy] = true;
    int qs = qx.size();
    int it = 0;
    int dist = 0;

    while(!qy.empty()){
        sx = qx.front();
        sy = qy.front();
        if(qs == it){
            qs = qx.size();
            it = 0;
            dist++;
        }
        it++;
        qx.pop();
        qy.pop();
        for(int k = 0; k < 4; k++){
            x = sx + direct[k];
            y = sy + direct[3 - k];
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(visited[x][y]) continue;
            if(grid[x][y] == 'e') {
                yes = true;
                goto ans;
            }
            if(grid[x][y] == '.') {
                qx.push(x);
                qy.push(y);
                visited[x][y] =true;
            }
        }
    }
    ans:;
    if(yes) cout << dist;
    else cout << -1;
}
