#include <bits/stdc++.h>

using namespace std;

vector<int> clubs;

int memo[5281] = {0};

int solve(int d){
    if(d == 0) return 0;
    if(d < 0) return 99999999;
    if(memo[d]) return memo[d];
    int n = 99999999;
    for(auto c: clubs){
        n = min(n, solve(d-c) + 1);
    }
    memo[d] = n;
    return n;
}

int main(){
    int d, c;
    cin >> d >> c;
    for(int i = 0; i < c; i++) {
        int a;
        cin >> a;
        clubs.push_back(a);
    }
    int n = solve(d);
    if(n == 99999999) cout << "Roberta acknowledges defeat.";
    else cout << "Roberta wins in " << n << " strokes.";
}