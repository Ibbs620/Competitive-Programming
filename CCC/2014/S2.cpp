#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string good = "good";
    cin >> n;
    string a[n], b[n];
    map<string, string> match;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        match[a[i]] = b[i];
        if(a[i] == b[i]) good = "bad";
    }
    for(int i = 0; i < n; i++){
        if(match[match[a[i]]] != a[i]) {
            good = "bad";
        }
    }
    cout << good;
}