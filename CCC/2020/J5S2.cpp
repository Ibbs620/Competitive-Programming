#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int main(){
    int m, n; //Dimensions of grid
    cin >> m >> n;
    int grid[m + 1][n + 1]; //grid to model the room
    bool vis[m + 1][n + 1]; //grid that says whether or not a space have already been visited
    bool yes = false; //stores answer
    int maxx = m*n;
    int fact;
    stack<int> qx;//create stack for x and y values
    stack<int> qy;
    int x = 1, y = 1; //set starting point
    for(int i = 1; i <= m; i++){ //get input
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
            vis[i][j] = false;
            if(grid[i][j] == n * m) yes = true;
        }
    }
    if(!yes) goto yes;
    yes = false;
    qx.push(x); //add points to stack
    qy.push(y);
    vis[x][y] = true; //mark points as visited

    //Depth First Search of the grid (Google DFS for more info)
    while(!qx.empty()){
        x = qx.top(); //set x and y to top of stack
        y = qy.top();

        qx.pop(); //remove top value from stack
        qy.pop();
        if(grid[x][y] > maxx) continue;
        for(int i = 1; i * i <= grid[x][y]; i++){
            if(grid[x][y] == maxx){
                yes = true;
                goto yes;
            }
            if(grid[x][y] % i == 0){
                if(grid[x][y] / i > m && grid[x][y] / i > n) continue;
                //if(i > m && i > n) break;
                fact = grid[x][y] / i;
                if(fact <= m && !vis[fact][i] && i <= n){
                    qx.push(fact);
                    qy.push(i);
                    vis[fact][i] = true;
                }
                if(fact <= n && !vis[i][fact] && i <= m){
                    qy.push(fact);
                    qx.push(i);
                    vis[i][fact] = true;
                }
            }
        }
    }
    yes:
    if(yes) cout << "yes"; //Output
    else cout << "no";
}