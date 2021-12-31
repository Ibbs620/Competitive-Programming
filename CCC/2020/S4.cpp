//NOTE: This solution is incomplete. Only 8/15 points were achieved.

#include <bits/stdc++.h>

using namespace std;

int main(){
    string n;
    cin >> n;
    int a = 0, b = 0, c = 0;
    for(auto x : n){
        if(x == 'A')a++;
        else if(x == 'B')b++;
        else c++;
    }
    string window;
    int aSection = 0;
    int aDensity = 0;
    window = n.substr(0, a);
    for(auto x : window) if(x == 'A') aDensity++;
    int maxADensity = aDensity;
    for(int i = 1; i < n.length(); i++){
        if(n[i-1] == 'A') aDensity--;
        if(n[(i + a - 1) % n.length()] == 'A') aDensity++;
        maxADensity = max(maxADensity, aDensity);
    }
    cout << a - maxADensity;
}