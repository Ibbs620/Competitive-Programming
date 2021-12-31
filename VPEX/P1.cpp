#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int s1[5],s2[5],sum1 = 0, sum2 = 0;
    for(int i = 0; i < 5; i++){
        cin >> s1[i];
    }
    for(int i = 0; i < 5; i++){
        cin >> s2[i];
    }
    sort(s1, s1 + 5);
    sort(s2, s2 + 5);
    for(int i = 1; i < 5; i++){
        sum1 += s1[i];
        sum2 += s2[i];
    }
    cout << max(sum1, sum2);
}