#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, m, sx, sy, x, y;
    cin >> n >> m;
    char grid[n][m];
    int distGrid[n][m];
    bool visited[n][m];
    int direct[4] = {1,-1,0,0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            distGrid[i][j] = -1;
            visited[i][j] = false;
            if(grid[i][j] == 'S'){
                sx = i;
                sy = j;
                distGrid[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'C'){
                for(int k = i + 1; k < n; k++){
                    if(grid[k][j] == 'W') break;
                    else if(grid[k][j] == '.') grid[k][j] = 'N';
                    else if(grid[k][j] == 'S') grid[k][j] = 'n';
                    else continue;
                }
                for(int k = i - 1; k >= 0; k--){
                    if(grid[k][j] == 'W') break;
                    else if(grid[k][j] == '.') grid[k][j] = 'N';
                    else if(grid[k][j] == 'S') grid[k][j] = 'n';
                    else continue;
                }
                for(int k = j + 1; k < m; k++){
                    if(grid[i][k] == 'W') break;
                    else if(grid[i][k] == '.') grid[i][k] = 'N';
                    else if(grid[i][k] == 'S') grid[i][k] = 'n';
                    else continue;
                }
                for(int k = j - 1; k >= 0; k--){
                    if(grid[i][k] == 'W') break;
                    else if(grid[i][k] == '.') grid[i][k] = 'N';
                    else if(grid[i][k] == 'S') grid[i][k] = 'n';
                    else continue;
                }
            }
        }
    }

    queue<pair<int,int>> q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;
    while(!q.empty() && grid[sx][sy] != 'n'){
        sx = q.front().first;
        sy = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            x = sx + direct[k];
            y = sy + direct[3 - k];
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(visited[x][y]) continue;
            if(grid[x][y] == '.' || grid[x][y] == 'S') {
                q.push(make_pair(x, y));
                distGrid[x][y] = distGrid[sx][sy] + 1;
                visited[x][y] = true;
            } else {
                while(grid[x][y] == 'U' || grid[x][y] == 'D' || grid[x][y] == 'L' || grid[x][y] == 'R'){
                    if(visited[x][y]) break;
                    visited[x][y] = true;
                    switch(grid[x][y]){
                    case 'U':
                        x--;
                        break;
                    case 'D':
                        x++;
                        break;
                    case 'R':
                        y++;
                        break;
                    case 'L':
                        y--;
                        break;
                    }
                }
                if(grid[x][y] == '.' && !visited[x][y]){
                    q.push(make_pair(x, y));
                    distGrid[x][y] = distGrid[sx][sy] + 1;
                    visited[x][y] = true;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' || grid[i][j] == 'N') cout << distGrid[i][j] << endl;
        }
    }
}