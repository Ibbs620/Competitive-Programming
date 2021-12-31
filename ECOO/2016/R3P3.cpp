//NOTE: This solution is incomplete. Only 8/10 points were acheived.

#include<bits/stdc++.h>

using namespace std;

string dict[200000];
unordered_map<string, int> memo;

int solve(string s, int n){
    if(memo.count(s)) return memo[s];
    if(s == "") return 1;
    int slen = s.length();
    int best = 20000;
    for(int i = 0; i < n; i++){
        int xlen = dict[i].length();
        if(s.substr(0, xlen) == dict[i]) best = min(solve(s.substr(xlen, slen), n) + 1, best);
    }
    memo[s] = best;
    return best;
}

int main(){
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++){
        cin >> dict[i];
        memo[dict[i]] = 2;
    }
    for(int i = 0; i < 10; i++){
        string s2;
        cin >> s2;
        cout << solve(s2, n) - 2 << "\n";
    }
}