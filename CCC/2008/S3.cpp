#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tests = 0; tests < t; tests++){
        int r, c;
        cin >> r >> c;
        char grid[r][c];
        int dir[4] = {1, -1, 0, 0};
        int dist[r][c];
        bool vis[r][c];
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> grid[i][j];
                vis[i][j] = 0;
                dist[i][j] = 0;
            }
        }
        queue<pair<int,int>> q;
        pair<int,int> s = make_pair(0, 0);
        q.push(s);
        vis[0][0] = 1;
        dist[0][0] = 1;
        while(!q.empty() && !dist[r-1][c-1] && grid[r-1][c-1] != '*'){
            int x, y;
            s = q.front();
            q.pop();
            if(grid[s.first][s.second] == '+'){
                for(int i = 0; i < 4; i++){
                    x = s.first + dir[i];
                    y = s.second + dir[3 - i];
                    if(x < 0 || x >= r || y < 0 || y >= c) continue;
                    if(vis[x][y]) continue;
                    if(grid[x][y] == '*') continue;
                    q.push(make_pair(x, y));
                    dist[x][y] = dist[s.first][s.second] + 1;
                    vis[x][y] = 1;
                }
            } else if(grid[s.first][s.second] == '|'){
                for(int i = 0; i < 2; i++){
                    x = s.first + dir[i];
                    y = s.second;
                    if(x < 0 || x >= r || y < 0 || y >= c) continue;
                    if(vis[x][y]) continue;
                    if(grid[x][y] == '*') continue;
                    q.push(make_pair(x, y));
                    dist[x][y] = dist[s.first][s.second] + 1;
                    vis[x][y] = 1;
                }
            } else if(grid[s.first][s.second] == '-'){
                for(int i = 0; i < 2; i++){
                    x = s.first;
                    y = s.second + dir[i];
                    if(x < 0 || x >= r || y < 0 || y >= c) continue;
                    if(vis[x][y]) continue;
                    if(grid[x][y] == '*') continue;
                    q.push(make_pair(x, y));
                    dist[x][y] = dist[s.first][s.second] + 1;
                    vis[x][y] = 1;
                }
            }
        }
        if(dist[r-1][c-1])cout << dist[r-1][c-1] << endl;
        else cout << -1 << endl;
    }
}
