#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, c, v;
    string word;
    cin >> n >> c >> v >> word;
    string con = "bcdfghjklmnpqrstvwxyz";
    string vow = "aeiouy";
    set<char> conSet, vowSet;
    for(char x: con) conSet.insert(x);
    for(char x: vow) vowSet.insert(x);
    int a = 0, b = 0;
    for(char x : word){
        if(conSet.count(x)){
            if(x != 'y') b = 0;
            a++;
        }
        if (vowSet.count(x)){
            if(x != 'y') a = 0;
            b++;
        }
        if(a > c || b > v){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}
