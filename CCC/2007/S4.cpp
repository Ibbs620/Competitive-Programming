//NOTE: This solution is incomplete. Only 10/50 points were achieved

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<vector<int>>pred;
int paths[10000]= {0};

int solve(int s){
    if(s == 1) return 1;
    if(paths[s]) return paths[s];
    for(auto u : tree[s]){
        if(u > s) continue;
        paths[s] += solve(u);
    }
    return paths[s];
}

int main(){
    int n;
    cin >> n;
    tree.resize(n+1);
    pred.resize(n+1);
    int x,y;
    while(x + y != 0){
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    for(int i = 1; i < tree.size(); i++){
        if(tree[i].size() == 1) paths[i] = 1;
        //cout << tree[i].size() << endl;
    }
    cout << solve(n);
}