#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    map<string,vector<string>> tree;
    map<string, string> pred;
    int n;
    cin >> n;
    string mother, daughter;
    for(int i = 0; i < n; i++){
        cin >> mother >> daughter;
        tree[mother].push_back(daughter);
        pred[daughter] = mother;
    }
    for(int a = 0; a < 10; a++){
        string s;
        int sisters = 0, cousins = 0;
        cin >> s;
        sisters = tree[pred[s]].size() - 1;
        for(auto x : tree[pred[pred[s]]]){
            if(tree[x] == tree[pred[s]]) continue;
            cousins += tree[x].size();
        }
        cout << "Cousins: " << cousins << ", Sisters: " << sisters << endl;
    }
}