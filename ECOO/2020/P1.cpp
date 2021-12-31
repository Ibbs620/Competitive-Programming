#include <bits/stdc++.h>

using namespace std;

string notes[] =
{"C", "C#","D","D#","E","F","F#","G","G#","A","A#","B"};

array<string, 4> cycle(array<string,4 > s, int t){
    for(int i = 0; i < t; i++){
        string hold = s[3];
        for(int j = 3; j > 0; j--){
            s[j] = s[j - 1];
        }
        s[0] = hold;
    }
    return s;
}

int main(){
    int t;
    cin >> t;
    for(int ts = 0; ts < t; ts++){
        array<string, 4> seq;
        int start;
        for(int i = 0; i < 4; i++) cin >> seq[i];
        for(int i = 0; i < 12; i++) {
            if(seq[0] == notes[i]) {
                start = i;
                break;
            }
        }
        if(notes[(start+4)%12] == seq[1] && notes[(start+7)%12] == seq[2] && notes[(start+10)%12] == seq[3]) {
            cout << "root\n";
            continue;
        }
        seq = cycle(seq, 1);
        for(int i = 0; i < 12; i++) {
            if(seq[0] == notes[i]) {
                start = i;
                break;
            }
        }
        if(notes[(start+4)%12] == seq[1] && notes[(start+7)%12] == seq[2] && notes[(start+10)%12] == seq[3]) {
            cout << "first\n";
            continue;
        }
        seq = cycle(seq, 1);
        for(int i = 0; i < 12; i++) {
            if(seq[0] == notes[i]) {
                start = i;
                break;
            }
        }
        if(notes[(start+4)%12] == seq[1] && notes[(start+7)%12] == seq[2] && notes[(start+10)%12] == seq[3]) {
            cout << "second\n";
            continue;
        }
        seq = cycle(seq, 1);
        for(int i = 0; i < 12; i++) {
            if(seq[0] == notes[i]) {
                start = i;
                break;
            }
        }
        if(notes[(start+4)%12] == seq[1] && notes[(start+7)%12] == seq[2] && notes[(start+10)%12] == seq[3]) {
            cout << "third\n";
            continue;
        }
        cout << "invalid\n";
    }
}