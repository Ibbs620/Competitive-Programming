#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <map>

using namespace std;

int compare(string s1, string s2){
    if(s1.length() > s2.length()) return 1;
    return 0;
}

int main(){
    string moves;
    cin >> moves;
    int p = moves.length();
    int m;
    cin >> m;
    string combo[m];
    int pv[m];
    map<string, int> pvm;
    for(int i = 0; i < m; i++) {
        cin >> combo[i] >> pv[i];
        pvm.insert(pair<string,int>(combo[i], pv[i]));
    }
    sort(combo, combo + m, compare);
    for(int i = 0; i < moves.length(); i++){
        if(moves[i] == 'X') continue;
        for(int j = 0; j < m; j++){
            if(moves.substr(i, combo[j].length()) == combo[j]){
                p += pvm[combo[j]];
                for(int k = 0; k < combo[j].length(); k++) {
                    moves[k + i] = 'X';
                }
                break;
            }
        }
    }
    cout << p;
}