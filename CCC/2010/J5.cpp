#include <iostream>
#include <queue>

using namespace std;

int main(){
    int sx,sy,dx,dy,x,y;
    bool vis[9][9];
    int dist = 0;
    for(int i = 1; i < 9; i++) for(int j = 1; j < 9; j++) vis[i][j] = false;
    cin >> sx >> sy >> dx >> dy;
    queue<pair<int,int>> q;
    int d[8] = {2, 2, -2, -2, 1, -1, 1, -1};
    q.push(make_pair(sx,sy));
    int qs = q.size();
    int it = 0;
    vis[sx][sy] = true;
    while(!vis[dx][dy]){
        sx = q.front().first;
        sy = q.front().second;
        it++;
        if(it == qs){
            qs = q.size();
            it = 0;
            dist++;
        }
        q.pop();
        for(int i = 0; i < 8; i++){
            x = sx + d[i];
            y = sy + d[7 - i];
            if(x < 1 || x > 8 || y < 1 || y > 8) continue;
            if(!vis[x][y]){
                q.push(make_pair(x,y));
                vis[x][y] = true;
            }
        }
    }
    cout << dist;
}
