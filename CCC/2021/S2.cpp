//NOTE: This solution is incomplete. Only 10/15 points were achieved.

#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<bool>> grid;
    int c[m+1] = {0};
    grid.resize(m+1);
    for(int i = 1; i <= m; i++) grid[i].resize(n+1);
    int g = 0;
    for(int i = 0; i < k; i++){
        char rc;
        int num;
        cin >> rc >> num;
        if(rc == 'R'){
            grid[num].flip();
            c[num] = n - c[num];
        } else {
            for(int j = 1; j <= m; j++){
               grid[j][num] = !grid[j][num];
               if(grid[j][num]) c[j]++;
               else c[j]--;
            }

        }
    }
    for(auto x : c) {
        g += x;
    }
    cout << g;
}
