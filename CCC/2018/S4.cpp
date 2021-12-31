#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int,long long int> ans;

long long int solve(int x) {
    if(x == 1) return 1;
    if(ans.count(x) > 0) return ans[x];
    ans[x] = 0;
    int a, b;
    int i = x;
    while(i >= 2){
        a = x / i;
        b = x / (a + 1);
        ans[x] += solve(a) * (i - b);
        i = b;
    }
    return ans[x];
}

int main(){
    int n;
    cin >> n;
    cout << solve(n);
}