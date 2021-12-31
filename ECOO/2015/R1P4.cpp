#include <bits/stdc++.h>

using namespace std;

string d[10] = {"ug","ook","oog","ooga","ugug","mook","oogam","oogum","ookook","mookmook"};
map<string,int> memo;

int solve(string s){
    if(memo.count(s)) return memo[s];
    if(s == "ug" || s == "ook" || s == "oog" || s == "mook" || s == "oogum" || s == "ooga" || s == "oogam") return 1;
    if(s == "ugug" || s == "mookmook" || s == "ookook") return 2;
    int total = 0;
    for(auto x : d){
        if(x == s.substr(0, x.length())){
            total += solve(s.substr(x.length() + 0, s.length()));
        }
    }
    memo.insert(make_pair(s, total));
    return total;
}

int main(){
    for(int i = 0; i < 10; i++){
        string n;
        getline(cin, n);
        cout << solve(n) << "\n";
    }
}