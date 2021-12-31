#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    map<string, vector<string>> adj;
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < q; i++){
        string a, b;
        cin >> a >> b;
        string path = "";
        stack<string> q;
        map<string, bool> vis;
        map<string, int> dist;
        q.push(a);
        vis[a] = true;
        while(!q.empty()){
            string s = q.top(); q.pop();
            path = path.substr(0, dist[s]) + s[0];
            if(s == b) break;
            for(auto u : adj[s]){
                if(vis[u]) continue;
                vis[u] = true;
                dist[u] = dist[s] + 1;
                q.push(u);
            }
        }
        cout << path << endl;
    }
}
