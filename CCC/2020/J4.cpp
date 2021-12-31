#include <iostream>

using namespace std;

string cycle(string s){
    int last = s.length() -1;
    char c = s[last];
    s.erase(last,last);
    return c + s;
}

int main(){
    string t, s;
    cin >> t >> s;
    bool yes = false;
    if(t.length() < s.length()) goto yes;
    for(int i = 0; i <= t.length() - s.length(); i++){
        for(int j = 0; j < s.length(); j++){
            s = cycle(s);
            if(t.substr(i,s.length()) == s){
                yes = true;
                goto yes;
            }
        }
    }
    yes:
    if(yes) cout << "yes";
    else cout << "no";
}
