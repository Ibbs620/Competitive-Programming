//NOTE: This solution is incomplete. Only 4/10 points were acheived.

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int ts = 0; ts < t; ts++){
        int n;
        cin >> n;
        int answer[n];
        for(int it = 0; it < n; it++){
            int h,w;
            cin >> h >> w;
            char grid[h][w];
            string a = "0000000";
            int maxh=0, maxw=0,minh=500,minw=500;
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    cin >> grid[i][j];
                    if(grid[i][j] == '*'){
                        maxh=max(maxh,i);
                        maxw=max(maxw,j);
                        minh=min(minh,i);
                        minw=min(minw,j);
                    }
                }
            }
            pair<int,int> center = make_pair((maxh+minh)/2,(maxw+minw)/2);
            if(maxw == minw){
                answer[it] = 1;
                continue;
            }
            for(int i = minw; i < maxw; i++){
                if(grid[center.first][i] == '*') {
                    a[0] = '1';
                    break;
                }
            }
            for(int i = 1; center.first + i < maxh; i++){
                if(grid[center.first + i][minw] == '*') {
                    a[1] = '1';
                }
                if(grid[center.first - i][minw] == '*') {
                    a[2] = '1';
                }
                if(a[1] == '1' && a[2] == '1') break;
            }
            for(int i = 0; center.first + i <= maxh; i++){
                if(grid[center.first + i][maxw] == '*') {
                    a[3] = '1';
                }
                if(grid[center.first - i][maxw] == '*') {
                    a[4] = '1';
                }
                if(a[3] == '1' && a[4] == '1') break;
            }
            for(int i = minw + 1; i < maxw; i++){
                if(grid[minh][i] == '*') a[5] = '1';
                if(grid[maxh][i] == '*') a[6] = '1';
                if(a[5] == '1' && a[6] == '1') break;
            }
            if(a == "0111111") answer[it] = 0;
            else if(a == "0111100" || a == "0001100" ) answer[it] = 1;
            else if(a == "1100111") answer[it] = 2;
            else if(a == "1001111") answer[it] = 3;
            else if(a == "1001100" || a == "1011100") answer[it] = 4;
            else if(a == "1011011") answer[it] = 5;
            else if(a == "1111011") answer[it] = 6;
            else if(a == "0011100" || a == "0001110" ) answer[it] = 7;
            else if(a == "1111111") answer[it] = 8;
            else if(a == "1011111") answer[it] = 9;
            //cout << a << endl;
        }
        for(int i = 0; i < n; i++) cout << answer[i];
        cout << '\n';
    }
}
