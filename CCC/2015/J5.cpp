#include <iostream>

using namespace std;

int memo[250][250][250] = {{{0}}};

int dp(int n, int k, int l){
    if(n == k) return 1;
    if(k == 1) return 1;
    if(memo[n][k][l]) return memo[n][k][l];
    int total = 0;
    for(int i = l; i <= n / k; i++){
        total += dp(n-i, k-1, i);
    }
    memo[n][k][l] = total;
    return total;
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << dp(n, k, 1);
}