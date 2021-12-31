//NOTE: This solution is incomplete. Only 1/10 points were achieved

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    int ree = 0;
    for(int ts = 0; ts < t; ts++){
        int n;
        cin >> n;
        int sum = 0;
        map<string, vector<pair<string,int>>> funs;
        for(int tsk = 0; tsk < n - ree; tsk++){
            string ins, fname;
            int num;
            cin >> ins;
            if(ins == "FUN"){
                cin >> fname;
                while(true){
                    ree++;
                    cin >> ins;
                    if(ins == "END") break;
                    cin >> num;
                    funs[fname].push_back(make_pair(ins, num));
                }
                continue;
            } else if (ins == "CALL"){
                cin >> fname;
                for(auto x : funs[fname]){
                    ins = x.first;
                    num = x.second;
                    if(ins == "ADD") sum += num;
                    else if(ins == "SUB") sum -= num;
                    else if(ins == "MULT") sum *= num;
                }
                continue;
            }
            cin >> num;
            if(ins == "ADD") sum += num;
            else if(ins == "SUB") sum -= num;
            else if(ins == "MULT") sum *= num;
        }
        cout << sum % 1000000007 << '\n';
    }
}
