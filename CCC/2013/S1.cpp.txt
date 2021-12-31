#include <bits/stdc++.h>

using namespace std;

bool checkDistinct(int n){
    string num = to_string(n);
    sort(num.begin(), num.end());
    for(int i = 1; i < num.length(); i++){
        if(num[i] == num[i-1]) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    do n++;
    while(!checkDistinct(n));
    cout << n;
}