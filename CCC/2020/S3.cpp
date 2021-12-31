#include <bits/stdc++.h>

using namespace std;

bool isperm(map<char, int> a, map<char, int> b){
    for(int i = 0; i < 26; i++){
        char l = 'a' + i;
        if(a[l] != b[l]) return false;
    }
    return true;
}

int main(){
    string n, h;
    cin >> n >> h;
    int nlen = n.length(), hlen = h.length(), perms = 0;
    map<char, int> freqn;
    map<char, int> freqh;
    map<size_t, bool> appears;

    for(auto x : n) freqn[x]++;
    for(int i = 0; i < nlen; i++) freqh[h[i]]++;

    for(int i = 0; i < hlen - nlen + 1; i++){
        if(i > 0){
            freqh[h[i-1]]--;
            freqh[h[i+nlen-1]]++;
        }
        hash<string> hasher;
        size_t Hash = hasher(h.substr(i, nlen));
        if(isperm(freqh, freqn) && !appears[Hash]) {
            appears[Hash] = 1;
            perms++;
        }
    }
    cout << perms;
}